#ifndef SINGLE_H
#define SINGLE_H

#include <QDebug>

class Single
{
public:
    static Single *getSingle();
private:
    Single();

private:
    static Single *_single;
};

#endif // SINGLE_H
