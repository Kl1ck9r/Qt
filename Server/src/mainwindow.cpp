#include "mainwindow.h"
//#include "ui_mainwindow.h"

#include <QtWidgets>
#include <QTcpServer>
#include <QMessageBox>
#include <QTcpSocket>
#include <QVBoxLayout>
#include <QTimer>

MainWindow::MainWindow(int port,QWidget *parent) : QWidget(parent),_blockSize(0)

{
  _server=new QTcpServer(this);

  if(!_server->listen(QHostAddress::Any,port)){
      QMessageBox::warning(this,"Warning","Can't connection in server !");
        _server->close();
  }


  connect(_server,SIGNAL(newConnection()),this,SLOT(SlotNewConnection()));

  t_txt=new QTextEdit;
  t_txt->setReadOnly(true);

  QVBoxLayout *layout=new QVBoxLayout;
  layout->addWidget(new QLabel("<H1>Server<H1>"));
  layout->addWidget(t_txt);

  setLayout(layout);
}

void MainWindow::SlotNewConnection()
{
    QTcpSocket * _socket=_server->nextPendingConnection();

    connect(_socket,SIGNAL(disconnected()),
            _socket,SLOT(deleteLater()));

    connect(_socket,SIGNAL(newConnection()),
            this,SLOT(SlotReadReady()));

    SendToClient(_socket,"Hello from client !");

}

void MainWindow::SlotReadReady()
{
    QTcpSocket *_sockServer=(QTcpSocket*)sender();
    QDataStream in(_sockServer);
    in.setVersion(QDataStream::Qt_6_2);

    for(;;)
    {
        if(!_blockSize){
            if(_sockServer->bytesAvailable()<quint16(0)){
                break;
            }
        }
        if(_blockSize>_sockServer->bytesAvailable()){
            break;
        }

        QTime _time;
        QString _str;
        in>>_time>>_str;

        QString _send_Message=_time.toString()+""+_str;

        _blockSize=0;
        t_txt->append(_send_Message);

        SendToClient(_sockServer,"Hello and again i");

    }
}

void MainWindow::SendToClient(QTcpSocket *_socketServer, const QString &str)
{
    QByteArray _ByteArr;
    QDataStream out(&_ByteArr,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);

    out<<quint16(0)<<QTime::currentTime()<<str;

    out.device()->seek(0);
    out<<quint16(_ByteArr.size()-sizeof(quint16));

    _socketServer->write(_ByteArr);
}


