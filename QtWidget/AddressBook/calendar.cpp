#include "calendar.h"
#include "ui_calendar.h"


MainWindow::MainWindow(QWidget *parent):QWidget(parent)
{
    AddressBookSetUp();
}

MainWindow::~MainWindow()
{

}

auto  MainWindow::AddressBookSetUp() ->void
{
    _nameLabel=new QLabel(tr("Name: "));
    _addressLabel=new QLabel(tr("Address: "));

    _nameLine=new QLineEdit;
    _nameLine->setReadOnly(true);

    _addressLine=new QLineEdit;
    _addressLine->setReadOnly(true);

    _addButton=new QPushButton(tr("Add"));
    _addButton->show();

    _cancelButton=new QPushButton(tr("Cancel"));
    _cancelButton->hide();

    _submitButton=new QPushButton(tr("Submit"));
    _submitButton->hide();

    connect(_addButton,SIGNAL(clicked()),this,SLOT(addContanct()));
    connect(_submitButton,SIGNAL(clicked()),this,SLOT(sumbitContact()));
    connect(_cancelButton,SIGNAL(clicked()),this,SLOT(cancel()));

    QVBoxLayout *_boxLayout=new QVBoxLayout;
    _boxLayout->addWidget(_addButton,Qt::AlignTop);
     _boxLayout->addWidget(_submitButton);
    _boxLayout->addWidget(_cancelButton);



    QGridLayout *_layout=new QGridLayout;
   _layout->addWidget(_nameLabel,0,0);
   _layout->addWidget(_nameLine,0,1);
   _layout->addWidget(_addressLabel,1,0,Qt::AlignTop);
   _layout->addWidget(_addressLine,1,1);
   _layout->addLayout(_boxLayout,1,2);
    setLayout(_layout);

    setWindowTitle("Simple Address Book");
}

auto MainWindow::addContanct()->void
{
    old_name=_nameLine->text();
    old_address=_addressLine->text();

    _nameLine->clear();
    _addressLine->clear();

    _nameLine->setReadOnly(false);
    _addressLine->setReadOnly(false);

    _addButton->setEnabled(false);

    _cancelButton->show();
    _submitButton->show();
}

auto MainWindow::sumbitContact()->void
{
    QString name=_nameLine->text();
    QString address=_addressLine->text();

    if(name.isEmpty() || address.isEmpty()){
        QMessageBox::information(this,tr("Empty Field"),
                               tr("Please enter your a name and address "));
        return;
    }

    if(!contacts.contains(name)){
        contacts.insert(name,address);
        QMessageBox::information(this,tr("Add Successfull"),
                             tr("\"%1\" has been added to your address %1 Qt::Key_Book").arg(name).arg(address));
        return;
    }else{
        QMessageBox::information(this,tr("Add unsuccessfull"),
                                tr("Sorry, \"%1\" is a already in your address book ").arg(name));
        return ;
    }


    if(contacts.isEmpty()){
        _nameLine->clear();
        _addressLine->clear();
    }


    _nameLine->setReadOnly(true);
    _addressLine->setReadOnly(true);


    _addButton->setEnabled(true);
    _submitButton->hide();
    _cancelButton->hide();


}

auto MainWindow::cancel()->void
{
     _nameLine->setText(old_name);
    _nameLine->setReadOnly(true);

    _addressLine->setText(old_address);
    _addressLine->setReadOnly(true);

    _addButton->setEnabled(false);

    _cancelButton->hide();
    _submitButton->hide();
}
