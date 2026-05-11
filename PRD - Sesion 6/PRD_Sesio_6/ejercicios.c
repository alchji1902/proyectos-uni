/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "nif.h"
#include "array_list.h"



void sesion6_ej1()
{
    t_nif nif1 = generar_nif_aleatorio(), nif2 = generar_nif_aleatorio();
    
    mostrar_nif(nif1);
    printf("\n");
    mostrar_nif(nif2);
    printf("\n");
    
    
    if (comparar_nifs(nif1, nif2) > 0)
        printf("nif1 es mayor que nif2. ");
    else if (comparar_nifs(nif1, nif2) < 0)
        printf("nif2 es mayor que nif1. ");
    else
        printf("Los nifs son iguales. ");
    
    
}


void sesion6_ej2()
{
    int i;
    
    t_array_list * lista;
    lista = crear_lista();
    
    for (i = 0; i < 7; i++)
        add(lista, generar_nif_aleatorio());
    
    mostrar_lista(lista);
    
    for (i = 0; i < 4; i++)
        add(lista, generar_nif_aleatorio());
    
    mostrar_lista(lista);
    
    liberar_lista(lista);
    
}

void sesion6_ej3a()
{
    int i;
    
    t_array_list * lista;
    lista = crear_lista();
    
    for (i = 0; i < 7; i++)
        add(lista, generar_nif_aleatorio());
    
    mostrar_lista(lista);
    
    ordenar_lista_por_nif(lista);
    
    mostrar_lista(lista); 
    
    liberar_lista(lista);
    
    
}


void sesion6_ej3b()
{
    int i;
    
    t_array_list * lista;
    lista = crear_lista();
    
    for (i = 0; i < 7; i++)
            
    insertar_en_orden(lista, generar_nif_aleatorio());
    
    mostrar_lista(lista);
    
    liberar_lista(lista);
}


void sesion6_ej3c()
{
    int i;
    t_nif nif;
    int val; 

    t_array_list * lista;
    lista = crear_lista();
    
    for (i = 0; i < 7; i++)
            
    insertar_en_orden(lista, generar_nif_aleatorio());
    
    mostrar_lista(lista);

    printf("\n\n");

    printf("Introduce el nif a buscar: ");
    scanf("%d%c", &nif.numero, &nif.letra);

    val = buscar_registro_ordenado(lista, nif);

    if (val == -1)
        printf("Nif no encontrado....\n");
    
    else
        printf("Nif encontrado en la posición: %d\n", val);
    
    liberar_lista(lista);
}


void sesion6_ej4()
{
    int i;
    t_nif nif;
    int val; 

    t_array_list * lista;
    lista = crear_lista();
    
    for (i = 0; i < 7; i++)
            
    insertar_en_orden(lista, generar_nif_aleatorio());
    
    mostrar_lista(lista);
    printf("\n\n");

    printf("Introduce el nif a eliminar: ");
    scanf("%d%c", &nif.numero, &nif.letra);

    val = eliminar_nif(lista, nif);

    if (val == 0)
        printf("Nif no encontrado... \n\n"); 
    
    else if (val == 1){
        printf("Nif eliminado. \n\n");
        mostrar_lista(lista);
    }

    else
        printf("Ha habido un problema al relocar la memoria. \n");
    
    liberar_lista(lista);
    
}