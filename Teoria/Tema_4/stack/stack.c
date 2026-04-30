/* 
 * File:   stack.c
 * Author: alexch
 * 
 * Created on 30 d’abril del 2026, 9:11
 */

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>


t_stack * crear_pila()
{
    t_stack *pila = malloc(sizeof(t_stack));
    if (pila == NULL)
        return NULL;
    pila->head = NULL;
    pila->size = 0;
    return pila;
}

void alliberar_pila(t_stack *pila)
{
    t_node *tmp;
    
    while (pila->head != NULL)
    {
        tmp = pila->head->next;
        free(pila->head);
        pila->head = tmp;
        pila->size--;
    }

    free(pila);
}


int push(t_stack *pila, int valor)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    
    if (node == NULL)
        return -1;
    
    node->valor = valor;
    node->next = pila->head;
    pila->head = node;
    pila->size++;
    
    return 0;
}



int pop(t_stack *pila, int *res)
{
    int valor;
    t_node *tmp;

    if (pila->size == 0) {
        *res = -1;
        return -1;
    }

    *res = 0;
    valor = pila->head->valor;
    tmp = pila->head->next;
    free(pila->head);
    pila->head = tmp;
    pila->size--;
    
    return valor;
}


