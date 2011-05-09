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


//Holds a matrix of values representing the current state of the image
// It goes by (x,y)!
// (Default value is -1 which means empty)


// Value map:
// 0 - Empty (or black)
// 1 - Full (or white)

#define BLACK 0
#define WHITE 1

#ifndef IMAGEARRAY_H
#define IMAGEARRAY_H

#include <QObject>
#include <QList>

class ImageArray : public QObject
{
    Q_OBJECT
public:
    //Inits the array with the given size
    ImageArray(int n, int m);
    ~ImageArray();

    int at(int x, int y);
    void set(int x, int y, int val);

    int width();
    int height();

    //Returns a copy of this
    ImageArray * copy();

    void clear();

private:
    //Holds the values of each point.
    QList < QList <int> > imArray;

};

#endif // IMAGEARRAY_H
