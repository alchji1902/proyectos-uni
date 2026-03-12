/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include <stdio.h>
#include "complex.h"




void exercici5()
{
    t_complex c;
    
    c = llegir_complex();
    
    printf("El nombre complex introduit es: ");
    mostrar_complex(c);
    
    
    printf("\nEl seu modul es: %f\n", calcular_mod(c));
    
    printf("El seu argument es: %f radians\n", calcular_arg(c));
       
}


void exercici6a()
{
    t_complex c1, c2, res;
    c1 = llegir_complex();
    c2 = llegir_complex();
    
    
    
    sumar(res, c1, c2);
    
    printf("La suma entre %f+%fi i %f+%fi es: ", c1.real, c1.imaginaria, c2.real, c2.imaginaria);
    
    printf("%f+%fi", res.real, res.imaginaria);
   
}

void exercici6b()
{
    t_complex c1, c2, res;
    c1 = llegir_complex();
    c2 = llegir_complex();
    
    
    
    restar(res, c1, c2);
    
    printf("La resta entre %f+%fi i %f+%fi es: ", c1.real, c1.imaginaria, c2.real, c2.imaginaria);
    
    printf("%f-%fi", res.real, res.imaginaria);
    
    
}


void exercici6c()
{
    t_complex c1, c2, res;
    c1 = llegir_complex();
    c2 = llegir_complex();
    
    
    
    multiplicar(res, c1, c2);
    
    printf("La multiplicacio entre %f+%fi i %f+%fi es: ", c1.real, c1.imaginaria, c2.real, c2.imaginaria);
    
    printf("%f * %fi", res.real, res.imaginaria);
    
    
}

void exercici6d()
{
    t_complex c1, c2, res;
    
    c1 = llegir_complex();
    c2 = llegir_complex();
    
    
    
    multiplicar(res, c1, c2);
    
    printf("La divisió entre %f+%fi i %f+%fi es: ", c1.real, c1.imaginaria, c2.real, c2.imaginaria);
    
    printf("%f / %fi", res.real, res.imaginaria);
    
    
}