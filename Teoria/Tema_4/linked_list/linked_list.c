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
    t_node *tmp;
    int i = 0;

    if (index < 0 || index >= llista->size)
    {
        return NULL; //Index fora de rang
    }

    tmp = llista->head; //Fem una copia del node que apunta al head de la llista, per poder iterar per la llista sense modificar el head
    while (i < index) //Iterem per la llista fins arribar a l'index desitjat
    {
        tmp = tmp->next; //Actualitzem el tmp per apuntar al seguent node de la llista
        i++;
    }

    return tmp; // tmp apunta al node que representa la posicio de l'index de la llista enllaçada. 
}


int set(t_linked_list *llista, int index, int valor) // Tipicament significa substituir. 
{
    t_node *node;

    node = obtenir_node(llista, index); //Obtenim el node que representa la posicio de l'index de la llista enllaçada

    if (node == NULL)
        return (-2); //Index fora de rang

    node->valor = valor; //Actualitzem el valor del node que representa la posicio de l'index de la llista enllaçada

    return 0;

}

int inserir(t_linked_list *llista, int index, int valor)
{
    t_node *node, *tmp;

    if (index < 0 || index > llista->size)
        return (-2); //Index fora de rang

    node = (t_node *)malloc(sizeof(t_node));
    
    if (node == NULL)
        return -1; //malloc ha fallat

    node->valor = valor;

    if (index == 0) //Inserim al principi de la llista
    {
        node->next = llista->head; //El seguent del nou node apunta al head de la llista
        llista->head = node; //El head de la llista apunta al nou node
    }
    else
    {
        tmp = obtenir_node(llista, index - 1); //Obtenim el node que representa la posicio anterior a la posicio de l'index de la llista enllaçada

        node->next = tmp->next; //El seguent del nou node apunta al seguent del node que representa la posicio anterior a la posicio de l'index de la llista enllaçada
        tmp->next = node; //El seguent del node que representa la posicio anterior a la posicio de l'index de la llista enllaçada apunta al nou node
    }

    llista->size++; //Incrementem el tamany de la llista un cop afegit el nou node

    return (0);
}


int eliminar(t_linked_list *llista, int index)
{
    t_node *tmp, *tmp2;

    if (index < 0 || index >= llista->size)
        return (-2); //Index fora de rang (Posició index invalida). 

    if (index == 0) //Eliminem el primer node de la llista
    {
        tmp = llista->head; //Fem una copia del node que apunta al head de la llista, per poder alliberar la memoria del node que estem eliminant
        llista->head = llista->head->next; //El head de la llista apunta al seguent node de la llista
        free(tmp); //Alliberem la memoria del node que estem eliminant
    }
    else
    {
        tmp = obtenir_node(llista, index - 1); //Obtenim el node que representa la posicio anterior a la posicio de l'index de la llista enllaçada

        tmp2 = tmp->next; //Fem una copia del node que representa la posicio de l'index de la llista enllaçada, per poder alliberar la memoria del node que estem eliminant

        tmp->next = tmp2->next; //El seguent del node que representa la posicio anterior a la posicio de l'index de la llista enllaçada apunta al seguent del node que representa la posicio de l'index de la llista enllaçada

        free(tmp2); //Alliberem la memoria del node que estem eliminant
    }

    llista->size--; //Decrementem el tamany de la llista un cop eliminat el node

    return (0);
}


