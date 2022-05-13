//
// Created by Galaxyraul on 13/05/2022.
//

#ifndef POOFUSION_GIT_RENTEDDRONE_H
#define POOFUSION_GIT_RENTEDDRONE_H
#include <string>
#include "Drone.h"

class RentedDrone: public Drone{
private:
    std::string _company = "";
    float _dailyFee = 0;
public:
    virtual ~RentedDrone();

    RentedDrone(const std::string &company, float dailyFee);

    RentedDrone(int nPt, double nMl, const std::string &nT, const std::string &nRd, const std::string &company,
                float dailyFee);

    RentedDrone(const RentedDrone& orig);

    const std::string &getCompany() const;

    void setCompany(const std::string &company);

    float getDailyFee() const;

    void setDailyFee(float dailyFee);

    float getCost(int numdays) override;
};


#endif //POOFUSION_GIT_RENTEDDRONE_H
