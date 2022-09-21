#include "game.h"
#include "./ui_game.h"

Application::Application(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);
}

Application::~Application()
{
    delete ui;
}


void Application::on_action_New_triggered() // new
{
    ui->plainTextEdit->clear();

    ui->statusbar->showMessage(" ");
}


void Application::on_actionOpen_triggered() // open
{
    QString m_strForOpenFile=QFileDialog::getOpenFileName(this,"Open a File");
    QFile file(m_strForOpenFile);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::warning(this,"Error","Failed open a file "); // or file.errorString();
        return;
    }

    QTextStream out(&file);
    ui->plainTextEdit->setPlainText(out.readAll());
    file.close();

    ui->statusbar->showMessage(m_strForOpenFile);
    m_fileName=m_strForOpenFile;
}


void Application::on_actionSave_triggered() //save
{
    QString m_strForOpenFile=QFileDialog::getSaveFileName(this,"Save a File");
    QFile file(m_strForOpenFile);
    if(!file.open(QIODevice::WriteOnly)){
        QMessageBox::critical(this,"Error","Failed open a file "); // or file.errorString();
        return;
    }

    QTextStream out(&file);
    out<<ui->plainTextEdit->toPlainText();
    file.close();

    ui->statusbar->showMessage(m_strForOpenFile);
    m_fileName=m_strForOpenFile;
}


void Application::on_actionCopy_triggered() // copy
{
    ui->plainTextEdit->copy();
}


void Application::on_actionPaste_triggered() // paste
{
    ui->plainTextEdit->paste();

}


void Application::on_actionCut_triggered() // cut
{
    ui->plainTextEdit->cut();
}


void Application::on_actionSelect_triggered() // select
{
     ui->plainTextEdit->selectAll();

}

