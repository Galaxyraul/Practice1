#include <iostream>
#include "djutils.h"
#include "Fecha.h"
#include "Garito.h"
#include "Temazo.h"
#include <iostream>


int main() {
    Temazo t1;
    Temazo t2("I hate everything about you","Three days grace",231);

    Garito g1("Moët","Av.Andalucía nº 30");
    Garito g2 (g1);

    Fecha f1;
    Fecha f2(13,4,2003);
}
