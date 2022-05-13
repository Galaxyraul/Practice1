/*
 * File:   Paquete.cpp
 * Author: Juanma
 *
 * Created on 4 de abril de 2021, 18:49
 */
#include <stdexcept>

#include "Parcel.h"

Parcel::Parcel ( const Parcel& orig ) : _parcelId ( orig._parcelId )
                                      , _weight ( orig._weight )
                                      , _description ( orig._description )
{ }

Parcel::~Parcel ( )
{ }

void Parcel::setDescription ( std::string nDesc )
{
   this->_description = nDesc;
}

std::string Parcel::getDescription ( ) const
{
   return _description;
}

void Parcel::setWeight ( double nW )
{
   this->_weight = nW;
}

double Parcel::getWeight ( ) const
{
   return _weight;
}

void Parcel::setParcelId ( int nPID )
{
   this->_parcelId = nPID;
}

int Parcel::getParcelId ( ) const
{
   return _parcelId;
}

Drone* Parcel::getCarrier ( ) const
{
   return _carrier;
}

/**
 * @brief Changes the carrier of the parcel
 * @param newC Drone to carry the parcel
 * @pre newC Has to point to a valid Drone object
 * @post The parcel carrier changes to the new drone
 * @throw std::invalid_argument If the maximum load of the drone is less than
 *        the parcel weight
 */
void Parcel::setCarrier ( Drone* newC )
{
   if ( newC->getMaximumLoad () < _weight )
   {
      throw std::invalid_argument ( "[Parcel::setCarrier]: drone unable to carry"
                                    " the parcel" );
   }

   this->_carrier = newC;
}