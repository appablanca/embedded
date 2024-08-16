/********************************************************************************
** Form generated from reading UI file 'tcpServer.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tcpServer
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *tcpServer)
    {
        if (tcpServer->objectName().isEmpty())
            tcpServer->setObjectName("tcpServer");
        tcpServer->resize(800, 500);
        centralwidget = new QWidget(tcpServer);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);


        horizontalLayout->addLayout(verticalLayout);

        tcpServer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(tcpServer);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        tcpServer->setMenuBar(menubar);
        statusbar = new QStatusBar(tcpServer);
        statusbar->setObjectName("statusbar");
        tcpServer->setStatusBar(statusbar);

        retranslateUi(tcpServer);

        QMetaObject::connectSlotsByName(tcpServer);
    } // setupUi

    void retranslateUi(QMainWindow *tcpServer)
    {
        tcpServer->setWindowTitle(QCoreApplication::translate("tcpServer", "tcpServer", nullptr));
        label->setText(QCoreApplication::translate("tcpServer", "Messages", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tcpServer: public Ui_tcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
