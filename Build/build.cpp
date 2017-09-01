#include "build.h"

Build::Build()
{

}



CarModel::CarModel()
{

}

void CarModel::run()
{
    for (int i = 0; i < _carSort.size(); i++) {
        switch (_carSort.at(i)) {
        case Start:
            start();
            break;
        case Stop:
            stop();
            break;
        case Alarm:
            alarm();
            break;
        }
    }
}
QList<carSortEnum> CarModel::carSort() const
{
    return _carSort;
}

void CarModel::setCarSort(const QList<carSortEnum> &carSort)
{
    _carSort = carSort;
}

BenzCarModel::BenzCarModel()
{

}

void BenzCarModel::start()
{
    qDebug() << "benz start";
}

void BenzCarModel::stop()
{
    qDebug() << "benz stop";
}

void BenzCarModel::alarm()
{
    qDebug() << "benz alarm";
}


BMWCarModel::BMWCarModel()
{

}

void BMWCarModel::start()
{
    qDebug() << "BMW start";
}

void BMWCarModel::stop()
{
    qDebug() << "BMW stop";
}

void BMWCarModel::alarm()
{
    qDebug() << "BMW alarm";
}


BenzBuild::BenzBuild()
{
    _benzCarModel = new BenzCarModel;
}

void BenzBuild::setCarSort(const QList<carSortEnum> &carSort)
{
    _benzCarModel->setCarSort(carSort);
}

CarModel *BenzBuild::getCarModel()
{
    return _benzCarModel;
}


BMWBuild::BMWBuild()
{
    _bMWCarModel = new BMWCarModel;
}

void BMWBuild::setCarSort(const QList<carSortEnum> &carSort)
{
    _bMWCarModel->setCarSort(carSort);
}

CarModel *BMWBuild::getCarModel()
{
    return _bMWCarModel;
}


BuildCar::BuildCar()
{
    _benzBuild = new BenzBuild;
    _bMWBuild = new BMWBuild;
}

CarModel *BuildCar::getBenzCarModel_1()
{
    _carSort.clear();
    _carSort.append(Start);
    _carSort.append(Stop);
    _carSort.append(Alarm);
    _benzBuild->setCarSort(_carSort);
    return _benzBuild->getCarModel();
}

CarModel *BuildCar::getBenzCarModel_2()
{
    _carSort.clear();
    _carSort.append(Alarm);
    _carSort.append(Start);
    _carSort.append(Stop);
    _benzBuild->setCarSort(_carSort);
    return _benzBuild->getCarModel();
}

CarModel *BuildCar::getBMWCarModel_1()
{
    _carSort.clear();
    _carSort.append(Stop);
    _carSort.append(Alarm);
    _carSort.append(Start);
    _bMWBuild->setCarSort(_carSort);
    return _bMWBuild->getCarModel();
}

CarModel *BuildCar::getBMWCarModel_2()
{
    _carSort.clear();
    _carSort.append(Start);
    _bMWBuild->setCarSort(_carSort);
    return _bMWBuild->getCarModel();
}
