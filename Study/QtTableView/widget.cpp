#include "widget.h"
#include "ui_widget.h"

#include <QTableView>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
   _model=new QStandardItemModel;
   view=new QStandardItem(QObject::tr("ID"));

   view->setText("Hello i am ");
   view->setText("This not i");

   _model->setHorizontalHeaderItem(0,view);

   view_t=new QStandardItem(QObject::tr("Telephone"));
   _model->setHorizontalHeaderItem(1,view_t);

   number_telephone=new QLabel(tr("Telephone: "));
   line_number=new QLineEdit;
   line_number->setValidator(new QIntValidator);

   label_id=new QLabel(tr("ID: "));
   line_id=new QLineEdit;
   line_id->setValidator(new QIntValidator);

   table=new QTableView;
   table->setModel(_model);


   setButton=new QDialogButtonBox(Qt::Vertical);

   add_id=new QPushButton(tr("Add ID"));
   remove=new QPushButton(tr("Remove"));

   connect(add_id,SIGNAL(clicked()),this,SLOT(Add_id()));

   setButton->addButton(add_id,QDialogButtonBox::ActionRole);
   setButton->addButton(remove,QDialogButtonBox::ActionRole);

   QVBoxLayout *layout=new QVBoxLayout;
   layout->addWidget(setButton);

   QGridLayout *mainL=new QGridLayout(this);
    mainL->addWidget(number_telephone,0,0);
    mainL->addWidget(line_number,0,1);
    mainL->addWidget(label_id,1,0);
    mainL->addWidget(line_id,1,1);
    mainL->addLayout(layout,1,3);
    mainL->addWidget(table,2,0);

    setLayout(mainL);

    setWindowTitle("Saving info about person");

}

auto Widget::Save_telephone_number()->void
{


}

auto Widget::Add_id()->void
{

}




