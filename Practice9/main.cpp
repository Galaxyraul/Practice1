/** 
 * @file   main.cpp
 * @author jrbalsas
 *
 * @date 15 de abril de 2016
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "Cofre.h"
#include "Item.h"
#include "Steak.h"
#include "Sword.h"
#include "Block.h"
using namespace std;

/**Inicializa el vector de items inicial
 * @pre v no contiene punteros inicializados
 * @post crea algunos objetos en el vector e inicializa el resto de elementos a nullptr
 * @return número de posiciones del vector con items creados*/
int inicializaItems(Item* v[], int tamv) {
    int numItems=0;

    v[numItems++] = new Steak;
    v[numItems++] = new Sword;
    v[numItems++] = new Block;
    v[numItems++] = new Steak;
    v[numItems++] = new Block;

    //Asigna nullptr el resto de posiciones no ocupadas
    for (int i = numItems; i < tamv; i++) {
        v[i] = nullptr;
    }        
    return numItems;
}
/**Libera los items del vector creados en memoria dinámica*/
void liberaItems(Item* v[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        delete v[i];
        v[i]=nullptr;
    }

}

void visualiza(Cofre &c) {
    std::cout << "CONTENIDO DEL COFRE" << std::endl
              << "===================" << std::endl;
    for (int i = 1; i <= c.cuantosHay(); i++) {
        std::cout << i <<".- "
                  << c.consulta(i).getDescription() << std::endl;
    }

}


/**@brief Probando los Cofres
 * 
 */
int main(int argc, char** argv) {

    Cofre c1;
    try{
        Block b1("dirt",8),b2("stone",5),b3("Diamond",1);
        c1.mete(&b1);
        c1.mete(&b2);
        c1.mete(&b3);
        visualiza(c1);
    }catch (std::out_of_range &e){
        cerr<<e.what()<<std::endl;
    }catch (EmptyContainer &e){
        cerr<<e.what()<<std::endl;
    }catch (std::exception &e){
        cerr<<e.what()<<std::endl;
    }

    return 0;
}

