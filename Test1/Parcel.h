//
// Created by cocol on 31/03/2022.
//

#ifndef TEST1_PARCEL_H
#define TEST1_PARCEL_H


#include <string>
#include "Drone.h"
class Parcel
{
private:
    int _parcelId = 0;
    double _weight = 0;
    std::string _description = "";
    Drone *associated = nullptr;
public:
    Parcel ( ) = default;

    Parcel(int parcelId, double weight, const std::string &description);

    Parcel ( const Parcel& orig );

    virtual ~Parcel ( );

    void setDescription ( std::string newD );

    std::string getDescription ( ) const;

    void setWeight ( double newW );

    double getWeight ( ) const;

    void setParcelId ( int newPId );

    int getParcelId ( ) const;

    Drone *getAssociated() const;

    void setAssociated(Drone &associated);
};


#endif //TEST1_PARCEL_H
