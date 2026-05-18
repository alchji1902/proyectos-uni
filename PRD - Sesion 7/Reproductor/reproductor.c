/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "reproductor.h"


t_lista_rep *crear_lista_reproduccion()
{
    t_lista_rep *list;
    
    list = (t_lista_rep *)malloc(sizeof(t_lista_rep));
    
    if (list != NULL)
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;

    return (list);
}

void liberar_lista_reproduccion(t_lista_rep *lista)
{
    t_node *tmp;
    
    if (lista->size == 0)
        return;
    
    while (lista->head != NULL){
        tmp = lista->head->next;
        free(lista->head);
        lista->size--;
        lista->head = tmp;
    }
}

int add_cancion_final(t_lista_rep *lista, t_cancion c)
{
    t_node *node;
    
    node = (t_node *)malloc(sizeof(t_node));
    
    if (node == NULL){
        return (MEM_ALLOC_FAILURE);
    }
    
    node->cancion = c;
    node->next = NULL;
    
    if (lista->tail == NULL){
        lista->head = node;
        lista->tail = node;
        node->prev = NULL;
    }
    
    else{
        lista->tail->next = node;
        node->prev = lista->tail;
        lista->tail = node;
    }
        
    lista->size++;
    
    
    
    return (ACTION_SUCCESS); 
}

void mostrar_cancion (t_cancion c)
{
    printf("%s (%s), %d:%d", c.titulo, c.autor, c.duracion/60, c.duracion % 60);
}

void mostrar_contenido (t_lista_rep *lista)
{
    int i;
    t_node *tmp;
    
    tmp = lista->head;
    
    
    for (i = 0; i < lista->size; i++){
        printf("[%d] ", i);
        mostrar_cancion(tmp->cancion);
        tmp = tmp->next;
        printf("\n");
    }
}

void reproducir(t_lista_rep *lista)
{
    char option = '\0';
    
    t_node *tmp;
    
    while (option != 'e'){
        
        printf("Esta sonado: ");
        mostrar_cancion(tmp->cancion);
        printf("[n]ext, [b]ack, [e]nd: ");
        scanf("%c%*c", &option);
        
        switch (option){
            case 'e':
                break;
            case 'n':
                if (tmp->next == NULL)
                    tmp = lista->head;
                tmp = tmp->next;
                break;
            case 'b':
                if (tmp->prev == NULL)
                    tmp = lista->tail;
                tmp = tmp->prev;
        }
        
    }
    
    printf("Cerrando aplicacion....");
}

int insertar_cancion(t_lista_rep *lista, t_cancion c, int pos)
{
    /* Falta implementar */
    return (ACTION_SUCCESS);
}

int eliminar_cancion(t_lista_rep *lista, int pos)
{
    /* Falta implementar */
    return (ACTION_SUCCESS);
}
