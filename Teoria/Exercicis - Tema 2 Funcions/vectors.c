/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio>
#include "vectors.h"



int afegeix_valor(t_vector *v, int valor)
{
    
    if (v->num_valors == MAX_VAL)
        return(-1);      /*El vector ja es ple*/
    
    
    v->valors[v->num_valors]=valor;
    v->num_valors++;
    
    return(0);
}


void mostra_contingut (t_vector *v)
{
    /*Mostra el contingut del vector apuntat per v
     en format: v --> {valor0, valor1, ....., valor_{num-1}}}*/
    int i;
    
    printf("v => {");
    
    if (v->num_valors > 0)
    {
        
        printf("%d", v->valors[0]);
        for (i = 1; i < v->num_valors; i++)
            printf(", %d", v->valors[i]);
    }
    
    printf("}\n");
    
}

