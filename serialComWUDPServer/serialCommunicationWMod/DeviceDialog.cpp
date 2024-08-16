#include "DeviceDialog.h"
#include "ui_DeviceDialog.h"

DeviceDialog::DeviceDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DeviceDialog)
{
    ui->setupUi(this);
}

DeviceDialog::~DeviceDialog()
{
    delete ui;
}
