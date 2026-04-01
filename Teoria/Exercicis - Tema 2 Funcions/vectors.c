/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "vectors.h"



int afegeix_valor(t_vector *v, int valor)
{
    
    if (v->num_valors == MAX_VAL)
        return(-1);      /*El vector ja es ple*/
    
    
    v->valors[v->num_valors]=valor;
    v->num_valors++;
    
    return(0);
}


void mostra_contingut (t_vector *v)
{
    /*Mostra el contingut del vector apuntat per v
     en format: v --> {valor0, valor1, ....., valor_{num-1}}}*/
    int i;
    
    printf("v => {");
    
    if (v->num_valors > 0)
    {
        
        printf("%d", v->valors[0]);
        for (i = 1; i < v->num_valors; i++)
            printf(", %d", v->valors[i]);
    }
    
    printf("}\n");
    
}



int insereix_valor_posicio(t_vector *v, int valor, int pos)
{
    /*Insereix valor a la posicio pos del vector
     apuntat per v. Retorna -1 si el vector ja es ple.
     -2 si pos representa una posicio d'insercio invalida, 
     o 0 si valor inserit satisfactoriament*/
    
    
    int i;
    
    if (v->num_valors == MAX_VAL)
        return(-1);
    
    if (pos < 0 || pos > v->num_valors)
        return (-2);
    
    for (i = v->num_valors -1; i >= pos; i--)
    {
        v->valors[i+1] = v->valors[i];
    }
    
    v->valors[pos] = valor;
    v->num_valors++;
    return(0);
    
    
    
    
    
}


int insereix_valor_ordenat(t_vector *v, int valor)
{
    
    int pos = -1, i;
    
    if (v->num_valors == MAX_VAL)
        return(-1);
    
    for (i = 0; i < v->num_valors && pos == -1; i++)
    {
     if (v->valors[i] >= valor)
         pos = i;
        
    }
    
    if (pos == -1)
        v->valors[v->num_valors] = valor;
    else 
    {
        // Si hem trobat una posició, desplacem els elements a la dreta
        // Comencem des de l'últim element cap enrere fins a 'pos'
        for (i = v->num_valors - 1; i >= pos; i--) 
        {
            v->valors[i + 1] = v->valors[i];
        }
        // Insertem el valor a la posició lliure
        v->valors[pos] = valor;
    }

    // 4. Incrementem el comptador de valors i retornem èxit
    v->num_valors++;
    
    return 0;
    
    
    /*Opcio d'implementacio mes compacta:
     
    int pos, i;

    // 1. Sempre cal comprovar si hi ha espai!
    if (v->num_valors >= MAX_VAL) {
        return -1;
    }

    // 2. Trobar la posició (compte amb el typo 'poss')
    pos = 0;
    while (pos < v->num_valors && v->valors[pos] < valor) {
        pos++; 
    }

    // 3. Desplaçar valors a la dreta
    for (i = v->num_valors - 1; i >= pos; i--) {
        v->valors[i + 1] = v->valors[i];
    }

    // 4. Inserir i actualitzar comptador
    v->valors[pos] = valor;
    v->num_valors++;

    return 0; */
   
}


int elimina_valor_posicio(t_vector *v, int pos)
{
    
    int i;
    
    if (pos < 0 || pos >= v->num_valors)
        return(-2);
    
    
    for (i = pos+1; i < v->num_valors; i++)
        v->valors[i-1] = v->valors[i];
    
    v->num_valors--;
    return(0);
    
}



void tests_vectors()
{
    
    t_vector vec;
    
    vec.num_valors = 0;
    
    printf("%d\n", afegeix_valor(&vec, 1));
    printf("%d\n", afegeix_valor(&vec, 3));
    printf("%d\n", afegeix_valor(&vec, 5));
    printf("%d\n", afegeix_valor(&vec, 7));
    printf("%d\n", afegeix_valor(&vec, 9));
    printf("%d\n\n", insereix_valor_posicio(&vec, 11, 1));
    
    mostra_contingut(&vec);
    
    
}