/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "nif.h"
#include <string.h>


t_nif generar_nif_aleatorio()
{
    char letras[23] = {'T','R','W','A','G','M','Y','F','P',
                    'D','X','B','N','J','Z','S','Q','V','H',
                    'L','C','K','E'};
    t_nif nif;

    /* ... */
    
    nif.numero = 10000000 + rand() % 90000000;
    nif.letra = letras[nif.numero % 23];
    
    return (nif);
}




void mostrar_nif(t_nif nif)
{
    printf("%08d%c", nif.numero, nif.letra);
}


int comparar_nifs(t_nif nif1, t_nif nif2)
{
    if (nif1.numero > nif2.numero)
        return(1);
    
    else if (nif1.numero < nif2.numero)
        return (-1);
    
    else
        return (0);
}


