#include "tcpServer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tcpServer w;
    w.resize(487,356);
    w.show();

    return a.exec();
}
