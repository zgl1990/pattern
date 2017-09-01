#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

#include <QDebug>
#include <QMap>

class Flyweight
{
public:
    Flyweight(QString extrinsic);

    QString getName() const;
    void setName(const QString &value);

    QString getLocation() const;
    void setLocation(const QString &value);

    QString getExtrinsic() const;
    void setExtrinsic(const QString &value);

    virtual void operate() = 0;

private:
    QString _name;
    QString _location;

    QString _extrinsic;
};

class FlyweightFactory
{
public:
    FlyweightFactory() {}

    /*static */Flyweight *getFlayweight(QString extrinsic);

private:
    QMap<QString,Flyweight *> _flyweightMap;
};

//具体享元角色
class ConcreteFlyweight : public Flyweight
{
public:
    ConcreteFlyweight(QString extrinsic);

    virtual void operate();
};

//不可共享的享元角色
class UnsharedConcreteFlyweight : public Flyweight
{
public:
    UnsharedConcreteFlyweight(QString extrinsic);
    virtual void operate();
};

#endif // FLYWEIGHT_H
