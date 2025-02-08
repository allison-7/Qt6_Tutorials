#include <QCoreApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream qin(stdin);
    QTextStream qout(stdout);

    qout << "Please enter your name: " << Qt::endl;

    //Reading
    QString name = qin.readLine();

    //Flushing
    qout << "You entered: " << name << "\n";
    qout << "Enter your age ";
    qout.flush();

    //Example
    bool ok;
    int age = qin.readLine().toInt(&ok);
    if (ok) {
        qout << "You are " << age << " years old";
    } else {
        qout << "You have failed to enter a valid number";
    }
    qout.flush();

    return a.exec();
}
