#include "serialCom.h"
#include "ui_serialCom.h"
#include <QSerialPortInfo>


serialCom::serialCom(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::serialCom)
{
    ui->setupUi(this);
    loadPorts();
    connect(&_port, &SerialPort::dataRecieved, this, &serialCom::readData);
    TCPSocket = new QTcpSocket();

}

serialCom::~serialCom()
{
    delete ui;
}



void serialCom::on_pushButton_clicked()
{
    auto result = _port.connect(ui->comboBox->currentText());
    if(!result){
        ui->statusbar->showMessage("Unable to connect to port.",3000);
    }
    ui->statusbar->showMessage(("Connected to port "+  _port.getName()),3000);

}


void serialCom::on_pushButton_2_clicked()
{

    QString message = ui->lineEdit_2->text();
    auto numBytes = _port.write(ui->lineEdit_2->text().toUtf8());
    if (numBytes == -1){
        ui->statusbar->showMessage("Something went wrong.",3000);
    }
    ui->listWidget->addItem(_port.getName()+": "+message);
    QByteArray br = message.toUtf8();
    TCPSocket->write(br);

}

void serialCom::loadPorts()
{
    foreach (auto &port, QSerialPortInfo::availablePorts()){
        ui->comboBox->addItem(port.portName());
    }
}

void serialCom::readData(QByteArray data)
{

    ui->listWidget->addItem(QString(data));
}





void serialCom::on_pushButton_4_clicked()
{
    TCPSocket->connectToHost(QHostAddress::LocalHost,1234);
    TCPSocket->open(QIODevice::ReadWrite);
    if (TCPSocket->isOpen()){
        ui->statusbar->showMessage("Connection to TCP server established.",3000);
    } else {
        ui->statusbar->showMessage("Something went wrong.",3000);
    }
}

