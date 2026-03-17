/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vectors.h
 * Author: alexch
 *
 * Created on 17 de març de 2026, 12:44
 */

#ifndef VECTORS_H
#define VECTORS_H

#define MAX_VAL 20

typedef struct
{
    int num_valors;          /* Nombre de valors guardats */
    int valors[MAX_VAL];     /* Array de valors guardats */
} t_vector;

int afegeix_valor (t_vector *v, int valor);
void mostra_contingut (t_vector *v);
int insereix_valor_posicio (t_vector *v, int valor, int pos);
int insereix_valor_ordenat (t_vector *v, int valor);
int elimina_valor_posicio (t_vector *v, int pos);
void tests_vectors();

#endif /* VECTORS_H */

