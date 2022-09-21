#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QVector>
#include <QPoint>

class Game:public QWidget
{
public:
    Game(QWidget *parent=0);
    ~Game(){}

protected:
    void timerEvent(QTimerEvent *)override;
    void keyPressEvent(QKeyEvent *event)override;
    void paintEvent(QPaintEvent *event)override;

private :
    static const int WIDTH=20; // width snake
    static const int HEIGHT=20; // heigh snake
    static const int Field_Width=20;
    static const int Field_Height=20;
    static const int Time=150; // mls



private:
    int timerId;
    QPoint m_apple;
    bool m_Game;
    enum Direction{LEFT,RIGHT,UP,DOWN};
    Direction m_dir;
    QVector<QPoint> m_dots;

private :
   void InitGame();
   void localApple();
   void doDrawing();
   void Move();
   void check_field();
   void GameOver();
   void CheckApple();
};

#endif // GAME_H