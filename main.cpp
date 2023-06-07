#include "gameform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QIcon icon("icon.png");
    a.setWindowIcon(icon);

    GameForm w;
    w.show();

    return a.exec();
}
