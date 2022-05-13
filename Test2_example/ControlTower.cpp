/*
 * File:   ControlTower.cpp
 * Author: Juanma
 *
 * Created on 4 de abril de 2021, 19:21
 */
#include <stdexcept>

#include "ControlTower.h"
#include "BrokenDrone.h"
#include "RentedDrone.h"

ControlTower::ControlTower ( int nTowerId, double nControlArea
                             , std::string nLocation ) : _towerId ( nTowerId )
                                                       , _controlArea ( nControlArea )
                                                       , _location ( nLocation )
{
   for ( int i = 0; i < MAX_DRONES; i++ )
   {
      _drones[i] = nullptr;
   }
}

ControlTower::ControlTower ( const ControlTower& orig ) : _towerId ( orig._towerId )
                                                        , _controlArea ( orig._controlArea )
                                                        , _location ( orig._location )
                                                        , _nDrones ( orig._nDrones )
{
   for ( int i = 0; i < MAX_DRONES; i++ )
   {
      _drones[i] = orig._drones[i];
   }
}

ControlTower::~ControlTower ( ) { }

void ControlTower::setLocation ( std::string nLocation )
{
   this->_location = nLocation;
}

std::string ControlTower::getLocation ( ) const
{
   return _location;
}

void ControlTower::setControlArea ( double nControlArea )
{
   if ( nControlArea < 0 )
   {
      throw std::invalid_argument ( "The control area can not be negative" );
   }

   this->_controlArea = nControlArea;
}

double ControlTower::getControlArea ( ) const
{
   return _controlArea;
}

void ControlTower::setTowerId ( int nTowerId )
{
   this->_towerId = nTowerId;
}

int ControlTower::getTowerId ( ) const
{
   return _towerId;
}

int ControlTower::getNDrones ( ) const
{
   return _nDrones;
}

Drone* ControlTower::getDrone ( int which ) const
{
   if ( ( which < 0 ) || ( which >= _nDrones ) )
   {
      throw std::invalid_argument ( "Invalid index" );
   }

   return _drones[which];
}

void ControlTower::addDrone ( Drone* d )
{
   if ( _nDrones == MAX_DRONES )
   {
      throw std::length_error ( "There is no room for more drones" );
   }
   _drones[_nDrones] = d;
   _nDrones++;
}

Drone* ControlTower::bestDrone ( )
{
   int locBest = 0;
   if ( _nDrones > 1 )
   {
      for ( int i = 1; i < _nDrones; i++ )
      {
         if ( _drones[i]->getMaximumLoad ( ) > _drones[locBest]->getMaximumLoad ( ) )
         {
            locBest = i;
         }
      }
   }
   return _drones[locBest];
}

Drone *ControlTower::searchDrone(float cost) {
   int pos=0;
   for(int i= 0;i < _nDrones ;++i){
      if(_drones[i]!= nullptr){
         pos=_drones[pos]->getCost(1) < _drones[i]->getCost(1)?pos:i;
      }
   }
   if(_drones[pos]->getCost(1)>cost){
      return nullptr;
   }
   return _drones[pos];
}

