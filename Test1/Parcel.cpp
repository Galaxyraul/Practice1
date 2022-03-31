//
// Created by cocol on 31/03/2022.
//

#include "Parcel.h"
#include <iostream>
#include <string>

Parcel::Parcel ( const Parcel& orig ): _parcelId ( orig._parcelId )
        , _weight ( orig._weight )
        , _description ( orig._description )
{ }

Parcel::~Parcel ( ) { }

void Parcel::setDescription ( std::string newD )
{
    this->_description = newD;
}

std::string Parcel::getDescription ( ) const
{
    return _description;
}

void Parcel::setWeight ( double newW )
{
    this->_weight = newW;
}

double Parcel::getWeight ( ) const
{
    return _weight;
}

void Parcel::setParcelId ( int newPId )
{
    this->_parcelId = newPId;
}

int Parcel::getParcelId ( ) const
{
    return _parcelId;
}

Parcel::Parcel(int parcelId, double weight, const std::string &description) : _parcelId(parcelId), _weight(weight),
                                                                              _description(description) {}

Drone *Parcel::getAssociated() const {
    return associated;
}
/**
 * @brief setter of the
 * @param[in] associated address of the drones that is going to be set
 * @throw[out] string The cause of the error and where it occured
 */
void Parcel::setAssociated(Drone &associated) {
    if(associated.getMaximumLoad() < _weight){
        throw std::invalid_argument("Parcel.cpp::sendPackage:The load cannot be send by the drone change it");
    }
    Parcel::associated = &associated;
}

