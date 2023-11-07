#ifndef PLAYING_H
#define PLAYING_H
#include "image.h"
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#define ROWS 6
#define COLS 6
class Playing
{
    //    Q_OBJECT
public:
    Playing();
    void flip(int x, int y);
    //    void writeData();
    //    void getData();
    void setToBack();
    QPixmap render(int i);
    void setCards();
    void showPix();
    //    ~Playing();
private:
    Image images[ROWS][COLS];
    QGraphicsPixmapItem cards[ROWS][COLS];
    QGraphicsView* view;
    QGraphicsScene* scene;
};

#endif // PLAYING_H