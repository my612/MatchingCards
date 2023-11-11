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
#include <QGraphicsView>


#define ROWS 6
#define COLS 6

class cursor;
class Gameover;
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

    int openings=0;
    QGraphicsTextItem* openingsText;

    int score = 0;

    QGraphicsTextItem* scoreText;
    //game logic implemented

    Image* lastFlippedImages[2] = {nullptr, nullptr};
    bool ismatched();

    void gameOver();
    //    ~Playing();

private:
    int imagesdata[ROWS][COLS];
    Image images[ROWS][COLS];
    QGraphicsPixmapItem cards[ROWS][COLS];
    QGraphicsView* view;
    QGraphicsScene* scene;
    cursor *cursor1;
    Gameover* gover;
};

#endif // PLAYING_H
