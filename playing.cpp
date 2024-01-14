#include "playing.h"
#include"cursor.h"
#include "gameover.h"
#include<algorithm>
#include <iostream>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>

Playing::Playing()
{


    scene = new QGraphicsScene();
    setCards();
    showPix();
    view = new QGraphicsView();
    scene->setSceneRect(0, 0 , 850, 800);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(850, 800);
    cursor1 = new cursor(this);
    cursor1->setPos(70,115);
    scene->addItem(cursor1);

    cursor1->setFlag(QGraphicsItem::ItemIsFocusable);
    cursor1->setFocus();


  //add the openings counter
    openings=0;
    openingsText = new QGraphicsTextItem();
    openingsText->setDefaultTextColor(Qt::red);
    openingsText->setPos(10,10);
    openingsText->setFont(QFont("times",16));
    openingsText->setPlainText("Openings: " + QString::number(openings));
    scene->addItem(openingsText);

    //add the score counter

    scoreText = new QGraphicsTextItem();
    scoreText->setDefaultTextColor(Qt::blue);
    scoreText->setPos(400,10);
    scoreText->setFont(QFont("times",16));
    scoreText->setPlainText("Score: " + QString::number(openings));
    scene->addItem(scoreText);

    view->setScene(scene);
    view->show();

}

//the game over item
void Playing::gameOver() {
    view->hide();
    gover = new Gameover;
    gover->show();

}
void Playing::Wono() {
    view->hide();
    Won* wonover = new Won();
    wonover->show();

}

void Playing::firstflip(int x, int y){
    if(images1[x][y]==0){
        return;
    }
    imagesback[x][y]->hide();
    images1[x][y]->show();
    rowfirst=x;
    colfirst=y;
    cursor1->setOpacity(0);
    if(openings >40){
            gameOver();
     }else{
        if(y!=-1) { openings++;}
        }
     openingsText->setPlainText("Openings: " + QString::number(openings));

}
void Playing::delay(int s){
        QTime t= QTime::currentTime().addSecs(s);
        while (QTime::currentTime() < t)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Playing::secondflip(int r,int c){
        cursor1->setOpacity(0);
        if(images1[r][c]==0){
            return;
        }

        if(r == rowfirst && c == colfirst){
            imagesback[r][c]->show();
            images1[r][c]->hide();
            return;
        }else{
            imagesback[r][c]->hide();
            images1[r][c]->show();
            if(openings >40){
                gameOver();
            }else{
                if(c!=-1) { openings++;}
            }
            openingsText->setPlainText("Openings: " + QString::number(openings));
            delay(1);

        }

        if(imagesdata[r][c] == imagesdata[rowfirst][colfirst] && images1[r][c]!=0){
        qDebug()<<"MAtched";
        scene->removeItem(images1[r][c]);
        scene->removeItem(images1[rowfirst][colfirst]);
        scene->removeItem(imagesback[r][c]);
        scene->removeItem(imagesback[rowfirst][colfirst]);
        images1[r][c]=0;
        images1[rowfirst][colfirst] = 0;
        score+=1;
        scoreText->setPlainText("Score: " + QString::number(score));

        }else if(images1[r][c]!=images1[rowfirst][colfirst]){
        imagesback[r][c]->show();
        images1[r][c]->hide();
        images1[r][c] = nullptr;
        imagesback[rowfirst][colfirst]->show();
        images1[rowfirst][colfirst]->hide();
        images1[rowfirst][colfirst] = nullptr;
        return;
        }else{
        return;
        }
        bool lose = false;
        for(int i = 0; i < 6; i++)
            for(int j = 0; j < 6;j++)
                if(images1[i][j] != nullptr)
                    lose = true;
        if(!lose)
        {
            Wono();
        }
}

QPixmap Playing::render(int i)
{
    return QPixmap(":/images/img" + QString::number(i) + ".png");

}


bool Playing::gethide(){
    return ishidden;
}
void Playing::sethide(bool ishidden){
    this->ishidden=ishidden;
}
void Playing::shuffle(int arr[6][6]) {
    srand(time(0));

    for (int i = 5; i > 0; i--) {
        for (int j = 5; j > 0; j--) {
            int ri = rand() % (i + 1);
            int rj = rand() % (j + 1);


            int temp = arr[i][j];
            arr[i][j] = arr[ri][rj];
           arr[ri][rj] = temp;
        }
    }
}

void Playing::showall() {
    qDebug() << "showall function called";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if(images1[i][j]!=0){
                images1[i][j]->show();
                imagesback[i][j]->hide();
            }
        }
    }
    ishidden=false;
}


void Playing::hideall() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (images1[i][j] != nullptr) {
                images1[i][j]->hide();
            }
            if (imagesback[i][j] != nullptr) {
                imagesback[i][j]->show();
            }
        }
    }
    ishidden=true;
}

void Playing :: setCards()
{

            QPixmap card1(":/images/img1.png");
            card1 = card1.scaledToHeight(100);
            card1 = card1.scaledToWidth(60);


            QPixmap card2(":/images/img2.png");
            card2 = card2.scaledToHeight(100);
            card2 = card2.scaledToWidth(60);


            QPixmap card3(":/images/img3.png");
            card3 = card3.scaledToHeight(100);
            card3 = card3.scaledToWidth(60);


            QPixmap card4(":/images/img4.png");
            card4 = card4.scaledToHeight(100);
            card4 = card4.scaledToWidth(60);

            QPixmap card5(":/images/img5.png");
            card5 = card5.scaledToHeight(100);
            card5 = card5.scaledToWidth(60);

            QPixmap back(":/images/back.jpg");

            back = back.scaledToHeight(100);
            back = back.scaledToWidth(60);
            int count = 1;

    for(int i= 0;i<6;i++){
        for(int j =0;j<6;j++){
            imagesdata[i][j]= count;
        }
        count++;
        if(count > 5){count = 1;}
    }


    shuffle(imagesdata);


    int x = 150;
    int y = 100;
    for(int i= 0;i<6;i++){
        for(int j =0;j<6;j++){
            if(imagesdata[i][j] == 1){

                imagesback[i][j] = new QGraphicsPixmapItem();
                imagesback[i][j]->setPixmap(back);
                imagesback[i][j]->setPos(x, y);
                scene->addItem(imagesback[i][j]);

                images1[i][j] = new QGraphicsPixmapItem();
                images1[i][j]->setPixmap(card1);
                images1[i][j]->setPos(x, y);
                scene->addItem(images1[i][j]);
                images1[i][j]->hide();
            }
            if(imagesdata[i][j] == 2){
                imagesback[i][j] = new QGraphicsPixmapItem();
                imagesback[i][j]->setPixmap(back);
                imagesback[i][j]->setPos(x, y);
                scene->addItem(imagesback[i][j]);

                images1[i][j] = new QGraphicsPixmapItem();
                images1[i][j]->setPixmap(card2);
                images1[i][j]->setPos(x, y);
                scene->addItem(images1[i][j]);
                images1[i][j]->hide();
            }
            if(imagesdata[i][j] == 3){
                imagesback[i][j] = new QGraphicsPixmapItem();
                imagesback[i][j]->setPixmap(back);
                imagesback[i][j]->setPos(x, y);
                scene->addItem(imagesback[i][j]);

                images1[i][j] = new QGraphicsPixmapItem();
                images1[i][j]->setPixmap(card3);
                images1[i][j]->setPos(x, y);
                scene->addItem(images1[i][j]);
                images1[i][j]->hide();
            }
            if(imagesdata[i][j] == 4){
                imagesback[i][j] = new QGraphicsPixmapItem();
                imagesback[i][j]->setPixmap(back);
                imagesback[i][j]->setPos(x, y);
                scene->addItem(imagesback[i][j]);
                images1[i][j] = new QGraphicsPixmapItem();
                images1[i][j]->setPixmap(card4);
                images1[i][j]->setPos(x, y);
                scene->addItem(images1[i][j]);
                images1[i][j]->hide();

            }
            if(imagesdata[i][j] == 5){
                imagesback[i][j] = new QGraphicsPixmapItem();
                imagesback[i][j]->setPixmap(back);
                imagesback[i][j]->setPos(x, y);
                scene->addItem(imagesback[i][j]);

                images1[i][j] = new QGraphicsPixmapItem();
                images1[i][j]->setPixmap(card5);
                images1[i][j]->setPos(x, y);
                scene->addItem(images1[i][j]);
                images1[i][j]->hide();

            }
            x+=100;
        }
        y+=110;
        x=150;
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

