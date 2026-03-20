/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sesion4_ej4.h"
#include <stdio.h>




t_fraccion leer_fraccion()
{
    t_fraccion frac;
    
    
    printf("Fraccion (formato x/y): ");
    scanf("%d/%d", &frac.num, &frac.den);
    
    
    return (frac);
    
}


void mostrar_fraccion(t_fraccion f)
{
    
    printf("%d/%d", f.num, f.den);
    
}



t_fraccion operaciones_fracciones(char operador, t_fraccion f1, t_fraccion f2)
{
    t_fraccion fracres, frac1, frac2;
    
    frac1 = f1;
    frac2 = f2;
    
    
    
    switch (operador){
        
        case '+':
            fracres.num = (frac1.num * frac2.den) + (frac2.num * frac1.den);
            fracres.den = (frac1.den * frac2.den);
            break;
        
        case '-':
            fracres.num = (frac1.num * frac2.den) - (frac2.num * frac1.den);
            fracres.den = (frac1.den * frac2.den);
            break;
        case '*':
            fracres.num = (frac1.num * frac2.num);
            fracres.den = (frac1.den * frac2.den);
            break;
        case '/':
            fracres.num = (frac1.num * frac2.den);
            fracres.den = (frac1.den * frac2.num);
            break;
            
    }
    
    
    return (fracres);
    
    
}

void sesion4_ej4()
{
    t_fraccion f1, f2;
    
    char op;
    
    printf("Introduzca dos fracciones:\n ");
    
    
    f1 = leer_fraccion();
    f2 = leer_fraccion();
    
    printf("Introduzca un operador (+ o - o * o /): ");
    
    scanf(" %c", &op);
    
    
    printf("\nEl resultado de la suma es: %d/%d %c %d/%d = %d/%d", f1.num, f1.den, op, f2.num, f2.den, operaciones_fracciones(op, f1, f2).num, operaciones_fracciones(op, f1, f2).den);
    
}