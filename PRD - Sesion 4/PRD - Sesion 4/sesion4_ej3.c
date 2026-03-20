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
    printf("********** MENU **********\n");
    printf("1. Calcular potencia\n");
    printf("2. Calcular factorial\n");
    printf("3. Calcular numero combinatorio\n");
    printf("4. Salir\n\n");
    
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
    unsigned int opt, arg, p;
    
    unsigned long long factorial;
    
    float real;
    
    int n;
    
    
    opt = menu();
    
    while (opt != 4)
    {
        if (opt == 1){
            printf("Ha escogido la opcion calcular potencia\n");
            p = potencia();
        }
        else if (opt == 2){
            printf("Ha escogido la opcion calcular factorial\n");
            
            factorial = factorial();
        }
        else if (opt == 3){
            printf("Opt 3");
        }
        else{
            printf("Opcion no valida!");
        }
        
    }
    
    
    
    
    
    
}