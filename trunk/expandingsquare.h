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

 A slightly modified QRect.
 Holds information and methods of expanding sqaures for the 'expanding-sqaures' block detection method.

 */



#ifndef EXPANDINGSQUARE_H
#define EXPANDINGSQUARE_H

#include <QPoint>
#include <QRect>

#include "tzuraimage.h"

class TzuraImage;
class ImageArray;

class expandingSquare : public QRect
{
    public:

        //Expand from the given point with the given seed size and saturation level, on the given TzuraImage
        void Expand(QPoint p, int sSize, float MIN_SATURATION, ImageArray *IA);

        //Returns true if this square touches (or nearly does), the given square
        bool touches(expandingSquare other, int fuzziness = 1);


        //Where the square started from, and what minimal size did that start point have
        QPoint seed;
        int seedSize;
};

#endif // EXPANDINGSQUARE_H
