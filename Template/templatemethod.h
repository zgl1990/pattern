#ifndef TEMPLATEMETHOD_H
#define TEMPLATEMETHOD_H

#include <QDebug>

class TemplateMethod
{
public:
    TemplateMethod();

    virtual void say() = 0;
    void test();
};

class SayHello : public TemplateMethod
{
public:
    SayHello();
    virtual void say();
};

class SayWorld : public TemplateMethod
{
public:
    SayWorld();
    virtual void say();
};

#endif // TEMPLATEMETHOD_H
