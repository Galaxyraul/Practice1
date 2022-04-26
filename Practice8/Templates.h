//
// Created by Galaxyraul on 26/04/2022.
//

#ifndef PRUEBA_TEMPLATES_H
#define PRUEBA_TEMPLATES_H
template <typename T>
int superiorMutants (T** v,T value,int tamV){
    int count = 0;
    for(int i = 0; i < tamV; ++i){
       count = !(**v < value)? ++count:count;
    }
    return count;
}

#endif //PRUEBA_TEMPLATES_H
