/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   array_list.h
 * Author: alexch
 *
 * Created on 16 d’abril del 2026, 8:26
 */

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H



typedef struct{
    
    int capacitat;
    int ocupada;
    int *enters; /* Array intern de valors enters */
    
}t_array_list;



t_array_list * crear_llista();
void alliberar_llista(t_array_list *llista);
int add(t_array_list *llista, int valor);
void mostrar_llista(t_array_list *llista);
int inserir(t_array_list *llista, int index, int valor);
int eliminar(t_array_list *llista, int index);



#endif /* ARRAY_LIST_H */

