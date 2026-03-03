/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "ejercicios.h"

void sesion2_ej1()
{
    /* Completar con el código del ejercicio 1 */
    int h, m, s, nh, nm, ns;
    printf("Introduce una hora en formato hh:mm:ss: ");
    scanf("%d:%d:%d%*c", &h, &m, &s);
    
    s++;
    
    ns = s % 60;
    m = m + s / 60;
    nm = m % 60;
    h = h + m/60;
    nh = h % 24;
    
    printf("%02d:%02d:%02d", nh, nm, ns);
    
}


void sesion2_ej2()
{
    /* Completar con el código del ejercicio 2 */
    
}


void sesion2_ej3()
{
    /* Completar con el código del ejercicio 3 */
    float nota;
    
    printf("Introduzca su nota de PRD (numero entre 0 y 10): ");
    scanf("%f", &nota);
    if (nota >= 9.0) {printf("Tiene un sobresaliente :-))");}
    else if (nota >= 7.0){printf("Tiene un notable :-))");}
    else if (nota >= 5.0) {printf("Tiene un aprobado :-))");}
    else {printf("Ha suspendido; tiene que matricularse de PRD de nuevo :-(");}
    
    
}


void sesion2_ej4()
{
    /* Completar con el código del ejercicio 4 */
    
}


void sesion2_ej5a()
{
    /* Completar con el código del ejercicio 5.a */
    
}


void sesion2_ej5b()
{
    /* Completar con el código del ejercicio 5.b */
    
}


void sesion2_ej5c()
{
    /* Completar con el código del ejercicio 5.c */
    
}


void sesion2_ej6a()
{
    /* Completar con el código del ejercicio 6.a */
    
}


void sesion2_ej6b()
{
    /* Completar con el código del ejercicio 6.b */
    
}

void sesion2_ej7()
{
    /* Completar con el código del ejercicio opcional 7 */
    
}


void sesion2_ej8()
{
    /* Completar con el código del ejercicio opcional 8 */
    
}