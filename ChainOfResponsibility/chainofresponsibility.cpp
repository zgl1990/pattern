#include "chainofresponsibility.h"

ChainOfResponsibility::ChainOfResponsibility()
{

}



IWomen::IWomen()
{

}


Women::Women()
{

}

Women::Women(HandleLever handleLever, QString request)
{
    _request = request;
    _handleLever = handleLever;
    qDebug() << "women " << handleLever << request;
}
HandleLever Women::handleLever()
{
    return _handleLever;
}

void Women::setHandleLever(const HandleLever &handleLever)
{
    _handleLever = handleLever;
}
QString Women::request()
{
    return _request;
}

void Women::setRequest(const QString &request)
{
    _request = request;
}


Handle::Handle(HandleLever handleLever)
{
    _handleLever = handleLever;
}
void Handle::setNextHandle(Handle *nextHandle)
{
    _nextHandle = nextHandle;
}

void Handle::handleMsg(IWomen *women)
{
    qDebug() << this->_handleLever << "--" << women->handleLever();
    if (this->_handleLever == women->handleLever()) {
        this->response(women);
    } else {
        if (this->_nextHandle != NULL) {
            this->_nextHandle->handleMsg(women);
        } else {
            qDebug() << "next is NULL";
        }
    }
}


Father::Father() :
    Handle(FatherLever)
{

}

void Father::response(IWomen *women)
{
    qDebug() << "ask Father";
    qDebug() << women->request() << "--- Father";
}


Husband::Husband() :
    Handle(HusbandLever)
{

}

void Husband::response(IWomen *women)
{
    qDebug() << "ask Husband";
    qDebug() << women->request() << "--- Husband";
}


Son::Son() :
    Handle(SonLever)
{

}

void Son::response(IWomen *women)
{
    qDebug() << "ask Son";
    qDebug() << women->request() << "--- Son";
}
