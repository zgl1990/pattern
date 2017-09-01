#ifndef FACTORY_H
#define FACTORY_H

#include <QDebug>

class Product
{
public:
    Product();

    virtual void test() = 0;
};

class IphoneProduct : public Product
{
public:
    IphoneProduct();

    virtual void test();
};

class ZteProduct : public Product
{
public:
    ZteProduct();

    virtual void test();
};

class Factory
{
public:
    Factory();

    virtual Product *createProduct() = 0;
};

class IphoneFactory : public Factory
{
public:
    IphoneFactory();
    virtual IphoneProduct *createProduct();
};

class ZteFactory : public Factory
{
public:
    ZteFactory();
    virtual ZteProduct *createProduct();
};

//class AllFactory : public Factory
//{
//public:
//    enum productType {
//        Iphone,
//        Zte
//    };

//    AllFactory();
//    virtual Product *createProduct();

//    productType getPhoneType() const;
//    void setPhoneType(const productType &value);

//private:
//    productType phoneType;
//};

#endif // FACTORY_H
