#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QDebug>

class AbstractMediator;
class Mediator;

enum handleType {
    PurchaseType,
    SaleType,
    StockType
};

class Person
{
public:
    Person(AbstractMediator *mediator);

private:
    AbstractMediator *_mediator;
};

class Purchase : public Person
{
public:
    Purchase(AbstractMediator *mediator);

    void test();
};

class Sale : public Person
{
public:
    Sale(AbstractMediator *mediator);

    void test();
};

class Stock : public Person
{
public:
    Stock(AbstractMediator *mediator);

    void test();
};

class AbstractMediator
{
public:
    AbstractMediator();

    virtual void execute(handleType handletype) = 0;

protected:
    Purchase *_purchase;
    Sale *_sale;
    Stock *_stock;
};

class Mediator : public AbstractMediator
{
public:
    Mediator();

    virtual void execute(handleType handletype);
};

#endif // MEDIATOR_H
