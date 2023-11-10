#include "playing.h"
#include"cursor.h"

Playing::Playing()
{

    images[0][1].setFront(2);
    images[0][3].setFront(2);
    setToBack();
    scene = new QGraphicsScene();
    setCards();
    showPix();
    view = new QGraphicsView();
    scene->setSceneRect(-100, 0 , 800, 800);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800, 800);
    cursor1 = new cursor(this);
    view->setScene(scene);
    cursor1->setPos(5,40);
    scene->addItem(cursor1);

    cursor1->setFlag(QGraphicsItem::ItemIsFocusable);
    cursor1->setFocus();


    //set the focus


    //add cursor to the scene ----

  //add the openings counter
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


    view->show();

}
void Playing::hidePic(int x, int y)
{
    cards[x][y].hide();
}
void Playing::setToBack()
{
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            images[i][j].setFlipped(false);
}
void Playing::flip(int x, int y)
{
    images[y][x].flip(); //rows and cols switched

    if(openings >40){
        gameOver();
    }else{
        openings++;
    }
    openingsText->setPlainText("Openings: " + QString::number(openings));
    lastFlippedImages[0] = lastFlippedImages[1];
    lastFlippedImages[1] = &images[y][x];
}

void Playing::gameOver() {

    QGraphicsTextItem* gameOverText = new QGraphicsTextItem();
    gameOverText->setDefaultTextColor(Qt::red);
    openingsText->setFont(QFont("times",16));
    openingsText->setPlainText("Game Over! ");
    gameOverText->setPos(50,10);
    scene->addItem(gameOverText);

    view->show();
}


bool Playing::ismatched(){
    if (lastFlippedImages[0] == lastFlippedImages[1]) {
        return true;
    }
    return false;
}
QPixmap Playing::render(int i)
{//"img" + QString::number(i) + ".png"
    return QPixmap("B:\\Fall 23\\CS2 credit lab\\QT assignment\\MatchingCards\\img" + QString::number(i) + ".png");
}
void Playing :: setCards()
{
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
        {
            QPixmap card(render(images[i][j].getCurrent()));
            card = card.scaledToHeight(100);
            card = card.scaledToWidth(60);
            cards[i][j].setPixmap(card);
        }
}




void Playing::readimgdata()
{

    QFile file("M:\\MatchingCards\\MatchingCards\\imgdata.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);

    QString input;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            stream >> input;
            imagesdata[i][j] = input.toInt();
        }
    }
    file.close();


}
void Playing::writeimgdata(){
    QFile file("M:\\MatchingCards\\MatchingCards\\imgdata.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream stream(&file); // link the writing stream to your file

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            stream << (QString::number(imagesdata[i][j]) + " "); // write the data after converting it to a QString
        }
        stream << "\n";//add a new line after every row
    }
    file.close();





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
