/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   hashtable.h
 * Author: alexch
 *
 * Created on 7 de maig del 2026, 8:38
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H


typedef struct{
    int num;
    char lletra;
}t_nif;

typedef struct{
    t_nif nif;
    char nom[20];
}t_persona;

typedef struct node{
    t_persona p;
    struct node * next; 
}t_node;


typedef struct{
    int ncas;
    t_node **array_caselles;
}t_hasht;


t_hasht * crear_taula (int ncas);
void alliberar_taula (t_hasht *taula);
int conte_persona(t_hasht *taula, t_nif nif);
int put(t_hasht *taula, t_nif nif, t_persona p);
t_persona * get(t_hasht *taula, t_nif nif);
int eliminar(t_hasht *taula, t_nif nif);





#endif /* HASHTABLE_H */
