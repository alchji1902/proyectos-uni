/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "nif.h"
#include "array_list.h"




t_array_list * crear_lista()
{
    t_array_list *list = malloc(sizeof(t_array_list));
    
    if (list == NULL)
        return(NULL);
    
    list->capacidad = CAPACIDAD_INICIAL;
    list->ocupada = 0;
    
    list->nifs = calloc(list->capacidad, sizeof(t_nif));
    
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
    t_nif *tmp;
    
    if (lista->capacidad == lista->ocupada)
    {
        tmp = (t_nif *)realloc(lista->nifs, (lista->capacidad * 2) * sizeof(t_nif));
        
        if (tmp == NULL)
            return(-1);
            
        lista->capacidad *=2;
        lista->nifs = tmp;
    }
    
    lista->nifs[lista->ocupada] = nif;
    lista->ocupada++;
    
    return(0);
    
    
}



void mostrar_lista(t_array_list *list)
{
    printf("Mostrando contenido de la lista (capacidad ocupada: %d/%d)\n", list->ocupada, list->capacidad);
    
    int i;
    
    for (i = 0; i < list->ocupada; i++)
    {
        mostrar_nif(list->nifs[i]);
        printf("\n");
    }
}



void ordenar_lista_por_nif(t_array_list *lista)
{
    int i, j;
            
    t_nif elem;
    
    for (i = 1; i < lista->ocupada; i++){
        elem = lista->nifs[i];
        j = i - 1;
        
        while(j>=0 && comparar_nifs(lista->nifs[j], elem) == 1){
            lista->nifs[j+1] = lista->nifs[j];
            j--;    
        }
        
        lista->nifs[j+1] = elem;
        
    }
    
    
    
}



int insertar_en_orden(t_array_list *lista, t_nif nif)
{
    int i, pos = 0;
    
    while (pos < lista->ocupada && comparar_nifs(lista->nifs[pos], nif) == -1)
        pos++;
    
    if (lista->capacidad == lista->ocupada){
        t_nif *tmp;

        tmp = (t_nif *)realloc(lista->nifs, (lista->capacidad * 2) * sizeof(t_nif));

        if (tmp == NULL)
            return(-1);
        
        lista->nifs = tmp;
        lista->capacidad *=2;

    }
    
    
    for (i = lista->ocupada -1; i >= pos; i--)
    {
        lista->nifs[i+1] = lista->nifs[i];
    }
    
    lista->nifs[pos] = nif;
    lista->ocupada++;
    return(0);
    
}


int buscar_registro_ordenado(t_array_list *lista, t_nif nif)
{
    int left = 0;
    int mid; 
    int right = lista->ocupada -1;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if(lista->nifs[mid].numero == nif.numero)
            return(mid);
        
        if (lista->nifs[mid].numero < nif.numero)
            left = mid + 1;
        
        else 
            right = mid - 1;

    }

    return (-1);

}
