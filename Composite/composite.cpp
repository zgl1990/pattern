#include "composite.h"

Composite::Composite()
{

}



Corp::Corp(QString name, QString position, int salary) :
    _name(name),_position(position),_salary(salary)
{

}

void Corp::test()
{
    qDebug() << _name << _position << _salary;
}


LeafCorp::LeafCorp(QString name, QString position, int salary) :
    Corp(name,position,salary)
{

}


BranchCorp::BranchCorp(QString name, QString position, int salary) :
    Corp(name,position,salary)
{

}
QList<Corp *> BranchCorp::getCorpList() const
{
    return _corpList;
}

void BranchCorp::append(Corp *corp)
{
    this->_corpList.append(corp);
}



void Test::test(BranchCorp *testCorp)
{
    QList <Corp *> tmpList = testCorp->getCorpList();
    foreach (Corp *corp, tmpList) {
        corp->test();
    }
}
