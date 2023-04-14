#include "SmartTrashBin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SmartTrashBin w;
    w.show();
    return a.exec();
}
