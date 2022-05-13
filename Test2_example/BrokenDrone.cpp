//
// Created by Galaxyraul on 13/05/2022.
//

#include "BrokenDrone.h"
#include "FixingError.h"

BrokenDrone::BrokenDrone(int nPt, double nMl, const std::string &nT, const std::string &nRd, int breakdownSeverity,
                         float fixingCost, int expectedFixingTime) : Drone(nPt, nMl, nT, nRd),
                                                                     _breakdownSeverity(breakdownSeverity),
                                                                     _fixingCost(fixingCost),
                                                                     _expectedFixingTime(expectedFixingTime) {
    if(_expectedFixingTime < 0){
        _expectedFixingTime = 0;
        throw FixingError("The drone repairment time has to be greater than 0");
    }
}

int BrokenDrone::getBreakdownSeverity() const {
    return _breakdownSeverity;
}

void BrokenDrone::setBreakdownSeverity(int breakdownSeverity) {
    _breakdownSeverity = breakdownSeverity;
}

float BrokenDrone::getFixingCost() const {
    return _fixingCost;
}

void BrokenDrone::setFixingCost(float fixingCost) {
    _fixingCost = fixingCost;
}

int BrokenDrone::getExpectedFixingTime() const {
    return _expectedFixingTime;
}

void BrokenDrone::setExpectedFixingTime(int expectedFixingTime) {
    _expectedFixingTime = expectedFixingTime;
}

BrokenDrone::~BrokenDrone() {

}

BrokenDrone::BrokenDrone(int breakdownSeverity, float fixingCost, int expectedFixingTime) : _breakdownSeverity(
        breakdownSeverity), _fixingCost(fixingCost), _expectedFixingTime(expectedFixingTime) {
    if(_expectedFixingTime < 0){
        _expectedFixingTime = 0;
        throw FixingError("The drone repairment time has to be greater than 0");
    }
}

BrokenDrone::BrokenDrone(const BrokenDrone &orig) :_breakdownSeverity(orig._breakdownSeverity),_expectedFixingTime(orig._expectedFixingTime),_fixingCost(orig._fixingCost){
}

float BrokenDrone::getCost(int numdays) {
    return _fixingCost*_breakdownSeverity*numdays;
}
