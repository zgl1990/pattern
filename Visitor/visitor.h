#ifndef VISITOR_H
#define VISITOR_H

#include <QString>
#include <QDebug>

class AbstractVisitor;

class AbstractEmployee
{
public:
    AbstractEmployee() {}

    virtual void accept(AbstractVisitor *abstractVisitor) = 0;

    QString getName() const;
    void setName(const QString &value);

    int getAge() const;
    void setAge(int value);

    int getSalary() const;
    void setSalary(int value);

private:
    QString _name;
    int _age;
    int _salary;
};

class CommonEmployee : public AbstractEmployee
{
public:
    CommonEmployee() {}

    QString getJop() const;
    void setJop(const QString &value);

    virtual void accept(AbstractVisitor *abstractVisitor);

private:
    QString _jop;
};

class ManagerEmployee : public AbstractEmployee
{
public:
    ManagerEmployee() {}


    virtual void accept(AbstractVisitor *abstractVisitor);

    QString getPerformance() const;
    void setPerformance(const QString &value);

private:
    QString _performance;
};

class AbstractVisitor
{
public:
    AbstractVisitor() {}
    virtual void visit(CommonEmployee *commonEmployee) = 0;
    virtual void visit(ManagerEmployee *managerEmployee) = 0;
};

class Visitor : public AbstractVisitor
{
public:
    Visitor();
    virtual void visit(CommonEmployee *commonEmployee);
    virtual void visit(ManagerEmployee *managerEmployee);

private:
    QString getBaseInfo(AbstractEmployee *employee);
    QString getCommonInfo(CommonEmployee *employee);
    QString getManagerInfo(ManagerEmployee *employee);
};

#endif // VISITOR_H
