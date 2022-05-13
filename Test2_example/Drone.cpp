/*
 * File:   Dron.cpp
 * Author: Juanma
 *
 * Created on 4 de abril de 2021, 18:48
 */

#include "Drone.h"

Drone::Drone ( int nPT, double nML, std::string nT, std::string nRD ):
                                                            _plateNumber ( nPT )
                                                          , _maximumLoad ( nML )
                                                          , _type ( nT )
                                                     , _registrationDate ( nRD )
{ }

Drone::Drone ( const Drone& orig ) : _plateNumber ( orig._plateNumber )
                                   , _maximumLoad ( orig._maximumLoad )
                                   , _type ( orig._type )
                                   , _registrationDate ( orig._registrationDate )
{ }

Drone::~Drone ( )
{ }

void Drone::setRegistrationDate ( std::string nRegDate )
{
   this->_registrationDate = nRegDate;
}

std::string Drone::getRegistrationDate ( ) const
{
   return _registrationDate;
}

void Drone::setType ( std::string nType )
{
   this->_type = nType;
}

std::string Drone::getType ( ) const
{
   return _type;
}

void Drone::setMaximumLoad ( double nMaxLoad )
{
   this->_maximumLoad = nMaxLoad;
}

double Drone::getMaximumLoad ( ) const
{
   return _maximumLoad;
}

void Drone::setPlateNumber ( int nPN )
{
   this->_plateNumber = nPN;
}

int Drone::getPlateNumber ( ) const
{
   return _plateNumber;
}

float Drone::getCost ( int numDays )
{
   return ( 20.0 * numDays );
}

