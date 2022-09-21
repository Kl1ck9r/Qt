#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QTimer>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(nullptr));
    m_generationNumber=rand()%15;
    qDebug()<<"Number generation: "<<QString::number(m_generationNumber);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() // Guess
{
    m_GoalNumber=ui->spinBox->value();

    if(m_GoalNumber==m_generationNumber){
         ui->label_2->setText("Well done, You guess number ");
         ui->pushButton->setDisabled(true);
         ui->pushButton_2->setDisabled(false);
    }

    else if(m_GoalNumber<m_generationNumber){
        ui->label_2->setText("You need to bit more number ");
    }

    else if(m_GoalNumber>m_generationNumber){
        ui->label_2->setText("You need to bit less number ");
    }

    else
    {
        ui->label_2->setText("Wrong Number,You Lose ! ");
        return ;
    }

}


void MainWindow::on_pushButton_2_clicked() // start over
{
    srand(time(nullptr));
    m_generationNumber=rand()%15;

    ui->pushButton->setDisabled(false);

    ui->pushButton_2->setDisabled(true);

    ui->label_2->setText(" ");
    ui->spinBox->setValue(1);
}

