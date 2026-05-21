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
        /* El valor que introdueix l'usuari és octal */
        scanf("%o", &valor);
        
    }
    else if (base == 16){
        /* El valor que introdueix l'usuari és Hex */
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
    
    printf("\nNou valor desplaçat: %u. \n ", valor); /* Si faig +2 de desplaçament es divideix entre 2**2 si faig -2 es multiplicara per 2**2 */
    
    
    
}


void exercici4() {
    
    unsigned int valor, res;
    unsigned int mask = 1; /* LSB = 1; resta 0's */
    
    printf("Valor (>=0): ");
    scanf("%u", &valor);
    
    /*Parell? Imparell? */
    
    res = valor & mask;
    
    if (res == 0)
        printf("El valor es parell. \n");
    else
        printf("El valor es imparell. \n");
}



void exercici5()
{
    int valor;
    unsigned int mask = 1 << 31;
    unsigned int res;
    
    printf("Valor: ");
    scanf("%d", &valor);
    
    res = valor & mask;
    if (res == 0)
        printf("El valor es >=0. \n");
    else
        printf("El valor es < 0. \n");
}


void exercici7()
{
    int i;    
    unsigned int valor, mask, res = 0;
    
    printf("Valor (>=0): ");
    scanf("%u", &valor);
    
    if (valor == 0 || valor == 1){
        printf("Es requereix 1 bit per representar-lo. \n");
        return;
    }
    
    for (i = 31; i >= 1; i--){
        mask = 1 << i;
        res = valor & mask;
        if (res != 0){
            printf("Es requereixen %d bits per representar-lo. \n", res);
        }
    }
    
    
}



void exercici8()
{
    unsigned int valor, res;
    int i, primer1 = 0;
    
    printf("Valor (>=0): ");
    scanf("%u", &valor);
    
    /* Recorrem sequencia des de MSB(31) fins a LSB(0) */
    for (i = 31; i >= 1; i--){
        res = valor & (1 << i);
        
        if (res == 0 && primer1){
            printf("0"); /* A la posicio i de la sequencia hi tinc un 0 */
        }
        
        else if (res != 0){
            if (!primer1)
                primer1 = 1;
            printf("1"); /* Hi tinc un 1; */
        }
        
        if (primer1 && i % 4 == 0 && i != 0){
            printf(" ");
        }
        
    }
    
    if (valor == 0){
        printf("0\n");
    }
    
    printf("\n");
    
}


void exercici9()
{
    unsigned int valor1 , valor2 , seq_aux;
    int i , res = 0;
    
    printf("Valor1 (>=0): ");
    scanf("%u%*c", &valor1);
    printf("Valor2 (>=0): ");
    scanf("%u%*c", &valor2);
    
    seq_aux = valor1 ^ valor2; 
    
    /* xor */
    
    for (i = 31; i >= 0; i--)
    {
        if((seq_aux & (1<<i)) != 0)
            res++;
    }
    printf("Nombre de bits diferents: %d",res);
}