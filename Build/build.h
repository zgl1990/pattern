#ifndef BUILD_H
#define BUILD_H

#include <QDebug>
#include <QStringList>
#include <QList>

enum carSortEnum{
    Start,
    Stop,
    Alarm
};

class CarModel
{
public:
    CarModel();

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void alarm() = 0;

    void run();

    QList<carSortEnum> carSort() const;
    void setCarSort(const QList<carSortEnum> &carSort);

private:
    QList <carSortEnum> _carSort;
};

class BenzCarModel : public CarModel
{
public:
    BenzCarModel();

    virtual void start();
    virtual void stop();
    virtual void alarm();
};

class BMWCarModel : public CarModel
{
public:
    BMWCarModel();

    virtual void start();
    virtual void stop();
    virtual void alarm();
};

class Build
{
public:
    Build();

    virtual void setCarSort(const QList<carSortEnum> &carSort) = 0;
    virtual CarModel *getCarModel() = 0;
};

class BenzBuild : public Build
{
public:
    BenzBuild();

    virtual void setCarSort(const QList<carSortEnum> &carSort);
    virtual CarModel *getCarModel();

private:
    BenzCarModel *_benzCarModel;
};

class BMWBuild : public Build
{
public:
    BMWBuild();

    virtual void setCarSort(const QList<carSortEnum> &carSort);
    virtual CarModel *getCarModel();

private:
    BMWCarModel *_bMWCarModel;
};

class BuildCar
{
public:
    BuildCar();

    CarModel *getBenzCarModel_1();
    CarModel *getBenzCarModel_2();
    CarModel *getBMWCarModel_1();
    CarModel *getBMWCarModel_2();

private:
    BMWBuild *_bMWBuild;
    BenzBuild *_benzBuild;
    QList <carSortEnum> _carSort;
};

#endif // BUILD_H
