#include <iostream>
#include "djutils.h"
#include "Fecha.h"
#include "Garito.h"
#include "Temazo.h"


int main() {
    bool end = false;
    int answer;
    Temazo t1;
    Temazo t2("I hate everything about you","Three days grace",231);

    Garito g1("Moët","Av.Andalucía nº 30");
    Garito g2 (g1);

    Fecha f1;
    Fecha f2(13,4,2003);
    while(!end){
        std::cout <<"1.-Show the data of the temazos." <<std::endl
        <<"2.-Show the data of the garitos" <<std::endl
        <<"3.-Show the data of the fechas"<< std::endl
        <<"4.-Modify the data of the second garito"<<std::endl
        <<"5.-End the apliccation" <<std::endl<<
        "What do you want to do:" ;
        std::cin >> answer;
       switch (answer) {
            case 1:
                showTemazo(t1);
                showTemazo(t2);
                break;
            case 2:
                showGarito(g1);
                showGarito(g2);
                break;
            case 3:
                showFecha(f1);
                showFecha(f2);
                break;
            case 4:
                try{
                    changeGarito(g2);
                    showGarito(g2);
                }catch (std::string& e){
                    std::cerr << e;
                }
                break;
            case 5:
                end = true;
                break;
        }
        Garito g3("La Bernarda","Av.Andalucía");
        g3.setDateOfLastShow(20,04,2021);
        std::cout << "The last day in which Segis performed was :";
        showFecha(g3.getDateOfLastShow());
    }
}
