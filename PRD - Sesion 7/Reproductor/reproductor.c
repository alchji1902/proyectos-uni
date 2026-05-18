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
    
    tmp = lista->head;
    
    while (option != 'e'){
        
        printf("Esta sonado: ");
        mostrar_cancion(tmp->cancion);
        printf("\n");
        printf("[n]ext, [b]ack, [e]nd: ");
        scanf("%c%*c", &option);
        
        switch (option){
            case 'e':
                break;
            case 'n':
                if (tmp->next == NULL)
                    tmp = lista->head;
                else {
                    tmp = tmp->next;
                }
                break;
            case 'b':
                if (tmp->prev == NULL)
                    tmp = lista->tail;
                else {
                    tmp = tmp->prev;
                }       
        }        
    }
}

int insertar_cancion(t_lista_rep *lista, t_cancion c, int pos)
{
    
    t_node *tmp, *aux;
    
    if (pos < 0 || pos > lista->size)
        return (INDEX_ERROR);
    
    
    tmp = (t_node *)malloc(sizeof(t_node));
    
    if (tmp == NULL)
        return (MEM_ALLOC_FAILURE);
    
    tmp->cancion = c;
    
    
    if (pos == 0 && lista->size == 0){
        lista->head = tmp;
        lista->tail = tmp;
        tmp->next = NULL;
        tmp->prev = NULL;
    }
    
    else if (pos == 0 && lista->size != 0){
        tmp->next = lista->head;
        tmp->prev = NULL;
        lista->head->prev = tmp;
        lista->head = tmp;
    }
    
    else if (pos == lista->size && lista->size != 0){
        tmp->prev = lista->tail;
        tmp->next = NULL;
        lista->tail->next = tmp;
        lista->tail = tmp;
    }
    
    else {
        if (pos < lista->size / 2){
            /*Tengo que recorrer la lista desde head hacia adelante hasta apuntar al nodo que representa la 
             * posición pos de la lista, con un puntero a variable de tipo t_node. */
            
            aux = lista->head;
            
            int i = 1;
            
            while (i != pos){
                aux = aux->next;
                i++;
            }
            
            tmp->prev = aux->prev;
            tmp->next = aux;
            aux->prev->next = tmp;
            aux->prev = tmp;
        }
        
        if (pos > lista->size / 2){
            /*En caso contrario, la función debe recorrer la lista desde tail hacia atrás hasta apuntarlo. */
            aux = lista->tail;
            
            int i = lista->size -1;
            
            while (i != pos){
                aux = aux->prev;
                i--;
            }
            
            tmp->prev = aux->prev;
            tmp->next = aux;
            aux->prev->next = tmp;
            aux->prev = tmp;
        }
        
        
        else {
            /* Ens pot caure tambe just al mig, i tambe hauriem d'afegir-lo. */
            pos = lista->size / 2;
            
            int i = 1;
            
            while (i != pos){
                aux = aux->next;
                i++;
            }
            
            tmp->prev = aux->prev;
            tmp->next = aux;
            aux->prev->next = tmp;
            aux->prev = tmp;
        }
    }
    
    lista->size++;
    
    return (ACTION_SUCCESS);
}

int eliminar_cancion(t_lista_rep *lista, int pos)
{
    
    
    
    
    
    
    return (ACTION_SUCCESS);
}
