/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "nif.h"
#include "array_list.h"




t_array_list * crear_llista()
{
    t_array_list list = malloc(sizeof(t_array_list));
    
    if (list == NULL)
        return(NULL);
    
    list->capacidad = CAPACIDAD_INICIAL;
    
    list->nifs = calloc(list->capacidad, sizeof(int) * CAPACIDAD_INICIAL);
    
    if (list->nifs == NULL){
        free(list);
        return(NULL);
    }
    
    
    return(list);
}




void liberar_lista(t_array_list *lista)
{
    free(lista->nifs);
    free(lista);
}




int add(t_array_list *lista, t_nif nif)
{
    

    
}
