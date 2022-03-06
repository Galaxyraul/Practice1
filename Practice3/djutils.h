//
// Created by cocol on 26/02/2022.
//

#ifndef PRACTICE2_DJUTILS_H
#define PRACTICE2_DJUTILS_H
#include "Fecha.h"
#include "Garito.h"
#include "Temazo.h"

/**
 * @brief Module that has complementary function to the classes
 * @param temazo Object of type Temazo with its corresponding data
 * @param garito Object of type Garito with its corresponding data
 * @param fecha Object of type fecha with its corresponding data
 */
void showTemazo(const Temazo& temazo );

void showGarito(const Garito& garito );

void showFecha(const Fecha& fecha );

void changeGarito(Garito& garito);

void showPreviousTemazos(const Temazo t[] ,const int tam, Fecha f);



#endif //PRACTICE2_DJUTILS_H
