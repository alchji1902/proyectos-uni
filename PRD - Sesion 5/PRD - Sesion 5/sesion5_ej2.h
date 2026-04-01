/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef SESION5_EJ2_H
#define SESION5_EJ2_H

#include <stdio.h>

#define MAX_PERSONAS 200

typedef struct
{
    int numero;
    char letra;
    
}t_dni;

typedef struct
{
    char nom[20];
    t_dni dni;
    
}t_persona;

typedef struct
{
    int nper;
    t_persona personas[MAX_PERSONAS];
}t_lista_personas;

t_persona leer_persona();
void mostrar_persona(t_persona p);
void leer_lista_personas (t_lista_personas *lp);
void mostrar_lista_personas(t_lista_personas lp);
int insertar_persona (t_lista_personas *lp, t_persona p);

void sesion5_ej2a();
void sesion5_ej2b();
void sesion5_ej2c();

#endif /* SESION5_EJ2_H */
