#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>



class Widget : public QLabel
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget(){}

protected:
    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    virtual void mouseMoveEvent(QMouseEvent *ev);
    virtual void mouseDoubleClickEvent(QMouseEvent *ev);

    virtual void resizeEvent(QResizeEvent *res){   
        setText(QString("Resized")
                +"\n width()= "+QString::number(res->oldSize().width())
                +"\n height()= "+QString::number(res->oldSize().height())
                );
    }

    void dumpEvent(QMouseEvent *pe,const QString &_info);
    QString modifiersInfo(QMouseEvent *pe);
    QString buttonsInfo(QMouseEvent *pe);
};
#endif // WIDGET_H
