#include <QCoreApplication>
#include <QSharedPointer>
#include <QRandomGenerator>
#include "test.h"

QList<int> getNumbers() {
    QList<int> list;

    list << 300 << 400 << 500;
    int max = QRandomGenerator::global()->bounded(1,10);
    for (int i = 0; i <max; i++) {
        list.append(QRandomGenerator::global()->bounded(1,100));
    }

    return list;
}

void testNumbers() {
    QList<int> list = getNumbers();
    qInfo() << list;
    qInfo() << "Length" << list.length();
    qInfo() << "Count" << list.count();
    qInfo() << "Size" << list.size();

    for (int i = 0; i < list.length(); i++) {
        qInfo() << i << "=" << list.at(i) << "or" << list[i];
    }

    qInfo() << "-----------";
    foreach(int i, list) {
        qInfo() << i;
    }
}

void testModifying() {
    QList<int> list = getNumbers();

    //direct modification
    list[0] = 1000;

    //appending
    list.append(99);
    list << 2000 << 3000;

    //inserting
    list.insert(0, 55);

    //removing
    qInfo() << "Length" << list.length();
    list.removeAt(0);
    qInfo() << "Remove at" << list.length();
    list.removeOne(99);
    qInfo() << "Remove one" << list.length();
    //list.remove(5, 7);
    //qInfo() << "Remove" << list.length();

    for (int i = 0; i < list.length(); i++) {
        qInfo() << i << "=" << list.at(i);
    }
}

void testSearch() {
    QList<int> list = getNumbers();
    int item = 999;
    list.insert(0,item);
    list.insert(2,item);
    list.append(item);

    for (int i = 0; i < list.length(); i++) {
        qInfo() << i << "=" << list.at(i);
    }

    //First
    int firstPosition = list.indexOf(item);
    qInfo() << "First" << firstPosition;

    //Last
    int lastPosition = list.lastIndexOf(item);
    qInfo() << "Last" << lastPosition;

    //All
    int position = list.indexOf(item);
    do {
        qInfo() << "At" << position;
        position = list.indexOf(item, position + 1);
    } while (position > -1);

    qInfo() << "Contains" << list.contains(item);

    //Slice
    QList<int> items = list.sliced(1, 4);
    qInfo() << list;
    qInfo() << items;
}

void testDeleteAll() {
    QList<Test*> list;
    for (int i = 0; i < 5; i++) {
        list.append(new Test());
    }
    qInfo() << "Clean up";
    qDeleteAll(list);
    list.clear();
    qInfo() << list.length();
}

void testSmart() {
    QList<QSharedPointer<Test>> list;
    for (int i = 0; i < 5; i++) {
        QSharedPointer<Test> item(new Test);
        list.append(item);
    }
    qInfo() << "Remove first";
    list.removeFirst();
    qInfo() << "Clear";
    qInfo() << list.length();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //---Creating & adding data
    testNumbers();

    //---Modifying data
    testModifying();

    //--Searching
    testSearch();

    //---Memory Considerations
    testDeleteAll();
    testSmart();

    return a.exec();
}
