/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   problema_2_2025.c
 * Author: alexch
 * 
 * Created on 27 de maig del 2026, 20:48
 */

#include "problema_2_2025.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void inicialitza_sensors(t_sistema *sistema) 
{
    int i;
    
    for (i = 0; i < NUM_S; i++){
        sistema->sensors[i] = NULL;
    }
    
}


int afegir_mesura(t_sistema *sistema, int pos, int hora, float valor) 
{ 
    t_node *tmp, *aux;
    
    if ((0 > pos) || (pos > NUM_S -1))
        return(-1);
    
    
    tmp = (t_node *)malloc(sizeof(t_node));
    
    if (tmp == NULL)
        return (-2);
    
    tmp->hora = hora;
    tmp->valor = valor;
    tmp->next = NULL;
    
    
    aux = sistema->sensors[pos];
    
    if (sistema->sensors[pos] == NULL){
        sistema->sensors[pos] = tmp;
        return (0);
    }
    
    while (aux->next != NULL){
        aux = aux->next;
    }
    
    aux->next = tmp;
    
    return (0); 
}

float *extreure_mesures(t_sistema *sistema) 
{
    t_node *aux;
    int i = 0;
    
    float *v;
    
    v = (float *)calloc(NUM_S, sizeof(float));
    
    if (v == NULL)
        return NULL;
    
    aux = sistema->sensors[i];
    
    while (aux != NULL){
        aux = sistema->sensors[i];
        v[i] = aux->valor;
        aux = aux->next;
        i++;
    }    
    
    return v;  
}

void mostrar_mesures(t_sistema *sistema, int horaIni, int horaFin) 
{

    
}