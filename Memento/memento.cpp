#include "memento.h"

Memento::Memento(QMap<QString, QString> stateMap) :
    _stateMap(stateMap)
{

}
QMap<QString, QString> Memento::getStateMap() const
{
    return _stateMap;
}

void Memento::setStateMap(const QMap<QString, QString> &value)
{
    _stateMap = value;
}



QString Originator::getState_1() const
{
    return state_1;
}

void Originator::setState_1(QString value)
{
    state_1 = value;
}
QString Originator::getState_2() const
{
    return state_2;
}

void Originator::setState_2(QString value)
{
    state_2 = value;
}
QString Originator::getState_3() const
{
    return state_3;
}

void Originator::setState_3(QString value)
{
    state_3 = value;
}

Memento *Originator::createMemento()
{
    return new Memento(BeanUtils::backupProp(this));
}

void Originator::restoreMemento(Memento *memento)
{
    BeanUtils::restoreProp(this,memento->getStateMap());
}

void Originator::test()
{
    qDebug() << state_1 << state_2 << state_3;
}

QMap<QString, QString> BeanUtils::backupProp(Originator *originator)
{
    QMap<QString, QString> result;
    result["state_1"] = originator->getState_1();
    result["state_2"] = originator->getState_2();
    result["state_3"] = originator->getState_3();
    return result;
}

void BeanUtils::restoreProp(Originator *originator, QMap<QString, QString> prop)
{
    originator->setState_1(prop.value("state_1"));
    originator->setState_2(prop.value("state_2"));
    originator->setState_3(prop.value("state_3"));
}


Memento *Caretaker::menento() const
{
    return _menento;
}

void Caretaker::setMenento(Memento *menento)
{
    _menento = menento;
}
