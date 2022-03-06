//
// Created by cocol on 26/02/2022.
//

#include "djutils.h"
#include "Fecha.h"
#include "Garito.h"
#include "Temazo.h"
#include <iostream>
#include <string>

/**
 * @brief This function shows the data of an object of the type Temazo
 * @param temazo object from which the data is shown
 */
void showTemazo(const Temazo &temazo) {
    std::cout << "The title of this temazo is " + temazo.getTitle() << std::endl
    << "The performer of this temazo is " + temazo.getPerformer() << std::endl
    << "The length of this temazo is " << temazo.getLengthInSeconds() << " s" << std::endl
    << "The audience score of this temazo is " << temazo.getAudienceScore() << std::endl;
    std::cout << "" << std::endl;

}

/**
 * @brief This function shows the data of an object of the type garito
 * @param garito object from which the data is shown
 */
void showGarito(const Garito &garito) {
    std::cout << "The name of this Garito is " + garito.getName() << std::endl
    << "The address of this garito is " + garito.getAddress() << std::endl;
    std::cout << "" << std::endl;
}

/**
 * @brief This function shows the data of an object of the type Fecha
 * @param fecha object from which the data is shown
 */
void showFecha(const Fecha &fecha) {
    std::cout <<fecha.getDay() << "/" << fecha.getMonth() << "/" << fecha.getYear() <<std::endl;
    std::cout << "" << std::endl;
}

/**
 * @brief This function asks for new data and changes the value of the fields
 * @param garito Object which fields will be changed
 * @param name new value of the field _name
 * @param address new value of the field _address
 */
void changeGarito(Garito &garito) {
    std::string name;
    std::string address;
    while(getchar() != '\n');
    std::cout << "Introduce the new name of the garito:";
    std::getline(std::cin,name);
    garito.setName(name);
    while(getchar() != '\n');//Este bucle vacía el buffer que era la causa del problema
    std::cout << "Introduce the new address:";
    std::getline(std::cin,address);
    garito.setAddress(address);

}
