#ifndef SERIALCOM_H
#define SERIALCOM_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include "SerialPort.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class serialCom;
}
QT_END_NAMESPACE

class serialCom : public QMainWindow
{
    Q_OBJECT

public:
    serialCom(QWidget *parent = nullptr);
    ~serialCom();
private slots:
    void on_pushButton_clicked();


    void readData(QByteArray data);


    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::serialCom *ui;
    SerialPort _port;
    QTcpSocket *TCPSocket;
    void loadPorts();
};
#endif // SERIALCOM_H
