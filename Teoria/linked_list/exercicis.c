/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   exercicis.c
 * Author: alexch
 * 
 * Created on 23 d’abril del 2026, 9:34
 */


#include <stdio.h>
#include <stdlib.h>
#include "exercicis.h"
#include "linked_list.h"

void exercici5()
{
    t_linked_list *llista;
    
    llista = crear_llista();
    
    if (llista == NULL)
    {
        printf("Error creant la llista enllaçada. \n");
        return;
    }
    
    printf("%d\n", add(llista, 1));
    printf("%d\n", add(llista, 2));
    printf("%d\n", add(llista, 3));
    printf("%d\n", add(llista, 4));
    printf("%d\n", add(llista, 5));
    printf("%d\n\n", add(llista, 6));
    
    mostrar_llista(llista);
    
    
    alliberar_llista(llista);
}
