#-------------------------------------------------
#
# Project created by QtCreator 2015-11-10T14:21:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pattern
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Single/single.cpp \
    Factory/factory.cpp \
    AbstractFactory/abstractfactory.cpp \
    Template/templatemethod.cpp \
    Build/build.cpp \
    Proxy/proxy.cpp \
    Prototype/prototype.cpp \
    Mediator/mediator.cpp \
    Command/command.cpp \
    ChainOfResponsibility/chainofresponsibility.cpp \
    Decorator/decorator.cpp \
    Strategy/strategy.cpp \
    Adapter/adapter.cpp \
    Iterater/iterater.cpp \
    Composite/composite.cpp \
    Observer/observer.cpp \
    Calcuator/calcuator.cpp \
    FacadePattern/facadepattern.cpp \
    Memento/memento.cpp \
    Visitor/visitor.cpp \
    State/state.cpp \
    Expression/expression.cpp \
    Flyweight/flyweight.cpp \
    Brige/brige.cpp

HEADERS  += mainwindow.h \
    Single/single.h \
    Factory/factory.h \
    AbstractFactory/abstractfactory.h \
    Template/templatemethod.h \
    Build/build.h \
    Proxy/proxy.h \
    Prototype/prototype.h \
    Mediator/mediator.h \
    Command/command.h \
    ChainOfResponsibility/chainofresponsibility.h \
    Decorator/decorator.h \
    Strategy/strategy.h \
    Adapter/adapter.h \
    Iterater/iterater.h \
    Composite/composite.h \
    Observer/observer.h \
    Calcuator/calcuator.h \
    FacadePattern/facadepattern.h \
    Memento/memento.h \
    Visitor/visitor.h \
    State/state.h \
    Expression/expression.h \
    Flyweight/flyweight.h \
    Brige/brige.h

#CONFIG += c++11
