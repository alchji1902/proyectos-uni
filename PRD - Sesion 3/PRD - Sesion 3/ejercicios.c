/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "ejercicios.h"
#include "colours.h"

void sesion3_ej1()
{
    /* Completar con el código del ejercicio 1 */
    
    t_fraccion frac1, frac2, fracres;
    
    int suma, resta, multiplicacion;
    
    double division;
    
    
    
    printf("Fraccion 1 (formato x/y): ");
    scanf("%d/%d", &frac1.num, &frac1.den);
    printf("Fraccion 2 (formato x/y): ");
    scanf("%d/%d", &frac2.num, &frac2.den);
    
    printf("RESULTADO DE LAS OPERACIONES: \n\n");
    
    /*Resultado de la suma*/
    
    fracres.num = (frac1.num * frac2.den) + (frac2.num * frac1.den);
    fracres.den = (frac1.den * frac2.den);
    
    
    printf("Suma: %d/%d + %d/%d = %d/%d\n\n", frac1.num, frac1.den, frac2.num, frac2.den, fracres.num, fracres.den);
    
    /*Resultado de la resta*/
    
    fracres.num = (frac1.num * frac2.den) - (frac2.num * frac1.den);
    fracres.den = (frac1.den * frac2.den);
    
    
    printf("Resta: %d/%d - %d/%d = %d/%d\n\n", frac1.num, frac1.den, frac2.num, frac2.den, fracres.num, fracres.den);
    
    
    /*Resultado de la multiplicación*/
    
    
    fracres.num = (frac1.num * frac2.num);
    fracres.den = (frac1.den * frac2.den);
    
    
    printf("Multiplicación: %d/%d * %d/%d = %d/%d\n\n", frac1.num, frac1.den, frac2.num, frac2.den, fracres.num, fracres.den);
    
    
    /*Resultado de la división*/
    
    fracres.num = (frac1.num * frac2.den);
    fracres.den = (frac1.den * frac2.num);
    
    
    printf("División: %d/%d / %d/%d = %d/%d\n\n", frac1.num, frac1.den, frac2.num, frac2.den, fracres.num, fracres.den);
   
}


void sesion3_ej2a()
{
    /* Completar con el código del ejercicio 2.a */
    
    t_carta carta;
    
    printf("Figura carta: r o R, c o C, s o S, 9, ... , 1\nPalo carta: o o O(OROS), c o C(COPAS), e o E(ESPADAS) o b o B(BASTOS)\n");
    
    printf("Carta (figura, palo): ");
    
    scanf("(%c,%c)", &carta.fig, &carta.pal);
    
    if ((carta.fig >= 'a') && (carta.fig <= 'z')) {carta.fig = carta.fig-32;}
    if ((carta.pal >= 'a') && (carta.pal <= 'z')) {carta.pal = carta.pal-32;}
    
    /*printf("(%c,%c)", carta.fig, carta.pal);*/
    
    switch (carta.pal) {
        case 'C':
            printf("(%c,", carta.fig);
            cambiar_color(RED);
            printf("%c", carta.pal);
            cambiar_color(DEFAULT);
            printf(")");
            break;
            
        case 'O':
            printf("(%c,", carta.fig);
            cambiar_color(YELLOW);
            printf("%c", carta.pal);
            cambiar_color(DEFAULT);
            printf(")");
            break;
        case 'B':
            printf("(%c,", carta.fig);
            cambiar_color(GREEN);
            printf("%c", carta.pal);
            cambiar_color(DEFAULT);
            printf(")");
            break;
        case 'E':
            printf("(%c,", carta.fig);
            cambiar_color(BLUE);
            printf("%c", carta.pal);
            cambiar_color(DEFAULT);
            printf(")");
            break;
        
        
    }
    
    
    
    
    
    
    
    
    
    
}


void sesion3_ej2b()
{
    /* Completar con el código del ejercicio 2.b */
    t_carta carta, alta;
    
    char carta[5];
    
    char pals[4] = O, C, E, B;
    
    char figuras[12] = R, C, S, 9, 8, 7, 6, 5, 4, 3, 2, 1;
    
    char car;
    
    int i, pos, pos_fig, j;
    
    
    int pos_max = 0;
    
    int pos_max_fig = 0;
    
    
    printf("Figura carta: r o R, c o C, s o S, 9, ... , 1\nPalo carta: o o O(OROS), c o C(COPAS), e o E(ESPADAS) o b o B(BASTOS)\n");
    
    printf("Carta (figura, palo): ");
    
    do {
        
        scanf("(%c,%c)", &carta.fig, &carta.pal);
    
        if ((carta.fig >= 'a') && (carta.fig <= 'z')) {carta.fig = carta.fig-32;}
        
        if ((carta.pal >= 'a') && (carta.pal <= 'z')) {carta.pal = carta.pal-32;}
        
        scanf("%c", &car);
        
        
        for (i=0; i<5; i++) {
            
            if (pals[i] == carta.pal){
                pos = i;
            }    
        }
        
        if (pos > pos_max){
            pos_max = pos;
            alta.fig = carta.fig;
            alta.pal = carta.pal;
        }
        
        if (pos = pos_max){
            for (j=0; j<11; j++){
                
                if (figuras[i] == carta.fig){
                    pos_fig = j;
                }    
                
            }
            
            if (pos > pos_max_fig){
                pos_max = pos;
                alta.fig = carta.fig;
                alta.pal = carta.pal;
            }
            
        }
        
        
        
        
        
        
    }while (car != '.')
    
    
    
    
    switch (carta.pal) {
        case 'C':
            printf("(%c,", carta.fig);
            cambiar_color(RED);
            printf("%c", carta.pal);
            cambiar_color(DEFAULT);
            printf(")");
            break;
            
        case 'O':
            printf("(%c,", carta.fig);
            cambiar_color(YELLOW);
            printf("%c", carta.pal);
            cambiar_color(DEFAULT);
            printf(")");
            break;
        case 'B':
            printf("(%c,", carta.fig);
            cambiar_color(GREEN);
            printf("%c", carta.pal);
            cambiar_color(DEFAULT);
            printf(")");
            break;
        case 'E':
            printf("(%c,", carta.fig);
            cambiar_color(BLUE);
            printf("%c", carta.pal);
            cambiar_color(DEFAULT);
            printf(")");
            break;
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}


void sesion3_ej3()
{
    /* Completar con el código del ejercicio 3 */
    
}


void sesion3_ej4a()
{
    /* Completar con el código del ejercicio 4.a */
    
}


void sesion3_ej4b()
{
    /* Completar con el código del ejercicio 4.b */
    
}