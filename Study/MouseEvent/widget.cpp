#include "widget.h"
#include "ui_widget.h"

#include <QTableView>

Widget::Widget(QWidget *parent)
    : QLabel(parent)
{

    setAlignment(Qt::AlignCenter); // set center our QLabel
    setText("Mouse interactions\n Press a mouse button)");
}

void Widget::mousePressEvent(QMouseEvent *ev) // for hit button mouse
{
    dumpEvent(ev,"Press mouse ");
}

void Widget::mouseReleaseEvent(QMouseEvent *ev) // for letting go mouse
{
    dumpEvent(ev,"Release mouse ");
}

void Widget::mouseMoveEvent(QMouseEvent *ev) // for moving mouse
{
    dumpEvent(ev,"Moving is mouse");
}

void Widget::mouseDoubleClickEvent(QMouseEvent *ev) // for double click to mouse
{
    dumpEvent(ev,"Double Click Event");
}

QString Widget::buttonsInfo(QMouseEvent *pe) // methof Infobuttons -  info us about pressed buttons
{
    QString str_buttons;

    if(pe->buttons() & Qt::LeftButton){
        str_buttons+="Left Button";
    }

    if(pe->buttons() & Qt::RightButton){
        str_buttons+="Right Button";
    }

    if(pe->buttons() & Qt::MiddleButton){
        str_buttons+="Middle Button";
    }

    return str_buttons;
}

void Widget::dumpEvent(QMouseEvent *pe,const QString &_info) // input info about mouse
{
    setText(_info
            +"\n buttons()="+buttonsInfo(pe)
            +"\n x()="+QString::number(pe->x())
            +"\n globalX()="+QString::number(pe->globalX())
            +"\n y() ="+QString::number(pe->y())
            +"\n globalY()= "+QString::number(pe->globalY())
            +"\n KeyBoard buttons= "+modifiersInfo(pe)
            );

}

QString Widget::modifiersInfo(QMouseEvent *pe) //
{
    QString str_modifi;

    if(pe->modifiers() &Qt::ShiftModifier){
        str_modifi+="Shift";
    }
    if(pe->modifiers() & Qt::ControlModifier){
        str_modifi+="Ctrl";
    }

    if(pe->modifiers() & Qt::AltModifier){
        str_modifi+="Alt";
    }

    return str_modifi;
}




