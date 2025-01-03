#include <QCoreApplication>
#include <QSharedPointer>
#include <QRandomGenerator>
#include <QMap>
#include "cat.h"

typedef QMap<QString, QSharedPointer<Cat>> catMap;

catMap getCats() {
    catMap cats;
    for(int i = 0; i < 5; i++) {
        QSharedPointer<Cat> ptr(new Cat());
        ptr->setAge(QRandomGenerator::global()->bounded(1,5));
        ptr->setName("Unknown");
        cats.insert("pet" + QString::number(i), ptr);
    }
    return cats;
}

void display(catMap &cats) {
    foreach(QString key, cats.keys()) {
        QSharedPointer<Cat> ptr = cats.value(key);
        qInfo() << key << ptr->name() << ptr->age() << ptr.data();
    }
}

void modifyCat(catMap &cats, QString key) {
    if(cats.contains(key)) {
        qInfo() << "Modifying: " << key;
        cats[key]->setAge(99);
        cats[key]->setName("Fluffy");
        display(cats);
    }
}

void addCat(catMap &cats) {
    qInfo() << "Adding and inserting";
    QSharedPointer<Cat> ptr(new Cat());
    ptr->setAge(100);
    ptr->setName("Test Cat");
    //cats.insert("test", ptr);
    cats["test"] = ptr;
    display(cats);
}

void findCat(catMap &cats, QString key) {
    qInfo() << "Exists:" << cats.contains(key);
    auto iter = cats.find(key);
    if(iter != cats.end()) {
        qInfo() << iter.key() << iter.value();
    }
    foreach(QSharedPointer<Cat> value, cats.values()) {
        qInfo() << value;
    }
    foreach(QString key, cats.keys()) {
        qInfo() << "Key: " << key << "Value: " << cats.value(key);
    }
}

void removeCat(catMap &cats, QString key) {
    if(!cats.contains(key)) {
        qWarning() << "Cat not found";
        return;
    }
    cats.remove(key);
    display(cats);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //---Intro
    QMap<QString,double> lucky;
    lucky.insert(QString("Bryan"), 22.5);
    qInfo() << lucky;
    qInfo() << "My lucky number: " << lucky["Bryan"];

    //---Creating a map
    catMap cats = getCats();
    qInfo() << cats;

    //---Displaying a QMap
    display(cats);

    //---Modifying an item
    modifyCat(cats, "pet2");

    //---Adding & inserting
    addCat(cats);

    //---Searching
    findCat(cats,"test");

    //---Removing an item
    removeCat(cats, "test");

    //---Cleanup
    qInfo() << "Clearing";
    cats.clear();

    return a.exec();
}
