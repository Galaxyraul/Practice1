#include <iostream>
#include "vehicle.h"
using namespace v;

int main() {
    int tam;
    string plate;
    int pos;
    cout << "Introduce the size of the array:";
    cin >> tam;
    Vehicle *v1 = new Vehicle[tam];
    fillVector(v1,tam);
    showOnScreen(v1,tam);
    cout <<"The most expensive is:" <<endl;
    showOnScreen(v1[maxPrice(v1,tam)]);
    do {
        cout << "Introduce the number of plate to change:";
        cin >> plate;
    } while (plate.length()!= 6);
    pos = searchByPlate(plate,v1,tam);
    do {
        cout << "Introduce the new brand of the vehicle:";
        cin >> v1[pos].Brand;
    } while ((v1[pos].Brand.length() < 3) || (v1[pos].Brand.length() > 20));
    do {
        cout << "Introduce the new model of the vehicle:";
        cin >> v1[pos].Model;
    } while ((v1[pos].Model.length() < 1) || (v1[pos].Model.length() > 30));
    do {
        cout << "Introduce the new plate of the vehicle:";
        cin >> v1[pos].Plate;
    } while (v1[pos].Plate.length() != 6);
    cout << "Introduce the new manufacture year:";
    cin >> v1[pos].ManufacturerYear;

    do {
        cout << "Introduce the new price of the vehicle:";
        cin >> v1[pos].Price;
    } while (v1[pos].Price <= 0);

    delete [] v1;
    v1 = nullptr;
    return 0;
}
