/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: alexch
 *
 * Created on 30 d’abril del 2026, 9:11
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


/*
 * 
 */
int main(int argc, char** argv) {

    t_stack *pila = crear_pila();
    int valor, res;
    
    if (pila == NULL)
        return EXIT_FAILURE;

    printf("%d\n", push(pila, 1));
    printf("%d\n", push(pila, 2));
    printf("%d\n", push(pila, 3));
    printf("%d\n", push(pila, 4));
    printf("%d\n", push(pila, 5));
    printf("%d\n\n", push(pila, 6));

    printf("Extracció en mode LIFO:\n");    
    valor = pop(pila, &res);

    printf("valor = %d, res = %d\n", valor, res);
    valor = pop(pila, &res);
    printf("valor = %d, res = %d\n", valor, res);
    valor = pop(pila, &res);
    printf("valor = %d, res = %d\n", valor, res);
    valor = pop(pila, &res);
    printf("valor = %d, res = %d\n", valor, res);
    valor = pop(pila, &res);
    printf("valor = %d, res = %d\n", valor, res);
    valor = pop(pila, &res);
    printf("valor = %d, res = %d\n", valor, res);
    valor = pop(pila, &res);
    printf("valor = %d, res = %d\n", valor, res);
    valor = pop(pila, &res);

    alliberar_pila(pila);

    return (EXIT_SUCCESS);
}

