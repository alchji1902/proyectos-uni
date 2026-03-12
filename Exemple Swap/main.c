/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: alexch
 *
 * Created on 12 de marzo de 2026, 9:36
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void swap (int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
    
}


int main(int argc, char** argv) {
    
    int val1 = 5, val2 = 4;
    
    printf("val1: %d; val2: %d\n", val1, val2);
    
    swap(&val1, &val2);
    
    printf("val1: %d; val2: %d\n", val1, val2);
    
    
    printf("val1 : % d; val2 : % d\n", val1, val2);
    
    
    
    return (EXIT_SUCCESS);
}

