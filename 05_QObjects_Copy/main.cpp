#include <QCoreApplication>
#include "cat.h"
#include <QDebug>

void test (Cat &cat) {
    qInfo() << "Addr: " << &cat;
}

void test2 (Cat *cat) {
    qInfo() << "Ptr: " << cat;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cat kitty;
    kitty.setObjectName("kitty");
    Cat kitty2;
    kitty2.setObjectName("kitty2");

    test(kitty);
    test2(&kitty);
    test(kitty2);
    test2(&kitty2);

    //qInfo() << &kitty;

    return a.exec();
}
