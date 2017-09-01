#include "templatemethod.h"

TemplateMethod::TemplateMethod()
{

}

void TemplateMethod::test()
{
    say();
}



SayHello::SayHello()
{

}

void SayHello::say()
{
    qDebug() << "hello";
}


SayWorld::SayWorld()
{

}

void SayWorld::say()
{
    qDebug() << "world";
}
