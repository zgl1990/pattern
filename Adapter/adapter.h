#ifndef ADAPTER_H
#define ADAPTER_H

#include <QString>
#include <QStringList>
#include <QDebug>
#include <QMap>

const QString USERNAME = "userName";
const QString HOMEADDRESS = "homeAddress";
const QString MOBILENUM = "mobileNum";
const QString JOPPOSITON = "jopPosition";


//#define USERNAME  "userName"
//#define HOMEADDRESS  "homeAddress"
//#define MOBILENUM  "mobileNum"
//#define JOPPOSITON  "jopPosition"

class AbstractUserInfo
{
public:
    AbstractUserInfo();
    virtual QString getUserName() const = 0;
    virtual void setUserName(const QString &value) = 0;

    virtual QString getHomeAddress() const = 0;
    virtual void setHomeAddress(const QString &value) = 0;

    virtual QString getMobileNum() const = 0;
    virtual void setMobileNum(const QString &value) = 0;

    virtual QString getJopPosition() const = 0;
    virtual void setJopPosition(const QString &value) = 0;

protected:
    QString userName;
    QString homeAddress;
    QString mobileNum;
    QString jopPosition;
};

class UserInfo : public AbstractUserInfo
{
public:
    UserInfo();

    QString getUserName() const;
    void setUserName(const QString &value);

    QString getHomeAddress() const;
    void setHomeAddress(const QString &value);

    QString getMobileNum() const;
    void setMobileNum(const QString &value);

    QString getJopPosition() const;
    void setJopPosition(const QString &value);
};

class AbstractInterfaceUserInfo
{
public:
    AbstractInterfaceUserInfo();

    virtual QMap<QString, QString> getUserBaseInfo() const = 0;
    virtual void setUserBaseInfo(const QMap<QString, QString> &value) = 0;

    virtual QMap<QString, QString> getUserOfficeInfo() const = 0;
    virtual void setUserOfficeInfo(const QMap<QString, QString> &value) = 0;

    virtual QMap<QString, QString> getUserHomeInfo() const = 0;
    virtual void setUserHomeInfo(const QMap<QString, QString> &value) = 0;
protected:
    QMap<QString,QString> userBaseInfo;
    QMap<QString,QString> userOfficeInfo;
    QMap<QString,QString> userHomeInfo;
};

class InterfaceUserInfo : public AbstractInterfaceUserInfo
{
public:
    InterfaceUserInfo();


    QMap<QString, QString> getUserBaseInfo() const;
    void setUserBaseInfo(const QMap<QString, QString> &value);

    QMap<QString, QString> getUserOfficeInfo() const;
    void setUserOfficeInfo(const QMap<QString, QString> &value);

    QMap<QString, QString> getUserHomeInfo() const;
    void setUserHomeInfo(const QMap<QString, QString> &value);
};

class Adapter : public AbstractUserInfo
{
public:
//    Adapter();
    Adapter(AbstractInterfaceUserInfo *interfaceUserInfo);

    AbstractInterfaceUserInfo *getInterfaceUserInfo() const;

/*
    QString getInterfaceUserName(const QMap<QString, QString> &value) const;

    QString getInterfaceHomeAddress(const QMap<QString, QString> &value) const;

    QString getInterfaceMobileNum(const QMap<QString, QString> &value) const;

    QString getInterfaceJopPosition(const QMap<QString, QString> &value) const;
*/
    QString getUserName() const;
    void setUserName(const QString &value);

    QString getHomeAddress() const;
    void setHomeAddress(const QString &value);

    QString getMobileNum() const;
    void setMobileNum(const QString &value);

    QString getJopPosition() const;
    void setJopPosition(const QString &value);

private:
    AbstractInterfaceUserInfo *_interfaceUserInfo;
    void setInterfaceUserInfo(AbstractInterfaceUserInfo *value);
};

#endif // ADAPTER_H
