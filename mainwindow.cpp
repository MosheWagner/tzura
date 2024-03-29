/* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2
* as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* Author: Moshe Wagner. <moshe.wagner@gmail.com>
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "help.h"

// Tzura - A super primitive document layout analyzer for detection of the Gmara's Tzurat Hadaf


// -----------------------------------------------------------------------------
// Note: Points in QImage (and other stuff too), start from the (user's) top left.
// -----------------------------------------------------------------------------

// ------------------------------------------------------------------------------
// Almost works!
//
// Time test:
// Brachot took 27 minutes. (2 pages not done)
// Comes out about 21 hours for the whole shas.
// -------------------------------------------------------------------------------


//TODO: Add file names to '.layout' files (to know which masechet it's from)

/*
@ Basic 'expanding blocks' algorithm:
    ('V' - done,
     '-' - done but could be improved,
     '?' - How the h*** do you do it?)

# [V] Load image
# [V] Force image to B&W
# [?] Align image to XY axises

# [-] Build rough array representing the image
# [?] Filter noises out of the array

# [-] Roughly detect internal square of Gmara-Rashi-Tosfot
    -> Bottom left corner, then top left, and finally top right

# [-] Start 'expanding' white blocks, until shapes are formed
# [-] Remove too small / blocks of last-line in block words

# [-] Link connected rectangles to form blocks
# [ ] Improve the shapes to get better blocks

# [ ] Guess what block goes with what text (by size? position?)

# [-] Allow user to change the image and re-detect, or approve the detection

# [ ] Load the Wagshol PDF of this page, read blocks' contents, and see if all is ok

# [-] Save page block information

# [ ] Done!
*/

using namespace std;


MainWindow::MainWindow(QWidget * parent /*,  QString path */) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QApplication::processEvents();

    showHelp();


    setWindowState(Qt::WindowMaximized);

    paintMode = -1;

    tz = NULL;

    ui->tabWidget->setCornerWidget(ui->proglabel);

    brushSize = 9;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showHelp()
{
    help *h = new help();
    h->setModal(true);
    h->show();
}


void MainWindow::on_openfileBTN_clicked()
{
    QFileDialog dialog(this);

    dialog.setDirectory(QDir::current());
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setNameFilter(tr("PNG Image (*.png)"));


    if (dialog.exec() && !dialog.selectedFiles().empty())
    {
        ui->fileLine->setText(dialog.selectedFiles().at(0));

        process();
    }
}


void MainWindow::on_prevBTN_clicked()
{
    ui->prevBTN->setEnabled(false);
    ui->nextBTN->setEnabled(false);

    QString cur = ui->fileLine->text();
    QString newfile = cur;

    QRegExp rx("a(\\d+).png");
    int pos = rx.indexIn(cur);
    if (pos > -1)
    {

        int n = QString(rx.cap(1)).toInt();

        if (n >= 0) newfile = cur.replace(rx, "a" + QString::number(n - 1) + ".png");

        qDebug() << newfile;
    }

    ui->fileLine->setText(newfile);

    process();

    ui->prevBTN->setEnabled(true);
    ui->nextBTN->setEnabled(true);
}


void MainWindow::on_nextBTN_clicked()
{
    ui->prevBTN->setEnabled(false);
    ui->nextBTN->setEnabled(false);

    QString cur = ui->fileLine->text();
    QString newfile = cur;

    QRegExp rx("([a-zA-Z].)(\\d+).png");
    int pos = rx.indexIn(cur);
    if (pos > -1)
    {

        int n = QString(rx.cap(2)).toInt();

        if (n >= 0) newfile = cur.replace(rx, rx.cap(1) + QString::number(n + 1) + ".png");

        qDebug() << newfile;
    }

    ui->fileLine->setText(newfile);

    process();

    ui->prevBTN->setEnabled(true);
    ui->nextBTN->setEnabled(true);
}


void MainWindow::process()
{
    if (tz) delete tz;

    tz = new TzuraImage(ui->fileLine->text());

    connect(tz, SIGNAL(message(QString)), this, SLOT(update(QString)));

    tz->setSquareBorderSensitivity(ui->satSpinBox->value());

    tz->process();

    showDetection();
    showBlockArray();
}

void MainWindow::on_reprocBTN_clicked()
{
    if (tz != NULL)
    {
        tz->setSquareBorderSensitivity(ui->satSpinBox->value());

        tz->process(false);

        showDetection();
        showBlockArray();
    }
}

void MainWindow::showDetection()
{
    //Display image with transparent detection above it
    QPixmap Blocks(QPixmap::fromImage(tz->render(2)));

    QImage im = *tz->getIM();
    im = im.scaledToWidth(Blocks.width());
    QPixmap PM(QPixmap::fromImage(im));



    QPainter p(&PM);
    p.drawPixmap(0,0, Blocks);

    ui->label->setPixmap(PM);
}

void MainWindow::showBlockArray()
{
    //Display image with transparent blocks above it
    QPixmap BlockArray(QPixmap::fromImage(tz->render(0)));

    QImage im = *tz->getIM();
    im = im.scaledToWidth(BlockArray.width());
    QPixmap PM(QPixmap::fromImage(im));


    QPainter p(&PM);
    p.drawPixmap(0,0, BlockArray);

    ui->label_2->setPixmap(PM);
}

//Prints a message to both console and message label
void MainWindow::update(QString message)
{
    ui->proglabel->setText(message);
    QApplication::processEvents();

    //qDebug() << message;
}

void MainWindow::on_blackBTN_clicked(bool checked)
{
    ui->whiteBTN->setChecked(false);

    if (checked)
    {
        QCursor cur(QPixmap(":/Icons/Icons/Black.png").scaledToHeight(brushSize));

        QApplication::restoreOverrideCursor();
        QApplication::setOverrideCursor(cur);

        paintMode = 0;
    }
    else
    {
        paintMode = -1;
        QApplication::restoreOverrideCursor();
    }
}

void MainWindow::on_whiteBTN_clicked(bool checked)
{
    ui->blackBTN->setChecked(false);

    if (checked)
    {
        QCursor cur(QPixmap(":/Icons/Icons/White.png").scaledToHeight(brushSize));

        QApplication::restoreOverrideCursor();
        QApplication::setOverrideCursor(cur);

        paintMode = 1;
    }
    else
    {
        paintMode = -1;
        QApplication::restoreOverrideCursor();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (paintMode != -1 && tz != NULL && ui->tabWidget->currentIndex() == 1)
    {
        if (event->button() == Qt::LeftButton)
        {
            valueChangeRequest(event->globalPos());
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (paintMode != -1 && tz != NULL && ui->tabWidget->currentIndex() == 1)
    {
      valueChangeRequest(event->globalPos());
    }
}


void MainWindow::valueChangeRequest(QPoint pos)
{
    //Find where the click was, relative to the labels
    QPoint p = ui->label_2->mapFromGlobal(pos);

    //Find closest location in array:
    QSize blockSize = tz->getPaintBlockSize();

    int x = -1;
    int y = -1;

    x = (p.x() / blockSize.width()) - 1;
    y = (p.y() / blockSize.height()) - 1 ;

    int size = (QApplication::overrideCursor()->pixmap().size().width() / 3);

    int n = (size / 2) - 1;

    //Update the image array
    for (int a= n * -1; a<size - n; a++) for (int b=n * -1; b<size - n; b++)
    {
        tz->setArrayPoint(x + a, y + b,paintMode);
    }

    //Show how it looks now
    showBlockArray();


    QApplication::processEvents();
}

void MainWindow::on_saveLayoutBTN_clicked()
{
    QFile f(ui->fileLine->text().replace(".png", ".layout"));


    if (f.open(QFile::WriteOnly))
    {
        f.write(tz->blockOutput().toUtf8());
        f.close();
    }

    on_nextBTN_clicked();
}

void MainWindow::on_toolButton_clicked()
{
    showHelp();
}

void MainWindow::on_plusBTN_clicked()
{
    brushSize += 3;

    QCursor cur(QApplication::overrideCursor()->pixmap().scaledToHeight(brushSize));

    QApplication::restoreOverrideCursor();
    QApplication::setOverrideCursor(cur);
}

void MainWindow::on_minusBTN_clicked()
{
    if (brushSize > 3) brushSize -= 3;

    QCursor cur(QApplication::overrideCursor()->pixmap().scaledToHeight(brushSize));

    QApplication::restoreOverrideCursor();
    QApplication::setOverrideCursor(cur);
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (index == 0) QApplication::restoreOverrideCursor();
    else
    {
        if (ui->whiteBTN->isChecked())
        {
            QCursor cur(QPixmap(":/Icons/Icons/White.png").scaledToHeight(brushSize));
            QApplication::setOverrideCursor(cur);
        }
        else if (ui->blackBTN->isChecked())
        {
            QCursor cur(QPixmap(":/Icons/Icons/Black.png").scaledToHeight(brushSize));
            QApplication::setOverrideCursor(cur);
        }
    }
}
