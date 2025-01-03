#include "cat.h"

Cat::Cat(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "Constructed";
}

Cat::~Cat()
{
    qInfo() << this << "Deconstructed";
}

QString Cat::name() const
{
    return this->m_name;
}

void Cat::setName(const QString &name)
{
    this->m_name = name;
}

int Cat::age() const
{
    return this->m_age;
}

void Cat::setAge(int age)
{
    this->m_age = age;
}
