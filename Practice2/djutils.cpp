//
// Created by cocol on 26/02/2022.
//

#include "djutils.h"
#include "Fecha.h"
#include "Garito.h"
#include "Temazo.h"
#include <iostream>

void showTemazo(const Temazo &temazo) {
    std::cout << "The title of this temazo is " + temazo.getTitle() << std::endl
    << "The performer of this temazo is " + temazo.getPerformer() << std::endl
    << "The length of this temazo is " << temazo.getLengthInSeconds() << " s" << std::endl
    << "The audience score of this temazo is " << temazo.getAudienceScore() << std::endl;

}

void showGarito(const Garito &garito) {
    std::cout << "The name of this Garito is " + garito.getName() << std::endl
    << "The address of this garito is " + garito.getAddress() << std::endl;
}

void showFecha(const Fecha &fecha) {
    std::cout << "The date is " << fecha.getDay() << "/" << fecha.getMonth() << "/" << fecha.getYear() <<std::endl;
}

void changeGarito(Garito &garito) {
    std::string name;
    std::string address;
    std::cout << "Introduce the new name of the garito";
    std::cin >> name;
    garito.setName(name);
    std::cout << "Introduce the new address";
    std::cin >> address;
    garito.setAddress(address);

}
