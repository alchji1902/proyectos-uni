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
    int i, pos = -1;
    
    for (i = 0; i < l_elect->numelec; i++){
        if (l_elect->electores[i].nif.numero == n.numero){
            pos = i;
        }
    }
    
    if (pos == -1){
        return -1;
    }
    else
        return pos;
    
}

int anyadir_elector (t_electorado *l_elect, t_elector e)
{
    int encontrado = -1; 
    
    if (l_elect->numelec >= MAX_EL){
        return -1;
    }
    
    encontrado = buscar_elector(l_elect, e.nif);
    
    if (encontrado != -1){
        return -1;
    }
    
    
    l_elect->electores[l_elect->numelec] = e;
    l_elect->numelec++;
    return 0;
}

int votar_elector (t_electorado *l_elect, t_votos *v, t_nif n, int voto)
{
    /* Completar código: apartado (c) */
    int encontrado = -1, able = -1;

    encontrado = buscar_elector(l_elect, n);
    
    if (encontrado == -1)
        return -1;
    
    if (l_elect->electores[encontrado].ha_votado == SI)
        return -1;
    
    able = votar(v, voto);

    if (able == -1)
        return -1;
    
    l_elect->electores[encontrado].ha_votado = SI;
    
    return 0;
    
    
    
    
}

int comprobar_voto (t_electorado *l_elect, t_nif n)
{
    /* Completar código: apartado (d) */
    
    int encontrado = -1;

    encontrado = buscar_elector(l_elect, n);
    
    if (encontrado == -1)
        return -1;
    
    if (l_elect->electores[encontrado].ha_votado == SI)
        return 1;
    
    
    return 0;
    
    
    
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
