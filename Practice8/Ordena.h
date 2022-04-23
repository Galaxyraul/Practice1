//
// Created by cocol on 23/04/2022.
//

#ifndef PRUEBA_ORDENA_H
#define PRUEBA_ORDENA_H
template<typename T>
void ordena(T* v[], int tamV){
    T* aux;
    for(int i = 0; i < tamV; ++i){
        for(int j = 0;j < tamV - i - 1; ++j){
            if(v[j]!= nullptr){
                while(v[j+1] == nullptr && j < tamV -i -1){
                    ++j;
                }
                if (j == tamV -i -1){
                    break;
                }
                if(*v[j] < *v[j+1]){
                    aux = v[j+1];
                    v[j+1] = v[j];
                    v[j] = aux;
                }
            }
        }
    }
}
#endif //PRUEBA_ORDENA_H
