/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sesion5_ej1.h"



int eliminar_elemento(int elem, t_vector *v) 
{
    int desp = 0;
    
    int i;

    for (i = 0; i < v->nelem; i++)
    {
        if (elem == v->vector[i])
        {
            desp++;
            
        }
        
        else {
            v->vector[i-desp] = v->vector[i];
            
        }
        
    }
    
    v->nelem = v->nelem - desp;
    
    if (desp == 0)
        return (0);
    
    else
        return (desp);
    
    
}


void sesion5_ej1()
{
    t_vector v = {16,{3,15,19,19,23,32,38,53,123,321,543,1000,1123,6578,6660,7999}};
    int num;
    int i;
    int num_elim;
    
    
    printf("Numero a eliminar: ");
    scanf("%d", &num);
    
    
    num_elim = eliminar_elemento(num, &v);
    
    
    if (num_elim == 0)
        printf("Elemento no eliminado");
    else {
        printf("Se han eliminado %d elementos \n\n", num_elim);    
        
        
        printf("Elementos del vector: %d", v.vector[0]);
        
        for (i = 1; i < v.nelem; i++)
        {
            printf(",%d", v.vector[i]);
            
            
        }
    
    
    }
}