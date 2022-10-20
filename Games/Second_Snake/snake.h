#ifndef SNAKE_H
#define SNAKE_H


#include <QtWidgets>
#include <QEvent>


enum class Direction{
   UP,
   DOWN,
   LEFT,
   RIGHT
};

class Snake : public QWidget
{
    Q_OBJECT

public:
    Snake(QWidget *parent = nullptr);
    ~Snake()noexcept = default;

protected:
    virtual void keyPressEvent(QKeyEvent *event)override;
    virtual void paintEvent(QPaintEvent *event)override;
 //   virtual void timerEvent(QTimerEvent *event) override;

private:
    bool IsGameOver();
    void GameOver();
    void GamePause();
    void CreateFood();
    void Set_up_Game();

private slots:
    void Set_up_Snake();

private:
    QTimer *timer_game;
    bool pause_game;
    int _score;
    QPoint food_point;
    QList<QPoint> _snake;
    Direction _dir;

public:
    const int BLOC_SIZE=25; //Длина стороны единичного блока
    const int MARGIN=5;     //поля сцены
    const int AREA_ROW=15;  //количество строк сцены
    const int AREA_COL=15;  // количество столбцов сцены
};



#endif // SNAKE_H
