/** 
 * @file Droide.cpp
 * @author Casipro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <sstream>

#include "Droide.h"

using std::string;

int Droide::_numDroides = 0;

Droide::Droide ( )
{ }

Droide::Droide ( string marca, string modelo,int numberOfMissions ): _marca (marca), _modelo (modelo),_numberOfMissions(numberOfMissions)
{
   _numDroides++;
   _idD = _numDroides;
}

Droide::Droide ( const Droide& orig ): _marca(orig._marca), _modelo(orig._modelo),_numberOfMissions(orig.numberOfMissions)
{
   _numDroides++;
   _idD = _numDroides;
}

Droide::~Droide ( )
{ }

int Droide::getIdD ( ) const
{
   return _idD;
}

const Droide&  Droide::setModelo ( string modelo )
{
   this->_modelo = modelo;
    return (*this);
}

string Droide::getModelo ( ) const
{
   return _modelo;
}

const Droide&  Droide::setMarca ( string marca )
{
   this->_marca = marca;
    return (*this);
}

string Droide::getMarca ( ) const
{
   return _marca;
}

string Droide::toCSV () const
{
   std::stringstream aux;

   aux << _marca << " ; "
       << _modelo <<" ; "
       << _numberOfMissions;

   return ( aux.str () );
}

Droide& Droide::operator = ( const Droide& otro )
{
   if ( this != &otro )
   {
      _marca = otro._marca;
      _modelo = otro._modelo;
      _numberOfMissions = otro._numberOfMissions;
   }
   
   return ( *this );
}

const void Droide::fromCSV(std::string CSV) {
    std::stringstream ss;
    ss.str(CSV);
    std::getline(ss,_marca,';');
    std::getline(ss,_modelo,';');
    ss>>_numberOfMissions;
}

int Droide::getNumberOfMissions() const {
    return _numberOfMissions;
}

void Droide::setNumberOfMissions(int numberOfMissions) {
    _numberOfMissions = numberOfMissions;
}

const void Droide::newMission() {
    ++_numberOfMissions;
}

const bool Droide::needsMaintenance() {
    return (_numberOfMissions%10 == 0);
}
