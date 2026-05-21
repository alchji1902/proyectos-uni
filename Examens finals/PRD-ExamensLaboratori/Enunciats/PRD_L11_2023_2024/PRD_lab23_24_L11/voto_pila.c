/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "voto_pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inicializar_votos (t_votos **l_votos)
{
    (*l_votos) = (t_votos *) malloc (sizeof (t_votos));
    if (*l_votos == NULL)
        return -1;
    
    (*l_votos)->nvotos = 0;
    (*l_votos)->top = NULL;
}

int obtener_hora_actual()
{
    time_t t;
    struct tm *tm;
    
    t = time (NULL);
    tm = localtime(&t);
    
    return (tm->tm_hour*100 + tm->tm_min);
}

int votar (t_votos *l_votos, int valor)
{
    t_voto *new_voto;
    
    new_voto = (t_voto *) malloc (sizeof (t_voto));
    if (new_voto == NULL)
        return -1;
    
    new_voto->valor = valor;
    new_voto->hora  = obtener_hora_actual();
    
    new_voto->next  = l_votos->top;
    l_votos->top    = new_voto;    
    l_votos->nvotos++;    
    
    return (0);
}

void mostrar_votos (t_votos *l_votos)
{
    int i;
    t_voto *tmp;
    
    if (l_votos->nvotos == 0)
    {
        printf ("No hay ningún voto\n");
        return;
    }
    
    printf ("\n");
    tmp = l_votos->top;
    for (i=0; i < l_votos->nvotos; i++)
    {
        printf ("Voto: %d Valor: ", i);
        if (tmp->valor == VOT_SI)
            printf ("SI\t");
        else if (tmp->valor == VOT_NO)
            printf ("NO\t");
        else if (tmp->valor == VOT_BLANCO)
            printf ("En blanco");
        
        printf (" Emitido a las %02d:%02d\n", tmp->hora/100, tmp->hora%100);        
        tmp = tmp->next;
    }
    printf ("\n");
}

int liberar_votos (t_votos **l_votos)
{
    t_voto *tmp;
    int i;
    
    if (*l_votos == NULL)            
        return -1;
        
    tmp = (*l_votos)->top;
    for (i=0; i<(*l_votos)->nvotos;i++)
    {
        (*l_votos)->top = tmp->next;
        free(tmp);
        tmp = (*l_votos)->top;
    }
    
    free (*l_votos);
    
    return 0;
}