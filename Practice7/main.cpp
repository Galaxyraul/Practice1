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
#include "fstream"
using namespace std;

/***@brief Visualiza la información completa de un mutante*/
void visualiza( Mutante& m) {
    std::cout << "MUTANTE: " 
              << m.toCSV() << std::endl;
    std::cout << "  Poderes : " << std::endl;
    int k = m.getNumOfPowers();
    for(int i = 0; i <= m.MAX_PODERES && k>0; ++i){
        if(m.getPower(i)!= nullptr){
            cout << m.getPower(i)->toCSV() << endl;
            --k;
        }
    }
}
string mutantToString( Mutante& m) {
    string result = "";
    result+= "MUTANTE: " + m.toCSV() + "\n" + "  Poderes : " +" \n";
    int k = m.getNumOfPowers();
    for(int i = 0; i <= m.MAX_PODERES && k>0; ++i){
        if(m.getPower(i)!= nullptr){
           result += m.getPower(i)->toCSV() + "\n";
            --k;
        }
    }
    return result;
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

void storeMutants(Mutante* v[], int tamV, std::string fileName){
    ofstream f;
    f.open(fileName.c_str());
    if(f.good()){
        for(int i = 0; i < tamV;++i){
            if(v[i] != nullptr){
                f<<v[i]->toCSV() << endl;
            }
        }
        f.close();
    }
}

void storeMutantTeam(EquipoMutante& eq,string fileName){
    ofstream f;
    f.open(fileName.c_str());
    if(f.good()){
        f<< "EQUIPO: " << eq.getNombre()
         << " (Base: " << eq.getBase()<< ")" <<std::endl
         << "============================"
         << std::endl;
        int k = eq.getNumMiembros();
        for(int i = 0; i < eq._MAX_MIEMBROS_ && k > 0;++i){
            if(eq.getMutante(i)!= nullptr){
                f << mutantToString(*eq.getMutante(i));
                k--;
            }
        }
        f.close();
    }
}

//almacenaMutantesCSV()


int main(int argc, char** argv) {

    
   Mutante* v[5];
   for (int i = 0; i < 5; ++i){
       v[i] = new Mutante ();
   }
   v[0]->setApodo("Larry");
   v[0]->setFechaDeNacimiento(13042003);
   v[0]->setNacionalidad("Spanish");
   v[0]->setNombreReal("Pepe");

   v[1]->setApodo("B.I.G");
   v[1]->setFechaDeNacimiento(01042003);
   v[1]->setNacionalidad("Spanish");
   v[1]->setNombreReal("Antonio");

   v[2]->setApodo("N");
   v[2]->setFechaDeNacimiento(07042003);
   v[2]->setNacionalidad("French");
   v[2]->setNombreReal("Engolo");

   v[3]->setApodo("NightK");
   v[3]->setFechaDeNacimiento(18509300);
   v[3]->setNacionalidad("Japanese");
   v[3]->setNombreReal("Yumiko");

   v[4]->setApodo("CaptainSun");
   v[4]->setFechaDeNacimiento(15082005);
   v[4]->setNacionalidad("American");
   v[4]->setNombreReal("Peggy");
    Power p1("PyroKinesis","Ability to control fire","Effective on almost every mutant but water related",100,true);
    Power p2("WaterBending","Ability to control water","Effective on fire related mutants",75,false);
   try{
       v[0]->addPower("PyroKinesis","Ability to control fire","Effective on almost every mutant but water related",100,false);
       v[0]->addPower(p1);
       v[0]->addPower(p2);
       v[1]->addPower("WaterBending","Ability to control water","Effective on fire related mutants",75,false);
       v[2]->addPower("Invisibility","Ability to become invisible to humans","Effective every mutant but tracking related",2,true);
       v[3]->addPower("Teleportation","Ability to appear in whichever place the user wants","Effective on no mutant",0,false);
       v[4]->addPower("Flight","Ability to fly ","Effective on no mutant",20,false);
   }catch (std::string &e){
       cerr << e;
   }
   cout << v[0]->totalDestructiveCapacity();

   EquipoMutante t1;
   EquipoMutante t2;
   try{
       for(int i = 0; i < 5;++i){
           if(i%2 == 0){
               t1.addMutante(v[i]);
           } else{
               t2.addMutante(v[i]);
           }
       }
   }catch (std::length_error &e){
       cerr << e.what();
   }
try {
    visualiza(t1);
    visualiza(t2);
}catch (std::invalid_argument &e){
    cerr << e.what();
}
    storeMutants(v,5,"List.csv");
    storeMutantTeam(t1,"Team.CSV");
    
    
   // Destruye todos los objetos creados en memoria dinámica antes de la
   // finalización del programa


    for(int i = 0 ; i  < 5; ++i){
        delete v[i];
        v[i] = nullptr;
    }
    
    return 0;
}

