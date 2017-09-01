#ifndef MEMENTO_H
#define MEMENTO_H

#include <QDebug>
#include <QMap>

class Memento
{
public:
    Memento(QMap<QString,QString> stateMap);

    QMap<QString, QString> getStateMap() const;
    void setStateMap(const QMap<QString, QString> &value);

private:
    QMap<QString,QString> _stateMap;
};

class Originator
{
public:
    Originator() {}

    QString getState_1() const;
    void setState_1(QString value);

    QString getState_2() const;
    void setState_2(QString value);

    QString getState_3() const;
    void setState_3(QString value);

    Memento *createMemento();
    void restoreMemento(Memento *memento);

    void test();

private:
    QString state_1;
    QString state_2;
    QString state_3;
};

class BeanUtils
{
public:
    BeanUtils() {}
    static QMap<QString,QString> backupProp(Originator *originator);
    static void restoreProp(Originator *originator,QMap<QString,QString> prop);

private:
    QString state_1,state_2,state_3;
};

class Caretaker
{
     //发起人对象
private:
    Memento *_menento;

public:
    Caretaker() {}

    Memento *menento() const;
    void setMenento(Memento *menento);
};

#endif // MEMENTO_H
