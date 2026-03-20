/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */




#include <stdio.h>
#include "sesion4_ej3.h"


int menu() 
{
    unsigned int val = 0;
    printf("********** MENU **********");
    printf("1. Calcular potencia");
    printf("2. Calcular factorial");
    printf("3. Calcular numero combinatorio");
    printf("4. Salir");
    
    printf("Escoja una opcion: ");
    scanf("%ud", &val);
    
    return (val);
    
}


int potencia(float real, int n)
{
    int i, res = 0;
    
    for (i = 0; i < n; i++)
    {
        res = res * real;
    }
    
    
    return (res);
}


float factorial(unsigned int arg)
{
    unsigned long long factorial = 1;
    
    for (i = 1; i <= arg; i++){
        factorial = factorial * i;
        
    }
    
    return (factorial);
    
}

void sesion4_ej3()
{
    unsigned int opt, arg;
    
    float real;
    
    int n;
    
    
    opt = menu();
    
    
    
    
}