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




