#include "widget.h"
#include "ui_widget.h"

#include <QTableView>

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
{
    _save=new QAction(tr("Save"),this);
    _open=new QAction(tr("Open"),this);
    _close=new QAction(tr("Close"),this);


    connect(_save,SIGNAL(triggered()),this,SLOT(Save()));
    connect(_open,SIGNAL(triggered()),this,SLOT(Open()));
    connect(_close,SIGNAL(triggered()),qApp,SLOT(quit()));

    fileMenu=new QMenu;
    fileMenu=menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(_save);
    fileMenu->addAction(_open);
    fileMenu->addAction(_close);

    t_edit=new QTextEdit;

    setCentralWidget(t_edit);


    setWindowTitle("Notepad");
}

void Widget::Save()
{
    QString name_file=QFileDialog::getSaveFileName(this,tr("Open file")," ",
                                                   tr("Text files (.*txt);; C++ Files (.*cpp) *.hpp)"));


    QFile file(name_file);

    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::warning(this,"Can't open","Failed open a file !");
        return ;
    }

    QTextStream in(&file);
    in<<t_edit->toPlainText();
    in.flush();
    file.close();
}


void Widget::Open()
{
    QString name_file=QFileDialog::getOpenFileName(this,tr("Open file")," ",
                                                   tr("Text files (.*txt);; C++ Files (.*cpp) *.hpp)"));


    QFile file(name_file);

    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::warning(this,"Can't open","Failed open a file !");
        return ;
    }

    QTextStream in(&file);
    t_edit->setText(in.readAll());
    file.close();
}
