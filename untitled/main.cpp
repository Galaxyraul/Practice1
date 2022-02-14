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
void kbRead(Vehicle &v,int size){
    for(int i = 0; i < size;++i){
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
}

void kbRead(Vehicle *v,int size){
    for(int i = 0; i < size; ++i){
        do {
            cout << "Introduce the brand of the vehicle";
            cin >> v->Brand;
        } while ((v->Brand.length() < 3) || (v->Brand.length() > 20));
        do {
            cout << "Introduce the model of the vehicle";
            cin >> v->Model;
        } while ((v->Model.length() < 1) || (v->Model.length() > 30));
        do {
            cout << "Introduce the plate of the vehicle";
            cin >> v->Plate;
        } while (v->Plate.length() != 6);
        cout << "Introduce the manufacture year";
        cin >> v->ManufacturerYear;
        do {
            cout << "Introduce the price of the vehicle";
            cin >> v->Model;
        } while (v->Price <= 0);
    }
}

void showOnScreen(const Vehicle &v){
    cout << "Brand:" << v.Brand << endl;
    cout << "Model:" << v.Model << endl;
    cout << "Plate:" << v.Plate << endl;
    cout << "Manufacturer year:" << v.ManufacturerYear << endl;
    cout << "Price:" << v.Price << endl;
};

void showOnScreen(const Vehicle *v){
    cout << "Brand:" << v->Brand << endl;
    cout << "Model:" << v->Model << endl;
    cout << "Plate:" << v->Plate << endl;
    cout << "Manufacturer year:" << v->ManufacturerYear << endl;
    cout << "Price:" << v->Price << endl;
};


int main() {
    int size = 0;
    Vehicle a = {"mercedes","hola","123456",1907,200};
    Vehicle list[MAX_VEHICLES];
    do{
        cout << "Introduce the number of vehicles:";
        cin >> size;
    }while(size > MAX_VEHICLES);
    kbRead(list,size);
    showOnScreen(a);
    return 0;
}
