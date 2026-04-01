/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef SESION5_EJ1_H
#define SESION5_EJ1_H

#include <stdio.h>

#define MAX_ELEM 100

typedef struct{
    int nelem;
    int vector[MAX_ELEM];
} t_vector;

int eliminar_elemento(int elem, t_vector *v);

void sesion5_ej1();

#endif /* SESION5_EJ1_H */
