#include "dialog.h"
#include "ui_dialog.h"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QSpinBox>


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    createMenu();
      createFormGroupBox();
    createHorizGroupBox();

   QVBoxLayout *layout=new QVBoxLayout;
    layout->addWidget(menuBar);
   layout->addWidget(horizGroup);
   layout->addWidget(fromBox);
   setLayout(layout);

}

void Dialog::createMenu()
{
    menuBar=new QMenuBar;

    menu=new QMenu("&File");

    exitAction=menu->addAction(tr("&Exit"));

    menuBar->addMenu(menu);

    connect(exitAction,SIGNAL(triggered()),this,SLOT(accept()));
}

void Dialog::createHorizGroupBox(){

    horizGroup=new QGroupBox("Horiz Group Box");

    QHBoxLayout* layout=new QHBoxLayout;

    for(int i=0;i<3;i++){
        buttons[i]= new QPushButton(tr("Button %1").arg(i+1));
        layout->addWidget(buttons[i]);
    }

    horizGroup->setLayout(layout);
}

void Dialog::createFormGroupBox()
{
    fromBox=new QGroupBox(tr("Form Layoutx"));

    QFormLayout *form=new QFormLayout;
    QSpinBox *s=new QSpinBox;
    s->setPrefix("$");
    s->setSuffix("rs");
    s->setSingleStep(3);

    form->addRow(new QLabel(tr("Line1: ")),new QLineEdit);
    form->addRow(new QLabel(tr("Line2: ")),new QSpinBox );
    form->addRow(new QLabel(tr("Line3: ")),new QComboBox);
    form->addRow(new QLabel(tr("Line4: ")),s);
    fromBox->setLayout(form);
}

Dialog::~Dialog()
{
    delete ui;
}

