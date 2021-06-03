#include "QtAccordionMenu.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtAccordionMenu w;
    w.show();
    return a.exec();
}
