/**
 * @file Mutante.h
 * @author algarcia
 *
 * @date 6 de abril de 2016, 19:52
 */

#ifndef MUTANTE_H
#define MUTANTE_H

#include "Power.h"
#include <string>
#include "Power.h"
#include "MentalPower.h"
#include "PhysicalPower.h"

using std::string;

/**
 * @brief Clase Muntante
 */
class Mutante {
public:
    static const int MAX_PODERES = 10; ///< Max. moderes de un mutante

public:
    Mutante();

    Mutante(string nombre, string apodo, int fechaN,string nacionalidad);

    Mutante(const Mutante& orig);

    virtual ~Mutante();

    void setNombreReal(string nombreReal);

    string getNombreReal() const;

    void setNacionalidad(string nacionalidad);

    string getNacionalidad() const;

    void setFechaDeNacimiento(int fechaDeNacimiento);

    int getFechaDeNacimiento() const;

    void setApodo(string apodo);

    string getApodo() const;

    string toCSV() const;

    Mutante& operator=(const Mutante& orig);

    virtual void addPower (const std::string &name, const std::string description, const std::string effectiveOn,float capacityOfD,bool inhibited );

    void erasePower(int which);

    virtual float totalDestructiveCapacity ();

    virtual void addMentalPower(const std::string &name, const std::string description, const std::string effectiveOn,float capacityOfD,bool inhibited,float lucidity );

    virtual void addPhysicalPower(const std::string &name, const std::string description, const std::string effectiveOn,float capacityOfD,bool inhibited);

    virtual void addPower (const Power& orig);

    virtual void addPower (const MentalPower& orig);

    virtual void addPower (const PhysicalPower& orig);

    Power *getPower(int which) const;

    int getNumOfPowers() const;

    bool operator <(Mutante& orig);

    void fromCSV (const std::string& orig);


private:
    string _nombreReal = "---";
    string _apodo = "---";
    int _fechaDeNacimiento = 0;
    string _nacionalidad = "---";
    int _numOfPowers = 0;
    Power *_power[MAX_PODERES];
};

#endif /* MUTANTE_H */

