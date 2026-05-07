/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   hashtable.c
 * Author: alexch
 * 
 * Created on 7 de maig del 2026, 8:38
 */


#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"



t_hasht  *crear_taula(int ncas){

    /* Cal crear taula hash am array intern de ncas 
    caselles (inicialment buides). Caldra retornar un punter a la taula hash creada
    o NULL si succeeix qualsevol problema de memoria dinamica. */

    t_hasht *taula;

    taula = (t_hasht *)malloc(sizeof(t_hasht));
    if(taula != NULL)
    {
        taula->ncas = ncas;
        taula->array_caselles = (t_node **)calloc(ncas, sizeof(t_node *));
        /* Com que el calloc inicialitza tot a NULL, no cal que fem cap bucle per inicialitzar totes les caselles a NULL, 
        (en realitat posa 0, pero es el mateix que NULL. Si haguessim posat malloc, hauriem de fer el bucle per inicialitzar-les)*/

        if(taula->array_caselles == NULL)
        {
            free(taula);
            taula = NULL;
        }

    }

    return taula;
}



void alliberar_taula (t_hasht *taula)
{
    t_node *tmp;
    int i;

    /* Alliberem primer les llistes enllaçades de les caselles*/

    for (i = 0; i < taula->ncas; i++)
    {
        while(taula->array_caselles[i] != NULL)
        {
            tmp = taula->array_caselles[i];
            taula->array_caselles[i] = taula->array_caselles[i]->next;
            free(tmp);
        }
    }
    
    /* Despres alliberem bloc que guarda array de caselles */
    free(taula->array_caselles);

    /*Finalment, el bloc que guarda la variable t_hasht */
    free(taula);
}


int conte_persona(t_hasht *taula, t_nif nif)
{
    /* Retorna 1 si existeix la persona amb el NIF nif a
    la taula hash, 0 en cas contrari si no existeix aquesta persona. */

    /* nif --> clau del valor que estem buscant */

    /* Usem el numero de cada NIF com a hashcode d'aquest*/

    int c;
    t_node *tmp;

    c = nif.num % taula->ncas; /* Calculem el hashcode a partir del numero del NIF i el nombre de caselles de la taula */

    /* Si la persona existeix dins de la taula hash, la tindrem a la llista enllaçada de la casella c*/

    tmp = taula->array_caselles[c]; /* Apuntem al primer node de la llista enllaçada de la casella c */
    
    while(tmp != NULL)
    {
        if (tmp->p.nif.num == nif.num)
            return 1;

        tmp = tmp->next;
    }
    return 0;
}



int put(t_hasht *taula, t_nif nif, t_persona p)
{

    t_node *node, *tmp;
    int c;

    if (conte_persona(taula, nif) == 1)
        return -2; /* No es pot inserir la persona a la taula hash, ja que ja existeix una persona amb el mateix NIF */
    
    /* Inserim la persona a la llista enllaçada de la casella c, on c es el hashcode calculat a partir del numero del NIF */

    node = (t_node *)malloc(sizeof(t_node));

    if (node == NULL)
        return -1; /* No es pot inserir la persona a la taula hash, ja que no s'ha pogut reservar memoria dinamica per al nou node de la llista enllaçada */

    
    node->p = p; /* Guardem la persona al node */
    node->next = NULL; /* Inicialitzem el punter al seguent node a NULL */

    c = nif.num % taula->ncas; /* Calculem el hashcode a partir del numero del NIF i el nombre de caselles de la taula */

    if (taula->array_caselles[c] == NULL)
        taula->array_caselles[c] = node;

    else 
    {
        tmp = taula->array_caselles[c]; /* Apuntem al primer node de la llista enllaçada de la casella c */

        while(tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = node; /* Enllacem el nou node al final de la llista enllaçada de la casella c */
    }

    return 0; /* S'ha inserit la persona a la taula hash correctament */

}


t_persona * get(t_hasht *taula, t_nif nif)
{
    int c;
    t_node *tmp;

    c = nif.num % taula->ncas;

    tmp = taula->array_caselles[c]; /* Apuntem al primer node de la llista enllaçada de la casella c */

    while(tmp != NULL)
    {
        if (tmp->p.nif.num == nif.num)
            return &(tmp->p); /* Retornem un punter a la persona que estem buscant */

        tmp = tmp->next;
    }
    return NULL; /* No s'ha trobat cap persona amb el NIF nif a la taula hash */
}

