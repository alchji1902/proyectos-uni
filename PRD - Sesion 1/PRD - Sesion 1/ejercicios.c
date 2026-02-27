/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "ejercicios.h"
#include "colours.h"

void sesion1_ej1()
{
    /* Completar con el código del ejercicio 1 */
    char a, b, c;
    int any;
    int edad;
    
    char a1, b1, c1;
    int edad1;
    
    printf("Introduce tu anyo de nacimiento: ");
    scanf(" %d", &any);
    
    
    printf("Introduce tus tres iniciales: ");
    scanf(" %c %c %c", &a, &b, &c);
    
    
    edad = 2030 - any;
    
    edad1 = cambiar_color(YELLOW);
    a1 = cambiar_color(RED);
    b1 = cambiar_color(RED);
    c1 = cambiar_color(RED);
    
    printf("Hola %c%c%c\n", a, b, c);
    printf("El 31/DIC/2030 tendras %d anys\n", edad);
    
}


void sesion1_ej2()
{
    /* Completar con el código del ejercicio 2 */
    
}


void sesion1_ej3()
{
    /* Completar con el código del ejercicio 3 */
    
}


void sesion1_ej4()
{
    /* Completar con el código del ejercicio 4 */
    
}


void sesion1_ej5()
{
    /* Completar con el código del ejercicio 5 */
    
}