#ifndef VIDEO11_H
#define VIDEO11_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

typedef struct {
    int id;
    char titulo[MAX];
    int reproducciones;    
} t_video;

typedef struct nodo {
    t_video v;
    struct nodo *next;
} t_nodo;

typedef struct {
    int size;
    t_nodo *head;
}t_video_list;

/* Operaciones video */
t_video leer_video ();
void mostrar_video (t_video v);

/* Operaciones lista de vídeos */
t_video_list *init ();
void free_lista_videos (t_video_list *lista);

void mostrar_lista_videos (t_video_list *lista);
int insertar_video_ordenado_asc (t_video_list *lista, t_video v);

void grupo11();

#endif /* VIDEO11_H */

