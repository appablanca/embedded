#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadPorts();

    connect(&_port, &SerialPort::dataRecieved, this, &MainWindow::readData);
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost,1234);

}

MainWindow::~MainWindow()
{    delete ui;


}




void MainWindow::on_pushButton_clicked()
{
    auto result = _port.connect(ui->comboBox->currentText());
    if(!result){
        ui->statusbar->showMessage("Unable to connect to port.");
    } else {
        ui->statusbar->showMessage(("Connected to port "+  _port.getName()),3000);
    }
}


void MainWindow::on_sendButton_clicked()
{
    QString message = ui->messageBox->text();
    auto numBytes = _port.write(ui->messageBox->text().toUtf8());
    if (numBytes == -1){
        ui->statusbar->showMessage("Something went wrong.");
    }
    ui->conversationBox->addItem(_port.getName()+": "+message);
    QByteArray br = message.toUtf8();
    socket->writeDatagram(br,QHostAddress::LocalHost,1234);

}

void MainWindow::loadPorts(){

    foreach (auto &port, QSerialPortInfo::availablePorts()){
        ui->comboBox->addItem(port.portName());
    }
}

void MainWindow::readData(QByteArray data)
{

    ui->conversationBox->addItem(QString(data));
}




void MainWindow::on_connectBtn_clicked()
{
    connect(socket,SIGNAL(readyRead()),this,SLOT(deleteLater()));
    ui->statusbar->showMessage("Connection to UDP server established.",3000);

}

