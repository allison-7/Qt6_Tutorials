#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{}

void Test::do_stuff()
{
    qInfo() << "Do stuff";
    emit close();
}
