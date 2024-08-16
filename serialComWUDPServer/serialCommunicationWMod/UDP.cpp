#include "UDP.h"

UDP::UDP(QObject *parent)
    : QObject{parent}
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost,1234);
    connect(socket,SIGNAL(readyRead()),this,SLOT(deleteLater()));

}

void UDP::sayHello()
{
    QByteArray Data;
    Data.append("Hello From sender UDP.");
    socket->writeDatagram(Data,QHostAddress::LocalHost,1234);


}
