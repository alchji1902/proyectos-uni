/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef SESION5_EJ3_H
#define SESION5_EJ3_H

#include <stdio.h>
#include <math.h>

#define MAX_COMPLEX 100

typedef struct
{    
     double preal;
     double pimag;
     double mod;
} t_complex; 

typedef struct
{
   int ncomplex;
   t_complex vcomplex[MAX_COMPLEX];
} t_vector_complejos; 


t_complex leer_complejo();
void mostrar_complejo(t_complex c);
void leer_vector_complejos(t_vector_complejos *vc);
void mostrar_vector_complejos(t_vector_complejos vc);
int eliminar_complejo_menor (t_vector_complejos *vc);

void sesion5_ej3();


#endif /* SESION5_EJ3_H */
