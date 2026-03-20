/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */




#include <stdio.h>
#include "sesion4_ej3.h"


unsigned int menu() 
{
    unsigned int val = 0;
    printf("********** MENU **********\n");
    printf("1. Calcular potencia\n");
    printf("2. Calcular factorial\n");
    printf("3. Calcular numero combinatorio\n");
    printf("4. Salir\n\n");
    
    printf("Escoja una opcion: ");
    scanf("%u", &val);
    printf("\n");
    
    
    return (val);
    
}


float potencia(float real, int n)
{
    float res = 1.0;
    
    int i;
    
    for (i = 0; i < n; i++)
    {
        res = res * real;
    }
    
    return (res);
}


unsigned long long factorial(unsigned int arg)
{
    unsigned long long factorial = 1;
    
    int i;
    
    for (i = 1; i <= arg; i++){
        factorial = factorial * i;
        
    }
    
    return (factorial);
    
}



float combinatorio(int m, int n)
{
    float res = 0, num, den;
    
    
    num = factorial(m);
    
    den = factorial(n)*factorial(m-n);
    
    
    res = num / den;
    
    return (res);
    
    
    
    
    
    
}


void sesion4_ej3()
{
    unsigned int opt, arg;
    
    float real;
    
    int natural, n, m;
    
    
    opt = menu();
    
    while (opt != 4)
    {
        if (opt == 1){
            printf("Ha escogido la opcion calcular potencia\n");
            
            printf("\nIntroduzca el valor de x (real): ");
            scanf("%f", &real);
            
            printf("\n\nIntroduzca el valor de n (natural): ");
            scanf("%d", &natural);
            
            
            
            printf("\n%.2f elevado a %d es igual a: %.2f", real, natural, potencia(real, natural));
            printf("\n\n");
        }
        else if (opt == 2){
            printf("Ha escogido la opcion calcular factorial\n");
            
            printf("\nIntroduzca un numero entero positivo: ");
            scanf("%d", &arg);
            
            printf("Factorial de %d es: %llu", arg, factorial(arg));
            printf("\n\n");
        }
        else if (opt == 3){
            printf("Ha escogido la opcion calcular numero combinatorio\n\n");
            
            printf("Introduzca el numero combinatorio (m n): ");
            scanf(" (%d %d)", &m, &n);
            
            printf("%.2f\n\n", combinatorio(m,n));
        }
        else{
            printf("Ha escogido una opcion incorrecta. Vuelva a intentarlo!");
        }
        
        opt = menu();
        
    }
    
    printf("Ha escojido la opcion salir");
    
    
    
    
    
}