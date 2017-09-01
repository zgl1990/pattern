#include "expression.h"

Expression::Expression()
{

}



VarExpression::VarExpression(QString key) :
    _key(key)
{

}

int VarExpression::interpreter(QMap<QString, int> value)
{
    return value.value(_key);
}



SymbolExpression::SymbolExpression(Expression *left, Expression *right) :
    _left(left),_right(right)
{

}


AddExpression::AddExpression(Expression *left, Expression *right) :
    SymbolExpression(left,right)
{

}

int AddExpression::interpreter(QMap<QString, int> value)
{
    return (_left->interpreter(value) + _right->interpreter(value));
}


SubExpression::SubExpression(Expression *left, Expression *right) :
    SymbolExpression(left,right)
{

}

int SubExpression::interpreter(QMap<QString, int> value)
{
    return (_left->interpreter(value) - _right->interpreter(value));
}


TestExpression::TestExpression(QString expStr)
{
    QByteArray byteArray = expStr.toLatin1();
    for (int i = 0; i < byteArray.length(); i++)
    {
        switch (byteArray.at(i)) {
        case '+':
            break;
        case '-':
            break;
        default:
            break;
        }
    }
}
