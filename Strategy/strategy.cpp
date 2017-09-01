#include "strategy.h"

Strategy::Strategy()
{

}



OpenStrategy::OpenStrategy()
{

}

void OpenStrategy::operate()
{
    qDebug() << "OpenStrategy operate()";
}


LightStrategy::LightStrategy()
{

}

void LightStrategy::operate()
{
    qDebug() << "LightStrategy operate()";
}


KillStrategy::KillStrategy()
{

}

void KillStrategy::operate()
{
    qDebug() << "KillStrategy operate()";
}


Context::Context(Strategy *strategy) :
    _strategy(strategy)
{

}

void Context::operate()
{
    _strategy->operate();
}
/*
template <class T>
Operation<T>::Operation()
{

}

template <class T>
PlusOperation<T>::PlusOperation()
{

}

template <class T>
T PlusOperation<T>::exec(T left, T right)
{
    return (left + right);
}

template <class T>
MinusOperation<T>::MinusOperation()
{

}

template <class T>
T MinusOperation<T>::exec(T left, T right)
{
    return (left - right);
}

template <class T>
MultiplyOperation<T>::MultiplyOperation()
{

}

template <class T>
T MultiplyOperation<T>::exec(T left, T right)
{
    return (left * right);
}

template <class T>
DivideOperation<T>::DivideOperation()
{

}

template <class T>
T DivideOperation<T>::exec(T left, T right)
{
    return (left / right);
}

//template <class T>
//Calcuator<T>::Calcuator(Operation<T> *operation) :
//    _operation(operation)
//{

//}

template <class T>
Calcuator<T>::Calcuator()
{

}

template <class T>
void Calcuator<T>::setOperation(Operation<T> *operation)
{
    if (_operation != NULL) {
        qDebug() << "delete _operation";
        delete _operation;
    }
    _operation = operation;
}

template <class T>
T Calcuator<T>::exec(T left, T right, OperationType operationType)
{
    switch (operationType) {
    case plusition:
        setOperation(new PlusOperation<T>);
        break;
    case minustion:
        setOperation(new MinusOperation<T>);
        break;
    case multiplication:
        setOperation(new MultiplyOperation<T>);
        break;
    case division:
        setOperation(new DivideOperation<T>);
        break;
    }

    return _operation->exec(left,right);
}

*/
