/** 
 * @file main.cpp
 * @author Casipro Gramo 
 * @author Yoyapro GRamo
 *
 * @date Fecha estelar 20160309
 */

#include <cstdlib>
#include <string>
#include <iostream>

#include "Informe.h"
#include "Piloto.h"
#include "Droide.h"
#include "StarFighter.h"
#include "Part.h"
#include "Squad.h"

using namespace std;

/**
 * @todo Ver el enunciado del ejercicio 5 de la práctica
 */
int main ( int argc, char** argv )
{

    string datosPilotos[5] = {"Dameron Poe;Jakku;100;123456;---",
                             "Anakin Skywalker;Tatooine;133;126756;Derribados 3 cazas enemigos",
                             "Han Solo;Corellia;247;126786;Impacto en motor izquierdo",
                             "Chewbacca;Kashyyk;115;136786;---",
                             "Leia Organa;Alderaan;3;126336;Derribados 10 cazas enemigos"};
    string datosNaves[5] = {"Kuat Systems;Delta-7;1",
                           "Kuat Systems;Delta-7B;1",
                           "Incom Corporation;T-65B X-wing;1",
                           "Koensayr Manufacturing;Y-wing;2",
                           "Kuat Systems;A-wing;1"};
    string datosDroides[5] = {"Industrial Automation;R2-D2",
                             "Industrial Automation;R2-KT",
                             "AccuTronics;R3-D3",
                             "AccuTronics;R3-KT",
                             "Arakyd Industries;C3PO"};

    // Ejemplo de encadenamiento de llamadas a métodos sobre un objeto
    Informe i1;
    i1.setIdPiloto (1)
     .setFechaEstelar (31521231)
     .setDatosInforme ("Sin novedad");
    Piloto *pilots[5];
    for(int i = 0; i < 5; ++i){
        pilots[i]=new Piloto;
    }
    for(int i = 0; i < 5; ++i){
       pilots[i]->fromCSV(datosPilotos[i]);
    }
    Droide d1("Hola","R2-D2",0);
    pilots[0]->newDroid(d1);
    Squad s1 ("First squad","Tatooine");
    Squad s2 ("Second squad","Mandalor");
    s1.newRecuit(*pilots[0]);
    s1.newRecuit(*pilots[1]);
    s2.newRecuit(*pilots[2]);
    s2.newRecuit(*pilots[3]);
    s2.newRecuit(*pilots[4]);
    std::cerr << "The squad " + s1.getName() + " has an average of :" << s1.averageNumberOfMissions() << " missions" <<std::endl;
    std::cerr << "The squad " + s2.getName() + " has an average of :" << s2.averageNumberOfMissions() << " missions" <<std::endl;
    StarFighter *sf1 = new StarFighter();
    StarFighter *sf2 = new StarFighter();

    sf1->newPart("wing",200);
    sf1->newPart("wheels",100);
    sf1->newPart("capsule",800);
    std::cerr << sf1->computeWeight()<<std::endl;

    sf2->newPart("cannon",500);
    sf2->newPart("console",200);
    sf2->newPart("engine",1000);
    std::cerr << sf2->computeWeight()<<std::endl;

    *sf2 = *sf1;
    s2 = s1;
    cout << s2.getName() << endl;
    cout << s1.getName() << endl;
    cout<< sf1->computeWeight()<<std::endl;
    cout<< sf2->computeWeight()<<std::endl;
    Piloto &p = s1.partnerOfDroid(d1);
    cout << p.toCSV()<<endl;
    delete sf1;
    sf1 = nullptr;
    delete sf2;
    sf2 = nullptr;
    for(int i = 0; i < 5; ++i){
        delete pilots[i];
        pilots[i] = nullptr;
    }
    return 0;
}

