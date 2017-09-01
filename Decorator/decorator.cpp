#include "decorator.h"

Decorator::Decorator(SchoolReport *schoolReport) :
    _schoolReport(schoolReport)
{

}

void Decorator::report()
{
    _schoolReport->report();
}

void Decorator::say()
{
    _schoolReport->say();
}



SchoolReport::SchoolReport()
{

}


FirstGradeSchoolReport::FirstGradeSchoolReport()
{

}

void FirstGradeSchoolReport::report()
{
    qDebug() << "FirstGradeSchoolReport report()";
}

void FirstGradeSchoolReport::say()
{
    qDebug() << "FirstGradeSchoolReport say()";
}


HighScoreDecorator::HighScoreDecorator(SchoolReport *schoolReport) :
    Decorator(schoolReport)
{

}

void HighScoreDecorator::report()
{
    reportHighScore();
    _schoolReport->report();
}

void HighScoreDecorator::reportHighScore()
{
    qDebug() << "HighScoreDecorator reportHighScore()";
}


SortDecorator::SortDecorator(SchoolReport *schoolReport) :
    Decorator(schoolReport)
{

}

void SortDecorator::report()
{
    reportSort();
    _schoolReport->report();
}

void SortDecorator::reportSort()
{
    qDebug() << "SortDecorator reportSort()";
}
