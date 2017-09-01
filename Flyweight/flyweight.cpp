#include "flyweight.h"

Flyweight::Flyweight(QString extrinsic) :
    _extrinsic(extrinsic)
{

}
QString Flyweight::getName() const
{
    return _name;
}

void Flyweight::setName(const QString &value)
{
    _name = value;
}
QString Flyweight::getLocation() const
{
    return _location;
}

void Flyweight::setLocation(const QString &value)
{
    _location = value;
}
QString Flyweight::getExtrinsic() const
{
    return _extrinsic;
}

void Flyweight::setExtrinsic(const QString &value)
{
    _extrinsic = value;
}

ConcreteFlyweight::ConcreteFlyweight(QString extrinsic) :
    Flyweight(extrinsic)
{

}

void ConcreteFlyweight::operate()
{
    qDebug() << "ConcreteFlyweight::operate()" << getName() << getLocation();
}


UnsharedConcreteFlyweight::UnsharedConcreteFlyweight(QString extrinsic) :
    Flyweight(extrinsic)
{

}

void UnsharedConcreteFlyweight::operate()
{
    qDebug() << getName() << getLocation() << "UnsharedConcreteFlyweight::operate()";
}

Flyweight *FlyweightFactory::getFlayweight(QString extrinsic)
{
    Flyweight *result = NULL;
    if (_flyweightMap.contains(extrinsic)) {
        qDebug() << "copy class" << extrinsic;
        result = _flyweightMap.value(extrinsic);
    } else {
        qDebug() << "new class"<< extrinsic;
        result = new ConcreteFlyweight(extrinsic);
        _flyweightMap[extrinsic] = result;
    }
    return result;
}
