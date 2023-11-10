#ifndef PLAYING_H
#define PLAYING_H
#include "image.h"
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QFile>
#include <QTextStream>
#define ROWS 6
#define COLS 6

class cursor;
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
    void writeimgdata();
    void showPix();
    void hidePic(int x, int y);
    void readimgdata();
    //    ~Playing();

private:
    int imagesdata[ROWS][COLS];
    Image images[ROWS][COLS];
    QGraphicsPixmapItem cards[ROWS][COLS];
    QGraphicsView* view;
    QGraphicsScene* scene;
    cursor *cursor1;
};

#endif // PLAYING_H
