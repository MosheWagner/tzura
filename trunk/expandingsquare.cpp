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

#include "expandingsquare.h"

// TODO: Paint square function

//Expand from the given point with the given seed size and saturation level, on the given TzuraImage
void expandingSquare::Expand(QPoint p, int sSize, float MIN_SATURATION, ImageArray *IA)
{
    seedSize = sSize;
    seed = p;

    int RES_X = IA->width();
    int RES_Y = IA->height();

    //Start the square
    setTopLeft(p);
    setBottomRight(QPoint(p.x() + seedSize, p.y() + seedSize));

    //Invalid
    if (right() > RES_X - 1|| bottom() > RES_Y - 1 || left() < 1 || top() < 1)
    {
        //Quit here
        setTopLeft(QPoint(0,0));
        setBottomRight(QPoint(0,0));

        return;
    }

    //Remember originall width and height
    int lastw = 0; int lasth = 0;

    //Quit if the square didn't change from last time
    while (lastw != width() || lasth != height())
    {
        lastw = width(); lasth = height();

        //Do this for - up, left, down, right
        for (int d=0; d<4; d++)
        {
            int dir = d;

            QPoint np1; QPoint np2;

            if (dir == 0) //Up:
            {
                np1.ry() = y() - 1; np2.ry() = y() - 1;
                np1.rx() = left(); np2.rx() = right();
            }

            else if (dir == 1) //Right:
            {
                np1.ry() = top(); np2.ry() = bottom();
                np1.rx() = right() + 1; np2.rx() = right() + 1;
            }

            else if (dir == 2) //Down:
            {
                np1.ry() = bottom() + 1; np2.ry() = bottom() + 1;
                np1.rx() = left(); np2.rx() = right();
            }
            else //Left:
            {
                np1.ry() = top(); np2.ry() = bottom();
                np1.rx() = left() - 1; np2.rx() = left() - 1;
            }

            if (np1.x() < 2 || np1.x() > RES_X - 1 || np1.y() < 2 || np1.y() > RES_Y - 1)
                break;
            if (np2.x() < 2 || np2.x() > RES_X - 1 || np2.y() < 2 || np2.y() > RES_Y - 1)
                break;

            //See if this should be added
            int cnt = 0;

            for (int k=np1.x(); k<=np2.x(); k++) if (IA->at(k,np1.y()) == 1) cnt++;
            for (int k=np1.y(); k<=np2.y(); k++) if (IA->at(np1.x(),k) == 1) cnt++;

            //Add to square
            bool ok = false;
            if (dir == 0  && cnt > width() * MIN_SATURATION ) ok = true;
            if (dir == 2  && cnt > width() * (MIN_SATURATION) ) ok = true;
            if (dir == 1 || dir == 3)
            {
                if (cnt > height() * MIN_SATURATION ) ok = true;
            }

            if (ok)
            {
                //Up:
                if (dir==0)
                {
                    setTop(top() - 1);
                }
                //Right:
                else if (dir==1)
                {
                    setRight(right() + 1);
                }
                //Down:
                else if (dir==2)
                {
                    setBottom(bottom() + 1);
                }
                //Left:
                else if (dir==3)
                {
                    setLeft(left() - 1);
                }

                for (int k=np1.x(); k<=np2.x(); k++) { IA->set(k, np1.y(), 10); }
                for (int k=np1.y(); k<=np2.y(); k++) { IA->set(np1.x(), k, 10); }
            }
        }
    }
}

//Returns true if this square touches (or nearly does), the given square
bool expandingSquare::touches(expandingSquare other, int fuzz)
{
    QRect ra((QRect)*this);
    ra.adjust(fuzz * -1, fuzz * -1, fuzz, fuzz);

    QRect rb((QRect)other);
    rb.adjust(fuzz * -1, fuzz * -1, fuzz, fuzz);

    return ra.intersects(rb);
}


