/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */




#include "sesion4_ej1.h"
#include <stdio.h>



void sesion4_ej2()
{
    int num;
    
    printf("Introduzca una secuencia de numeros finalizada en -1: ");
    while (num != -1){
        scanf("%d, ", &num);
        if (num != -1) {printf("La suma de los digitos de %d es %d\n", num, suma_digitos(num));}
        
    }
    
}


