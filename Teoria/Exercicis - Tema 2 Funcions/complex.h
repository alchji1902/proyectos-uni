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

typedef struct {    
    float real;
    float imaginaria;
    
} t_complex;



t_complex llegir_complex();

void mostrar_complex(t_complex c);

float calcular_mod(t_complex c);

float calcular_arg(t_complex c);

#endif /* COMPLEX_H */

