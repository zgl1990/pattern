#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <QDebug>
#include <QString>

class Prototype
{
public:
    Prototype();

    virtual Prototype *clone() = 0;
    virtual void test() = 0;

    QString name() const;
    void setName(const QString &name);

private:
    QString _name;
};

class ConcreatePrototypeHello : public Prototype
{
public:
    ConcreatePrototypeHello();

    virtual Prototype *clone();
    virtual void test();
};

class ConcreatePrototypeWorld : public Prototype
{
public:
    ConcreatePrototypeWorld();

    virtual Prototype *clone();
    virtual void test();
};

#endif // PROTOTYPE_H
