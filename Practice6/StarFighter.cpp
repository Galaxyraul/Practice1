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

StarFighter::StarFighter ()
{
    for(int i = 0; i < 50; ++i){
        _components[i] = nullptr;
    }
}

StarFighter::StarFighter ( string marca, string modelo ): _marca (marca),
                                                          _modelo(modelo)

{
    for(int i = 0; i < 50; ++i){
        _components[i] = nullptr;
    }
   _numStarFighters++;
   _idSF = _numStarFighters;
}

StarFighter::StarFighter ( const StarFighter& orig ): _marca(orig._marca),
                                                      _modelo(orig._modelo),
                                                      _numPlazas(orig._numPlazas),
                                                      _numOfComponents(orig._numOfComponents)
{

    for(int i = 0; i < 50; ++i){
        if(i < _numOfComponents){
            _components[i] = new Part(*orig._components[i]);
        } else{
            _components[i] = nullptr;
        }
    }

   _numStarFighters++;
   _idSF = _numStarFighters;
}

StarFighter::~StarFighter ( )
{
    for(int i = 0; i < 50; ++i){
        if(_components[i]!= nullptr){
            delete _components[i];
            _components[i] = nullptr;
        }
    }
}

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

StarFighter& StarFighter::operator= (const StarFighter& otro)
{
   if ( this != &otro )
   {
      _marca = otro._marca;
      _modelo = otro._modelo;
      _numPlazas = otro._numPlazas;
      if(_numOfComponents > 0){
          for(int i = 0; i < 50; ++i){
              if(_components[i]!= nullptr){
                  delete _components[i];
              }
          }
      }
      try {
          for (int i = 0; i < 50; ++i) {
              if (i < otro._numOfComponents) {
                  _components[i] = new Part (*otro._components[i]);
              } else {
                  _components[i] = nullptr;
              }
          }
          _numOfComponents=otro._numOfComponents;
      }catch ( std::bad_alloc &ex )
      {
          throw ex;
      }
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

const void StarFighter::newPart(){
    if(_numOfComponents == 50){
        throw std::string ("StarFighter.cpp::newPart:The starfighter cannot have more parts");
    }
    _components[_numOfComponents] = new Part();
    _numOfComponents++;

}
const void StarFighter::newPart(const string &name, float weight) {
    if(_numOfComponents == 50){
        throw std::string ("StarFighter.cpp::newPart:The starfighter cannot have more parts");
    }
    _components[_numOfComponents] = new Part(name,weight);
    _numOfComponents++;
}

const void StarFighter::ReplacePart(int pos) {
    if(pos < 0 || pos > 49){
        throw std::string ("StarFighter::ReplacePart:The values is out of bounds");
    }
    Part *aux = new Part(*_components[pos]);
    delete _components[pos];
    _components[pos] = aux;
}

const void StarFighter::RemovePart(int pos) {
    if(pos < 0 || pos > 49){
        throw std::string ("StarFighter::RemovePart:The values is out of bounds");
    }
    if(_components[pos] == nullptr){
        throw std::string ("StarFighter::RemovePart:There is no part in that spot");
    }
    delete _components[pos];
}

float StarFighter::computeWeight() {
    float result = 0;
    for(int i = 0; i < 50; ++i){
        if(_components[i]!= nullptr){
            result+=_components[i]->getWeight();
        }
    }
    return result;
}






