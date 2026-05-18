/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   exercicis.c
 * Author: alexch
 * 
 * Created on 14 de maig del 2026, 8:22
 */

#include "exercicis.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>




void exercici1()
{
    char seq[32];
    
    int i, valor = 0;
        
    printf("Introdueix la sequencia de bits: ");
    scanf("%s", &seq);

    for (i = 0; i < strlen(seq); i++)
    {
        if (seq[i] == '1')
            valor += pow(2, strlen(seq)-1-i);
        
    }
    
    printf("Valor en base10: %u\n", valor);
    printf("Valor en base16: %x\n", valor);
}


void exercici2()
{
    char seq[32];
    unsigned int valor = 0;
    int i, base;
    
    printf("Introdueix base_valor (base 2, 8 o 16): ");
    scanf("%d_", &base);
    
    if (base == 2){
        scanf("%s", seq);
        for (i = 0; i < strlen(seq); i++){
            if (seq[i] == '1')
                valor += pow(2,strlen(seq)-1-i);
        }
    }
    else if (base == 8){
        // El valor que introdueix l'usuari és octal
        scanf("%o", &valor);
        
    }
    else if (base == 16){
        // El valor que introdueix l'usuari és Hex
        scanf("%x", &valor);
    }
    else {
        printf("Base incorrecta. \n");
        return;
    }
    
    printf("El valor en base10 es %u. \n", valor);
}


void exercici3()
{
    unsigned int valor, desp;
    char sentit;
    
    printf("Valor: ");
    scanf("%u%*c", &valor);
    
    printf("Desplaçament: precedit per (+/-): ");
    scanf("%c%u", &sentit, &desp);
    
    if (sentit == '+'){
        valor = valor >> desp;
    }
    else if (sentit == '-'){
        valor = valor << desp;
    }
    
    else {
        printf("Sentit incorrecte. \n");
        return;
    }
    
    printf("\nNou valor desplaçat: %u. \n ", valor); //Si faig +2 de desplaçament es divideix entre 2**2 si faig -2 es multiplicara per 2**2
    
    
    
}
    