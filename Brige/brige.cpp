#include "brige.h"

Brige::Brige()
{

}


Abstraction::Abstraction(Implementor *implementor) :
    _implementor(implementor)
{

}

Implementor *Abstraction::getImplementor() const
{
    return _implementor;
}

void Abstraction::setImplementor(Implementor *value)
{
    _implementor = value;
}

void Abstraction::makeMoney()
{
    qDebug() << "Abstraction::makeMoney()";
    _implementor->beProducted();
    _implementor->beSelled();
}


Implementor::Implementor()
{

}

void Implementor::beProducted()
{

}

void Implementor::beSelled()
{

}


RefinedAbstraction::RefinedAbstraction(Implementor *implementor) :
    Abstraction(implementor)
{

}

void RefinedAbstraction::test(QString txt)
{
    qDebug() << "RefinedAbstraction::test(QString txt)" << txt;
}

ConcreteImplementor::ConcreteImplementor()
{

}

void ConcreteImplementor::beProducted()
{
    qDebug() << "ConcreteImplementor::beProducted()";
}

void ConcreteImplementor::beSelled()
{
    qDebug() << "ConcreteImplementor::beSelled()";
}
