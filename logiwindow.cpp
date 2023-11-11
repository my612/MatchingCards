#include "logiwindow.h"
#include "ui_logiwindow.h"

Logiwindow::Logiwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Logiwindow)
{
    ui->setupUi(this);
}

Logiwindow::~Logiwindow()
{
    delete ui;
}
