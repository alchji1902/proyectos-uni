/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "complex.h"
#include <math.h>



t_complex llegir_complex() {
    
    t_complex c;
    
    printf("Introdueix un nombre complex(format: a+bi: ");
    scanf("%f+%fi", &c.real, &c.imaginaria);
    
    return (c);
    
}





void mostrar_complex(t_complex c){
    
    if (c.real != 0.0) {
        printf("%f ", c.real);
        if (c.imaginaria > 0)
            printf("+");
    }
    
    if (c.imaginaria != 0.0){
        printf("%fi", c.imaginaria);
    }
}





float calcular_mod(t_complex c) {
    
    return (sqrt(c.real*c.real + c.imaginaria*c.imaginaria));
    
    
}


float calcular_arg(t_complex c){
    
    return(atan2(c.imaginaria, c.real)); 
}



void sumar(t_complex *res, t_complex c1, t_complex c2)
{
    (*res).real = c1.real + c2.real;
    (*res).imaginaria = c1.imaginaria + c2.imaginaria;
    
}


void restar(t_complex *res, t_complex c1, t_complex c2)
{
    res->real = c1.real - c2.real;
    res->imaginaria = c1.imaginaria - c2.imaginaria;
    
}



void multiplicar(t_complex *res, t_complex c1, t_complex c2)
{
    float mod = calcular_mod(c1)*calcular_mod(c2);
    float arg = calcular_arg(c1) + calcular_arg(c2);
    
    res->real = mod * cos(arg);
    res->imaginaria = mod * sin(arg);
}


void dividir(t_complex *res, t_complex c1, t_complex c2)
{
    
    
}



