/* 
 * File:   Parcel.h
 * Author: Juanma
 *
 * Created on 4 de abril de 2021, 18:49
 */

#ifndef PARCEL_H
#define PARCEL_H

#include <string>
#include "Drone.h"

class Parcel
{
 private:
   int _parcelId = 0;
   double _weight = 0;
   std::string _description = "";
   Drone* _carrier = nullptr;
 public:
   Parcel ( ) = default;
   Parcel ( const Parcel& orig );
   virtual ~Parcel ( );
   void setDescription ( std::string nDesc );
   std::string getDescription ( ) const;
   void setWeight ( double nW );
   double getWeight ( ) const;
   void setParcelId ( int nPID );
   int getParcelId ( ) const;
   Drone* getCarrier ( ) const;
   void setCarrier ( Drone* newC );
};

#endif /* PARCEL_H */

