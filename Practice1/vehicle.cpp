//
// Created by cocol on 19/02/2022.
//

#include "vehicle.h"
#include <iostream>

void vehicle::setBrand(const string &brand){
    if((brand.length() > 3) && (brand.length() < 20)){
        _brand = brand;
    }else{
        std::cout << "The brand length doesn't fit the standards";
    }
}

void vehicle::setModel(const string &model){
    if((model.length() > 1) && (model.length() < 30)){
        _model = model;
    }else{
        std::cout << "The model length doesn't fit the standards";
    }
}

void vehicle::setPlate(const string &Plate){
    if(Plate.length() != 6){
        _plate = Plate;
    }else{
        std::cout << "The plate length doesn't fit the standards";
    }
}

void vehicle::setManufacturerYear(const int &manufacturerYear){
    _manufacturerYear = manufacturerYear;
}

void vehicle::setPrice(const float &price){
    if(price> 0){
        _price = price;
    } else{
        std::cout << "The price can't be negative";
    }
}
