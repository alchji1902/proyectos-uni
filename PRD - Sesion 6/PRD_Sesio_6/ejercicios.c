/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "nif.h"
#include "array_list.h"



void sesion6_ej1()
{
    t_nif nif1 = generar_nif_aleatorio(), nif2 = generar_nif_aleatorio();
    
    mostrar_nif(nif1);
    printf("\n");
    mostrar_nif(nif2);
    printf("\n");
    
    
    if (comparar_nifs(nif1, nif2) > 0)
        printf("nif1 es mayor que nif2. ");
    else if (comparar_nifs(nif1, nif2) < 0)
        printf("nif2 es mayor que nif1. ");
    else
        printf("Los nifs son iguales. ");
    
    
}



