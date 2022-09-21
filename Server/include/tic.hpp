#pragma once

#include <QtWidgets>
#include <QTextEdit>
#include <QTcpServer>
#include <QString>


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(int port,QWidget *parent = nullptr);
    ~MainWindow(){}

 public:
    void SlotNewConnection();
    void SlotReadReady();

private:
    QTcpServer * _server;
    QTextEdit* t_txt;
    quint16 _blockSize;

private:
    void SendToClient(QTcpSocket* _socketServer,const QString &str);
};

