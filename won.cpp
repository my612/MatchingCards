#include "won.h"
#include "ui_won.h"

Won::Won(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Won)
{
    ui->setupUi(this);
    ui->wonend->show();
}

Won::~Won()
{
    delete ui;
}
