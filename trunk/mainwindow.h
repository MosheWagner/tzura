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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "tzuraimage.h"
#include <QPainter>
#include <iostream>
#include <QDir>
#include <QCursor>
#include <QPainter>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent /*, QString path */);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    TzuraImage *tz;

    //Holds the color the image will be painted with if requested by user
    int paintMode;

    void process();
    void showDetection();
    void showBlockArray();

    int brushSize;

public slots:
    //Prints a message to both console and message label
    void update(QString message);

private slots:
    void on_tabWidget_currentChanged(int index);
    void on_minusBTN_clicked();
    void on_plusBTN_clicked();
    void on_toolButton_clicked();
    void on_nextBTN_clicked();
    void on_prevBTN_clicked();
    void on_saveLayoutBTN_clicked();
    void on_reprocBTN_clicked();
    void on_whiteBTN_clicked(bool checked);
    void on_blackBTN_clicked(bool checked);

    void on_openfileBTN_clicked();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void valueChangeRequest(QPoint pos);

    void showHelp();
};

#endif // MAINWINDOW_H
