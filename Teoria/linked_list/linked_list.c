/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */


#include <stdio.h>
#include "linked_list.h"
#include <stdlib.h>

t_linked_list * crear_llista()
{
    t_linked_list *llista;
    llista = (t_linked_list *)malloc(sizeof(t_linked_list));
    
    if (llista != NULL)
    {
        /*malloc() ha funcionat*/
        llista->size = 0;
        llista->head = NULL;
    }
    return llista;
}



void alliberar_llista(t_linked_list *llista)
{
    t_node *tmp;

    while (llista->head != NULL)
    {
        tmp = llista->head->next; //El necestem per alliberar la memoria del node que estem alliberant 
        free(llista->head); // Alliberem la memoria del node que estem alliberant
        llista->size--;
        llista->head = tmp;
    }

    free(llista);

}


/* ALTERNATIVA DE LA FUNCIO ALLIBERAR LLISTA, QUE ES MÉS OPTIMA PERQUÈ NO NECESSITA UNA VARIABLE TEMPORAL PER GUARDAR EL SEGÜENT NODE, JA QUE AIXÒ ES POT FER DIRECTAMENT AMB LA VARIABLE DE LA LLISTA.

void alliberar_llista(t_linked_list *llista)
{
    t_node *tmp;

    while (llista->head != NULL)
    {
        tmp = llista->head; //El necestem per alliberar la memoria del node que estem alliberant 
        llista->head = llista->head->next; // Aixo apunta al seguent node del que s'està alliberant
        free(tmp); //Alliberem la memoria del node que estem alliberant
    }
    free(llista); //Alliberem la memoria de la llista un cop alliberats tots els nodes
}
*/


int add(t_linked_list *llista, int valor)
{
    t_node *node;
    t_node *tmp;


    node = (t_node *)malloc(sizeof(t_node));
    if (node == NULL)
    {
        //malloc ha fallat
        return -1;
    }
    node->valor = valor;
    node->next = NULL;

    if (llista->head == NULL)
    {
        llista->head = node;
    }
    else
    {
        tmp = llista->head; //Fem una copia del node que apunta al head de la llista, per poder iterar per la llista sense modificar el head
        while (tmp->next != NULL) //Iterem per la llista fins arribar al final
        {
            /*Encara no apuntem al darrer node de la llista: 
              saltem al seu node següent*/

            tmp = tmp->next; //Actualitzem el tmp per apuntar al seguent node de la llista
        }

        tmp->next = node; //Un cop arribem al final de la llista, assignem el nou node al seguent del ultim node de la llista
    }
    llista->size++; //Incrementem el tamany de la llista un cop afegit el nou node
    return 0;
}


void mostrar_llista(t_linked_list *llista)
{
    t_node *tmp;

    printf("LLista de mida %d: ==> {", llista->size);

    if (llista->head != NULL)
    {
        printf("%d", llista->head->valor); //Mostrem el valor del head de la llista
        tmp = llista->head->next; //Fem una copia del node que apunta al head de la llista, per poder iterar per la llista sense modificar el head
        while (tmp != NULL) 
        {
            printf(" -> %d", tmp->valor); //Mostrem el valor del node actual
            tmp = tmp->next; //Actualitzem el tmp per apuntar al seguent node de la llista
        }
    }

    printf("}\n");
}




t_node * obtenir_node(t_linked_list *llista, int index)
{
    
}





