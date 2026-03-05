/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   exercicis.h
 * Author: alexch
 *
 * Created on 19 de febrero de 2026, 9:37
 */

#ifndef EXERCICIS_H
#define EXERCICIS_H

#define PI 3.145
#define MAX_ALUMNES 50


typedef struct {
    int numero;
    char lletra;
}t_nif;


typedef struct {
    t_nif nif;
    float nota_lab;
    float nota_par;
    float nota_fin;
}t_alumne;

typedef struct {
    int grup;
    int num_matriculats;
    t_alumne matriculats[MAX_ALUMNES];
}t_grup;



void exercici1();
void exercici2();
void exercici3();
void exercici4();
void exercici5();
void exercici6();
void exercici7();
void exercici8();
void exercici9();
void exercici10();
void exercici11();





#endif /* EXERCICIS_H */

