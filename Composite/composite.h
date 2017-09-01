#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <QString>
#include <QDebug>
#include <QList>

class Corp
{
public:
    Corp(QString name,QString position,int salary);

    void test();

private:
    QString _name;
    QString _position;
    int _salary;
};

class LeafCorp : public Corp
{
public:
    LeafCorp(QString name,QString position,int salary);
};

class BranchCorp : public Corp
{
public:
    BranchCorp(QString name,QString position,int salary);

    QList<Corp *> getCorpList() const;
    void append(Corp *corp);

private:
    QList <Corp *> _corpList;
};

class Composite
{
public:
    Composite();
};

class Test
{
public:
    Test() {}
    static void test(BranchCorp *testCorp);
};

#endif // COMPOSITE_H
