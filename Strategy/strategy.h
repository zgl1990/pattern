#ifndef STRATEGY_H
#define STRATEGY_H

#include <QDebug>

class Strategy
{
public:
    Strategy();
    virtual void operate() = 0;
};

class OpenStrategy : public Strategy
{
public:
    OpenStrategy();
    void operate();
};

class LightStrategy : public Strategy
{
public:
    LightStrategy();
    void operate();
};

class KillStrategy : public Strategy
{
public:
    KillStrategy();
    void operate();
};

class Context
{
public:
    Context(Strategy *strategy);

    void operate();

private:
    Strategy *_strategy;
};

//------------------------------
/*
enum OperationType{
    plusition, // +
    minustion, // -
    multiplication, // *
    division // /
};

template <class T>
class Operation
{
public:
    Operation();
    virtual int exec(int left,int right) = 0;
};

template <class T>
class PlusOperation : public Operation<T>
{
public:
    PlusOperation();
    T exec(T left,T right);
};

template <class T>
class MinusOperation : public Operation<T>
{
public:
    MinusOperation();
    T exec(T left,T right);
};

template <class T>
class MultiplyOperation : public Operation<T>
{
public:
    MultiplyOperation();
    T exec(T left,T right);
};

template <class T>
class DivideOperation : public Operation<T>
{
public:
    DivideOperation();
    T exec(T left,T right);
};

template <class T>
class Calcuator
{
public:
//    Calcuator(Operation<T> *operation);
    Calcuator();

    T exec(T left,T right,OperationType operationType);

private:
    void setOperation(Operation<T> *operation);
    Operation<T> *_operation;

};
*/
#endif // STRATEGY_H
