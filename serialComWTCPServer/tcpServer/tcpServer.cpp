#include "tcpServer.h"
#include "ui_tcpServer.h"

tcpServer::tcpServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tcpServer)
    ,_server(this)
{

    ui->setupUi(this);
    _server.listen(QHostAddress::LocalHost,1234);
    connect(&_server,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
}

tcpServer::~tcpServer()
{
    delete ui;
}

void tcpServer::onNewConnection()
{
    QTcpSocket *clientSocket = _server.nextPendingConnection();
    connect(clientSocket, SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(clientSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));

    _sockets.push_back(clientSocket);
    for (QTcpSocket* socket: _sockets){
        socket->write(QByteArray::fromStdString(clientSocket->peerAddress().toString().toStdString()+"connected to server"));
        qDebug() << "connected";

    }
}

void tcpServer::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    if(socketState == QAbstractSocket::UnconnectedState){
        QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
        _sockets.removeOne(sender);
    }
}

void tcpServer::onReadyRead()
{
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    QByteArray datas = sender->readAll();
    for (QTcpSocket* socket: _sockets){
        if (socket != sender){
            socket->write(QByteArray::fromStdString(sender->peerAddress().toString().toStdString() + ": " + datas.toStdString()));

        }
    }
    ui->listWidget->addItem(datas);
    qDebug() << datas;
}
