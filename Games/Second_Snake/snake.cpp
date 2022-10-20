#include "snake.h"
#include "ui_snake.h"

Snake::Snake(QWidget *parent)
    : QWidget(parent)

{
    resize(MARGIN*4+(AREA_COL+3)*BLOC_SIZE,MARGIN*2+AREA_ROW*BLOC_SIZE);
    Set_up_Game();
}

void Snake::keyPressEvent(QKeyEvent *event)
{

    switch(event->key())
    {
    case Qt::Key_Up:
        if(_dir!=Direction::DOWN) { _dir = Direction::UP;}
        break;

    case Qt::Key_Down:
        if(_dir!=Direction::UP) { _dir=Direction::DOWN;}
        break;

    case Qt::Key_Left:
       if(_dir!=Direction::RIGHT) { _dir=Direction::LEFT; }
        break;

    case Qt::Key_Right:
        if(_dir!=Direction::LEFT) {_dir=Direction::RIGHT;}
        break;

    case Qt::Key_F1:
        GamePause();
        break;

    default:
        break;
    }

}

void Snake::paintEvent(QPaintEvent *event)
{
    QPainter pan(this);
    pan.setBrush(Qt::red);
    pan.setPen(Qt::blue);
    pan.drawRect(MARGIN,MARGIN,AREA_COL*BLOC_SIZE,AREA_ROW*BLOC_SIZE);

    pan.setBrush(Qt::red);
    pan.setPen(Qt::green);

    for(int i=0;i<_snake.size();i++)
        pan.drawEllipse(MARGIN+_snake[i].x()*BLOC_SIZE,MARGIN+_snake[i].y()*BLOC_SIZE,BLOC_SIZE,BLOC_SIZE);
    pan.setBrush(Qt::green);


    pan.drawEllipse(MARGIN+food_point.x()*BLOC_SIZE,MARGIN+food_point.y()*BLOC_SIZE,BLOC_SIZE,BLOC_SIZE);// for paint food

    pan.setPen(Qt::black);
    pan.setFont(QFont("Score Shirft",14));
    pan.drawText(MARGIN*3+AREA_COL*BLOC_SIZE,MARGIN+2*BLOC_SIZE,"Score: "+QString::number(_score)); //
    }

bool Snake::IsGameOver()
{
    int _x=_snake.front().x();
    int _y=_snake.front().y();

    if(_x<0|| _x>AREA_COL-1 || _y<0 || _y>AREA_ROW-1){
            return true;
    }

    for(int i=3;i<_snake.size();i++)
        if(_snake[i]==_snake.front())
            return true;

    return false;
}

void Snake::GameOver()
{
    timer_game->stop();
    QMessageBox::information(this,"About game","Game come to the end");

}

void Snake::GamePause()
{
    if(!pause_game){
        pause_game=!pause_game;
        timer_game->stop();
    }else{
         pause_game=!pause_game;
         timer_game->start(250);
    }
}

void Snake::CreateFood()
{
    food_point.setX(rand()%AREA_COL);
    food_point.setY(rand()%AREA_ROW);

   if(_snake.contains(food_point)){
       CreateFood();
   }
}

void Snake::Set_up_Game()
{

    for(int head=4;head>=0;head--){
       _snake.push_back(QPoint(head,0)); // first cordinat x,second cordinat y
    }

    _dir=Direction::RIGHT;

    srand(time(nullptr));
    CreateFood();

    pause_game=false;


    timer_game=new QTimer(this);
    connect(timer_game,SIGNAL(timeout()),this,SLOT(Set_up_Snake()));
    timer_game->start(250);

    _score=0;
}

void Snake::Set_up_Snake()
{
    switch(_dir){
       case Direction::UP:
          _snake.push_front(QPoint(_snake.front().x(),_snake.front().y()-1));
        break;

       case Direction::DOWN:
        _snake.push_front(QPoint(_snake.front().x(),_snake.front().y()+1));
        break;

    case Direction::LEFT:
        _snake.push_front(QPoint(_snake.front().x()+1,_snake.front().y()));
          break;

    case Direction::RIGHT:
        _snake.push_front(QPoint(_snake.front().x()-1,_snake.front().y()));
        break;

       default:
        break;
    }


    if(_snake.contains(food_point)){
        _score=+1;
        CreateFood();
    }else{
        _snake.pop_back();

    }

    if(IsGameOver()){
        GameOver();
        return ;
    }
    update(); // for repaints widget
}

