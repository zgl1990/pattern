#include "observer.h"
/*
Observer::Observer()
{

}

HanFeiZi::HanFeiZi()
{

}

void HanFeiZi::haveBreakfast()
{
    qDebug() << "HanFeiZi haveBreakfast()";
    this->notifyObserver("chifan");
}

void HanFeiZi::playGame()
{
    qDebug() << "HanFeiZi playGame()";
    this->notifyObserver("playgame");
}

void HanFeiZi::sleep()
{
    qDebug() << "HanFeiZi sleep()";
    this->notifyObserver("sleep");
}

void HanFeiZi::addObserver(Observer *observer)
{
    this->_observerList.append(observer);
}

void HanFeiZi::delObserver(Observer *observer)
{
    this->_observerList.removeOne(observer);
}

void HanFeiZi::notifyObserver(QString msg)
{

}


void LiSi::update(QString msg)
{
    qDebug() << "LiSi update(QString msg)" << msg;
}
*/


Observer::Observer()
{

}


Observable::Observable()
{

}


LiSiObserver::LiSiObserver()
{

}

void LiSiObserver::update(QString msg)
{
    qDebug() << "LiSiObserver update(QString msg)" << msg << "LiSi";
}


HelloObserver::HelloObserver()
{

}

void HelloObserver::update(QString msg)
{
    qDebug() << "HelloObserver update(QString msg)" << msg << "Hello";
}


CryObserver::CryObserver()
{

}

void CryObserver::update(QString msg)
{
    qDebug() << "CryObserver update(QString msg)" << msg << "Cry";
}


HanFeiZi::HanFeiZi()
{

}

void HanFeiZi::addObserver(Observer *observer)
{
    _observerList.append(observer);
}

void HanFeiZi::delObserver(Observer *observer)
{
    _observerList.removeOne(observer);
}

void HanFeiZi::notifyObserver(int index, QString msg)
{
    if (_observerList.size() > 0) {
        if (index < (_observerList.size() - 1)) {
            _observerList.at(index)->update(msg);
        } else {
            qDebug() << index << _observerList.size()
                     << "index >= (_observerList.size() - 1)";
        }
    } else {
        qDebug() << "_observerList.size()=" << _observerList.size();
    }
}

void HanFeiZi::notifyObserver(QString msg)
{
    if (_observerList.size() > 0) { //no need
        foreach (Observer *tmp, _observerList) {
            tmp->update(msg);
        }
    } else {
        qDebug() << "_observerList.size() == 0";
    }
}

void HanFeiZi::play()
{
    qDebug() << "HanFeiZi play()" << "mhxy";
    notifyObserver("play Game");
}

void HanFeiZi::sleep()
{
    qDebug() << "HanFeiZi sleep()";
    notifyObserver("sleep");
}
