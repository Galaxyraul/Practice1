//
// Created by cocol on 19/02/2022.
//

#include "vehicle.h"
#include <iostream>

using namespace v;
/**
 * @brief Asks the user for the data of a vehicle
 * @param v [out] the vehicle to be filled
 * @param size
 */
void v::kbRead(Vehicle &v){
    cout << "Introduce the brand of the vehicle:";
    cin >> v.Brand;
    if((v.Brand.length() < 3) || (v.Brand.length() > 20)) {
        throw string("The brand length doesn't fit the standards");
    }
    cout << "Introduce the model of the vehicle:";
    cin >> v.Model;
    if((v.Model.length() < 1) || (v.Model.length() > 30)){
        throw string("The model length doesn't fit the standards");
    }

    cout << "Introduce the plate of the vehicle:";
    cin >> v.Plate;
    if (v.Plate.length() != 6){
        throw string("The plate length doesn't fit the standards");
    }
    cout << "Introduce the manufacture year:";
    cin >> v.ManufacturerYear;
        cout << "Introduce the price of the vehicle:";
        cin >> v.Price;
    if (v.Price <= 0){
        throw string("The price can't be negative");
    }
}
/**
 * @brief ASk the user for the data of the vehicles of a list and it fills it
 * @param v [out] Pointer to the array of vehicles
 * @param size [in] Size of the array so that we can end the loop
 */
void v::kbRead(Vehicle *v,const int size){
    for(int i = 0; i < size; ++i){
        cout << "Introduce the brand of the vehicle:";
        cin >> v[i].Brand;
        if((v[i].Brand.length() < 3) || (v[i].Brand.length() > 20)) {
            throw string("The brand length doesn't fit the standards");
        }

        cout << "Introduce the model of the vehicle:";
        cin >> v[i].Model;
        if((v[i].Model.length() < 1) || (v[i].Model.length() > 30)){
            throw string("The model length doesn't fit the standards");
        }
        cout << "Introduce the plate of the vehicle:";
        cin >> v[i].Plate;
        if(v[i].Plate.length() != 6){
            throw string("The plate length doesn't fit the standards");
        }
        cout << "Introduce the manufacture year:";
        cin >>v[i].ManufacturerYear;
        cout << "Introduce the price of the vehicle:";
        cin >> v[i].Price;
        if(v[i].Price <= 0){
            throw string("The price can't be negative");
        }
    }
}
/**
 * @brief This function shows on screen the data of a vehicle
 * @param v [in] The adress of the vehicle
 * @param size [in]
 */
void v::showOnScreen(const Vehicle &v){
    cout << "Brand:" << v.Brand << endl;
    cout << "Model:" << v.Model << endl;
    cout << "Plate:" << v.Plate << endl;
    cout << "Manufacturer year:" << v.ManufacturerYear << endl;
    cout << "Price:" << v.Price << endl;
    cout << endl;
}
/**
 * @brief This function shows on screen the data of the vehicles inside a list
 * @param v [in] The pointer to the array
 * @param size [in] The size of the array
 */
void v::showOnScreen(const Vehicle *v,const int size){
    for(int i = 0; i < size; ++i ) {
        cout << "Brand:" << v[i].Brand << endl;
        cout << "Model:" << v[i].Model << endl;
        cout << "Plate:" << v[i].Plate << endl;
        cout << "Manufacturer year:" << v[i].ManufacturerYear << endl;
        cout << "Price:" << v[i].Price << endl;
        cout << endl;
    }
}
/**
 * @brief This functions goes through the array finding the greatest value among the prices
 * @param v [in] The pointer to the array
 * @param size [int] The size of the array
 * @return The position of the most expensive vehicle
 */
int v::findMostExpensive(const Vehicle *v,const int size){
    int posMostExpensive = 0;
    for (int i = 1; i < size;++i){
        posMostExpensive = (v[posMostExpensive].Price > v[i].Price)? posMostExpensive:i;
    }
    return posMostExpensive;
}
/**
 * @brief This functions compares if the first and last character of the plate is the same and if so it shows its data
 * @param v [in] Pointer to the array
 * @param size [in] Size of the array
 */
void v::platesSECharacter (const Vehicle *v,const int size){
    for(int i = 0; i < size;++i){
        if(v[i].Plate.front() == v[i].Plate.back()){
            showOnScreen(v[i]);//preguntar al profesor xq no funciona pero llamando a otro si
        }
    }

}
/**
 * @brief This functions check if the plate is written the same from right to left as from left to rigth
 * @param v [in] Pointer to the array
 * @param size [in] Size of the array
 */
void v::platesPalyndrome (const Vehicle *v,const int size){
    int j = 0;
    bool palyndrome = true;
    for(int i = 0; i < size;++i){
        while (palyndrome && (j < (v[i].Plate.length()))/2){
            palyndrome = (v[i].Plate[j] == v[i].Plate[v[i].Plate.length()-1-j]);
            ++j;
        }
        if (palyndrome){
            showOnScreen(v[i]);
        }
        palyndrome = true;
        j = 0;
    }

}
/**
 * @brief Given the array of vehicles it fill its asking the user for the data
 * @param v [in] array of vehicles
 * @param size [in] dimension of the array
 * @return The space used of the array
 */
int v::fillVector(Vehicle v[],const int size){
    string answer ="Y";
    int i;
    for(i = 0; (i < size) && (answer == "Y"); ++i) {
        kbRead(v[i]);
        cout <<"Would you like to add another vehicle?(Y/N)";
        cin >> answer;
    }
    return i;
}
/**
 * @brief given the array of vehicles it show its content in groups of five
 * @param v [in]array of vehicles
 * @param size [in] dimension of the array
 */
void v::showOnScreen(Vehicle v[],const int size){
    string answer ="Y";
    for(int i = 0; (i < size) && (answer == "Y"); ++i ) {
        showOnScreen(v[i]);
        if((i+1)%5==0){
            cout << "Press Y to show the next page";
            cin >> answer;
        }
    }
}
/**
 * @brief given the array of vehicles it returns the position of the most expensive
 * @param v [in]array in which the vehicles are contained
 * @param size [in]dimension of the array
 * @return the position of the most expensive vehicle inside the array
 */
int v::maxPrice(const Vehicle v[],const int size){
    int posMostExpensive = 0;
    for (int i = 1; i < size;++i){
        posMostExpensive = (v[posMostExpensive].Price > v[i].Price)? posMostExpensive:i;
    }
    return posMostExpensive;
}
/**
 * @brief Given a plate number it returns the position inside the vector in which is contained
 * @param plateNumber[in] data introduce by the user
 * @param v [in]vector of vehicles
 * @param size [in]dimension of the array
 * @return The position of the vehicle which matches with the plateNumber
 */
int v::searchByPlate (const std::string plateNumber,const Vehicle v[],const int size){
    bool match = false;
    int pos = 0;
    for(int i = 0; i < size && !match;++i){
        if (v[i].Plate == plateNumber){
            match = true;
            pos = i;
        }
    }
    if (match){
    return pos;
    }else{
        return -1;
    }

}



