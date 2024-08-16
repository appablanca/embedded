#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost,1234);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::readyRead(){

    QByteArray Buffer;
    Buffer.resize(socket->pendingDatagramSize());
    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(Buffer.data(),Buffer.size(),&sender,&senderPort);
    ui->recievedMsg->addItem(sender.toString() + ":" + Buffer);



}
