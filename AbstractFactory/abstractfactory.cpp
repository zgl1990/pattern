#include "abstractfactory.h"

AbstractFactory::AbstractFactory()
{

}



AbstractSystem::AbstractSystem()
{

}


WindowsSystem::WindowsSystem()
{

}

void WindowsSystem::test()
{
    qDebug() << "WindowsSystem";
}


LinuxSystem::LinuxSystem()
{

}

void LinuxSystem::test()
{
    qDebug() << "LinuxSystem";
}


SystemFactory::SystemFactory()
{

}

WindowsSystem *SystemFactory::createWindows()
{
    return new WindowsSystem;
}

LinuxSystem *SystemFactory::createLinux()
{
    return new LinuxSystem;
}


AbstractSystemFactory::AbstractSystemFactory()
{

}

AbstractSystem *AbstractSystemFactory::createSystem(AbstractSystemFactory::systemType systemtype)
{
    switch (systemtype) {
    case Windows:
        return new WindowsSystem;
    case Linux:
        return new LinuxSystem;
    default:
        return new WindowsSystem;
    }
}
