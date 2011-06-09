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

#include "tzuraimage.h"

#include <QPainter>
#include <QColor>
#include <QPen>
#include <QFile>
#include <QStringList>
#include <QXmlStreamReader>

//Build the tzura image from the given image file
TzuraImage::TzuraImage(QString path)
{
    imagePath = path;

    im.fill(0);
    im.scaledToHeight(1);

    im.load(imagePath);

    if (im.isNull())
    {
        qCritical() << "Can't load image! Quiting!";
        exit(3); //Image can't open
    }

    //Scale the image to a normal size
    im = im.scaledToHeight(7500);

    //Force to B/W:
    im = im.convertToFormat(QImage::Format_Mono);

    //Init val
    squareBorderSensitivity = 0.7;
}

TzuraImage::~TzuraImage()
{
    for (int i=0; i<4; i++)
    {
        delete ImgArray[i];
    }
}

void TzuraImage::process(bool firstTime)
{
    if (firstTime)
    {
        //Set parameters for image prcessing
        XY_RATIO =  (float) im.height() / im.width();
        RES_X  = 200;
        RES_Y = RES_X * XY_RATIO;

        qDebug() << RES_Y;

        BLOCK_SIZE_X = im.width() / RES_X + 1;
        BLOCK_SIZE_Y = im.height() / RES_Y + 1;

        im = im.scaledToWidth(BLOCK_SIZE_X * RES_X);

        //For images directly rendered from the pdf
        SATURATION_PERCENT = 0.01;
        //For all other images
        //SATURATION_PERCENT = 5;
        SATURATION_LEVEL = BLOCK_SIZE_Y * BLOCK_SIZE_X * SATURATION_PERCENT / 100;

        //Build a block array from the image
        emit message("Building image array...");
        buildBlockArray(RES_X, BLOCK_SIZE_X, RES_Y, BLOCK_SIZE_Y, SATURATION_LEVEL);
    }

    //Pass the image through filters to remove noise
    emit message("Filtering image...");


    SingleLineYFilter();

    //Crop edges:
    cropEdges();

    //Filter image:
    SingleLineXFilter();

    lastWordInBlockFilter();

    SingleLineYFilter();
    SingleLineXFilter();
    //strongFilter(5);

    //strongFilter(14);
    strongFilter(14);

    SingleLineYFilter();
    SingleLineXFilter();


    //See if it has a layout file already
    QFile f(imagePath.replace(".png", ".layout"));

    if (f.exists() && firstTime)
    {
        drawSavedRects(imagePath.replace(".png", ".layout"));

        emit message("Displaying saved page layout. Click re-process to ignore it.");
    }
    else
    {

        //Growing-Squares method
        emit message("Finding squares...");

        findSquares(squareBorderSensitivity, 10);

        findSquares(squareBorderSensitivity, 2);

        joinSquares();

        makeNewBlocks();

        emit message("Done!");
    }


    /*
    //DEBUG:
    //Show square seed
    for (int i=0; i<squareList.size(); i++)
    {
        expandingSquare square = squareList[i];
        for (int k=square.seed.x(); k<square.seed.x() + square.seedSize; k++)
            for (int l=square.seed.y(); l<square.seed.y() + square.seedSize; l++)
                ImgArray[2]->set(k,l,9);
    }
    */

}

void TzuraImage::setSquareBorderSensitivity(float sbs)
{
    squareBorderSensitivity = sbs;
}

//Build a block array from the image
void TzuraImage::buildBlockArray(int RES_X, int BLOCK_SIZE_X, int RES_Y, int BLOCK_SIZE_Y, int SATURATION_LEVEL)
{
    //Create 4 layers:
    for (int i=0; i<4; i++) ImgArray << new ImageArray(RES_X, RES_Y);

    //TODO: How to not miss out edges of the image?

    int BLACKPIXEL = im.color(1);

    //Build array
    for (int i=0; i<RES_X; i++)
    {
        for (int j=0; j<RES_Y; j++)
        {
            int count = 0;
            for (int x=i*BLOCK_SIZE_X; x<(i+1)*BLOCK_SIZE_X; x++)
            {
                for (int y=j*BLOCK_SIZE_Y; y<(j+1)*BLOCK_SIZE_Y; y++)
                {
                    if (im.pixel(x,y) == BLACKPIXEL) count ++;
                }
            }

            if (count > SATURATION_LEVEL) ImgArray[0]->set(i,j,1);
            else ImgArray[0]->set(i,j,0);

            count = 0;
        }
    }
}



//Simple filter to remove too thin lines on the Y axis
void TzuraImage::SingleLineYFilter()
{
    for (int i=1; i<RES_X-1; i++)
    {
        for (int j=1; j<RES_Y-1; j++)
        {
            if (ImgArray[0]->at(i, j-1) == 1 && ImgArray[0]->at(i, j+1) == 1) ImgArray[0]->set(i,j,1);
            if (ImgArray[0]->at(i, j-1) == 0 && ImgArray[0]->at(i, j+1) == 0) ImgArray[0]->set(i,j,0);
        }
    }
}

/*
//Simple filter to remove too thin lines on the Y axis
void TzuraImage::DoubleLineYFilter()
{
    for (int i=1; i<RES_X-1; i++)
    {
        for (int j=2; j<RES_Y-3; j++)
        {
            if (ImageArray[i][j-2] == 1 && ImageArray[i][j-1] == 1 && ImageArray[i][j+2] == 1 && ImageArray[i][j+3] == 1)
            {
                ImageArray[i][j] = 1;
                ImageArray[i][j + 1] = 1;
            }
            if (ImageArray[i][j-2] == 0 && ImageArray[i][j-1] == 0 && ImageArray[i][j+2] == 0 && ImageArray[i][j+3] == 0)
            {
                ImageArray[i][j] = 0;
                ImageArray[i][j + 1] = 0;
            }
        }
    }
}
*/

//Simple filter to remove too thin lines on the X axis
void TzuraImage::SingleLineXFilter()
{
    for (int i=1; i<RES_X-1; i++)
    {
        for (int j=1; j<RES_Y-1; j++)
        {
            if (ImgArray[0]->at(i-1,j) == 1 && ImgArray[0]->at(i+1,j) == 1) ImgArray[0]->set(i,j,1);
            if (ImgArray[0]->at(i-1,j) == 0 && ImgArray[0]->at(i+1,j) == 0) ImgArray[0]->set(i,j,0);
        }
    }
}

/*
//Simple filter to remove too thin lines on the X axis
void TzuraImage::DoubleLineXFilter()
{
    for (int i=2; i<RES_X-3; i++)
    {
        for (int j=1; j<RES_Y-1; j++)
        {
            if (ImageArray[i-2][j] == 1 && ImageArray[i-1][j] == 1 && ImageArray[i+2][j] == 1 && ImageArray[i+3][j] == 1)
            {
                ImageArray[i][j] = 1;
                ImageArray[i+1][j] = 1;
            }
            if (ImageArray[i-2][j] == 0 && ImageArray[i-1][j] == 0 && ImageArray[i+2][j] == 0 && ImageArray[i+3][j] == 0)
            {
                ImageArray[i][j] = 0;
                ImageArray[i+1][j] = 0;
            }
        }
    }
}
*/

//Inverts points (of both values) that do not have enough straight neighbors of the same color
// (By the given size)
void TzuraImage::strongFilter(int squareSize)
{
    int n = squareSize / 2;

    for (int i=squareSize; i<RES_X-squareSize; i++)
    {
        for (int j=squareSize; j<RES_Y-squareSize; j++)
        {
            if (ImgArray[0]->at(i,j) == 0) //Is black
            {
                //Find an (almost) full line of blacks
                int safe = 0;

                //Up:
                int c = 0;
                for (int m=j-n; m<j; m++) if (ImgArray[0]->at(i,m) == 0) c++;
                if (c > n * 0.8)
                {
                    safe++;

                    //See if this can b done even further
                    c = 0;
                    for (int m=j-n-n; m<j-n; m++) if (ImgArray[0]->at(i,m) == 0) c++;
                    if (c > n * 0.8) safe++;
                }

                //Right:
                c = 0;
                for (int l=i; l<i+n; l++) if (ImgArray[0]->at(l,j) == 0) c++;
                if (c > n * 0.8)
                {
                    safe++;

                    c = 0;
                    for (int l=i+n; l<i+n+n; l++) if (ImgArray[0]->at(l,j) == 0) c++;
                    if (c > n * 0.8) safe++;
                }

                //Down:
                c = 0;
                for (int m=j; m<j+n; m++) if (ImgArray[0]->at(i,m) == 0) c++;
                if (c > n * 0.8)
                {
                    safe++;

                    c = 0;
                    for (int m=j+n; m<j+n+n; m++) if (ImgArray[0]->at(i,m) == 0) c++;
                    if (c > n * 0.8) safe++;
                }

                //Left:
                c = 0;
                for (int l=i-n; l<i; l++) if (ImgArray[0]->at(l,j) == 0) c++;
                if (c > n * 0.8)
                {
                    safe++;

                    c = 0;
                    for (int l=i-n-n; l<i-n; l++) if (ImgArray[0]->at(l,j) == 0) c++;
                    if (c > n * 0.8) safe++;
                }


                if (safe < 2) ImgArray[0]->set(i,j,1);
            }
        }
    }
}

//Crop the image so only the internal gmara-rashi-tosfot square is left
void TzuraImage::cropEdges()
{
    int l = 0, r = 0;

    //Left
    for (int i=0; i<RES_X / 4; i++)
    {
        int c = 0;
        for (int j=0; j < RES_Y * 0.75; j++) if (ImgArray[0]->at(i,j) == 0 ) c++;

        if (c > (RES_Y * 0.75) * 0.9)
        {
            l = i;

            for (int n=0; n<=i; n++)
            {
                for (int m=0; m<RES_Y; m++) ImgArray[0]->set(n,m,3);
            }
        }
    }

    //Right
    for (int i=RES_X - 1; i>RES_X * 0.75; i--)
    {
        int c = 0;
        for (int j=0; j < RES_Y * 0.75; j++) if (ImgArray[0]->at(i,j) == 0 ) c++;

        if (c > (RES_Y * 0.75) * 0.9)
        {
            r = i + 1;

            for (int n=RES_X - 1; n>i; n--)
            {
                for (int m=0; m<RES_Y; m++) ImgArray[0]->set(n,m,3);
            }
        }
    }

    //Top
    for (int j=0; j<RES_Y / 7; j++)
    {
        int c = 0;
        for (int i=l; i<r; i++) if (ImgArray[0]->at(i,j) == 0) c++;

        if (c > (r-l) * 0.96)
        {
            for (int m=0; m<=j; m++)
            {
                for (int n=0; n<RES_X; n++)
                {
                    //Cheating...
                    if ( abs(RES_X /2 - n) < 20 && j - m < 4) ImgArray[0]->set(n,m,0);
                    else ImgArray[0]->set(n,m,3);
                }
            }
        }
    }

    //Bottom
    for (int j=RES_Y - 1; j>RES_Y * 0.75; j--)
    {
        int c = 0;
        for (int i=l; i<r; i++) if (ImgArray[0]->at(i,j) == 0) c++;

        if (c > (r-l) * 0.9)
        {
            for (int m=RES_Y - 1; m >= j; m--)
            {
                for (int n=0; n<RES_X; n++) ImgArray[0]->set(n,m,3);
            }
        }
    }
}


//Tries to remove the 'last word of block' that bothers the detection
void TzuraImage::lastWordInBlockFilter()
{
    //Go over all lines
    for (int l=0; l<RES_Y; l++)
    {
        QPoint a(-1, -1);
        QPoint b(-1, -1);

        //Remember how big the white patch is
        for (int k=0; k<RES_X; k++)
        {
            if (ImgArray[0]->at(k,l) == 1)
            {
                if (a.y() != -1)
                {
                    b.rx() ++;
                }
                else
                {
                    a = b = QPoint(k,l);
                }
            }
            else
            {
                //Last white patch was small
                if (a.y() != -1 && b.x() - a.x() + 1 < 20 && b.x() < RES_X - 30 && a.x() > 8)
                {

                    int c = 0;
                    for (int t=1; t<20; t++) if (ImgArray[0]->at(b.x() + t, l) == 0) c++;

                    //Make sure it has a lot of black ahead and behind it
                    if (c > 18)
                    {
                        c = 0;
                        for (int t=1; t<8; t++) if (ImgArray[0]->at(a.x() - t, l) != 1) c++;

                        //Remove the white patch
                        if (c > 6)
                        {
                            for (int t=a.x(); t<=b.x(); t++) ImgArray[0]->set(t,l,0);
                        }
                    }
                }

                a = b = QPoint(-1,-1);
            }
        }
    }
}

/*
void TzuraImage::SmallAreaFilter()
{
    //Copy the imagearray
    IAC.clear();
    for (int i=0; i<RES_X; i++) IAC << *(new QList <int> (ImageArray[i]));

    //qDebug() << RES_X << RES_Y;
    //qDebug() << IAC.size() << IAC[0].size();

    for (int i=2; i<RES_X-2; i++)
    {
        for (int j=2; j<RES_Y-2; j++)
        {
            QList <QPoint> bp;

            if (IAC[i][j] == 0)
            {
                bp = findNeighbors(bp, QPoint(i,j));
                if (bp.size() <= 30)
                {
                    for (int x=0; x<bp.size(); x++)
                    {
                        QPoint p;
                        p.rx() = bp[x].x();
                        p.ry() = bp[x].y();
                        if (p.x() > 2 && p.x() < RES_X - 2 && p.y() > 2 && p.y() < RES_Y - 2 )
                        {
                            ImageArray[p.x()][p.y()] = 1;
                        }
                    }
                    ImageArray[i][j] = 10;
                    //qDebug() << bp.size();
                    //qDebug() << i << j;
                }
            }
        }
    }

    qDebug() << RES_X << RES_Y;
}
*/


//Find squares in the image with this cool new method
// (By given seed size)
void TzuraImage::findSquares(float MIN_SATURATION, int seedSize)
{
    squareList.clear();

    //Copy the imagearray to layer 2
    ImgArray[1] = ImgArray[0]->copy();

    //Go over the whole array
    for (int i=1; i<RES_X-seedSize - 1; i++)
    {
        for (int j=1; j<RES_Y-seedSize - 1; j++)
        {
            //TODO: Maybe make this a 90% test and not 100% ?

            //Make sure we have a black block
            bool isWhite = true;
            for (int s=0; s<seedSize; s++) for (int g=0; g<seedSize; g++) if (ImgArray[1]->at(i+s,j+g) != 1) isWhite = false;
/*
 //And start in a corner only

            int c = 0;
            for (int v=-1; v < seedSize + 1; v++) for (int x=-1; x<seedSize + 1; x++) if (ImgArray[0]->at(v + i,x + j) == 0) c++;
            //More than one axis has to have black points
            if ( c < seedSize * 1.2) isWhite = false;
*/

            if (isWhite)
            {
                expandingSquare square;
                square.Expand(QPoint(i,j),seedSize, MIN_SATURATION, ImgArray[1]);

                //Minimal h,w, and area
                if (square.width() > 2 && square.height() > 2 && square.width() * square.height() > 50)
                {
                    squareList << square;
                }
            }
        }
    }
}


//
int clr = 0;

void TzuraImage::joinSquares()
{
    ImgArray[2]->clear();

    clr = 0;

    for (int i=0; i<squareList.size(); i++)
    {
        if (ImgArray[1]->at(squareList[i].seed.x(),squareList[i].seed.y()) == 10)
        {
            int color = clr++;

            //Paint him
            expandingSquare square = squareList[i];
            for (int s=square.left(); s<=square.right(); s++) for (int g=square.top(); g<=square.bottom(); g++) ImgArray[2]->set(s,g,color);
            //Mark square as used
            for (int s=square.left(); s<=square.right(); s++) for (int g=square.top(); g<=square.bottom(); g++) ImgArray[1]->set(s,g,20);
            //Make him paint all his children
            colorNeighbors(i, color);
        }
    }
}

void TzuraImage::colorNeighbors(int listIndex, int color)
{
    for (int i=0; i<squareList.size(); i++)
    {
        if (i != listIndex && ImgArray[1]->at(squareList[i].seed.x(),squareList[i].seed.y()) == 10)
        {
            if (squareList[listIndex].touches(squareList[i]))
            {
                //Paint him
                expandingSquare square = squareList[i];
                for (int s=square.left(); s<=square.right(); s++) for (int g=square.top(); g<=square.bottom(); g++) ImgArray[2]->set(s,g,color);
                //Mark square as used
                for (int s=square.left(); s<=square.right(); s++) for (int g=square.top(); g<=square.bottom(); g++) ImgArray[1]->set(s,g,20);

                colorNeighbors(i, color);
            }
        }
    }
}


void TzuraImage::makeNewBlocks()
{
    rectList.clear();

    //Go over all colors
    for (int color=0; color<clr; color++)
    {
        int lastw = -1;
        QRect lastrec(QPoint(-1, -1), QPoint(-1, -1));

        //Go over every line
        for (int l=0; l<RES_Y; l++)
        {
            int a = 0, b = 0;

            //Find first occurence
            for (int i=0; i<RES_X; i++)
            {
                if (ImgArray[2]->at(i,l) == color) { a = i; break; }
            }
            //Find last occurence
            for (int i=RES_X - 2; i>0; i--)
            {
                if (ImgArray[2]->at(i,l) == color) { b = i; break; }
            }

            int w = b-a;
            if (abs(w - lastw) > 2) // Realy different widths
            {
                if (lastrec.top() != -1)
                {
                    //Add to list
                    rectList << lastrec;
                }

                //Make a new one
                lastrec.setTopLeft(QPoint(a,l));
                lastrec.setBottomRight(QPoint(b,l));
            }
            else
            {
                //Add this line to the rectangle
                lastrec.setBottom(lastrec.bottom() + 1);
            }

            lastw = b - a + 1;
        }
        //Add last one to list
        if (lastrec.top() != -1 && lastrec.width() > 3 && lastrec.height() > 1)
        {
            //Add to list
            rectList << lastrec;
        }
    }


    //Mark on layer 3:
    for (int i=0; i<rectList.size(); i++)
    {
        QRect r = rectList[i];

        int s = r.top(); for (int g = r.left(); g<=r.right(); g++) ImgArray[2]->set(g,s,15);
        s = r.bottom(); for (int g = r.left(); g<=r.right(); g++) ImgArray[2]->set(g,s,15);
        int g = r.left(); if (g<0) g=0;
        for (int s=r.top(); s<=r.bottom(); s++) ImgArray[2]->set(g,s,15);
        g = r.right(); if (g + 1> RES_X - 1) g=RES_X - 1; if (g<0) g=0;
        for (int s=r.top(); s<=r.bottom(); s++) ImgArray[2]->set(g,s,15);
    }
}


//Paint the blocks so they look cool
QImage TzuraImage::render(int layer, bool grid)
{
    int paintBlockSizeX = getPaintBlockSize().width();
    int paintBlockSizeY = getPaintBlockSize().height();


    int w = RES_X * paintBlockSizeX;
    QImage newImage(w, RES_Y * paintBlockSizeY, QImage::Format_ARGB32);

    QPainter painter(&newImage);

    //Draw blocks
    for (int i=0; i<RES_X; i++)
    {
        for (int j=0; j<RES_Y; j++)
        {
            QColor color;

            if (layer == 0)
            {
                if (ImgArray[0]->at(i,j) == 0) color.setNamedColor("Black");

                if (ImgArray[0]->at(i,j) == 1) color.setNamedColor("White");

                //Draw with slight transparacy
                color.setAlpha(130);

                painter.fillRect(QRect(QPoint(i*paintBlockSizeX, j*paintBlockSizeY), QPoint((i+1)*paintBlockSizeX, (j+1)*paintBlockSizeY)), color);
            }

            if (layer == 2) //Blocks' layer
            {
                if (ImgArray[2]->at(i,j) == -1)
                {
                    //if (ImgArray[0]->at(i,j) == 0) color.setNamedColor("Black");
                    //if (ImgArray[0]->at(i,j) == 1) color.setNamedColor("White");
                }
                else
                {
                    if (ImgArray[2]->at(i,j) == 0) color.setNamedColor("Green");
                    if (ImgArray[2]->at(i,j) == 1) color.setNamedColor("Blue");
                    if (ImgArray[2]->at(i,j) == 2) color.setNamedColor("Red");
                    if (ImgArray[2]->at(i,j) == 3) color.setNamedColor("Pink");
                    if (ImgArray[2]->at(i,j) == 4) color.setNamedColor("Violet");
                    if (ImgArray[2]->at(i,j) == 5) color.setNamedColor("Grey");
                    if (ImgArray[2]->at(i,j) == 6) color.setNamedColor("Brown");
                    if (ImgArray[2]->at(i,j) == 7) color.setNamedColor("Orange");
                    if (ImgArray[2]->at(i,j) == 8) color.setNamedColor("Magenta");
                    if (ImgArray[2]->at(i,j) == 9) color.setNamedColor("Cyan");

                    if (ImgArray[2]->at(i,j) == 15) color.setNamedColor("Yellow");

                    //Draw with transparacy
                    color.setAlpha(50);

                    painter.fillRect(QRect(QPoint(i*paintBlockSizeX, j*paintBlockSizeY), QPoint((i+1)*paintBlockSizeX, (j+1)*paintBlockSizeY)), color);
                }
            }


        }
    }

    /*
    if (grid == true)
    {
        //Draw grid
        for (int i=0; i<RES_X; i++)
        {
            for (int j=0; j<RES_Y; j++)
            {
                QPen e;

                e.setWidth(4);
                e.setColor(QColor("Red"));
                painter.setPen(e);

                painter.drawRect(QRect (QPoint(i*paintBlockSizeX, j*paintBlockSizeY), QPoint((i+1)*paintBlockSizeX, (j+1)*paintBlockSizeY)));

            }
        }
    }
    */

    return newImage;
}

QImage * TzuraImage::getIM()
{
    QImage *ni = new QImage(im.scaledToHeight(1500));
    return ni;
}

QSize TzuraImage::getPaintBlockSize()
{
    return QSize(BLOCK_SIZE_X / 9, BLOCK_SIZE_Y / 9);
}

void TzuraImage::setArrayPoint(int x, int y, int val)
{
    ImgArray[0]->set(x,y,val);
}

#include <QXmlStreamWriter>
QString TzuraImage::blockOutput()
{
    QString output;
    QXmlStreamWriter stream(&output);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();

    stream.writeStartElement("PageLayout");

    for (int c=0; c<clr; c++)
    {
        stream.writeStartElement("BlockSet");
        stream.writeAttribute("ColorCode", QString::number(c));
        for (int i=0; i<rectList.size(); i++)
        {
            if (ImgArray[2]->at(rectList[i].topLeft().x() + 1, rectList[i].topLeft().y() + 1) == c)
            {
                QString t = QString::number(rectList[i].topLeft().x()) + "," + QString::number(rectList[i].topLeft().y());
                t += " - " + QString::number(rectList[i].bottomRight().x()) + "," + QString::number(rectList[i].bottomRight().y());
                stream.writeTextElement("Block", t);
            }
        }
        stream.writeEndElement(); // Set
    }

    stream.writeEndElement(); // Blocks

    return output;
}

void TzuraImage::drawSavedRects(QString filename)
{
    QXmlStreamReader xml;
    QFile f(filename);
    if (!f.open(QFile::ReadOnly | QFile::Text))
    {
        qCritical() << "Invalid layout file!";
        return;
    }

    int color = -1;

    xml.setDevice(&f);

    xml.readNextStartElement();


    if (xml.name() == "PageLayout")
    {
        xml.readNextStartElement();

        //for (int a=0; a<xml.attributes().size(); a++ ) qDebug() << xml.attributes().toStdVector().at(a);
        while(xml.name() == "BlockSet")
        {
            if (xml.attributes().size() > 0)
            {
                if (xml.attributes()[0].name() == "ColorCode")
                {
                    color = xml.attributes()[0].value().toString().toInt();
                }
            }

            xml.readNextStartElement();
            while(xml.name() == "Block")
            {
                //Generate rectangle:
                QString t = xml.readElementText();

                QStringList tt = t.split(" - ");
                if (tt.size() > 1)
                {
                    QPoint p1(tt[0].split(",")[0].toInt(), tt[0].split(",")[1].toInt());
                    QPoint p2(tt[1].split(",")[0].toInt(), tt[1].split(",")[1].toInt());

                    //Mark colors on layer 3:
                    for (int a=p1.x(); a<p2.x(); a++) for (int b=p1.y(); b<p2.y(); b++) ImgArray[2]->set(a,b,color);

                    //Add to rect list
                    rectList << QRect(p1,p2);
                }

                xml.readNextStartElement();
            }
        }
    }
    if (xml.hasError())
    {
        qCritical() << "Invalid layout file!";
    }

    //Mark rects on layer 3:
    for (int i=0; i<rectList.size(); i++)
    {
        QRect r = rectList[i];

        int s = r.top(); for (int g = r.left(); g<=r.right(); g++) ImgArray[2]->set(g,s,15);
        s = r.bottom(); for (int g = r.left(); g<=r.right(); g++) ImgArray[2]->set(g,s,15);
        int g = r.left(); if (g<0) g=0;
        for (int s=r.top(); s<=r.bottom(); s++) ImgArray[2]->set(g,s,15);
        g = r.right(); if (g + 1> RES_X - 1) g=RES_X - 1; if (g<0) g=0;
        for (int s=r.top(); s<=r.bottom(); s++) ImgArray[2]->set(g,s,15);
    }


    f.close();
}
