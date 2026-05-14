/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "reproductor.h"


void mostrar_retorno(int ret)
{
    switch (ret)
    {
        case MEM_ALLOC_FAILURE:
            printf ("MEM_ALLOC_FAILURE: Reserva de memoria dinamica incorrecta.\n");
            break;
        case INDEX_ERROR:
            printf("INDEX_ERROR: Indice incorrecto (fuera de rango).\n");
            break;
        case ACTION_SUCCESS:
            printf("ACTION_SUCCESS: Accion realizada correctamente.\n");
    }
}

void cargar_lista_reproduccion(t_lista_rep *lista)
{
    t_cancion c1 = {"Shape of You", "Ed Sheeran", 276};
    t_cancion c2 = {"Blinding Lights", "The Weeknd", 204};
    t_cancion c3 = {"Despacito", "Luis Fonsi feat. Daddy Yankee", 227};
    t_cancion c4 = {"Hello", "Adele", 295};
    t_cancion c5 = {"Bad Guy", "Billie Eilish", 194};
    
    mostrar_retorno(add_cancion_final(lista, c1));
    mostrar_retorno(add_cancion_final(lista, c2));
    mostrar_retorno(add_cancion_final(lista, c3));
    mostrar_retorno(add_cancion_final(lista, c4));
    mostrar_retorno(add_cancion_final(lista, c5));
    printf("\n");
}

void ejercicio1()
{
    t_lista_rep *lista = crear_lista_reproduccion();
    if (lista == NULL)
    {
        printf("Error durante la creacion de la lista de reproduccion.\n");
        return;
    }
    
    cargar_lista_reproduccion(lista);
    mostrar_contenido(lista);
    
    printf("\n");
    reproducir(lista);
    
    liberar_lista_reproduccion (lista);
    lista = NULL;
}

void ejercicio2()
{
    t_cancion nueva = {"Gangnam Style", "PSY", 253};
    
    t_lista_rep *lista = crear_lista_reproduccion();
    if (lista == NULL)
    {
        printf("Error durante la creacion de la lista de reproduccion.\n");
        return;
    }
    
    cargar_lista_reproduccion(lista);
    mostrar_contenido(lista);
    
    printf("\n");
    mostrar_retorno(insertar_cancion(lista, nueva, 2));
    
    printf("\n");
    mostrar_contenido(lista);
    
    printf("\n");
    reproducir(lista);
    
    liberar_lista_reproduccion (lista);
    lista = NULL;
}

void ejercicio3()
{
    int pos;
    t_lista_rep *lista = crear_lista_reproduccion();
    if (lista == NULL)
    {
        printf("Error durante la creacion de la lista de reproduccion.\n");
        return;
    }
    
    cargar_lista_reproduccion(lista);
    mostrar_contenido(lista);
    
    printf("\nCancion a eliminar: ");
    scanf("%d%*c", &pos);
    
    mostrar_retorno(eliminar_cancion(lista, pos));
    
    printf("\n"); 
    mostrar_contenido(lista);
    
    printf("\n");
    reproducir (lista);
    
    liberar_lista_reproduccion (lista);
    lista = NULL;
}