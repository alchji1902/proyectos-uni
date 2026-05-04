/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "nif.h"
#define CAPACIDAD_INICIAL 5

typedef struct
{
    int capacidad;
    int ocupada;
    t_nif *nifs;    /* Array interno de variables t_nif */
     
}t_array_list;

t_array_list * crear_lista();
void liberar_lista(t_array_list *lista);
int add(t_array_list *lista, t_nif nif);
void mostrar_lista(t_array_list *list);
void ordenar_lista_por_nif(t_array_list *lista);
int insertar_en_orden(t_array_list *lista, t_nif nif);
int buscar_registro_ordenado(t_array_list *lista, t_nif nif);
int eliminar_nif(t_array_list *lista, t_nif nif);

#endif /* ARRAY_LIST_H */

