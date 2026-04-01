/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sesion5_ej3.h"

#include <math.h>





t_complex leer_complejo()
{
    t_complex complex;
    
    char basura;
    
    
    printf("Introduce complejo (a+bi): ");
    scanf("%lf+ %lfi", &complex.preal, &complex.pimag);
    scanf("%c", &basura);
    
    
    complex.mod = sqrt(complex.preal * complex.preal + complex.pimag * complex.pimag);
    
    
    return (complex);
    
    
}


void mostrar_complejo(t_complex c)
{
    printf("%.2lf + %.2lfi (mod=%.2lf)\n\n", c.preal, c.pimag, c.mod);
    
    
    
    
}

void leer_vector_complejos(t_vector_complejos *vc)
{
    int i;
    
    printf("Introduce cantidad de numeros complejos del vector de complejos: ");
    scanf("%d", &vc->ncomplex);
    
    for (i = 0; i < vc->ncomplex; i++)
    {
        vc->vcomplex[i] = leer_complejo();
        
    }
    
    
}


void mostrar_vector_complejos(t_vector_complejos vc)
{
    
    int i; 
    
    if (vc.ncomplex == 0)
        printf("Vector vacio. ");
        
    
    else {
        for (i = 0; i < vc.ncomplex; i++)
        {
            mostrar_complejo(vc.vcomplex[i]);


        }
    
    }
    
}


int eliminar_complejo_menor (t_vector_complejos *vc)
{
    int pos = -1, i;
    
    t_complex comp_aux;
    
    if (vc->ncomplex == 0)
        return (0);
    
    
    comp_aux.mod = vc->vcomplex[0].mod;
    
    
    for (i = 0; i < vc->ncomplex; i++)
    {
        
        if (vc->vcomplex[i].mod <= comp_aux.mod){
            
            comp_aux.mod = vc->vcomplex[i].mod;
            pos = i;
        }
        
        
    }
    
    
    for (i = pos; i < vc->ncomplex-1; i++)
    {
        
        vc->vcomplex[i] = vc->vcomplex[i+1]; 
        
    }
    
    
    
    
    if (pos == -1)
        return (0);
    else{
        vc->ncomplex--;
        return(1);
    }
    
    
    
}



void sesion5_ej3()
{
    t_vector_complejos vc;
    
    leer_vector_complejos(&vc);
    
    int elim = eliminar_complejo_menor(&vc);
    
    if (elim == 0)
        printf("\nNo se ha podido eliminar el complejo con menor modulo.\n\n");
    
    else 
        printf("\nSe ha podido eliminar el complejo con menor modulo.\n\n");
    
    
    printf("Vector de complejos: \n\n");
    mostrar_vector_complejos(vc);
    
	
}