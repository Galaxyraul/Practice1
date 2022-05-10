    //
// Created by Galaxyraul on 10/05/2022.
//

#include "Villager.h"
#include "ItemApilable.h"
#include <sstream>
#include <iostream>

int Villager::getEmeralds() const {
    return _emeralds;
}

std::string Villager::sell(Item *item, int offer) {
    if(offer > 20){
        throw HmmmException("Villager.cpp::sell:The offer is out of bounds");
    }
std::stringstream ss;
    int price = rand()*10 + 20;
    ss<<price;
    if(offer > price){
        _emeralds+=offer;
        for(int i = 1; i <= _inventory->cuantosHay();++i){
            if(*item == _inventory->consulta(i)){
                ItemApilable *ptr = dynamic_cast<ItemApilable*>(&_inventory->consulta(i));
                if(ptr!= nullptr){
                    ptr->decrementaNumElementos(1);
                }else{
                    _inventory->saca(i);
                }
            }
        }
        return "The offer has been accepted";
    }
    return "The offer has been refused the price is:" + ss.str();
}

Item &Villager::consulta(int cual) {
    return _inventory->consulta(cual);
}

std::string Villager::buy(Item *item, int value) {
    std::stringstream ss;
    int price = rand()*5 + 5;
    ss<<price;
    if(value > price){
        _emeralds-=value;
        return "The product has been bought";
    }
    std::cout << "The offer has been refused the offer is:" + ss.str() << std::endl<<
    "Would you accept it?";
    std::string answer = "";
    std::cin >> answer;
    if(answer == "Y"){
        _emeralds-=price;
        return "The product has been bought";
    }
    return "How unfortunate";
}

    int Villager::getNumObjects() const {
        return _inventory->cuantosHay();
    }

