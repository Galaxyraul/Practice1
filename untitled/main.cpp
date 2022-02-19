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

/**
 * @brief Asks the user for the data of a vehicle
 * @param v [out] the vehicle to be filled
 * @param size
 */
void kbRead(Vehicle &v,const int size){
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
        cin >> v.Price;
    } while (v.Price <= 0);
}
/**
 * @brief ASk the user for the data of the vehicles of a list and it fills it
 * @param v [out] Pointer to the array of vehicles
 * @param size [in] Size of the array so that we can end the loop
 */
void kbRead(Vehicle *v,const int size){
    for(int i = 0; i < size; ++i){
        do {
            cout << "Introduce the brand of the vehicle:";
            cin >> v[i].Brand;
        } while ((v[i].Brand.length() < 3) || (v[i].Brand.length() > 20));
        do {
            cout << "Introduce the model of the vehicle:";
            cin >> v[i].Model;
        } while ((v[i].Model.length() < 1) || (v[i].Model.length() > 30));
        do {
            cout << "Introduce the plate of the vehicle:";
            cin >> v[i].Plate;
        } while (v[i].Plate.length() != 6);
        cout << "Introduce the manufacture year:";
        cin >>v[i].ManufacturerYear;
        do {
            cout << "Introduce the price of the vehicle:";
            cin >> v[i].Price;
        } while (v[i].Price <= 0);
    }
}
/**
 * @brief This function shows on screen the data of a vehicle
 * @param v [in] The adress of the vehicle
 * @param size [in]
 */
void showOnScreen(const Vehicle &v,int size){
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
void showOnScreen(const Vehicle *v,const int size){
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
int findMostExpensive(const Vehicle *v,const int size){
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
void platesSECharacter (const Vehicle *v,const int size){
    for(int i = 0; i < size;++i){
        if(v[i].Plate.front() == v[i].Plate.back()){
            showOnScreen(v[i],size);
        }
    }

}
/**
 * @brief This functions check if the plate is written the same from right to left as from left to rigth
 * @param v [in] Pointer to the array
 * @param size [in] Size of the array
 */
void platesPalyndrome (const Vehicle *v,const int size){
    int j = 0;
    bool palyndrome = true;
    for(int i = 0; i < size;++i){
        while (palyndrome && (j < (v[i].Plate.length()))/2){
            palyndrome = (v[i].Plate[j] == v[i].Plate[v[i].Plate.length()-1-j]);
            ++j;
        }
        if (palyndrome){
            showOnScreen(v[i],size);
        }
        palyndrome = true;
        j = 0;
    }

}

int main() {
    int size = 2;
    int posMostExpensive;
    Vehicle a = {"mercedes","hola","123456",1907,200};
    Vehicle list[MAX_VEHICLES];
    list[0] = {"mercedes","hola","123321",1907,200};
    list[1] = {"mercedes","hola","123452",1907,200};
    /*do{
        cout << "Introduce the number of vehicles:";
        cin >> size;
    }while(size > MAX_VEHICLES);
    kbRead(list,size);
    posMostExpensive = findMostExpensive(list,size);
    showOnScreen(list,size);
    cout << "The most expensive vehicle data is:" << endl;
    showOnScreen(list[posMostExpensive],size);
    platesSECharacter(list,size);*/
    platesPalyndrome(list,size);
    return 0;
}
