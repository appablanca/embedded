        #ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QMainWindow>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QDataStream>

QT_BEGIN_NAMESPACE
namespace Ui {
class tcpServer;
}
QT_END_NAMESPACE

class tcpServer : public QMainWindow
{
    Q_OBJECT

public:
    tcpServer(QWidget *parent = nullptr);
    ~tcpServer();

public slots:
    void onNewConnection();
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);
    void onReadyRead();

private:
    Ui::tcpServer *ui;
    QTcpServer _server;
    QList<QTcpSocket*> _sockets;

};
#endif // TCPSERVER_H
