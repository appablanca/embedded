#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&_port, &SerialPort::dataRecieved, this, &MainWindow::readData);
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &portInfo : serialPortInfos) {

        QString s = portInfo.portName();
        ui->comboBox->addItem(s);
    }
}

MainWindow::~MainWindow()
{    delete ui;


}

void MainWindow::on_pushButton_clicked()
{
    auto result = _port.connect(ui->comboBox->currentText());
    if(!result){
       ui->statusbar->showMessage("Unable to connect to port.");
    }
    ui->statusbar->showMessage("Connected to port: " + _port.getName());
}


void MainWindow::on_sendButton_clicked()
{
    QString message = ui->messageBox->text();
    auto numBytes = _port.write(ui->messageBox->text().toUtf8());
    if (numBytes == -1){
        ui->statusbar->showMessage("Something went wrong.");
    }
    ui->conversationBox->addItem(_port.getName()+": "+message);
}

void MainWindow::readData(QByteArray data)
{

    ui->conversationBox->addItem(QString(data));

}

