/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef ELECTOR_H
#define ELECTOR_H

#include "voto_pila.h"

#define MAX_NOM 20
#define MAX_EL  200
#define SI      1
#define NO      0

typedef struct
{
    int numero;     /* Número del NIF */
    char letra;     /* Letra del NIF  */
}t_nif;

typedef struct
{
    t_nif nif;
    char nombre[MAX_NOM], apellido1[MAX_NOM], apellido2[MAX_NOM];
    int ha_votado;                  /* Valores posibles SI, NO */    
}t_elector;

typedef struct
{
    int numelec;
    t_elector electores[MAX_EL];
}t_electorado;

int inicializar_electorado (t_electorado *l_elect);
int buscar_elector (t_electorado *l_elect, t_nif n);
int anyadir_elector (t_electorado *l_elect, t_elector e);
int eliminar_elector (t_electorado *l_elect, t_nif n);
int votar_elector (t_electorado *l_elect, t_votos *v, t_nif n, int voto);
int comprobar_voto (t_electorado *l_elect, t_nif n);
void mostrar_electorado (t_electorado *l_elect);

#endif /* ELECTOR_H */

