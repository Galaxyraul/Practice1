//
// Created by Galaxyraul on 13/05/2022.
//

#ifndef POOFUSION_GIT_BROKENDRONE_H
#define POOFUSION_GIT_BROKENDRONE_H
#include "Drone.h"
#include <string>

class BrokenDrone: public Drone{
private:
    int _breakdownSeverity = 0;
    float _fixingCost = 0;
    int _expectedFixingTime = 0;
public:
    int getBreakdownSeverity() const;

    void setBreakdownSeverity(int breakdownSeverity);

    BrokenDrone(int breakdownSeverity, float fixingCost, int expectedFixingTime);

    float getFixingCost() const;

    void setFixingCost(float fixingCost);

    int getExpectedFixingTime() const;

    void setExpectedFixingTime(int expectedFixingTime);

    BrokenDrone(int nPt, double nMl, const std::string &nT, const std::string &nRd, int breakdownSeverity,
                float fixingCost, int expectedFixingTime);

    BrokenDrone(const BrokenDrone& orig);
    virtual ~BrokenDrone();

    float getCost(int numdays) override;
};


#endif //POOFUSION_GIT_BROKENDRONE_H
