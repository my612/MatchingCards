#include "image.h"

Image::Image(QObject *parent, int front)
    : QObject{parent}
{
    flipped = false;
    back = 0;
    this->front = front;
}
void Image::setFront(int i)
{
    front = i;
}
void Image::flip()
{
    if(flipped)
        flipped = false;
    else
        flipped = true;
}
int Image::getCurrent()
{
    if(flipped)
        return front;
    else
        return back;
}
void Image::setFlipped(bool f)
{
    flipped = f;
}
bool Image::getFlipped()
{
    return flipped;
}

