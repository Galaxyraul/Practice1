//
// Created by cocol on 31/03/2022.
//

#ifndef TEST1_DRONE_H
#define TEST1_DRONE_H


#include <string>

class Drone
{
private:
    int _plateNumber = 0;
    double _maximumLoad = 0;
    std::string _type = "";
    std::string _registrationDate = "";

public:
    Drone ( ) = default;
    Drone ( const Drone& orig );
    virtual ~Drone ( );
    void setRegistrationDate ( std::string newRD );
    std::string getRegistrationDate ( ) const;
    void setType ( std::string newT );
    std::string getType ( ) const;
    void setMaximumLoad ( double newML );
    double getMaximumLoad ( ) const;
    void setPlateNumber ( int newPN );
    int getPlateNumber ( ) const;
};

#endif //TEST1_DRONE_H
