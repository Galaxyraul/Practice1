/* 
 * File:   main.cpp
 * Author: jrbalsas
 *
 * Created on 15 de abril de 2016, 11:11
 */

#include <cstdlib>
#include <iostream>

#include "Cofre.h"
#include "Item.h"
#include "Bloque.h"
#include "Espada.h"
#include "Filete.h"
#include "Inventario.h"
#include "ContenedorItem.h"


using namespace std;

/**Inicializa el vector de items inicial
 * @pre v no contiene punteros inicializados
 * @post crea algunos objetos en el vector e inicializa el resto de elementos a 0
 * @return número de posiciones del vector con items creados*/
int inicializaItems(ContenedorItem& c) {
    int numItems = 0;

  c.mete(new Bloque(5));
  ++numItems;
  c.mete(new Bloque(8));
    ++numItems;
  c.mete(new Bloque());
    ++numItems;
  c.mete(new Espada());
    ++numItems;
  c.mete(new Filete());
    ++numItems;
    return numItems;
}

/**Libera los items del vector creados en memoria dinámica*/
void liberaItems(ContenedorItem& c) {
    c.~ContenedorItem();//Delete could have been used if I had created it on dynamic memory
}

void visualiza(Cofre &c) {
    std::cout << "CONTENIDO DEL COFRE" << std::endl
            << "===================" << std::endl;
    for (int i = 1; i <= c.cuantosHay(); i++) {
        std::cout << i << ".- "
                << c.consulta(i).getDescripcion() << std::endl;
    }

}

/**@brief Probando los Cofres
 * 
 */
int main(int argc, char** argv) {
    Inventario i1;
    ContenedorItem cO1(20);
    const int MAXITEMS = 10;
    Item* objetos[MAXITEMS];

    try {

        //Inicializamos algunos objetos de prueba
        int numObjetos = inicializaItems(cO1);

        Cofre c; //Creamos un cofre con 27 posiciones

        //Metemos todos los objetos en el cofre

        try {
            for (int i = 1; i < numObjetos; i++) {
                c.mete(&cO1.consulta(i));
            }
        }catch(std::exception &e) {
            //Capturamos cualquier excepción de la jerarquía que pueda generar
            //Consulta::mete. Es decir: out_of_range y invalid_argument
            std::cerr   << "Error al intentar meter un objeto en el cofre: "
                        << e.what() << std::endl;
        }
        i1.mete(&c);
        visualiza(c);

        //Liberamos recursos
        liberaItems(cO1);
        
    } catch (std::exception &e) {
        //Capturamos cualquier excepción que se haya podido escapar
        //En tiempo de desarrollo
        std::cerr << "Finalización del programa por excepción sin capturar: "
                << e.what() << std::endl;
    }
    return 0;
}

