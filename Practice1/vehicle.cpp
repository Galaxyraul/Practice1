//
// Created by cocol on 19/02/2022.
//

#include "vehicle.h"
#include <iostream>

void vehicle::setBrand(){
    string brand;
    do {
        cout << "Introduce the brand of the vehicle:";
        cin >> brand;
    } while ((brand.length() < 3) || (brand.length() > 20));
    _brand = brand;
}

void vehicle::setModel(){
    string model;
    do {
        cout << "Introduce the model of the vehicle:";
        cin >> model;
    } while ((model.length() < 1) || (model.length() > 30));
    _model = model;
}

void vehicle::setPlate(){
    string plate;
    do {
        cout << "Introduce the plate of the vehicle:";
        cin >> plate;
    } while (plate.length() != 6);
    _plate = plate;
}

void vehicle::setManufacturerYear(){
    cout << "Introduce the manufacture year:";
    cin >> _manufacturerYear;
}

void vehicle::setPrice(){
    int price;
    do {
        cout << "Introduce the price of the vehicle:";
        cin >> price;
    } while (price <= 0);
    _price = price;
}
