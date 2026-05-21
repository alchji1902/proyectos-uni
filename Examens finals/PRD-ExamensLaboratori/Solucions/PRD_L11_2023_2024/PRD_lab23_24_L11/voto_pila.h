/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef VOTO_PILA_H
#define VOTO_PILA_H

#define VOT_SI       1
#define VOT_NO       0
#define VOT_BLANCO  -1
#define NUM_VOT     20

typedef struct voto{
    int valor;     
    int hora;
    struct voto *next;
}t_voto;

typedef struct{
    int nvotos;
    t_voto *top;
}t_votos;

int inicializar_votos (t_votos **l_votos);
int obtener_hora_actual();
int votar (t_votos *l_votos, int valor);
void mostrar_votos (t_votos *l_votos);
int liberar_votos (t_votos **l_votos);

#endif /* VOTO_PILA_H */

