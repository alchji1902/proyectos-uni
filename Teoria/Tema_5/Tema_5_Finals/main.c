/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: alexch
 *
 * Created on 26 de maig del 2026, 12:18
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int apagar_bits(unsigned int *seq, unsigned int b1,
                                   unsigned int b2)
{
    int cont = 0, i;
    unsigned int mask, res;

    if (b1 < 0 || b1 > 31 || b2 < 0 || b2 > 31 || b1 < b2)
        return (-1);

    for (i = b1; i >= b2; i--)
    {
        mask = (1 << i);
        res = *seq & mask;

        if (res != 0)
        {
            /* A la posició i hi ha un 1 que hem de passar a 0 */
            cont++;
            mask = ~mask;
            *seq = *seq & mask;
        }
    }

    return (cont);
}


int substituir_bits(unsigned int *seq_d, unsigned int seq, int b1, int b2)
{
    int i, cont = 0;
    unsigned int mask, res1, res2;
    
    if (b1 < 0 || b1 > 31 || b2 < 0 || b2 > 31 || b1 < b2)
        return (-1);
    
    for (i = b1; i >= b2; i--){
        mask = 1 << i;
        
        res1 = *seq_d & mask;
        res2 = seq & mask;
        
        if (res1 != res2){
            /*A la posició i teni un bit amb valor diferent a les sequencies
             seq_d i seq. */
            
            
            
        }
    }
    
    
}


int main(int argc, char** argv) {
    unsigned int seq = 0x1111; 
    printf("%u\n", seq);
    apagar_bits(&seq, 6, 2);
    printf("%u", seq);
    
    return (EXIT_SUCCESS);
}

