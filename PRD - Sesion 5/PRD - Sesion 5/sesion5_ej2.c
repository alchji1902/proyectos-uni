/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "sesion5_ej2.h"



t_persona leer_persona()
{
    t_persona pers;
    
    char basura;
    
    printf("Introduzca el nombre (<20 caracteres): ");
    
    char car = '\0';
    
    int i = 0;
    
    do 
    {
        scanf("%c", &car);
        pers.nom[i] = car;
        i++;
        
        
    } while (car != '\n');
    
    pers.nom[i] = '\0';
    
    printf("Introduzca DNI (Ej: 11111111A): ");
    
    scanf("%d %c", &pers.dni.numero, &pers.dni.letra);
    
    scanf("%c", &basura);
    
    return (pers);    
}


void mostrar_persona(t_persona p)
{
    printf("Nombre: %s", p.nom);
    printf("DNI: %d", p.dni.numero);
    printf("%c", p.dni.letra);    
}

void leer_lista_personas (t_lista_personas *lp)
{
    char basura; 
    int i; 
    
    printf("Cuantas personas va a introducir: ");   
    scanf("%d", &lp->nper);
    scanf("%c", &basura);
    
    for (i = 0; i < lp->nper; i++){
        
        lp->personas[i] = leer_persona();
        printf("\n");   
    }   
}

void mostrar_lista_personas(t_lista_personas lp)
{
    
    int i; 
    
    printf("LISTA DE PERSONAS: \n\n");
    
    for (i = 0; i < lp.nper; i++)
    {
        
        mostrar_persona(lp.personas[i]);
        printf("\n\n");   
    }
}


int insertar_persona (t_lista_personas *lp, t_persona p)
{
    int pos = -1, i;
    
    if (lp->nper == MAX_PERSONAS)
        return (0);
    
    for (i = 0; i < lp->nper; i++){
        
        if (lp->personas[i].dni.numero == p.dni.numero)
            return (0);
        
    }
    
   
    
    for (i = 0; i < lp->nper && pos == -1; i++)
    {
        if (lp->personas[i].dni.numero > p.dni.numero)
            pos = i;
        
    }
    
    if (pos == -1)
        lp->personas[lp->nper] = p;
    
    else
    {
        
        for (i = lp->nper-1; i >= pos; i--)
            lp->personas[i+1] = lp->personas[i];
        
        lp->personas[pos] = p;
    }
    
    lp->nper++;
    
    return (1);
    
  
}


void sesion5_ej2a()
{
    t_persona pers = leer_persona();
    
    mostrar_persona(pers);

    
}



void sesion5_ej2b()
{
    
    t_lista_personas lp;
    
    leer_lista_personas(&lp);
    
    mostrar_lista_personas(lp);

    
}

void sesion5_ej2c()
{
    t_lista_personas lp = {5,{{"Maria Gomez\n", {11111111,'A'}},
            {"Jose Gonzalez\n", {22222222,'A'}},
            {"Juan Colas\n", {31111112,'B'}},
            {"Anna Bardou\n", {32365816,'S'}},
            {"Felip Sanz\n", {82723746,'A'}}}};
    
    t_persona pers; 
    
    pers = leer_persona();
    
    int conf = insertar_persona(&lp, pers);
    
    
    if (conf == 1){
        printf("Persona insertada \n\n");
        
        mostrar_lista_personas(lp);
    }        
    else {
        
        printf("Persona no insertada");
        
    }
 
}