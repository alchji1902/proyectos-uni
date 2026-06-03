/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   problema_2_2025.h
 * Author: alexch
 *
 * Created on 27 de maig del 2026, 20:48
 */

#ifndef PROBLEMA_2_2025_H
#define PROBLEMA_2_2025_H


#define NUM_S 10            /* Nombre de sensors del sistema IoT */

typedef struct node {
    int hora;               /* Hora de la mesura (format: hhmm) */
    float valor;           /* Valor mesurat */
    struct node *next;     /* Punter a següent node de la llista */
} t_node;

typedef struct {
    t_node *sensors[NUM_S]; /* Array de sensors del sistema */
} t_sistema;


/* Capçaleres de funcions extretes de imatge.png */

void inicialitza_sensors(t_sistema *sistema);
int afegir_mesura(t_sistema *sistema, int pos, int hora, float valor);
float *extreure_mesures(t_sistema *sistema);
void mostrar_mesures(t_sistema *sistema, int horaIni, int horaFin);
/* A partir d’aquesta descripció i definicions inicials, es demana implementar les següents */

#endif /* PROBLEMA_2_2025_H */
