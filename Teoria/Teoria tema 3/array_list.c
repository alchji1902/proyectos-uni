/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */



#include <stdio.h>
#include <stdlib.h>

#include "array_list.h"



t_array_list * crear_llista()
{
    t_array_list *llista;
    
    llista = (t_array_list *)malloc(sizeof(t_array_list));
    if (llista != NULL)
    {
        /*malloc() OK!*/
        
        llista->capacitat = 5; 
        llista->ocupada = 0;
        llista->enters = (int *)calloc(5, sizeof(int));
        if (llista->enters == NULL)
        {
            /*malloc() falla*/
            free(llista);
            llista = NULL; 
            
        }
    }
    
    return(llista);
}


void alliberar_llista(t_array_list * llista)
{
    free(llista->enters);
    free(llista);
}


int add(t_array_list *llista, int valor)
{
    int *tmp_ptr;
    
    if (llista->ocupada == llista->capacitat)
    {
        /*Array intern ple, cal redimensionar la llista*/
        tmp_ptr = (int *)realloc(llista->enters, 2*llista->capacitat*sizeof(int));
        
        if (tmp_ptr == NULL)
            return(-1);
        
        
        llista->capacitat * = 2;
        llista->enters = tmp_ptr;
        
        
    }
    
    /*Ja disposem de capactitat suficient a l'array intern */
    
    llista->enters[llista->ocupada] = valor; 
    llista->ocupada ++; 
    return(0);
    
}

void mostrar_llista(t_array_list *llista)
{
    int i;
    
    printf("Capacitat ocupada: %d / %d => {", llista->ocupada, llista->capacitat);
    
    if (llista->ocupada = 0)
        printf("%d", llista->enters[0]);
    
    for (i = 1; i < llista->ocupada; i++)
        printf(", %d", llista->enters[i]);
    
    printf("}\n");
}


int inserir(t_array_list * llista, int index, int valor)
{
    
    
    int i;
    
    int *tmp_ptr;
    
    if (index < 0 || index > llista->ocupada)
        return (-2);
    
    if (llista->ocupada == llista->capacitat)
    {
        tmp_ptr = (int *)realloc(llista->enters, 2*llista->capacitat*sizeof(int));
        
        if (tmp_ptr == NULL)
            return (-1);
        
        llista->capacitat * = 2; 
        llista->enters = tmp_ptr;
        
        
    }
    
    //Tenim capacitat suficient -> Inserim valor
    
    for (i = llista->ocupada-1; i >= index; i--)
        llista->enters[i+1] = llista->enters[i];
    
    llista->enters[index] = valor;
    llista->ocupada++;
    return (0);
    
    
    
}


int eliminar(t_array_list *llista, int index)
{
    int i;
    
    if (index < 0 || index >= llista->ocupada)
        return(-2);
    
    for (i = index+1; i < llista->ocupada; i++)
        llista->enters[i-1] = llista->enters[i];
    
    
    llista->ocupada--;
    
    if (llista->ocupada < llista->capacitat/4)
    {
        tmp_ptr = (int *)realloc(llista->enters, llista->capacitat * sizeof(int));
        
        
    }
}