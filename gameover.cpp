#include "gameover.h"
#include "ui_gameover.h"
#include "playing.h"

Gameover::Gameover(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gameover)
{
    ui->setupUi(this);
    ui->gameend->show();
}

Gameover::~Gameover()
{
    delete ui;
}
