#ifndef BRIGE_H
#define BRIGE_H

#include <QDebug>

class Implementor
{
public:
    Implementor();

    virtual void beProducted();
    virtual void beSelled();
};

class Abstraction
{
public:
    Abstraction(Implementor *implementor);

    Implementor *getImplementor() const;
    void setImplementor(Implementor *value);

    void makeMoney();

    virtual void test(QString txt) = 0;

private:
    Implementor *_implementor;
};

class RefinedAbstraction : public Abstraction
{
public:
    RefinedAbstraction(Implementor *implementor);

    virtual void test(QString txt);
};

class ConcreteImplementor : public Implementor
{
public:
    ConcreteImplementor();
    virtual void beProducted();
    virtual void beSelled();
};

class Brige
{
public:
    Brige();
};

#endif // BRIGE_H
