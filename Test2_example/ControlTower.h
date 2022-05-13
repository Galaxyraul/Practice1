/* 
 * File:   ControlTower.h
 * Author: Juanma
 *
 * Created on 4 de abril de 2021, 19:21
 */

#ifndef CONTROLTOWER_H
#define CONTROLTOWER_H

#include "Drone.h"
#include "Parcel.h"

class ControlTower
{
 public:
   static const int MAX_DRONES = 1000;

 private:
   int _towerId = 0;
   double _controlArea = 0;
   std::string _location = "";
   Drone* _drones[MAX_DRONES];
   int _nDrones = 0;

 public:
   ControlTower ( ) = default;
   ControlTower ( int nTowerId, double nControlArea, std::string nLocation );
   ControlTower ( const ControlTower& orig );
   virtual ~ControlTower ( );
   void setLocation ( std::string nLocation );
   std::string getLocation ( ) const;
   void setControlArea ( double nControlArea );
   double getControlArea ( ) const;
   void setTowerId ( int _idTorre );
   int getTowerId ( ) const;
   int getNDrones ( ) const;
   Drone* getDrone ( int which ) const;
   void addDrone ( Drone* d );
   Drone* bestDrone ( );
   Drone* searchDrone(float cost);
};

#endif /* CONTROLTOWER_H */

