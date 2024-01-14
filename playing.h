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
#include <QTime>
#include "won.h"

#define ROWS 6
#define COLS 6

class cursor;
class Gameover;
class Playing
{
    //    Q_OBJECT
public:
    Playing();
    void setToBack();
    QPixmap render(int i);
    void setCards();
    void writeimgdata();
    void showPix();
    void hidePic(int x, int y);
    void readimgdata();
    int rowfirst;
    int colfirst;
    int openings=0;
    QGraphicsTextItem* openingsText;
    void showall();
    void hideall();
    int score = 0;
    void firstflip(int r,int c);
    void secondflip(int r,int c);

    QGraphicsTextItem* scoreText;
    //game logic implemented
    void shuffle(int arr[6][6]);
   // Image* lastFlippedImages[2] = {nullptr, nullptr};
    bool ismatched();

    bool isFirstClick;
    bool isSecondClick;
    void Wono();
    void gameOver();
    //    ~Playing();
    QGraphicsView* view;
    QGraphicsScene* scene;
    void flip(int x, int y);

    void delay(int s);
    bool ishidden=true;
    bool gethide();
    void sethide(bool ishidden);
private:
    int imagesdata[6][6];
 //   Image images[ROWS][COLS];
    QGraphicsPixmapItem*imagesback[6][6];
    QGraphicsPixmapItem* images1[ROWS][COLS];
  //   QList<Image*> flippedCards;
    QGraphicsPixmapItem cards[ROWS][COLS];

    cursor *cursor1;
    Gameover* gover;
};

#endif // PLAYING_H
