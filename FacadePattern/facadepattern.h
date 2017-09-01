#ifndef FACADEPATTERN_H
#define FACADEPATTERN_H

#include <QDebug>
#include <QString>

class AbstractLetterProcess
{
public:
    AbstractLetterProcess() {}
    //首先要写信的内容
    virtual void writeContext (QString context) = 0 ;
    //其次写信封
    virtual void fillEnvelope (QString address) = 0 ;
    //把信放到信封里
    virtual void letterInotoEnvelope () = 0 ;
    //然后邮递
    virtual void sendLetter () = 0 ;
};

class LetterProcess : public AbstractLetterProcess
{
public:
    LetterProcess() {}
    //首先要写信的内容
    virtual void writeContext (QString context);
    //其次写信封
    virtual void fillEnvelope (QString address);
    //把信放到信封里
    virtual void letterInotoEnvelope ();
    //然后邮递
    virtual void sendLetter ();
};

class PoliceCheck
{
public:
    PoliceCheck() {}

    void check(QString say);
};

class FacadePattern
{
public:
    FacadePattern();

    void sendLetter();

private:
    AbstractLetterProcess *_letterProcess;
    PoliceCheck *_police;
};

#endif // FACADEPATTERN_H
