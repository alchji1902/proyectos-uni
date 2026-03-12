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