/**
 * @file Mutante.cpp
 * @author algarcia
 *
 */

#include <stdexcept>
#include <sstream>

#include "Mutante.h"

Mutante::Mutante(string nombre, string apodo, int fechaN, string nacionalidad) 
    : _nombreReal(nombre),
      _apodo(apodo),
      _fechaDeNacimiento(fechaN),
      _nacionalidad(nacionalidad)
      {
          for(int i = 0; i < MAX_PODERES;++i){
              _power[i]= nullptr;
          }
}

Mutante::Mutante(const Mutante& orig)
    : _nombreReal(orig._nombreReal),
    _apodo(orig._apodo),
    _fechaDeNacimiento(orig._fechaDeNacimiento),
    _nacionalidad(orig._nacionalidad),
    _numOfPowers(orig._numOfPowers)
 {
    int k = 0;
     for(int i = 0; i < MAX_PODERES;++i){
         _power[i] = nullptr;
         if(orig._power[i]!= nullptr){
             _power[k] = new Power (*orig._power[i]);
             k++;
         }
     }
}

Mutante::~Mutante() {
    int k = _numOfPowers;
    for(int i = 0; i < MAX_PODERES && k > 0;++i){
        if(_power[i]!= nullptr){
            delete _power[i];
            _power[i]= nullptr;
            --k;
        }
    }
}

void Mutante::setNombreReal(string nombreReal) {
    this->_nombreReal = nombreReal;
}

string Mutante::getNombreReal() const {
    return _nombreReal;
}

void Mutante::setNacionalidad(string nacionalidad) {
    this->_nacionalidad = nacionalidad;
}

string Mutante::getNacionalidad() const {
    return _nacionalidad;
}

void Mutante::setFechaDeNacimiento(int fechaDeNacimiento) {
    this->_fechaDeNacimiento = fechaDeNacimiento;
}

int Mutante::getFechaDeNacimiento() const {
    return _fechaDeNacimiento;
}

void Mutante::setApodo(string apodo) {
    this->_apodo = apodo;
}

string Mutante::getApodo() const {
    return _apodo;
}


/**@brief Representación CSV de un mutante
   @post  Genera la representación básica en CSV, sin incluir los poderes*/
string Mutante::toCSV() const{
    std::stringstream aux;
    aux << _nombreReal << ";"
            << _apodo << ";"
            << _fechaDeNacimiento << ";"
            << _nacionalidad;

    return aux.str();
}

Mutante& Mutante::operator=(const Mutante& orig) {
    if (this != &orig) {
        _nombreReal = orig._nombreReal;
        _apodo = orig._apodo;
        _fechaDeNacimiento = orig._fechaDeNacimiento;
        _nacionalidad = orig._nacionalidad;
        int k = 0;
        for(int i = 0; i < MAX_PODERES;++i){
            delete _power[i];
            _power[i] = nullptr;
            if(orig._power[i]!=nullptr){
                _power[k] = new Power(*orig._power[i]);
            }

        }
    }
    return  *this;
}

Mutante::Mutante() {
    for(int i = 0; i < MAX_PODERES;++i){
        _power[i]= nullptr;
    }
}

void
Mutante::addPower(const string &name, const std::string description, const std::string effectiveOn, float capacityOfD) {
    if(_numOfPowers>=MAX_PODERES){
        throw std::string ("Mutant.cpp::addPower:The mutant cannot have more powers");
    }
    for(int i = 0; i < MAX_PODERES;++i){
        if(_power[i]== nullptr){
            _power[i] = new Power(name,description,effectiveOn,capacityOfD);
            _numOfPowers++;
            break;
        }
    }
}

void Mutante::erasePower(int which) {
    if(_power[which-1] == nullptr){
        throw std::string ("Mutant.cpp::erasePower:The position does not have a power");
    }
    if(which-1 <= 0 || which - 1 >= 10 ){
        throw std::invalid_argument ("Mutant.cpp::erasePower:The value is not valid");
    }
    delete _power[which - 1];
    _power[which - 1] = nullptr;
}

float Mutante::totalDestructiveCapacity(){
    float result = 0;
    int k = _numOfPowers;
    for(int i = 0; i < MAX_PODERES && k > 0;++i){
        if(_power[i]!= nullptr){
            result+=_power[i]->getDestructiveCapacity();
            --k;
        }
    }
    return result;
}

void Mutante::addMentalPower(const string &name, const std::string description, const std::string effectiveOn,
                             float capacityOfD) {
    if(_numOfPowers>=MAX_PODERES){
        throw std::string ("Mutant.cpp::addPower:The mutant cannot have more powers");
    }
    for(int i = 0; i < MAX_PODERES;++i){
        if(_power[i]== nullptr){
            _power[i] = new MentalPower(name,description,effectiveOn,capacityOfD);
            _numOfPowers++;
            break;
        }
    }
}

void Mutante::addPhysicalPower(const string &name, const std::string description, const std::string effectiveOn,
                               float capacityOfD) {
    if(_numOfPowers>=MAX_PODERES){
        throw std::string ("Mutant.cpp::addPower:The mutant cannot have more powers");
    }
    for(int i = 0; i < MAX_PODERES;++i){
        if(_power[i]== nullptr){
            _power[i] = new PhysicalPower(name,description,effectiveOn,capacityOfD);
            _numOfPowers++;
            break;
        }
    }
}

void Mutante::addPower(const Power &orig) {
    if(_numOfPowers>=MAX_PODERES){
        throw std::string ("Mutant.cpp::addPower:The mutant cannot have more powers");
    }
    for(int i = 0; i < MAX_PODERES;++i){
        if(_power[i]== nullptr){
            _power[i] = new Power(orig);
            _numOfPowers++;
            break;
        }
    }
}

void Mutante::addPower(const MentalPower &orig) {
    if(_numOfPowers>=MAX_PODERES){
        throw std::string ("Mutant.cpp::addPower:The mutant cannot have more powers");
    }
    for(int i = 0; i < MAX_PODERES;++i){
        if(_power[i]== nullptr){
            _power[i] = new MentalPower(orig);
            _numOfPowers++;
            break;
        }
    }
}

void Mutante::addPower(const PhysicalPower &orig) {
    if(_numOfPowers>=MAX_PODERES){
        throw std::string ("Mutant.cpp::addPower:The mutant cannot have more powers");
    }
    for(int i = 0; i < MAX_PODERES;++i){
        if(_power[i]== nullptr){
            _power[i] = new PhysicalPower(orig);
            _numOfPowers++;
            break;
        }
    }
}

Power *Mutante::getPower(int which) const {
    if(which< 0 || which>=10){
        throw std::invalid_argument("Mutant.cpp::getPower:The value is not suitable");
    }
    return _power[which];
}

int Mutante::getNumOfPowers() const {
    return _numOfPowers;
}




