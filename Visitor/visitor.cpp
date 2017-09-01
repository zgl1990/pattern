#include "visitor.h"

Visitor::Visitor()
{

}

void Visitor::visit(CommonEmployee *commonEmployee)
{
    qDebug() << this->getCommonInfo(commonEmployee);
}

void Visitor::visit(ManagerEmployee *managerEmployee)
{
    qDebug() << this->getManagerInfo(managerEmployee);
}

QString Visitor::getBaseInfo(AbstractEmployee *employee)
{
    QString result = "BaseInfo=";
    result += employee->getName();
    result += QString::number(employee->getAge());
    result += QString::number(employee->getSalary());
    return result;
}

QString Visitor::getCommonInfo(CommonEmployee *employee)
{
    return (getBaseInfo(employee) + "---" + employee->getJop());
}

QString Visitor::getManagerInfo(ManagerEmployee *employee)
{
    return (getBaseInfo(employee) + "---" + employee->getPerformance());
}


QString AbstractEmployee::getName() const
{
    return _name;
}

void AbstractEmployee::setName(const QString &value)
{
    _name = value;
}
int AbstractEmployee::getAge() const
{
    return _age;
}

void AbstractEmployee::setAge(int value)
{
    _age = value;
}
int AbstractEmployee::getSalary() const
{
    return _salary;
}

void AbstractEmployee::setSalary(int value)
{
    _salary = value;
}



QString CommonEmployee::getJop() const
{
    return _jop;
}

void CommonEmployee::setJop(const QString &value)
{
    _jop = value;
}

void CommonEmployee::accept(AbstractVisitor *abstractVisitor)
{
    abstractVisitor->visit(this);
}

void ManagerEmployee::accept(AbstractVisitor *abstractVisitor)
{
    abstractVisitor->visit(this);
}

QString ManagerEmployee::getPerformance() const
{
    return _performance;
}

void ManagerEmployee::setPerformance(const QString &value)
{
    _performance = value;
}
