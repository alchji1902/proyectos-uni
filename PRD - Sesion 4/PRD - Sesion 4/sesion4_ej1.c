/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <stdio.h>
#include "sesion4_ej1.h"


int suma_digitos(int num) {
    
    
    int digits = 0, restant = num, suma = 0, i, rest;

    while (restant != 0) {

        restant = restant / 10;
        digits++;

    }
    
    
    rest = num; 
    
    for (i = 0; i < digits; i++){
        
        suma = suma + rest%10;
        rest = rest / 10;
        
    }
    return suma;
    
    
}


void sesion4_ej1() 
{
    int sum, num;
    
    printf("Introduzca un valor natural: ");
    scanf("%d", &num);
    
    
    sum = suma_digitos(num);
    
    printf("La suma de los digitos de %d es: %d", num, sum);
    
    
}