#include <iostream>
using namespace std;
const int MAX_VEHICLES = 100;

struct Vehicle{
    string Brand ="";
    string Model ="";
    string Plate ="";
    int ManufacturerYear = 0;
    float Price = 0;
};
void kbRead(Vehicle &v){
    do {
        cout << "Introduce the brand of the vehicle";
        cin >> v.Brand;
    } while ((v.Brand.length() < 3) || (v.Brand.length() > 20));
    do {
        cout << "Introduce the model of the vehicle";
        cin >> v.Model;
    } while ((v.Model.length() < 1) || (v.Model.length() > 30));
    do {
        cout << "Introduce the plate of the vehicle";
        cin >> v.Plate;
    } while (v.Plate.length() != 6);
    cout << "Introduce the manufacture year";
    cin >> v.ManufacturerYear;
    do {
        cout << "Introduce the price of the vehicle";
        cin >> v.Model;
    } while (v.Price <= 0);
}

void kbRead(Vehicle *v,const int size){
    for(int i = 0; i < size; ++i){
        do {
            cout << "Introduce the brand of the vehicle";
            cin >> v[i].Brand;
        } while ((v[i].Brand.length() < 3) || (v[i].Brand.length() > 20));
        do {
            cout << "Introduce the model of the vehicle";
            cin >> v[i].Model;
        } while ((v[i].Model.length() < 1) || (v[i].Model.length() > 30));
        do {
            cout << "Introduce the plate of the vehicle";
            cin >> v[i].Plate;
        } while (v[i].Plate.length() != 6);
        cout << "Introduce the manufacture year";
        cin >>v[i].ManufacturerYear;
        do {
            cout << "Introduce the price of the vehicle";
            cin >> v[i].Model;
        } while (v[i].Price <= 0);
    }
}

void showOnScreen(const Vehicle &v){
        cout << "Brand:" << v.Brand << endl;
        cout << "Model:" << v.Model << endl;
        cout << "Plate:" << v.Plate << endl;
        cout << "Manufacturer year:" << v.ManufacturerYear << endl;
        cout << "Price:" << v.Price << endl;
}

void showOnScreen(const Vehicle *v,const int size){
    for(int i = 0; i < size; ++i ) {
        cout << "Brand:" << v[i].Brand << endl;
        cout << "Model:" << v[i].Model << endl;
        cout << "Plate:" << v[i].Plate << endl;
        cout << "Manufacturer year:" << v[i].ManufacturerYear << endl;
        cout << "Price:" << v[i].Price << endl;
        cout << "";
    }
}

int findMostExpensive(Vehicle *v,const int size){
    int posMostExpensive = 0;
    for (int i = 1; i < size;++i){
        posMostExpensive = (v[posMostExpensive].Price > v[i].Price)? posMostExpensive:i;
    }
    return posMostExpensive;
}

int main() {
    int size = 0;
    int posMostExpensive;
    Vehicle a = {"mercedes","hola","123456",1907,200};
    Vehicle list[MAX_VEHICLES];
    do{
        cout << "Introduce the number of vehicles:";
        cin >> size;
    }while(size > MAX_VEHICLES);
    kbRead(list,size);
    posMostExpensive = findMostExpensive(list,size);
    showOnScreen(list,size);
    cout << "The most expensive vehicle data is:" << endl;
    showOnScreen(list[posMostExpensive]);
    return 0;
}
