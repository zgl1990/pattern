#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QMap>
#include <QList>
#include <QDebug>

class Expression
{
public:
    Expression();

    virtual int interpreter(QMap<QString,int> value) = 0;
};

class VarExpression : public Expression
{
public:
    VarExpression(QString key);
    int interpreter(QMap<QString,int> value);

private:
    QString _key;
};

class SymbolExpression : public Expression
{
public:
    SymbolExpression(Expression *left,Expression *right);
    virtual int interpreter(QMap<QString,int> value) = 0;

protected:
    Expression *_left;
    Expression *_right;
};

class AddExpression : public SymbolExpression
{
public:
    AddExpression(Expression *left,Expression *right);
    virtual int interpreter(QMap<QString,int> value);
};

class SubExpression : public SymbolExpression
{
public:
    SubExpression(Expression *left,Expression *right);
    virtual int interpreter(QMap<QString,int> value);
};

class TestExpression
{
public:
    TestExpression(QString expStr);
};

#endif // EXPRESSION_H
