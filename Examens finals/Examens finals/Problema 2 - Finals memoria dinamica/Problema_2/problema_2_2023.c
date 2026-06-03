/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   problema_2.c
 * Author: alexch
 * 
 * Created on 27 de maig del 2026, 18:31
 */

#include "problema_2_2023.h"
#include <stdio.h>
#include <stdlib.h>



int comparar (t_llista *llista1, t_llista *llista2)
{
    t_node *tmp, *tmp2;
    int dif = -1;
    
    tmp = llista1->head;
    tmp2 = llista2->head;
    
    
    while ((dif != 1) && (tmp->next != NULL) && (tmp2->next != NULL)){
        if (tmp->valor != tmp2->valor){
            dif = 1;
        }
        else {
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }
    }
    
    if (dif == -1)
        return(1);
    
    else 
        return(0);
}



int identificar_ordre (t_llista *llista)
{   
    
    if (llista->head == NULL){
        return 0;
    }
    
    if (llista->size == 1){
        return 0;
    }
    
    
    if (llista->head < llista->head->next){
        return(1);
    }
    
    else if (llista->head > llista->head->next){
        return(-1);
    }
    
    else {
        return 1;
    }
    
}


void obtenir_array (t_llista *llista, int **v)
{
    t_node *tmp;
    
    int num_elem, i = 0;
    *v = (int *)calloc(llista->size, sizeof(int));
    
    if (*v == NULL){
        return;
    }
    
    if (llista->head == NULL){
        *v = NULL;
        return;
    }
    
    tmp = llista->head;
    
    while (tmp != NULL){
        (*v)[i] = tmp->valor;
        tmp = tmp->next;
        i++;
    }
}

t_llista * duplicar (t_llista *llista)
{
    t_llista *nova;
    
    t_node *tmp, *tmp2, *aux;
    
    nova = (t_llista *)malloc(sizeof(t_llista));
    
    if (nova == NULL){
        return NULL;
    }
    
    nova->head = NULL;
    nova->size = 0;
    
    if (llista->head == NULL){
        return nova;
    }
    
    nova->head = (t_node *)malloc(sizeof(t_node));
    
    if (nova->head == NULL){
        return NULL;
    }
    nova->head->valor = llista->head->valor;
    
    tmp = llista->head;
    aux = nova->head;
    
    while (tmp != NULL){
        tmp2 = (t_node *)malloc(sizeof(t_node));
        
        if (tmp2 == NULL){
            return NULL;
        }
        
        tmp2->valor = tmp->valor;
        aux->next = tmp2;
        tmp = tmp->next;
        aux = aux->next;
    }
    
    aux->next = NULL;
    
}
