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

#include <QtGui/QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    //Show gui
    QApplication a(argc, argv);

    /*
    QStringList args = a.arguments();

    //For demo:
    args << "TestImages/a29.png";

    if (args.size() < 2)
    {
        qCritical() << "No image specified. Quiting.";
        exit(1); //No filename given
    }
    */

    MainWindow w(NULL);
    w.show();
    return a.exec();
}
