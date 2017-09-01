#ifndef DECORATOR_H
#define DECORATOR_H

#include <QDebug>

class SchoolReport
{
public:
    SchoolReport();
    virtual void report() = 0;
    virtual void say() = 0;
};

class FirstGradeSchoolReport : public SchoolReport
{
public:
    FirstGradeSchoolReport();
    virtual void report();
    virtual void say();
};

class Decorator : public SchoolReport
{
public:
    Decorator(SchoolReport *schoolReport);

    virtual void report();
    virtual void say();

protected:
    SchoolReport *_schoolReport;
};

class HighScoreDecorator : public Decorator
{
public:
    HighScoreDecorator(SchoolReport *schoolReport);

    virtual void report();

private:
    void reportHighScore();
};

class SortDecorator : public Decorator
{
public:
    SortDecorator(SchoolReport *schoolReport);

    virtual void report();

private:
    void reportSort();
};

#endif // DECORATOR_H
