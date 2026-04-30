/* 
 * File:   stack.h
 * Author: alexch
 *
 * Created on 30 d’abril del 2026, 9:11
 */

#ifndef STACK_H
#define STACK_H

typedef struct node {
    int valor;
    struct node *next;
    
}t_node;


typedef struct{
    int size;
    t_node *head;
    
}t_stack;


t_stack * crear_pila();
void alliberar_pila(t_stack *pila);
int push(t_stack *pila, int valor);
int pop(t_stack *pila, int *res);

#endif /* STACK_H */
