#ifndef ITERATER_H
#define ITERATER_H

#include <QDebug>
#include <QList>

class IprojectIterater;

class AbstractProject
{
public:
    AbstractProject();

    virtual void addProject(QString name,int count,int money) = 0;
    virtual QString getProjectInfo() = 0;
    virtual IprojectIterater *iterater() = 0;
};

class TestProject : public AbstractProject
{
public:
    TestProject();
    TestProject(QString name,int count,int money);
    virtual void addProject(QString name,int count,int money);
    virtual QString getProjectInfo();
    virtual IprojectIterater *iterater();

private:
    QString _name;
    int _count;
    int _money;
    QList <AbstractProject *> _projectList;
};

class Iterater
{
public:
    Iterater();
};

class IprojectIterater
{
public:
    IprojectIterater();

    virtual bool hasNext() = 0;
    virtual AbstractProject* next() = 0;
};

class ProjectIterater : public IprojectIterater
{
public:
    ProjectIterater(QList <AbstractProject *> projectList);

    virtual bool hasNext();
    virtual AbstractProject* next();

private:
    QList <AbstractProject *> _projectList;
    int currentIndex;
};

#endif // ITERATER_H
