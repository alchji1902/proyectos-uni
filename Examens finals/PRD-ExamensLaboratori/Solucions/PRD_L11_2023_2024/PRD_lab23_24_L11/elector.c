/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "elector.h"
#include <stdio.h>

int inicializar_electorado (t_electorado *l_elect)
{
    l_elect->numelec = 0;
}

int buscar_elector (t_electorado *l_elect, t_nif n)
{
    int i, encontrado = 0, pos;
    if (l_elect->numelec == 0)
        return -1;
    
    i = 0;
    while(i<l_elect->numelec && !encontrado)
    {
        if (l_elect->electores[i].nif.numero == n.numero)
        {
            encontrado = 1;        
            pos = i;
        }
        i++;        
    }
    if (!encontrado)
        return -1;
    
    return pos;
}

int anyadir_elector (t_electorado *l_elect, t_elector e)
{       
    if (l_elect->numelec == MAX_EL)
        return -1;
    
    if (buscar_elector (l_elect, e.nif) == -1)
    {
        l_elect->electores[l_elect->numelec++] = e;
        return 0;        
    }
   
    return -1;
}

int eliminar_elector (t_electorado *l_elect, t_nif n)
{
    int pos, i;
    
    if (l_elect->numelec == 0)
        return -1;
    
    pos = buscar_elector (l_elect, n);    
    if (pos == -1)    
        return -1;    
   
    for (i=pos; i<l_elect->numelec-1;i++)
        l_elect->electores[i] = l_elect->electores[i+1];
    
    l_elect->numelec--;
    
    return 0;   
}

int votar_elector (t_electorado *l_elect, t_votos *v, t_nif n, int voto)
{
    int pos, i, res;
    
    if (l_elect->numelec == 0)
        return -1;
    
    pos = buscar_elector (l_elect, n);    
    if (pos == -1)    
        return -1;        
   
    if (l_elect->electores[pos].ha_votado == SI)
        return -1;
    
    l_elect->electores[pos].ha_votado = SI;    
    res = votar(v, voto);
    
    return res;    
}

int comprobar_voto (t_electorado *l_elect, t_nif n)
{
    int pos;
    
    pos = buscar_elector (l_elect, n);    
    if (pos == -1)    
        return -1;   
   
    if (l_elect->electores[pos].ha_votado == SI)
        return 1;
    else
        return 0;
    
    return -1;    
}

void mostrar_electorado (t_electorado *l_elect)
{
    int i;
    
    printf("\nElectorado:\n");
    for (i=0; i<l_elect->numelec;i++)
    {
        printf("Nombre y Apellidos: %s %s %s\n", l_elect->electores[i].nombre, l_elect->electores[i].apellido1, l_elect->electores[i].apellido2);
        printf("NIF: %d-%c\n", l_elect->electores[i].nif.numero, l_elect->electores[i].nif.letra);
        printf("¿Ha votado? ");
        switch (l_elect->electores[i].ha_votado)
        {
            case SI: 
                printf ("SI");
                break;                
            case NO:
                printf ("NO");
                break;          
        }   
        printf("\n");
    }    
    printf("\n");
}
