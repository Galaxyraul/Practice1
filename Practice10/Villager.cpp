    //
// Created by Galaxyraul on 10/05/2022.
//

#include "Villager.h"
#include "ItemApilable.h"
#include "HmmmException.h"
#include "EmptyContainer.h"
#include <sstream>
#include <iostream>

int Villager::getEmeralds() const {
    return _emeralds;
}
//No habia entendido el enunciado y lo he hecho como una tienda en la que buscas y si no está te lo dice no como un catalogo
std::string Villager::sell(Item *item, int offer) {
    if(offer > 20){
        throw HmmmException("Villager.cpp::sell:The offer is out of bounds");
    }
    if(item == nullptr){
        throw HmmmException("Villager.cpp::sell:You have not passed an item");
    }
std::stringstream ss;
    int price = rand()*10 + 20;
    ss<<price;
    if(offer > price){
        _emeralds+=offer;
        for(int i = 1; i <= _inventory->cuantosHay();++i){
            try{
                if(*item == _inventory->consulta(i)){
                    ItemApilable *ptr = dynamic_cast<ItemApilable*>(&_inventory->consulta(i));
                    if(ptr!= nullptr){
                        ptr->decrementaNumElementos(1);
                    }else{
                        _inventory->saca(i);
                    }
                }
            }catch(std::out_of_range& e){
                throw HmmmException(e.what());
            }catch(EmptyContainer& e){
                throw HmmmException(e.what());
            }
        }
        return "The offer has been accepted";
    }
    return "The offer has been refused the price is:" + ss.str();
}

std::string Villager::sell(int pos,int offer) {
    if(offer > 20){
        throw HmmmException("Villager.cpp::sell:The offer is out of bounds");
    }
    std::stringstream ss;
    int price = rand()*10 + 20;
    ss<<price;
    if(offer > price){
        _emeralds+=offer;
        for(int i = 1; i <= _inventory->cuantosHay();++i){
            try{
                ItemApilable *ptr = dynamic_cast<ItemApilable*>(&_inventory->consulta(pos));
                if(ptr!= nullptr){
                    ptr->decrementaNumElementos(1);
                }else{
                    _inventory->saca(pos);
                }

            }catch(std::out_of_range& e){
                throw HmmmException(e.what());
            }catch(EmptyContainer& e){
                throw HmmmException(e.what());
            }
        }
        return "The offer has been accepted";
    }
    return "The offer has been refused the price is:" + ss.str();
}

Item &Villager::consulta(int cual) {
    try{
        return _inventory->consulta(cual);
    }catch(std::out_of_range& e){
        throw HmmmException(e.what());
    }catch(EmptyContainer& e){
        throw HmmmException(e.what());
    }
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

