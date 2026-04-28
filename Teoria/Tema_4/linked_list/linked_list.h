/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   linked_list.h
 * Author: alexch
 *
 * Created on 23 d’abril del 2026, 8:34
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node
{
    int valor;
    struct node *next;

}t_node;


typedef struct 
{
    int size;
    t_node *head;
    
}t_linked_list;


t_linked_list * crear_llista();
void alliberar_llista(t_linked_list *llista);
int add(t_linked_list *llista, int valor);
void mostrar_llista(t_linked_list *llista);


t_node * obtenir_node(t_linked_list *llista, int index);
int set(t_linked_list *llista, int index, int valor);
int inserir(t_linked_list *llista, int index, int valor);
int eliminar(t_linked_list *llista, int index);
void invertir(t_linked_list *llista);
void ordenar(t_linked_list *llista);

#endif /* LINKED_LIST_H */

