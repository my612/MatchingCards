#include "cursor.h"
#include<QKeyEvent>


cursor::cursor(Playing*  playinview)
{
    rowindex=0;
    colindex=-1;

    QPixmap thing("M:\\MatchingCards\\MatchingCards\\img0.png");
    thing = thing.scaledToHeight(40);
    thing = thing.scaledToWidth(80);
    setPixmap(thing);
    playwindow = playinview;


}
void cursor::keyPressEvent(QKeyEvent* event){

    if(event->key() == Qt::Key_Left){
        if(colindex >-1)
        {
            colindex--;
            setPos(x()-70,y());
        }
    }else if(event->key()==Qt::Key_Right){
        if(colindex<COLS-1)
        {
            colindex++;
            setPos(x()+70,y());
        }
    }
    if(event->key()==Qt::Key_Up){
        if(rowindex>0 && colindex > -1)
        {
            rowindex--;
            setPos(x(),y()-100);
        }
    }else if(event->key()==Qt::Key_Down){
        if(rowindex<ROWS-1 && colindex > -1 )
        {
            rowindex++;
            setPos(x(),y()+100);
        }
    }
   else if(event->key()==Qt::Key_Space){
        playwindow->flip(rowindex,colindex);
        playwindow->setCards();
        playwindow->showPix();
        //playwindow->hidePic(colindex,rowindex);
    }




}





