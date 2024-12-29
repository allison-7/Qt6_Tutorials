#include <QCoreApplication>
#include <iostream>

void test(QString &data) {
    qInfo() << data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //---Creating---
    QString line("Hello World");
    qInfo()<< line;

    int pos = 504;
    int max = 7439;
    QString status = QString("Processing file %1 of %2").arg(pos).arg(max);
    qInfo() << status;

    //--Reading---
    for (int i = 0; i < line.length(); i++) {
        QChar c = line.at(i);
        qInfo() << c;
    }

    //---Comparing & Searching---
    qInfo() << "Compare" << line.compare("hello world",Qt::CaseSensitivity::CaseSensitive);
    qInfo() << "Starts" << line.startsWith("hello", Qt::CaseInsensitive);
    qInfo() << "Ends" << line.endsWith("world", Qt::CaseInsensitive);
    qInfo() << "Contains" << line.contains("world", Qt::CaseInsensitive);
    qInfo() << "Index" << line.indexOf("World");

    //---Modifying & Parsing---
    line.append(" Today Bob said \"Hello\", how are you?");
    qInfo() << "Escape" << line;

    line.append("\r\n<i>This</i> is HTML <br>");
    qInfo() << "HTML" << line.toHtmlEscaped();

    line.replace("?", "!");
    qInfo() << "Replaced" << line;

    qInfo() << "Upper" << line.toUpper();
    qInfo() << "Lower" << line.toLower();
    qInfo() << "Mid" << line.mid(3,5);

    QStringList list = line.split("\n");
    foreach(QString item, list) {
        qInfo() << "item" << item.trimmed();
    }

    //---Conversion---
    std::cout << "std " << line.toStdString() << std::endl;
    qInfo() << "UTF8" << line.toUtf8();
    qInfo() << "Base64" << line.toUtf8().toBase64();
    qInfo() << "Hex" << line.toUtf8().toHex();

    //---Not a QObject---
    test(line);

    return a.exec();
}
