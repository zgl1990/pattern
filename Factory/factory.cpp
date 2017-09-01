#include "factory.h"

Factory::Factory()
{

}

Product::Product()
{

}


IphoneProduct::IphoneProduct()
{

}

void IphoneProduct::test()
{
    qDebug() << "iphone";
}


ZteProduct::ZteProduct()
{

}

void ZteProduct::test()
{
    qDebug() << "Zte";
}


IphoneFactory::IphoneFactory()
{

}

IphoneProduct *IphoneFactory::createProduct()
{
    return new IphoneProduct;
}


ZteFactory::ZteFactory()
{

}

ZteProduct *ZteFactory::createProduct()
{
    return new ZteProduct;
}

/*
AllFactory::AllFactory()
{
    phoneType = Iphone;
}

Product *AllFactory::createProduct()
{
    switch (getPhoneType()) {
    case Iphone:
        return new IphoneProduct;
    case Zte:
        return new ZteProduct;
    }
}

AllFactory::productType AllFactory::getPhoneType() const
{
    return phoneType;
}

void AllFactory::setPhoneType(const productType &value)
{
    phoneType = value;
}

*/
