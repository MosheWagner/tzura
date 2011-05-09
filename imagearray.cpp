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


#include "imagearray.h"
#include <QDebug>

//Inits the array with the given size
ImageArray::ImageArray(int n, int m)
{
    for (int i=0; i<n; i++)
    {
        QList <int> vline;
        for (int j=0; j<m; j++) vline << -1;

        imArray << vline;
    }
}

ImageArray::~ImageArray()
{
    for (int i=0; i<imArray.size(); i++) imArray[i].clear();
    imArray.clear();
}

int ImageArray::at(int x, int y)
{
    if (x >= 0 && x < imArray.size() && y >= 0 && y < imArray[0].size())
    {
        return imArray[x][y];
    }
    else
    {
        qCritical() << "Invalid access to ImageArray at: " << x << ", " << y;
    }
}

void ImageArray::set(int x, int y, int val)
{
    if (x >= 0 && x < imArray.size() && y >= 0 && y < imArray[0].size())
    {
        imArray[x][y] = val;
    }
    else
    {
        qCritical() << "Invalid set of ImageArray at: " << x << ", " << y;
    }
}

int ImageArray::width() { return imArray.size(); }

int ImageArray::height() { return imArray[0].size(); }

ImageArray * ImageArray::copy()
{
    ImageArray *IA = new ImageArray(width(),height());

    for (int i=0; i<width(); i++) for(int j=0; j<height(); j++) IA->set(i,j, imArray[i][j]);

    return IA;
}

void ImageArray::clear()
{
    for (int i=0; i<width(); i++) for(int j=0; j<height(); j++) imArray[i][j] = -1;
}
