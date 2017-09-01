#include "proxy.h"

Proxy::Proxy()
{

}

Proxy::Proxy(IGamePlay *gamePlay)
{
    _gameplay = gamePlay;
}

Proxy::Proxy(QString user)
{
    _gameplay = new GamePlay(this,user);
}

bool Proxy::login(QString name, QString passwd)
{
    return _gameplay->login(name,passwd);
}

void Proxy::play()
{
    _gameplay->play();
}

void Proxy::upgrade()
{
    _gameplay->upgrade();
}



IGamePlay::IGamePlay()
{

}


GamePlay::GamePlay()
{

}

GamePlay::GamePlay(QString user)
{
    _user = user;
}

GamePlay::GamePlay(IGamePlay *gameplayer, QString user)
{
    if (gameplayer == NULL) {
        qDebug() << "create error";
    } else {
        _user = user;
    }
}

bool GamePlay::login(QString name, QString passwd)
{
    qDebug() << "User+name+Passwd=" << _user << " " << name << " " << passwd;
    return true;
}

void GamePlay::play()
{
    qDebug() << "play game";
}

void GamePlay::upgrade()
{
    qDebug() << "++1 upgrade";
}
