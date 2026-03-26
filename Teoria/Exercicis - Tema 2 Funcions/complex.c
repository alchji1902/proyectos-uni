/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <stdio.h>
#include "complex.h"
#include <math.h>



t_complex llegir_complex() {
    
    t_complex c;
    
    printf("Introdueix un nombre complex(format: a+bi: ");
    scanf("%f+%fi", &c.real, &c.imaginaria);
    
    return (c);
    
}





void mostrar_complex(t_complex c){
    
    if (c.real != 0.0) {
        printf("%.2f ", c.real);
        if (c.imaginaria > 0)
            printf("+");
    }
    
    if (c.imaginaria != 0.0){
        printf("%.2fi", c.imaginaria);
    }
}





float calcular_mod(t_complex c) {
    
    return (sqrt(c.real*c.real + c.imaginaria*c.imaginaria));
    
    
}


float calcular_arg(t_complex c){
    
    return(atan2(c.imaginaria, c.real)); 
}



void sumar(t_complex *res, t_complex c1, t_complex c2)
{
    (*res).real = c1.real + c2.real;
    (*res).imaginaria = c1.imaginaria + c2.imaginaria;
    
}


void restar(t_complex *res, t_complex c1, t_complex c2)
{
    res->real = c1.real - c2.real;
    res->imaginaria = c1.imaginaria - c2.imaginaria;
    
}



void multiplicar(t_complex *res, t_complex c1, t_complex c2)
{
    float mod = calcular_mod(c1)*calcular_mod(c2);
    float arg = calcular_arg(c1) + calcular_arg(c2);
    
    res->real = mod * cos(arg);
    res->imaginaria = mod * sin(arg);
}


void dividir(t_complex *res, t_complex c1, t_complex c2)
{
    float mod = calcular_mod(c1) / calcular_mod(c2);
    float arg = calcular_arg(c1) - calcular_arg(c2);
    
    res->real = mod * cos(arg);
    res->imaginaria = mod * sin(arg);
    
}



void major(t_complex **ma, t_complex *c1, t_complex *c2)
{
    if (calcular_mod(*c1) >= calcular_mod(*c2))
    {
        /*El punter apuntat per ma cali
 que apunti a 
         la variable apuntada per c1 */
        *ma = c1;
        
    }
    else 
    {
        /*El punter apuntat per ma cal que apunti a
         la variable apuntada per c2 */
        *ma = c2;
    }
    
}


t_vec_comp llegir_vector_complexos()
{
    t_vec_comp vc;
    
    int i;
    
    
    
    vc.num_comp = -1;
    while (vc.num_comp < 1 || vc.num_comp > MAX_COMPLEXOS)
    {
        
        printf("Nombre de complexos [1, %d]: ", MAX_COMPLEXOS);
        scanf("%d", &vc.num_comp);
        
        if (vc.num_comp < 1 || vc.num_comp > MAX_COMPLEXOS)
            printf("Valor fora de rang. Torna-hi!\n");
        
    }
    
    
    for (i = 0; i < vc.num_comp; i++)
        vc.complexos[i] = llegir_complex();
    
    return (vc);
    
    
}

void mostrar(t_vec_comp vc)
{
    int i;
    
    
    if (vc.num_comp == 0)
        printf("El vector de complexos es buit. \n");
    
    else 
    {
        
        printf("CONTINGUT DEL VECTOR: \n");
        
        
        for (i = 0; i < vc.num_comp; i++)
        {
            mostrar_complex(vc.complexos[i]);
            printf("\n");           
        }
        
    }
    
}


void ordenar_seleccio(t_vec_comp *vc) 
{
    /*Seleccio directa !!*/
    
    int i, j, imin;
    t_complex aux;
    
    /* crims */
    
    for (i = 0; i < vc->num_comp -1; i++)
    {
        
        imin = i;
        
        for (j = i+1; j < vc->num_comp; j++)
        {
            
            if (calcular_mod(vc ->complexos[j]) < calcular_mod(vc->complexos[imin]))
                imin = j;
            
        }
        
        if (imin != i)
        {
            aux = vc->complexos[i];
            vc->complexos[i] = vc->complexos[imin];
            vc->complexos[imin] = aux;
            
            
            
        }
        
        
    }
        
}

void ordenar_insercio(t_vec_comp *vc)
{
    int i, j;
    t_complex aux;
    
    for (i = 1; i < vc->num_comp; i++)
    {
        aux = vc->complexos[i];
        j = i-1;
        
        while (j >=0 && calcular_mod(vc->complexos[j]) > calcular_mod(aux))
        {
            
            vc->complexos[j+1] = vc->complexos[j];
            j--;
            
        }
        
        vc->complexos[j+1] = aux;
        
        
    }
    
    
    
}


void ordenar_bombolla(t_vec_comp *vc)
{
    int i, j;
    t_complex aux;
    
    for (i = 0; i < vc->num_comp -1; i++)
    {
        
        for (j = 1; j < vc->num_comp -i ; j++)
        {
            if (calcular_mod(vc->complexos[j-1]) > calcular_mod(vc->complexos[j]))
            {
                /*Intercanviem parella d'elements*/
                aux = vc->complexos[j-1];
                vc->complexos[j-1] = vc->complexos[j];
                vc->complexos[j] = aux;
                
            }
                
            
        }
        
    }
    
    
}

void ordenar_bombolla_millorat(t_vec_comp *vc)
{
    int i, j, inter = 1;
    t_complex aux;
    
    for (i = 0; i < vc->num_comp -1 && inter; i++)
    {
        inter = 0;
        
        for (j = 1; j < vc->num_comp -i ; j++)
        {
            if (calcular_mod(vc->complexos[j-1]) > calcular_mod(vc->complexos[j]))
            {
                /*Intercanviem parella d'elements*/
                aux = vc->complexos[j-1];
                vc->complexos[j-1] = vc->complexos[j];
                vc->complexos[j] = aux;
                inter = 1;
                
            }
           
        }
        
    }

}


int cerca_binaria(t_vec_comp vc, t_complex c)
{
    int inf, sup, centre, pos = -1;
    
    float mod_centre, mod_c = calcular_mod(c);
   
    
    inf = 0;
    sup = vc.num_comp-1;
    
    while (inf <= sup && pos == -1)
    {
        centre = (inf+sup) / 2;
        
        mod_centre = calcular_mod(vc.complexos[centre]);
        
        if (mod_c == mod_centre)
            pos = centre; /*L'hem trobat !!*/
        else if (mod_c < mod_centre)
            sup = centre -1;
        else
            inf = centre +1;
    
    }
    
    return (pos); /* Si no hem trobat el complex, pos = -1 */
}






int eliminar(t_vec_comp *vc, t_complex c)
{
    int i, pos = -1;
    
    
    for (i = 0; i < vc->num_comp && pos == -1; i++)
    {
        
        if (vc->complexos[i].real == c.real && vc->complexos[i].imaginaria == c.imaginaria)
            pos = i;
        
    }
    
    if (pos == -1)
        return(-1);
    else
    {
        for (i = pos +1; i < vc->num_comp; i++)
            vc->complexos[i-1] = vc->complexos[i];
        
        vc->num_comp--;
        
        return (0);
    }
    
    
}