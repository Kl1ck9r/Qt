#ifndef CALENDAR_H
#define CALENDAR_H

#include <QtWidgets>
#include <QMainWindow>
#include <QProcess>

class MainWindow: public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    auto AddressBookSetUp()->void;

public slots:
    auto cancel()->void;
    auto addContanct()->void;
    auto sumbitContact()->void;

private :
    QLabel * _nameLabel;
    QLabel *_addressLabel;

    QLineEdit *_nameLine;
    QLineEdit *_addressLine;

    QPushButton *_cancelButton;
    QPushButton *_addButton;
    QPushButton *_submitButton;

    QMap<QString,QString> contacts;

    QString old_name;
    QString old_address;


};
#endif // CALENDAR_H
