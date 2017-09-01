#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <QDebug>

class AbstractSystem
{
public:
    AbstractSystem();

    virtual void test() = 0;
};

class WindowsSystem : public AbstractSystem
{
public:
    WindowsSystem();
    virtual void test();
};

class LinuxSystem : public AbstractSystem
{
public:
    LinuxSystem();
    virtual void test();
};

class AbstractFactory
{
public:
    AbstractFactory();
    virtual WindowsSystem *createWindows() = 0;
    virtual LinuxSystem *createLinux() = 0;
};

class SystemFactory : public AbstractFactory
{
public:
    SystemFactory();
    virtual WindowsSystem *createWindows();
    virtual LinuxSystem *createLinux();
};


class AbstractSystemFactory
{
public:
    enum systemType {
        Windows,
        Linux
    };

    AbstractSystemFactory();

    virtual AbstractSystem *createSystem(systemType systemtype);
};

#endif // ABSTRACTFACTORY_H
