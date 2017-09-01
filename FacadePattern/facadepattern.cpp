#include "facadepattern.h"

FacadePattern::FacadePattern() :
    _letterProcess(new LetterProcess),
    _police(new PoliceCheck)
{

}

void FacadePattern::sendLetter()
{
    _letterProcess->writeContext("hello");
    _letterProcess->fillEnvelope("cq");
    _police->check("yes");
    _letterProcess->letterInotoEnvelope();
    _letterProcess->sendLetter();
}

void LetterProcess::writeContext(QString context)
{
    qDebug() << "LetterProcess writeContext" << context;
}

void LetterProcess::fillEnvelope(QString address)
{
    qDebug() << "LetterProcess fillEnvelope" << address;
}

void LetterProcess::letterInotoEnvelope()
{
    qDebug() << "LetterProcess letterInotoEnvelope()";
}

void LetterProcess::sendLetter()
{
    qDebug() << "LetterProcess sendLetter()";
}


void PoliceCheck::check(QString say)
{
    qDebug() << "police check say" << say;
}
