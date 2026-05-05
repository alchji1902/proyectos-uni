/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   queue.c
 * Author: alexch
 * 
 * Created on 30 d’abril del 2026, 9:42
 */

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>



t_queue * crear_cua(){
    t_queue *cua;

    cua = (t_queue *)malloc(sizeof(t_queue));
    
    if(cua != NULL){
        cua->size = 0;
        cua->head = cua->tail = NULL;
    }

    return cua;
}

void alliberar_cua(t_queue *cua){
    t_node *tmp;

    while(cua->head != NULL){
        tmp = cua->head;
        cua->head = cua->head->next;
        free(tmp);
        cua->size--;
    }
    
    free(cua);
}




int enqueue(t_queue *cua, int valor)
{
    t_node *node;

    node = (t_node *)malloc(sizeof(t_node));

    if(node == NULL){
        return -1;
    }

    node->valor = valor;
    node->next = NULL;

    if(cua->size == 0){
        cua->head = cua->tail = node;
    }else{
        cua->tail->next = node;
        cua->tail = node;
    }

    cua->size++;

    return 0;
}


int dequeue(t_queue *cua, int *res)
{
    t_node *tmp;

    int valor;

    if(cua->size == 0){
        *res = -1; // Cua buida, no hi ha res a retornar. 
        return -1; // Valor retornat invalid per indicar error.
    }

    valor = cua->head->valor; // Guardem el valor del node que anem a eliminar per retornar-lo després.

    tmp = cua->head;
    cua->head = cua->head->next;
    free(tmp);

    if (cua->head == NULL)
        cua->tail = NULL; // Si la cua queda buida després de eliminar el node, actualitzem el punter tail a NULL.
    
    *res = 0; // Simplement indiquem que l'operació s'ha realitzat correctament.
    cua->size--;
    return valor;
}

