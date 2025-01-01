#include <QCoreApplication>

void readName(QString &name) {
    name.insert(0, "Mr.");
    qInfo() << "Changed" << name;
}

void readOnly(QStringView name) {
    qInfo() << "name" << name.data() << name;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString first = "Bryan";
    QString last = "Cairns";

    //---Copy & Modification
    readName(first);
    qInfo() << "Original" << first;

    //---Read only, no copy
    qInfo() << "name" << first.data() << first;
    readOnly(first);

    //---Basic parsing
    QString fullName = first + " " + last;
    foreach(QStringView part, QStringView(fullName).split(QChar(' '))) {
        qInfo() << "part" << part;
        if(part.startsWith(QStringView(first),Qt::CaseInsensitive)) {
            qInfo() << "First name detected";
            readOnly(QStringView(first).mid(1,3));
        }
    }

    return a.exec();
}
