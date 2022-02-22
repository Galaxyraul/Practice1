#include <iostream>
#include "vehicle.h"
using namespace v;

int main() {
    int tam;
    string plate;
    int pos;
    try{
        cout << "Introduce the size of the array:";
        cin >> tam;
        if (tam < 0){
            throw string ("Error the size can't be negative");
        }
        Vehicle *v1 = new Vehicle[tam];
        try {
            fillVector(v1, tam);
            showOnScreen(v1,tam);
            try {
                pos = maxPrice(v1, tam);
                cout << "The most expensive is:" << endl;
                showOnScreen(v1[pos]);
                try{
                    cout << "Introduce the number of plate to change:";
                    cin >> plate;
                    pos = searchByPlate(plate,v1,tam);
                    try{
                        kbRead(v1[pos]);
                    }
                    catch (string &e){
                        cout << e;
                    }
                }
                catch (string& e){
                    cout << e;
                }
            }
            catch (string& e){
                cout << e;
            }
        }
        catch (string& e){
            cout << e;
        }
        delete [] v1;
        v1 = nullptr;
        return 0;
    }
    catch (string& e){
        cout << e;
    }



}
