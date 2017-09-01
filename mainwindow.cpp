#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    btnGroup = new QButtonGroup;
    QStringList mvcNameList;
    mvcNameList.clear();
    mvcNameList << "single" << "factory" << "abstract factory"
                << "templateMethod" << "build" << "proxy"
                << "prototype" << "mediator" << "command"
                << "ChainOfResponsibility" << "Decorator"
                << "Strategy+-*/" << "Adapter" << "Iterater"
                << "Composite //Unkown" << "Observer"
                << "FacadePattern" << "Memento" << "Visitor"
                << "State" << "Interpreter Pattern" << "Flyweight"
                << "Brige";
    QGridLayout *layout = new QGridLayout;
    for (int i = 0; i < MVC_COUNT;i++) {
        btnList.append(new QPushButton(mvcNameList.at(i)));
        layout->addWidget(btnList.at(i),i / 2,i % 2);
        btnGroup->addButton(btnList.at(i),i);
    }
    setLayout(layout);

    connect(btnGroup,SIGNAL(buttonClicked(int)),this,SLOT(btnClickSlot(int)));

}

MainWindow::~MainWindow()
{

}

void MainWindow::btnClickSlot(int index)
{
    qDebug() << index;
    switch (index) {
    case 0:
        singleTest();
        break;
    case 1:
        factoryTest();
        break;
    case 2:
        abstractfactoryTest();
        break;
    case 3:
        templateMethodTest();
        break;
    case 4:
        buildTest();
        break;
    case 5:
        proxyText();
        break;
    case 6:
        prototypeTest();
        break;
    case 7:
        mediatorTest();
        break;
    case 8:
        commandTest();
        break;
    case 9:
        ChainOfResponsibilityTest();
        break;
    case 10:
        decoratorTest();
        break;
    case 11:
        strategyTest();
        break;
    case 12:
        adapterTest();
        break;
    case 13:
        iteraterTest();
        break;
    case 14:
        compositeTest();
        break;
    case 15:
        observerTest();
        break;
    case 16:
        facadePatternTest();
        break;
    case 17:
        mementoTest();
        break;
    case 18:
        visitorTest();
        break;
    case 19:
        stateTest();
        break;
    case 20:
        expressionTest();
        break;
    case 21:
        flyweightTest();
        break;
    case 22:
        brigeTest();
        break;
    default:
        qDebug() << "other index = " << index;
        break;
    }
}

void MainWindow::singleTest()
{
    for (int i = 0; i < 10; i++) {
        Single *single = Single::getSingle();;
        qDebug() << single;
    }
}

void MainWindow::factoryTest()
{
    Factory *_factory = new IphoneFactory;
    _factory->createProduct()->test();
    _factory = new ZteFactory;
    _factory->createProduct()->test();
}

void MainWindow::abstractfactoryTest()
{
    AbstractFactory *_factory = new SystemFactory;
    AbstractSystem *_system = _factory->createLinux();
    _system->test();
    _system = _factory->createWindows();
    _system->test();

    AbstractSystemFactory *tmp = new AbstractSystemFactory;
    _system = tmp->createSystem(AbstractSystemFactory::Windows);
    _system->test();
    _system = tmp->createSystem(AbstractSystemFactory::Linux);
    _system->test();
}

void MainWindow::templateMethodTest()
{
    TemplateMethod *tmp = new SayHello;
    tmp->test();

    tmp = new SayWorld;
    tmp->test();
}

void MainWindow::buildTest()
{
    QList <carSortEnum> carSortList;
    carSortList.clear();
    carSortList.append(Start);
    carSortList.append(Stop);
    carSortList.append(Alarm);
    Build *carBuild = new BenzBuild;
    carBuild->setCarSort(carSortList);
    CarModel *carModel = carBuild->getCarModel();
    carModel->run();
    qDebug() << "--------------------";
    BuildCar *buildCar = new BuildCar;
    buildCar->getBenzCarModel_1()->run();
    qDebug() << "~~~~~~~~~~~";
    buildCar->getBenzCarModel_2()->run();
    qDebug() << "~~~~~~~~~~~";
    buildCar->getBMWCarModel_1()->run();
    qDebug() << "~~~~~~~~~~~";
    buildCar->getBMWCarModel_2()->run();
}

void MainWindow::proxyText()
{
    IGamePlay *gamePlayer = new GamePlay("zgl");
    IGamePlay *gameProxy = new Proxy(gamePlayer);
    gameProxy->login("Galen","123456");
    gameProxy->play();
    gameProxy->upgrade();

    qDebug() << "putong daili";

    gameProxy = new Proxy("zhy");
    gameProxy->login("zd","123456");
    gameProxy->play();
    gameProxy->upgrade();
}

void MainWindow::prototypeTest()
{
    Prototype *prototype1 = new ConcreatePrototypeHello;
    prototype1->test();
    Prototype *prototype2 = prototype1->clone();
    prototype2->setName("zhy");
    prototype2->test();

    Prototype *prototype3 = new ConcreatePrototypeWorld;
    prototype3->test();
    Prototype *prototype4 = prototype3->clone();
    prototype4->setName("zd");
    prototype4->test();

    qDebug() << "----------";
    prototype1->test();
    prototype2->test();
    prototype3->test();
    prototype4->test();
}

void MainWindow::mediatorTest()
{
    AbstractMediator *mediator = new Mediator;
    mediator->execute(SaleType);
    mediator->execute(PurchaseType);
    mediator->execute(StockType);
}

void MainWindow::commandTest()
{
    Invoker *invoker = new Invoker(new AddRequirementCommand);
    invoker->test();
    qDebug() << "------------";
    invoker->setCommand(new DelPageCommand);
    invoker->test();
    qDebug() << "------------";
    invoker->setCommand(new BackCommand);
    invoker->test();
}

void MainWindow::ChainOfResponsibilityTest()
{
    Handle *father = new Father;
    Handle *husband = new Husband;
    Handle *son = new Son;
    father->setNextHandle(husband);
    husband->setNextHandle(son);
    son->setNextHandle(father);
    IWomen *wm = new Women(FatherLever,"sleep");
    husband->handleMsg(wm);
}

void MainWindow::decoratorTest()
{
    SchoolReport *report = new FirstGradeSchoolReport;
    report->report();
    report->say();
    qDebug() << "-------------";
    report = new HighScoreDecorator(report);
    report->report();
    report->say();
    qDebug() << "-------------";
    report = new SortDecorator(report);
    report->report();
    report->say();
}

//template <class T>
void MainWindow::strategyTest()
{
//    Context *tmp = new Context(new OpenStrategy);
//    tmp->operate();

//    qDebug() << "---------------";

    Calcuator<float> *calc = new Calcuator<float>(new PlusOperation<float>);
    qDebug() << calc->exec(1,2) << calc->exec(1.2,2.3) << calc->exec(1,2.3);
}

void MainWindow::adapterTest()
{
    AbstractUserInfo *tmp1 = new UserInfo;
    tmp1->setUserName("zgl");
    tmp1->setHomeAddress("cq");
    tmp1->setMobileNum("15215007527");
    tmp1->setJopPosition("c++");

    qDebug() << tmp1->getUserName();
    qDebug() << tmp1->getHomeAddress();
    qDebug() << tmp1->getMobileNum();
    qDebug() << tmp1->getJopPosition();

    AbstractInterfaceUserInfo *tmp2 = new InterfaceUserInfo;

    QMap<QString,QString> map;
    map[USERNAME] = "zhy";
    map[HOMEADDRESS] = "renhe";
    map[MOBILENUM] = "18580895166";
    map[JOPPOSITON] = "qt";
//    map.k

    tmp2->setUserBaseInfo(map);
    qDebug() << "-----------";
    qDebug() << map[USERNAME] << map[HOMEADDRESS]
                << map[MOBILENUM] << map[JOPPOSITON] << map.value(USERNAME);
    qDebug() << "-----------";
    tmp1 = new Adapter(tmp2);

    qDebug() << tmp1->getUserName();
    qDebug() << tmp1->getHomeAddress();
    qDebug() << tmp1->getMobileNum();
    qDebug() << tmp1->getJopPosition();
}

void MainWindow::iteraterTest()
{
//    AbstractProject *tmp = new TestProject("zgl",10,1000);
    AbstractProject *tmp = new TestProject;
    tmp->addProject("zgl",10,1000);

    for (int i = 0; i < 3;i++) {
        tmp->addProject(("num" + QString::number(i)),20,10);
    }
    IprojectIterater *iter = tmp->iterater();
    while (iter->hasNext()) {
        tmp = iter->next();
        qDebug() << tmp->getProjectInfo();

    }
}

void MainWindow::compositeTest()
{
//    Corp *root = new Corp("zgl","laoban",99999999);
//    root->test();

    BranchCorp *jingli = new BranchCorp("shichang","jingli1",10000);
//    BranchCorp *jingli2 = new BranchCorp("xiaoshou","jingli2",8000);
//    BranchCorp *jingli3 = new BranchCorp("jishu","jingli3",12000);
//    jingli->test();
//    jingli2->test();
//    jingli3->test();

    Corp *leaf1 = new LeafCorp("1","leaf1",6000);
    Corp *leaf2 = new LeafCorp("2","leaf2",5000);
    Corp *leaf3 = new LeafCorp("3","leaf3",4000);

//    leaf1->test();
//    leaf2->test();
//    leaf3->test();

    jingli->append(leaf1);
    jingli->append(leaf2);
    jingli->append(leaf3);

    Test::test(jingli);
    qDebug() << "-----------------------";
}

void MainWindow::observerTest()
{
    HanFeiZi *tmpHanFeizi = new HanFeiZi();

    tmpHanFeizi->play();
    tmpHanFeizi->sleep();

    qDebug() << "----------------";

    Observer *lisi = new LiSiObserver;
    Observer *hello = new HelloObserver;
    Observer *cry = new CryObserver;

    tmpHanFeizi->addObserver(lisi);
    tmpHanFeizi->addObserver(hello);
    tmpHanFeizi->addObserver(cry);

    tmpHanFeizi->play();
    tmpHanFeizi->sleep();

    qDebug() << "----------------";

    tmpHanFeizi->delObserver(hello);
    tmpHanFeizi->play();
    tmpHanFeizi->sleep();
}

void MainWindow::facadePatternTest()
{
    FacadePattern *facade = new FacadePattern;
    facade->sendLetter();
}

void MainWindow::mementoTest()
{
    Originator *ori = new Originator;
    Caretaker *care = new Caretaker;
    ori->setState_1("111");
    ori->setState_2("222");
    ori->setState_3("333");

    ori->test();
    care->setMenento(ori->createMemento());

    ori->setState_1("AAA");
    ori->setState_2("BBB");
    ori->setState_3("CCC");

    ori->test();

    ori->restoreMemento(care->menento());

    ori->test();
}

void MainWindow::visitorTest()
{
    QList<AbstractEmployee *> empList;
    for (int i = 0; i < 6;i++) {
        if ( (i%2)) {
            CommonEmployee *zgl = new CommonEmployee;
            zgl->setName("zgl");
            zgl->setAge(25);
            zgl->setSalary(i);
            zgl->setJop("Code cainiao");
            empList.append(zgl);
        } else {
            CommonEmployee *leader = new CommonEmployee;
            leader->setName("zhuhy");
            leader->setAge(25);
            leader->setSalary(i);
            leader->setJop("team leader");
            empList.append(leader);
        }
    }

    qDebug() << empList.size() << "=size";

    foreach (AbstractEmployee *tmp, empList) {
        tmp->accept(new Visitor);
    }


}

void MainWindow::stateTest()
{
    StateContext *tmp = new StateContext;
    tmp->setState(new ClosingState);
    tmp->open();
    tmp->close();
    tmp->run();
    tmp->stop();
}

void MainWindow::expressionTest()
{
    //TestExpression *tmp = new TestExpression("1+22+33");
}

void MainWindow::flyweightTest()
{
    FlyweightFactory *_fly = new FlyweightFactory;
    for (int i = 0; i < 5; i++) {
        _fly->getFlayweight(QString::number(i));
    }

    qDebug() << "------------";
    _fly->getFlayweight("0");
    _fly->getFlayweight("100");
}

void MainWindow::brigeTest()
{
    Implementor *tmpImplementor = new ConcreteImplementor;
    Abstraction *tmpAbstraction = new RefinedAbstraction(tmpImplementor);
    tmpAbstraction->makeMoney();
    tmpAbstraction->test("123456");
}
