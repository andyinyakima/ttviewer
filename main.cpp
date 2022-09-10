#include "ttv.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    ttv w;

    w.show();

    return a.exec();
}
