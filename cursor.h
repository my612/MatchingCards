#ifndef CURSOR_H
#define CURSOR_H
#include "playing.h"
#include <QObject>
#include <QGraphicsObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>


class cursor: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    cursor(Playing*  playinview);

public slots:
  void keyPressEvent(QKeyEvent* event);

private:
    int rowindex;
    int colindex;
    Playing* playwindow;
};

#endif // CURSOR_H
