/** 
 * @file Piloto.cpp
 * @author Yoyapro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>

#include "Piloto.h"
#include "StarFighter.h"
#include "Informe.h"
#include <sstream>
using std::string;

int Piloto::_numPilotos = 0;

Piloto::Piloto ( )
{
}

Piloto::Piloto ( string nombre,int numberOfDroids ): _nombre (nombre),_numberOfDroids(numberOfDroids)
{
   _numPilotos++;
   _idP = _numPilotos;
}

Piloto::Piloto ( const Piloto& orig ): _nombre(orig._nombre),
                                       _nacionalidad(orig._nacionalidad),
                                       _numMisiones(orig._numMisiones),
                                       _fechaUltimaMision(orig._fechaUltimaMision),
                                       _incidenciasUltimaMision(orig._incidenciasUltimaMision),
                                       ship(orig.ship),
                                       supportDroid(orig.supportDroid)
{

   _numPilotos++;
   _idP = _numPilotos;
}

Piloto::~Piloto ( )
{ }

/**
 * @todo Aquí hay que añadir la comprobación del parámetro y lanzar la excepción
 *       correspondiente. El número de misiones no puede ser <= 0
 */
const Piloto& Piloto::setNumMisiones ( int numMisiones )
{
   this->_numMisiones = numMisiones;
    return (*this);
}

int Piloto::getNumMisiones ( ) const
{
   return _numMisiones;
}

const Piloto& Piloto::setNacionalidad ( string nacionalidad )
{
   this->_nacionalidad = nacionalidad;
    return (*this);
}

string Piloto::getNacionalidad ( ) const
{
   return _nacionalidad;
}

const Piloto& Piloto::setNombre ( string nombre )
{
   this->_nombre = nombre;
    return (*this);
}

string Piloto::getNombre ( ) const
{
   return _nombre;
}

int Piloto::getIdP ( ) const
{
   return _idP;
}

/**
 * @todo Si el número de misiones del piloto es 0, no puede tener incidencias;
 *       haz esta comprobación y lanza la excepción correspondiente
 */
const Piloto& Piloto::setIncidenciasUltimaMision ( string incidenciasUltimaMision )
{
   this->_incidenciasUltimaMision = incidenciasUltimaMision;
    return (*this);
}

string Piloto::getIncidenciasUltimaMision ( ) const
{
   return _incidenciasUltimaMision;
}

/**
 * @todo Si el número de misiones del piloto es 0, no puede tener fecha de
 *       última misión; haz esta comprobación y lanza la excepción
 *       correspondiente
 */
const Piloto& Piloto::setFechaUltimaMision ( long fechaUltimaMision )
{
   this->_fechaUltimaMision = fechaUltimaMision;
    return (*this);
}

/**
 * @todo Si el número de misiones del piloto es 0, no puede tener fecha de
 *       última misión; haz esta comprobación y lanza la excepción
 *       correspondiente
 */
long Piloto::getFechaUltimaMision ( ) const
{
   return _fechaUltimaMision;
}

string Piloto::toCSV () const
{
   std::stringstream aux;

   aux << _nombre << " ; "
       << _nacionalidad << " ; "
       << _numMisiones << " ; "
       << _fechaUltimaMision << " ; "
       << _incidenciasUltimaMision;

   return ( aux.str () );
}

const Piloto& Piloto::operator = ( const Piloto& otro )
{
   if ( this != &otro )
   {
      _nombre = otro._nombre;
      _nacionalidad = otro._nacionalidad;
      _numMisiones = otro._numMisiones;
      _fechaUltimaMision = otro._fechaUltimaMision;
      _incidenciasUltimaMision = otro._incidenciasUltimaMision;
   }
   
   return ( *this );
}

const void Piloto::newStarfighter(StarFighter *nuevo){
    ship = nuevo;
}


const void Piloto::despegar(){
    onService = true;
}

const void Piloto::aterrizar(){
    onService = false;
}

const void Piloto::newDroid() {
    if(_numberOfDroids == 1){
        throw std::string ("Piloto.cpp:newDroid:You already have a droid");
    }
    supportDroid = new Droide;
    _numberOfDroids++;
}

const void Piloto::droidCasualty() {
    if(_numberOfDroids == 0){
        throw std::string ("Piloto.cpp:DroidCasualty:You have no droids to kill");
    }
    _numberOfDroids--;
    delete supportDroid;
}

const Informe Piloto::createReport() const {
    Informe report;
    report.setIdPiloto(_idP);
    std::stringstream ss;
    ss << ship->getIdSF() << ";" << supportDroid->getIdD() << ";" << _incidenciasUltimaMision;
    report.setDatosInforme(ss.str());
    return report;
}

const void Piloto::replaceDroid() {
    supportDroid = new Droide;
}

const void Piloto::fromCSV(std::string CSV) {
    std::stringstream ss;
    ss.str(CSV);
    std::getline(ss,_nombre,';');
    std::getline(ss,_nacionalidad,';');
    ss>>_numMisiones;
    ss.ignore(1);
    ss>>_fechaUltimaMision;
    ss.ignore(1);
    std::getline(ss,_incidenciasUltimaMision,';');
}

const void Piloto::newDroid(Droide &droid) {
    supportDroid = &droid;
}

const bool Piloto::newMission(long date, const string &comments) {
    _fechaUltimaMision = date;
    _numMisiones++;
    _incidenciasUltimaMision = comments;
    supportDroid->newMission();
    return supportDroid->needsMaintenance();
}

StarFighter *Piloto::getShip() const {
    return ship;
}

Droide *Piloto::getSupportDroid() const {
    return supportDroid;
}
