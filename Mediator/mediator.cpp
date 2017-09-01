#include "mediator.h"

Mediator::Mediator()
{

}

void Mediator::execute(handleType handletype)
{
    switch (handletype) {
    case PurchaseType:
        _purchase->test();
        break;
    case SaleType:
        _sale->test();
        break;
    case StockType:
        _stock->test();
        break;
    }
}



AbstractMediator::AbstractMediator()
{
    _purchase = new Purchase(this);
    _sale = new Sale(this);
    _stock = new Stock(this);
}

Person::Person(AbstractMediator *mediator)
{
    _mediator = mediator;
}




Purchase::Purchase(AbstractMediator *mediator):
    Person(mediator)
{

}

void Purchase::test()
{
    qDebug() << "purchase test";
}


Sale::Sale(AbstractMediator *mediator):
    Person(mediator)
{

}

void Sale::test()
{
    qDebug() << "sale test";
}


Stock::Stock(AbstractMediator *mediator):
    Person(mediator)
{

}

void Stock::test()
{
    qDebug() << "stock test";
}
