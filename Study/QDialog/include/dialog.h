#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGroupBox>
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:

    void createHorizGroupBox();
    void createMenu();
    void createFormGroupBox();


    QMenu *menu;
    QMenuBar *menuBar;
     QAction *exitAction;

    QGroupBox *horizGroup;
    QGroupBox *fromBox;
    enum {numButton=3};
    QPushButton *buttons[numButton];
    Ui::Dialog *ui;
};
#endif // DIALOG_H
