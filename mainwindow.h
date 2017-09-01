#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QList>
#include <QPushButton>
#include <QStringList>
#include <QGridLayout>
#include <QButtonGroup>
#include <QDebug>

#include "Single/single.h"
#include "Factory/factory.h"
#include "AbstractFactory/abstractfactory.h"
#include "Template/templatemethod.h"
#include "Build/build.h"
#include "Proxy/proxy.h"
#include "Prototype/prototype.h"
#include "Mediator/mediator.h"
#include "Command/command.h"
#include "ChainOfResponsibility/chainofresponsibility.h"
#include "Decorator/decorator.h"
#include "Strategy/strategy.h"
#include "Adapter/adapter.h"
#include "Iterater/iterater.h"
#include "Composite/composite.h"
#include "Observer/observer.h"
#include "Calcuator/calcuator.h"
#include "FacadePattern/facadepattern.h"
#include "Memento/memento.h"
#include "Visitor/visitor.h"
#include "State/state.h"
#include "Expression/expression.h"
#include "Flyweight/flyweight.h"
#include "Brige/brige.h"

#define MVC_COUNT 23

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void btnClickSlot(int index);

private:
    QList<QPushButton *> btnList;
    QButtonGroup *btnGroup;

private:
    void singleTest();
    void factoryTest();
    void abstractfactoryTest();
    void templateMethodTest();
    void buildTest();
    void proxyText();
    void prototypeTest();
    void mediatorTest();
    void commandTest();
    void ChainOfResponsibilityTest();
    void decoratorTest();
    void strategyTest();
    void adapterTest();
    void iteraterTest();
    void compositeTest();
    void observerTest();
    void facadePatternTest();
    void mementoTest();
    void visitorTest();
    void stateTest();
    void expressionTest();
    void flyweightTest();
    void brigeTest();
};

#endif // MAINWINDOW_H
