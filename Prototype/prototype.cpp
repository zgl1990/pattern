#include "prototype.h"

Prototype::Prototype()
{
    setName("zgl");
}
QString Prototype::name() const
{
    return _name;
}

void Prototype::setName(const QString &name)
{
    _name = name;
}




ConcreatePrototypeHello::ConcreatePrototypeHello()
{

}

Prototype *ConcreatePrototypeHello::clone()
{
    return new ConcreatePrototypeHello;
}

void ConcreatePrototypeHello::test()
{
    qDebug() << "hello" << " " << name();
}


ConcreatePrototypeWorld::ConcreatePrototypeWorld()
{

}

Prototype *ConcreatePrototypeWorld::clone()
{
    return new ConcreatePrototypeWorld;
}

void ConcreatePrototypeWorld::test()
{
    qDebug() << "world" << " " << name();
}
