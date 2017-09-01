#ifndef CHAINOFRESPONSIBILITY_H
#define CHAINOFRESPONSIBILITY_H

#include <QString>
#include <QDebug>

enum HandleLever {
    FatherLever,
    HusbandLever,
    SonLever
};

class IWomen
{
public:
    IWomen();
    virtual HandleLever handleLever() = 0;
    virtual QString request() = 0;
};

class Women : public IWomen
{
public:
    Women();
    Women(HandleLever handleLever,QString request);

    HandleLever handleLever();
    void setHandleLever(const HandleLever &handleLever);

    QString request();
    void setRequest(const QString &request);

private:
    HandleLever _handleLever;
    QString _request;
};

class Handle
{
public:
    Handle(HandleLever handleLever);

    void setNextHandle(Handle *nextHandle);
    void handleMsg(IWomen *women);

protected:
    virtual void response(IWomen *women) = 0;

private:
    HandleLever _handleLever;
    Handle *_nextHandle;
};

class Father : public Handle
{
public:
    Father();

protected:
    virtual void response(IWomen *women);
};

class Husband : public Handle
{
public:
    Husband();

protected:
    virtual void response(IWomen *women);
};

class Son : public Handle
{
public:
    Son();

protected:
    virtual void response(IWomen *women);
};

class ChainOfResponsibility
{
public:
    ChainOfResponsibility();
};

#endif // CHAINOFRESPONSIBILITY_H
