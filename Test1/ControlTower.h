//
// Created by cocol on 31/03/2022.
//

#ifndef TEST1_CONTROLTOWER_H
#define TEST1_CONTROLTOWER_H

#include "Drone.h"
#include <string>


class ControlTower {
    const static int _MAXSIZE = 100;
private:
    static int _numberOfDrones;
    int _towerId = 0;
    double _controlArea = 0;
    std::string _location = "";
    Drone *drones[_MAXSIZE];

public:
    ControlTower(int towerId, double controlArea, const std::string &location);

    ControlTower(const ControlTower& orig);

    int getTowerId() const;

    void setTowerId(int towerId);

    double getControlArea() const;

    void setControlArea(double controlArea);

    const std::string &getLocation() const;

    void setLocation(const std::string &location);

    const Drone& getDrone (int which) const;

    const void addDrone ( Drone& n);

    Drone* bestDrone();


};


#endif //TEST1_CONTROLTOWER_H
