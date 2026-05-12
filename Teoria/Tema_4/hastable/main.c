/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: alexch
 *
 * Created on 7 de maig del 2026, 8:38
 */

#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

/*
 * 
 */
int main(int argc, char** argv) {

    t_hasht *taula;

    t_nif nif1 = {111111111, 'A'};
    t_nif nif2 = {222222222, 'B'};
    t_nif nif3 = {333333333, 'C'};
    t_nif nif4 = {444444444, 'D'};
    t_nif nif5 = {555555555, 'E'};

    t_persona p1 = {nif1, "Maria"};
    t_persona p2 = {nif2, "Joan"};
    t_persona p3 = {nif3, "Marta"};
    t_persona p4 = {nif4, "Laia"};

    int ret;

    t_persona *persona;

    taula = crear_taula(16);

    if (taula == NULL)
    {
        printf("Error al crear la taula hash\n");
        return (EXIT_FAILURE);
    }

    printf("%d\n", put(taula, nif1, p1));
    printf("%d\n", put(taula, nif2, p2));
    printf("%d\n", put(taula, nif3, p3));
    printf("%d\n\n", put(taula, nif4, p4));


    ret = conte_persona(taula, nif1);
    if (ret)
    {
        printf("La taula hash conte la persona buscada\n");
        persona = get(taula, nif1);    
        printf("El seu nom es: %s\n", persona->nom);
    }
    else
    {    
        printf("La taula hash no conte la persona buscada\n");
    }

    printf("\n%d\n\n", eliminar(taula, nif1));

    if (ret)
    {
        printf("La taula hash conte la persona buscada\n");
        persona = get(taula, nif1);    
        printf("El seu nom es: %s\n", persona->nom);
    }
    else
    {    
        printf("La taula hash no conte la persona buscada\n");
    }

    alliberar_taula(taula);

    return (EXIT_SUCCESS);
}

