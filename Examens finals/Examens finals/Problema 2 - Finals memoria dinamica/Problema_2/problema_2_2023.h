/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   problema_2.h
 * Author: alexch
 *
 * Created on 27 de maig del 2026, 18:31
 */

#ifndef PROBLEMA_2_H
#define PROBLEMA_2_H


typedef struct node
{
    int valor; /* Valor guardat al node de la llista */
    struct node *next; /* Punter al següent node de la llista */
}t_node;


typedef struct
{
    int size; /* Nombre de valors guardats */
    t_node *head; /* Punter al primer node de la llista */
}t_llista;

int comparar (t_llista *llista1, t_llista *llista2);
int identificar_ordre (t_llista *llista);
void obtenir_array (t_llista *llista, int **v);
t_llista * duplicar (t_llista *llista);



#endif /* PROBLEMA_2_H */
