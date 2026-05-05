/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: alexch
 *
 * Created on 30 d’abril del 2026, 9:42
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*
 * 
 */
int main(int argc, char** argv) {

    t_queue *cua = crear_cua();
    int valor, res;
    
    if (cua == NULL)
        return EXIT_FAILURE;

    printf("%d\n", enqueue(cua, 1));
    printf("%d\n", enqueue(cua, 2));
    printf("%d\n", enqueue(cua, 3));
    printf("%d\n", enqueue(cua, 4));
    printf("%d\n", enqueue(cua, 5));
    printf("%d\n\n", enqueue(cua, 6));

    printf("Extracció en mode FIFO:\n");    
    valor = dequeue(cua, &res);

    printf("valor = %d, res = %d\n", valor, res);
    valor = dequeue(cua, &res);
    printf("valor = %d, res = %d\n", valor, res);
    valor = dequeue(cua, &res);
    printf("valor = %d, res = %d\n", valor, res);
    valor = dequeue(cua, &res);
    printf("valor = %d, res = %d\n", valor, res);
    valor = dequeue(cua, &res);
    printf("valor = %d, res = %d\n", valor, res);
    valor = dequeue(cua, &res);
    printf("valor = %d, res = %d\n", valor, res);
    valor = dequeue(cua, &res);
    printf("valor = %d, res = %d\n", valor, res);
    valor = dequeue(cua, &res);
    printf("valor = %d, res = %d\n", valor, res);

    alliberar_cua(cua);

    return (EXIT_SUCCESS);
}

