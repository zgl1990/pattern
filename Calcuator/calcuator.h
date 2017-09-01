#ifndef CALCUATOR_H
#define CALCUATOR_H

#include <qlist.h>
#include <qmap.h>

template <class T> inline T plusition(T left, T right)
{
    return left + right;
}

template <class T> inline T minustion(T left, T right)
{
    return left - right;
}

template <class T> inline T multiplication(T left, T right)
{
    return left * right;
}

template <class T> inline T division(T left, T right)
{
    return left / right;
}

template <class T>
class Operation
{
public:
    Operation() {}
    virtual T exec(T left,T right) = 0;
};

template <class T>
class PlusOperation : public Operation<T>
{
public:
    PlusOperation() {}
    T exec(T left,T right) {return plusition(left,right);}
};

template <class T>
class MinusOperation : public Operation<T>
{
public:
    MinusOperation() {}
    T exec(T left,T right) {return minustion(left,right);}
};

template <class T>
class MultiplyOperation : public Operation<T>
{
public:
    MultiplyOperation() {}
    T exec(T left,T right) {return multiplication(left,right);}
};

template <class T>
class DivideOperation : public Operation<T>
{
public:
    DivideOperation() {}
    T exec(T left,T right) {return division(left,right);}
};

template <class T>
class Calcuator
{
public:
    Calcuator(Operation<T> *operation) {_operation = operation;}

    inline T exec(T left,T right) {return _operation->exec(left,right);}

private:
    Operation<T> *_operation;
};

#endif // CALCUATOR_H
