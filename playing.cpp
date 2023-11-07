#include "playing.h"

Playing::Playing()
{
    setToBack();
    scene = new QGraphicsScene();
    setCards();
    showPix();
    view = new QGraphicsView();
    scene->setSceneRect(-100, 0 , 800, 800);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800, 800);
    view->setScene(scene);
    view->show();
}
void Playing::setToBack()
{
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            images[i][j].setFlipped(false);
}
void Playing::flip(int x, int y)
{
    images[x][y].flip();
}
QPixmap Playing::render(int i)
{//"img" + QString::number(i) + ".png"
    return QPixmap("DISTFILES\\img" + QString::number(i) + ".png");
}
void Playing :: setCards()
{
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
        {
            QPixmap card(render(images[i][j].getCurrent()));
            card = card.scaledToHeight(100);
            card = card.scaledToWidth(60);
            cards[i][j].setPixmap(card);
        }
}
void Playing::showPix()
{
    for(int i = 0; i < ROWS;i++)
        for(int j = 0;j < COLS; j++)
        {
            cards[i][j].setPos(100 + (70*i), 50 + (110* j));
            scene->addItem(&cards[i][j]);
        }
}
