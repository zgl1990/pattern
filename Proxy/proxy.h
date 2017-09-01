#ifndef PROXY_H
#define PROXY_H

#include <QString>
#include <QDebug>

class IGamePlay
{
public:
    IGamePlay();

    virtual bool login(QString name,QString passwd) = 0;
    virtual void play() = 0;
    virtual void upgrade() = 0;
};

class GamePlay : public IGamePlay
{
public:
    GamePlay();
    GamePlay(QString user);

    //普通代理
    GamePlay(IGamePlay *gameplayer,QString user);

    virtual bool login(QString name,QString passwd);
    virtual void play();
    virtual void upgrade();

private:
    QString _user;
};

class Proxy : public IGamePlay
{
public:
    Proxy();
    Proxy(IGamePlay *gamePlay);
    //普通代理
    Proxy(QString user);

    virtual bool login(QString name,QString passwd);
    virtual void play();
    virtual void upgrade();

private:
    IGamePlay *_gameplay;
};

#endif // PROXY_H
