#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>



class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget(){}

private slots:
    void Save();
    void Open();

private:
    QAction *_save;
    QAction *_open;
    QAction *_close;


    QTextEdit *t_edit;


    QMenu *fileMenu;
};
#endif // WIDGET_H
