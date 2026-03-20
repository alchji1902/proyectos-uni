/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sesion4-ej1.h
 * Author: alexch
 *
 * Created on 16 de març de 2026, 12:13
 */

#ifndef SESION4_EJ1_H
#define SESION4_EJ1_H


typedef struct 
{
    int num;
    int den;
    
}t_fraccion;


t_fraccion leer_fraccion();

void mostrar_fraccion(t_fraccion f);


t_fraccion operaciones_fracciones(char operador, t_fraccion f1, t_fraccion f2);


void sesion4_ej4();





#endif /* SESION4_EJ1_H */

