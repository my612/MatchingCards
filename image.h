#ifndef IMAGE_H
#define IMAGE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QGraphicsPixmapItem>
using namespace std;
class Image : public QObject
{
    Q_OBJECT
    bool flipped;
    int back;
    int front;
public:
    explicit Image(QObject *parent = nullptr, int front = 0);
    void flip();
    bool getFlipped();
    void setFront(int i);
    void setFlipped(bool f);
    int getCurrent();
signals:

};

#endif // IMAGE_H

