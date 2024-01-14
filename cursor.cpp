#include "cursor.h"
#include<QKeyEvent>
#include<QGraphicsItem>
#include<QGraphicsWidget>


cursor::cursor(Playing*  playinview)
{
    rowindex=0;
    colindex=-1;
    QPixmap thing(":/images/img0.png");
    thing = thing.scaledToHeight(40);
    thing = thing.scaledToWidth(30);
    setPixmap(thing);
    playwindow = playinview;

     isFirstClick=true;
    isSecondClick=false;
//"B:\Fall 23\CS2 credit lab\QT assignment\MatchingCards\img0.png" file path for me
}
void cursor::keyPressEvent(QKeyEvent* event){
    this->setOpacity(100);

    if(event->key() == Qt::Key_Left){
        if(colindex > -1)
        {
            colindex--;
            setPos(x()-100,y());
        }
    }else if(event->key()==Qt::Key_Right){
        if(colindex<COLS-1)
        {
            colindex++;
            setPos(x()+100,y());
        }
    }
    if(event->key()==Qt::Key_Up){
        if(rowindex>0 && colindex > -1)
        {
            rowindex--;
            setPos(x(),y()-110);
        }
    }else if(event->key()==Qt::Key_Down){
        if(rowindex<ROWS-1 && colindex > -1 )
        {
            rowindex++;
            setPos(x(),y()+110);
        }
    }
   else if(event->key()==Qt::Key_Space){

        if (isFirstClick) {
            // Call the firstflip function
            // Replace x, y with the appropriate values
            playwindow->firstflip(rowindex, colindex);
            isFirstClick = false;
            isSecondClick = true;
        //    cursor1->setOpacity(100);
        } else if (isSecondClick) {
            // Call the secondflip function
            // Replace r, c with the appropriate values
            playwindow-> secondflip(rowindex, colindex);
            isFirstClick = true;
            isSecondClick = false;

        }
    } else if(event->key() == Qt::Key_S) {

        // Call the function you want to handle
        // Replace this with the actual function you want to call
        if(playwindow->gethide()){

            playwindow->showall();
        }else{

            playwindow->hideall();
        }


    }



}





