//
// Created by cocol on 31/03/2022.
//

#include "ControlTower.h"
#include <string>
#include <iostream>

int ControlTower::_numberOfDrones = 0;

ControlTower::ControlTower(int towerId, double controlArea, const std::string &location) : _towerId(towerId),
                                                                                           _controlArea(controlArea),
                                                                                           _location(location)
{
    for(int i = 0; i < _MAXSIZE; ++i){
        drones[i] = nullptr;
    }
}

int ControlTower::getTowerId() const {
    return _towerId;
}

void ControlTower::setTowerId(int towerId) {
    _towerId = towerId;
}

double ControlTower::getControlArea() const {
    return _controlArea;
}

void ControlTower::setControlArea(double controlArea) {
    if(controlArea < 0){
        throw std::invalid_argument("controlTower.cpp::setControlArea:The controlArea cannot be negative");
    }
    _controlArea = controlArea;
}

const std::string &ControlTower::getLocation() const {
    return _location;
}

void ControlTower::setLocation(const std::string &location) {
    _location = location;
}

ControlTower::ControlTower(const ControlTower &orig):_towerId(orig._towerId),
                                                     _controlArea(orig._controlArea),
                                                     _location(orig._location){
    int k = 0;
    for(int i = 0; i < _MAXSIZE;++i){
        drones[i] = nullptr;
    }
    for(int i = 0; i < _MAXSIZE;++i){
        if (orig.drones[i] != nullptr){
            drones[k] = orig.drones[i];
            k++;
        }
    }
}

const Drone &ControlTower::getDrone(int which) const {
    int pos = 0;
    bool match = false;
    for (int i = 0; (i < _MAXSIZE) && (!match);++i){
        match = which = drones[i]->getPlateNumber();
        pos = match? i:0;
    }
    if(!match){
        throw std::invalid_argument("ControlTower.cpp::getDrone:There is no drone with that identifier");
    }
    return *drones[pos];
}

const void ControlTower::addDrone(  Drone &n)  {
    if(_numberOfDrones >= _MAXSIZE){
        throw std::invalid_argument("ControlTower.cpp::setDrone:The tower is full");
    }
    for(int i = 0; i < _MAXSIZE;++i){
        if(drones[i] == nullptr){
            drones[i] = &n;
            _numberOfDrones++;
            break;
        }
    }

}

Drone *ControlTower::bestDrone() {
    int posBest = 0;
    int k = _numberOfDrones;
    for(int i = 0; i <_MAXSIZE && k > 0;++i) {
        if (drones[i] != nullptr){
            posBest = (drones[i]->getMaximumLoad() > drones[posBest]->getMaximumLoad()) ? i : posBest;
            k--;
        }
    }
    return drones[posBest];
}