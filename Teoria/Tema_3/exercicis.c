/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include <stdio.h>
#include <stdlib.h>
#include "exercicis.h"
#include "array_list.h"


void exercici7()
{
    t_array_list *llista;
   
    llista = crear_llista();
    
    if (llista == NULL)
    {
        printf("Error creant la llista basada en array. \n");
        return;
    } 
    
    printf("%d\n", add(llista, 1));
    printf("%d\n", add(llista, 2));
    printf("%d\n", add(llista, 3));
    printf("%d\n", add(llista, 4));
    printf("%d\n", add(llista, 5));
    printf("%d\n\n", add(llista, 6));
    
    
    
    
    //Comprovem que s'insereixi be. 
    printf("%d\n\n", inserir(llista, 0, 1000));
    
    mostrar_llista(llista);
    
    alliberar_llista(llista);
    
}

void exercici9()
{
    t_array_list *llista, *clon;
   
    llista = crear_llista();
    
    if (llista == NULL)
    {
        printf("Error creant la llista basada en array. \n");
        return;
    }
    
    printf("%d\n", add(llista, 3));
    printf("%d\n", add(llista, 2));
    printf("%d\n", add(llista, 1));
    printf("%d\n", add(llista, 5));
    printf("%d\n\n", add(llista, 4));
    
    printf("LLista original\n");
    mostrar_llista(llista);
    clon = clonar_llista(llista);
    if (clon == NULL){
        printf("Error clonant la llista\n");
        return;
    }
    
    ordenar_llista(llista);
    
    printf("LLista original: \n");
    mostrar_llista(llista);
    
    printf("LLista original: \n");
    mostrar_llista(clon);
    
    
    
    alliberar_llista(llista);
    alliberar_llista(clon);
    
    
}