#include <QCoreApplication>
#include <QDebug>
#include <QSysInfo>

void compileTime() {
#ifdef Q_OS_LINUX
    qInfo() << "Hello from Linux";
#endif

#ifdef Q_OS_WIN
    qInfo() << "Hello from Windows";
#endif
}

void runTime() {
    QSysInfo info;
    qInfo() << "Product name" << info.prettyProductName();
    qInfo() << "Product type" << info.productType();
    qInfo() << "Product version" << info.productVersion();
    qInfo() << "Machine host name" << info.machineUniqueId();
    qInfo() << "Machine unique ID" << info.machineUniqueId();
    qInfo() << "Current cpu architecture" << info.currentCpuArchitecture();
    qInfo() << "Build cpu architecture" << info.buildCpuArchitecture();
    qInfo() << "BuildAbi" << info.buildAbi();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //At compile time
    compileTime();

    //At run time
    runTime();

    return a.exec();
}
