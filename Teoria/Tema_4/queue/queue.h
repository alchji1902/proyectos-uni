/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   queue.h
 * Author: alexch
 *
 * Created on 30 d’abril del 2026, 9:42
 */

#ifndef QUEUE_H
#define QUEUE_H


typedef struct node{
    int valor; /*Element guardat*/
    struct node * next; 
    
}t_node;


typedef struct{
    int size;
    t_node *head;
    t_node *tail;
}t_queue;


t_queue * crear_cua();
void alliberar_cua(t_queue *cua);
int enqueue(t_queue *cua, int valor);
int dequeue(t_queue *cua, int *res);





#endif /* QUEUE_H */
