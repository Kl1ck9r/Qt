#include "mainwindow.h"
#include <QPainter>
#include <QMessageBox>
#include <QTime>

MainWindow::MainWindow(QWidget *parent): QWidget(parent)

{


  resize(WIDTH*Field_WIDTH,HEIGHT*Field_HEIGHT);

   StartGame();
}


void MainWindow::StartGame()
{
  Game=true;
  dir=RIGHT;
  dots.resize(3);

  for(int i=0;i<dots.size();i++){
        dots[i].rx()=dots.size()-i-1;
        dots[i].ry()=0;
  }


  LocalApple();

  timerId=startTimer(150);

}

void MainWindow::DrawingMap()
{
     QPainter draw(this);

     if(Game)
     {
         draw.setBrush(Qt::red);
         draw.drawEllipse(apple.x()*Field_WIDTH,apple.y()*Field_HEIGHT,Field_WIDTH,Field_HEIGHT);

         for(int i=0;i<dots.size();i++)
         {
             if(i==0){
                 draw.setBrush(Qt::white);
                 draw.drawEllipse(dots[i].x()*Field_WIDTH,dots[i].y()*Field_HEIGHT,Field_WIDTH,Field_HEIGHT);
             }else{
                 draw.setBrush(Qt::green);
                 draw.drawEllipse(dots[i].x()*Field_WIDTH,dots[i].y()*Field_HEIGHT,Field_WIDTH,Field_HEIGHT);
             }

         }
     }
     else{
         GameOver();
     }
}

void MainWindow::GameOver()
{
    QMessageBox box;
    box.setText("GameOver");
    box.exec();

    StartGame();

}

void MainWindow::Move()
{
    for(int i=dots.size()-1;i>0;i--){
        dots[i]=dots[i-1];
    }

    switch(dir)
    {
    case  RIGHT:{dots[0].rx()+=1;}
        break;

    case LEFT:{dots[0].rx()-=1;}
        break;

    case UP:{dots[0].ry()-=1;}
        break;

    case DOWN:{dots[0].ry()+=1;}
        break;
    }
}

void MainWindow::LocalApple()
{
    QTime time=QTime::currentTime();

    apple.rx()=rand()%Field_WIDTH;
    apple.ry()=rand()%Field_HEIGHT;
}

void MainWindow::CheckApple()
{
    if(apple==dots[0]){
        dots.push_back(QPoint(0,0));
        LocalApple();
    }
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    if(Game){
        CheckApple();
        Move();
        CheckField();
    }

    this->repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
   Q_UNUSED(event);

   DrawingMap();

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key=event->key();

    if(key==Qt::Key_Right && dir!=LEFT){
        dir=RIGHT;
    }

    if(key==Qt::Key_Left && dir!=RIGHT){
        dir=LEFT;
    }

    if(key==Qt::Key_Down && dir!=UP){
        dir=DOWN;
    }

    if(key==Qt::Key_Up && dir!=DOWN){
        dir=UP;
    }
}

void MainWindow::CheckField()
{
    if(dots.size()>4){
        for(int i=1;i<dots.size();i++){
            if(dots[0]==dots[i]){
                Game=false;
            }
        }
    }

    if(dots[0].x()>=Field_WIDTH){
        Game=false;
     }

     if(dots[0].x()<0){
        Game=false;
     }

     if(dots[0].y()>=Field_HEIGHT){
        Game=false;
     }

    if(dots[0].y()<0) {
       Game=false;
    }

    if(!Game){
        killTimer(timerId);
    }
}


