#ifndef OBSERVER_H
#define OBSERVER_H

#include <QDebug>
#include <QList>

/*
class AbstractHanFeiZi
{
public:
    AbstractHanFeiZi(){}

    virtual void haveBreakfast(){}
    virtual void playGame(){}
    virtual void sleep(){}
};

class AbstractLiSi
{
public:
    AbstractLiSi() {}

    virtual void update(QString) {}
};

class LiSi : public AbstractLiSi
{
public:
    LiSi() {}

    virtual void update(QString msg);
};

//观察者
class Observer
{
public:
    Observer();
};

//被观察者
class Observable
{
public:
    Observable();
    virtual void addObserver(Observer *observer) = 0;
    virtual void delObserver(Observer *observer) = 0;
    virtual void notifyObserver(QString msg) = 0;
};


class HanFeiZi : public AbstractHanFeiZi , Observable
{
public:
    HanFeiZi();
    virtual void haveBreakfast();
    virtual void playGame();
    virtual void sleep();

    virtual void addObserver(Observer *observer);
    virtual void delObserver(Observer *observer);
    virtual void notifyObserver(QString msg);

private:
    QList <Observer *> _observerList;
};
*/

//观察者
class Observer
{
public:
    Observer();

    virtual void update(QString msg) = 0;
};

//被观察者
class Observable
{
public:
    Observable();
    virtual void addObserver(Observer *) {}
    virtual void delObserver(Observer *) {}
    virtual void notifyObserver(QString) {}
};

class LiSiObserver : public Observer
{
public:
    LiSiObserver();
    virtual void update(QString msg);
};

class HelloObserver : public Observer
{
public:
    HelloObserver();
    virtual void update(QString msg);
};

class CryObserver : public Observer
{
public:
    CryObserver();
    virtual void update(QString msg);
};

class AbstractHanFeiZi
{
public:
    AbstractHanFeiZi(){}
    virtual void play(){}
    virtual void sleep(){}
};

class HanFeiZi : public AbstractHanFeiZi,Observable
{
public:
    HanFeiZi();

    virtual void addObserver(Observer *observer);
    virtual void delObserver(Observer *observer);
    virtual void notifyObserver(int index,QString msg);
    virtual void notifyObserver(QString msg);
    virtual void play();
    virtual void sleep();

private:
    QList <Observer *> _observerList;
};

#endif // OBSERVER_H
