/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H

#define MAX_CHAR 100

#define ACTION_SUCCESS       0      /* Acción realizada satisfactoriamente  */
#define MEM_ALLOC_FAILURE   -1      /* Problema durante reserva de memoria  */
#define INDEX_ERROR         -2      /* Índice incorrecto                    */

typedef struct
{
    char titulo[MAX_CHAR];     /* Título de la canción         */
    char autor[MAX_CHAR];      /* Autor(es) de la canción      */
    int duracion;              /* Duración en segundos         */
}t_cancion;

typedef struct node
{
    t_cancion cancion;      /* Canción guardada en el nodo              */
    struct node *next;      /* Puntero a siguiente nodo de la lista     */
    struct node *prev;      /* Puntero a nodo previo de la lista        */
}t_node;

typedef struct
{
    int size;               /* Número de canciones en la lista      */
    t_node *head;           /* Puntero a primer nodo de la lista    */          
    t_node *tail;           /* Puntero a último nodo de la lista    */
}t_lista_rep;

t_lista_rep *crear_lista_reproduccion();
void liberar_lista_reproduccion(t_lista_rep *lista);
int add_cancion_final(t_lista_rep *lista, t_cancion c);
void mostrar_cancion (t_cancion c);
void mostrar_contenido (t_lista_rep *lista);
void reproducir(t_lista_rep *lista);
int insertar_cancion(t_lista_rep *lista, t_cancion c, int pos);
int eliminar_cancion(t_lista_rep *lista, int pos);

#endif /* REPRODUCTOR_H */

