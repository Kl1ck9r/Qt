#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>



class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget(){}

private slots :
    auto Save_telephone_number()->void;
    auto Add_id()->void;


private:
    QLabel *number_telephone;
    QLineEdit *line_number;

    QLabel *label_id;
    QLineEdit *line_id;

    QDialogButtonBox *setButton;

    QPushButton *add_id;
    QPushButton *remove;

    QStandardItemModel *_model;
    QStandardItem *view;
    QStandardItem *view_t;

    QTableView *table;

};
#endif // WIDGET_H
