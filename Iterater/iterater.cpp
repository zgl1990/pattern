#include "iterater.h"

Iterater::Iterater()
{

}



AbstractProject::AbstractProject()
{

}


TestProject::TestProject()
{

}

TestProject::TestProject(QString name, int count, int money) :
    _name(name),_count(count),_money(money)
{

}

void TestProject::addProject(QString name, int count, int money)
{
//    qDebug() << __FILE__ << name << count << money;
    this->_projectList.append(new TestProject(name,count,money));
}

QString TestProject::getProjectInfo()
{
    QString result = "";
    result += ("ProjectName=" + _name);
    result += (" countPerson=" + QString::number(_count));
    result += (" money=" + QString::number(_money));
    return result;
}

IprojectIterater *TestProject::iterater()
{
    return new ProjectIterater(_projectList);
}


IprojectIterater::IprojectIterater()
{

}


ProjectIterater::ProjectIterater(QList<AbstractProject *> projectList) :
    currentIndex(0),_projectList(projectList)
{

}

bool ProjectIterater::hasNext()
{
    qDebug() << currentIndex << _projectList.size() << "-------";
    return (currentIndex < _projectList.size());
}

AbstractProject *ProjectIterater::next()
{
    return _projectList.at(currentIndex++);
}
