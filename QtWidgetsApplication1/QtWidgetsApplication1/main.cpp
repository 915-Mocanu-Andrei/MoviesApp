#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWidgetsApplication1 w;
    //Widget w;
    w.show();
    w.connect_signals_and_slots();
    return a.exec();
}
