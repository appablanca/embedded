/********************************************************************************
** Form generated from reading UI file 'serialCom.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALCOM_H
#define UI_SERIALCOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serialCom
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *serialCom)
    {
        if (serialCom->objectName().isEmpty())
            serialCom->setObjectName("serialCom");
        serialCom->resize(490, 308);
        centralwidget = new QWidget(serialCom);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_4 = new QHBoxLayout(centralwidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");

        horizontalLayout->addWidget(comboBox);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout->addWidget(lineEdit_2);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout_2->addLayout(verticalLayout);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");

        horizontalLayout_2->addWidget(listWidget);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout_3->addWidget(pushButton_4);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);

        serialCom->setCentralWidget(centralwidget);
        menubar = new QMenuBar(serialCom);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 490, 21));
        serialCom->setMenuBar(menubar);
        statusbar = new QStatusBar(serialCom);
        statusbar->setObjectName("statusbar");
        serialCom->setStatusBar(statusbar);

        retranslateUi(serialCom);

        QMetaObject::connectSlotsByName(serialCom);
    } // setupUi

    void retranslateUi(QMainWindow *serialCom)
    {
        serialCom->setWindowTitle(QCoreApplication::translate("serialCom", "serialCom", nullptr));
        label->setText(QCoreApplication::translate("serialCom", "Port", nullptr));
        pushButton->setText(QCoreApplication::translate("serialCom", "Open", nullptr));
        pushButton_2->setText(QCoreApplication::translate("serialCom", "Send", nullptr));
        pushButton_4->setText(QCoreApplication::translate("serialCom", "Connect to TCP server", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serialCom: public Ui_serialCom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALCOM_H
