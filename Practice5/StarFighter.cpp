/** 
 * @file StarFighter.cpp
 * @author Casipro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>
#include "StarFighter.h"

using std::string;

int StarFighter::_numStarFighters = 0;

StarFighter::StarFighter ( )
{ }

StarFighter::StarFighter ( string marca, string modelo ): _marca (marca),
                                                          _modelo(modelo)
{
   _numStarFighters++;
   _idSF = _numStarFighters;
}

StarFighter::StarFighter ( const StarFighter& orig ): _marca(orig._marca),
                                                      _modelo(orig._modelo),
                                                      _numPlazas(orig._numPlazas)
{
   _numStarFighters++;
   _idSF = _numStarFighters;
}

StarFighter::~StarFighter ( )
{ }

/**
 * @todo Aquí hay que añadir la comprobación del parámetro y lanzar la excepción
 *       correspondiente. El número de plazas no puede ser <= 0
 */
const StarFighter& StarFighter::setNumPlazas ( int numPlazas )
{
   this->_numPlazas = numPlazas;
    return (*this);
}

int StarFighter::getNumPlazas ( ) const
{
   return _numPlazas;
}

const StarFighter& StarFighter::setModelo ( string modelo )
{
   this->_modelo = modelo;
    return (*this);
}

string StarFighter::getModelo ( ) const
{
   return _modelo;
}

const StarFighter& StarFighter::setMarca ( string marca )
{
   this->_marca = marca;
    return (*this);
}

string StarFighter::getMarca ( ) const
{
   return _marca;
}

int StarFighter::getIdSF ( ) const
{
   return _idSF;
}

string StarFighter::toCSV () const
{
   std::stringstream aux;

   aux << _marca << " ; "
       << _modelo << " ; "
       << _numPlazas;

   return ( aux.str () );
}

StarFighter& StarFighter::operator = (const StarFighter& otro)
{
   if ( this != &otro )
   {
      _marca = otro._marca;
      _modelo = otro._modelo;
      _numPlazas = otro._numPlazas;
   }
   
   return ( *this );
}

const void StarFighter::fromCSV(std::string CSV) {
    std::stringstream ss;
    ss.str(CSV);
    std::getline(ss,_marca,';');
    std::getline(ss,_modelo,';');
    ss>>_numPlazas;
    ss.ignore(1);

}
