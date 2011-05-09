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

/*
 A class holding the rough (sampled) representation of an image,
 which it anylizes to get Tzurat Hadaf.
 */

#ifndef TZURAIMAGE_H
#define TZURAIMAGE_H

#include <QObject>
#include <QImage>
#include <QDebug>
#include <QRect>

#include "expandingsquare.h"
#include "imagearray.h"

class expandingSquare;

class TzuraImage : public QObject
{
    Q_OBJECT

public:
    //Build the tzura image from the given image file
    TzuraImage(QString imagePath);
    ~TzuraImage();

    //Process the image the whole way through
    void process(bool firsrtTime = true);


    void setSquareBorderSensitivity(float);

    //Returns a QImage of the way this TzuraImage looks
    QImage render(int layer = 0, bool grid = false);

    //Returns the originall image
    QImage * getIM();

    QSize getPaintBlockSize();


    void setArrayPoint(int x, int y, int val);


    //Output the shape of the detected blocks
    QString blockOutput();

private:
    //Each 'layer' (a seperate ImageArray), holds the values of each point.
    // (Some layers may not have all the values. They depend on the previous ones)
    // Layers are:
    // 0 - Basic array (filtered)
    // 1 - Includes expanded squares. (10 -> not merged yet, 20 -> merged square)
    // 2 - Merged layer. Includes colored squares, and borders of detected rectangles.
    //  (-1 -> empty (black), 0-10 -> colors, 15 -> border of rectangle
    QList <ImageArray *> ImgArray;

    //Path and QImage of the originall image
    QString imagePath;
    QImage im;

    //Build the block array from the image
    void buildBlockArray(int RES_X, int BLOCK_SIZE_X, int RES_Y, int BLOCK_SIZE_Y, int SATURATION_LEVEL);

    //Image filters:
    //Simple filter to remove too thin lines on the Y axis
    void SingleLineYFilter();

    void DoubleLineYFilter();

    //Simple filter to remove too thin lines on the X axis
    void SingleLineXFilter();
    void DoubleLineXFilter();

    //Inverts points (of both values) that do not have enough strait neighbors of the same color
    // (By the given size)
    void strongFilter(int s);

    //Tries to remove the 'last word of block' that bothers the detection
    void lastWordInBlockFilter();

    //Find squares in the image with this cool new method
    // (By given seed size)
    void findSquares(float sat, int seedSize);

    //Holds the list of the detected 'squares'
    QList <expandingSquare> squareList;
    QList <QRect> rectList;


    //
    //Joins all touching (or almost touching) squares
    void joinSquares();

    void colorNeighbors(int listIndex, int color);

    void makeNewBlocks();


    //
    void drawSavedRects(QString filename);

    //Apply the squares to the Image array
    //void addSquares();

    float XY_RATIO;
    int RES_X;
    int RES_Y;
    int BLOCK_SIZE_X;
    int BLOCK_SIZE_Y;
    float SATURATION_PERCENT;
    int SATURATION_LEVEL;

    float squareBorderSensitivity;

    //NOT GOOD
    // Removes all small black areas
    //void SmallAreaFilter();

signals:
    //Update the mainwindow about our progress
    void message(QString);

};

#endif // TZURAIMAGE_H

