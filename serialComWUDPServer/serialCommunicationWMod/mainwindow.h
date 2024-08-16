#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QUdpSocket>
#include "SerialPort.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_sendButton_clicked();

    void readData(QByteArray data);


    void on_connectBtn_clicked();

private:
    Ui::MainWindow *ui;
    SerialPort _port;
    QUdpSocket *socket;
    void loadPorts();
};
#endif // MAINWINDOW_H
