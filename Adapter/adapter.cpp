#include "adapter.h"

//Adapter::Adapter()
//{

//}

Adapter::Adapter(AbstractInterfaceUserInfo *interfaceUserInfo) :
    _interfaceUserInfo(interfaceUserInfo)
{

}

UserInfo::UserInfo()
{

}

QString UserInfo::getUserName() const
{
    return userName;
}

void UserInfo::setUserName(const QString &value)
{
    userName = value;
}
QString UserInfo::getHomeAddress() const
{
    return homeAddress;
}

void UserInfo::setHomeAddress(const QString &value)
{
    homeAddress = value;
}
QString UserInfo::getMobileNum() const
{
    return mobileNum;
}

void UserInfo::setMobileNum(const QString &value)
{
    mobileNum = value;
}
QString UserInfo::getJopPosition() const
{
    return jopPosition;
}

void UserInfo::setJopPosition(const QString &value)
{
    jopPosition = value;
}



AbstractInterfaceUserInfo::AbstractInterfaceUserInfo()
{

}


InterfaceUserInfo::InterfaceUserInfo()
{

}
QMap<QString, QString> InterfaceUserInfo::getUserBaseInfo() const
{
    return userBaseInfo;
}

void InterfaceUserInfo::setUserBaseInfo(const QMap<QString, QString> &value)
{
    userBaseInfo = value;
}
QMap<QString, QString> InterfaceUserInfo::getUserOfficeInfo() const
{
    return userOfficeInfo;
}

void InterfaceUserInfo::setUserOfficeInfo(const QMap<QString, QString> &value)
{
    userOfficeInfo = value;
}
QMap<QString, QString> InterfaceUserInfo::getUserHomeInfo() const
{
    return userHomeInfo;
}

void InterfaceUserInfo::setUserHomeInfo(const QMap<QString, QString> &value)
{
    userHomeInfo = value;
}






AbstractUserInfo::AbstractUserInfo()
{

}

AbstractInterfaceUserInfo *Adapter::getInterfaceUserInfo() const
{
    return _interfaceUserInfo;
}

void Adapter::setInterfaceUserInfo(AbstractInterfaceUserInfo *value)
{
    _interfaceUserInfo = value;
}

QString Adapter::getUserName() const
{
    return _interfaceUserInfo->getUserBaseInfo().value(USERNAME);
}

void Adapter::setUserName(const QString &value)
{
    userName = value;
}

QString Adapter::getHomeAddress() const
{
    return _interfaceUserInfo->getUserBaseInfo().value(HOMEADDRESS);
}

void Adapter::setHomeAddress(const QString &value)
{
    homeAddress = value;
}

QString Adapter::getMobileNum() const
{
    return _interfaceUserInfo->getUserBaseInfo().value(MOBILENUM);
}

void Adapter::setMobileNum(const QString &value)
{
    mobileNum = value;
}

QString Adapter::getJopPosition() const
{
    return _interfaceUserInfo->getUserBaseInfo().value(JOPPOSITON);
}

void Adapter::setJopPosition(const QString &value)
{
    jopPosition = value;
}
/*
QString Adapter::getInterfaceUserName(const QMap<QString, QString> &value) const
{
    return value.key(USERNAME);
}

QString Adapter::getInterfaceHomeAddress(const QMap<QString, QString> &value) const
{
    return value.key(HOMEADDRESS);
}

QString Adapter::getInterfaceMobileNum(const QMap<QString, QString> &value) const
{
    return value.key(MOBILENUM);
}

QString Adapter::getInterfaceJopPosition(const QMap<QString, QString> &value) const
{
    return value.key(JOPPOSITON);
}
*/
