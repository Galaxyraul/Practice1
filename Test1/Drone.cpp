//
// Created by cocol on 31/03/2022.
//

#include "Drone.h"
Drone::Drone ( const Drone& orig ) : _plateNumber ( orig._plateNumber )
        , _maximumLoad ( orig._maximumLoad )
        , _type ( orig._type )
        , _registrationDate ( orig._registrationDate )
{ }

Drone::~Drone ( )
{ }

void Drone::setRegistrationDate ( std::string newRD )
{
    this->_registrationDate = newRD;
}

std::string Drone::getRegistrationDate ( ) const
{
    return _registrationDate;
}

void Drone::setType ( std::string newT )
{
    this->_type = newT;
}

std::string Drone::getType ( ) const
{
    return _type;
}

void Drone::setMaximumLoad ( double newML )
{
    this->_maximumLoad = newML;
}

double Drone::getMaximumLoad ( ) const
{
    return _maximumLoad;
}

void Drone::setPlateNumber ( int newPN )
{
    this->_plateNumber = newPN;
}

int Drone::getPlateNumber ( ) const
{
    return _plateNumber;
}

