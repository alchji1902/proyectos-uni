/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   complex.h
 * Author: alexch
 *
 * Created on 10 de marzo de 2026, 12:40
 */

#ifndef COMPLEX_H
#define COMPLEX_H

#define MAX_COMPLEXOS 20

typedef struct {    
    float real;
    float imaginaria;
    
} t_complex;

typedef struct {
    
    int num_comp;
    t_complex complexos[MAX_COMPLEXOS];
    
}t_vec_comp;

t_complex llegir_complex();

void mostrar_complex(t_complex c);
float calcular_mod(t_complex c);
float calcular_arg(t_complex c);


void sumar(t_complex *res, t_complex c1, t_complex c2);
void restar(t_complex *res, t_complex c1, t_complex c2);
void multiplicar(t_complex *res, t_complex c1, t_complex c2);
void dividir(t_complex *res, t_complex c1, t_complex c2);
void major(t_complex **ma, t_complex *c1, t_complex *c2);


t_vec_comp llegir_vector_complexos();
void mostrar(t_vec_comp vc);
void ordenar_seleccio(t_vec_comp *vc);
void ordenar_insercio(t_vec_comp *vc);
void ordenar_bombolla(t_vec_comp * vc);



int cerca_binaria(t_vec_comp vc, t_complex c);
int eliminar(t_vec_comp *vc, t_complex c);













#endif /* COMPLEX_H */

