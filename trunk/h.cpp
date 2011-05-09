#include "h.h"
#include "ui_h.h"

h::h(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::h)
{
    ui->setupUi(this);
}

h::~h()
{
    delete ui;
}

void h::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
