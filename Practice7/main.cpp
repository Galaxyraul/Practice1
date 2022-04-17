/**
 * @file main.cpp
 * @author 
 *
 */

#include <iostream>
#include "EquipoMutante.h"
#include "Power.h"
#include "PhysicalPower.h"
#include "MentalPower.h"
using namespace std;

/***@brief Visualiza la información completa de un mutante*/
void visualiza( Mutante& m) {
    std::cout << "MUTANTE: " 
              << m.toCSV() << std::endl;
    std::cout << "  Poderes : " << std::endl;
    int k = m.getNumOfPowers();
    for(int i = 0; i < m.MAX_PODERES && k>0; ++i){
        if(m.getPower(i)!= nullptr){
            cout << m.getPower(i)->toCSV() << endl;
            --k;
        }
    }


}
/***@brief Visualiza los datos de todos los miembros de un equipo mutante*/
void visualiza( EquipoMutante& eq) {
    std::cout << "EQUIPO: " << eq.getNombre() 
              << " (Base: " << eq.getBase()<< ")" <<std::endl
              << "============================"
              << std::endl;
    int k = eq.getNumMiembros();
    for(int i = 0; i < eq._MAX_MIEMBROS_ && k > 0;++i){
        if(eq.getMutante(i)!= nullptr){
            visualiza(*eq.getMutante(i));
            k--;
        }
    }

}

//almacenaMutantesCSV()


int main(int argc, char** argv) {

    
   // Crea un array de 5 punteros a mutantes, asignándoles los valores a sus
   // atributos directamente en el código fuente

    
   // Crea dos equipos mutantes, asignando al primero los mutantes que ocupan
   // las posiciones pares del array, y al segundo los de las posiciones impares
    
    
   // Añade varios poderes a cada mutante, utilizando los métodos ya
   // implementados: usando datos o objetos de tipo Poder
   // Muestra por la consola la información de cada equipo mutante en formato CSV

    
   //Guardamos datos de mutantes en fichero CSV
    
    
   // Destruye todos los objetos creados en memoria dinámica antes de la
   // finalización del programa

    
    
    return 0;
}

