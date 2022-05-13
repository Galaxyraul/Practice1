//
// Created by Galaxyraul on 13/05/2022.
//

#include "RentedDrone.h"

RentedDrone::RentedDrone(int nPt, double nMl, const std::string &nT, const std::string &nRd, const std::string &company,
                         float dailyFee) : Drone(nPt, nMl, nT, nRd), _company(company), _dailyFee(dailyFee) {}

const std::string &RentedDrone::getCompany() const {
    return _company;
}

void RentedDrone::setCompany(const std::string &company) {
    RentedDrone::_company = company;
}

float RentedDrone::getDailyFee() const {
    return _dailyFee;
}

void RentedDrone::setDailyFee(float dailyFee) {
    RentedDrone::_dailyFee = dailyFee;
}

RentedDrone::~RentedDrone() {

}

RentedDrone::RentedDrone(const std::string &company, float dailyFee) : _company(company), _dailyFee(dailyFee) {}

RentedDrone::RentedDrone(const RentedDrone &orig):_company(orig._company),_dailyFee(orig._dailyFee) {

}

float RentedDrone::getCost(int numdays) {
    return _dailyFee*numdays;
}
