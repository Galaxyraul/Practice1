/* 
 * File:   Drone.h
 * Author: Juanma
 *
 * Created on 4 de abril de 2021, 18:48
 */

#ifndef DRONE_H
#define DRONE_H

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
   Drone ( int nPT, double nML, std::string nT, std::string nRD );
   Drone ( const Drone& orig );
   virtual ~Drone ( );
   void setRegistrationDate ( std::string nRegDate );
   std::string getRegistrationDate ( ) const;
   void setType ( std::string nType );
   std::string getType ( ) const;
   void setMaximumLoad ( double nMaxLoad );
   double getMaximumLoad ( ) const;
   void setPlateNumber ( int nPN );
   int getPlateNumber ( ) const;
   virtual float getCost ( int numDays );
};

#endif /* DRONE_H */

