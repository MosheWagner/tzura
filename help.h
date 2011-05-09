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


#ifndef HELP_H
#define HELP_H

#include <QDialog>

namespace Ui {
    class help;
}

class help : public QDialog
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = 0);
    ~help();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::help *ui;
};

#endif // HELP_H
