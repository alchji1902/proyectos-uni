#include <stdio.h>
#include <stdlib.h>
#include "voto_pila.h"
#include "elector.h"

int main(int argc, char** argv) {    
    
    /* Completar código: apartado (e) */
    
    t_electorado elect;
    t_votos *votos;
    t_elector elector1 = {{111111111, 'H'}, "Pepito", "Perez", "Perez", NO};
    t_elector elector2 = {{222222222, 'D'}, "Juanito", "Garcia", "Garcia", NO};
    t_elector elector3 = {{333333333, 'I'}, "Jorgito", "Lopez", "Lopez", NO};
    
    if (inicializar_electorado(&elect) == -1)
        return (EXIT_FAILURE);
    if (inicializar_votos(&votos) == -1)
        return (EXIT_FAILURE);
    
    if (anyadir_elector(&elect, elector1) == -1)
        printf("Error anyadiendo elector\n");
    else         
        printf("Elector anyadido\n");
    
    if (anyadir_elector(&elect, elector2) == -1)                
        printf("Error anyadiendo elector\n");
    else         
        printf("Elector anyadido\n");
    
    if (anyadir_elector(&elect, elector3) == -1)
        printf("Error anyadiendo elector\n");
    else         
        printf("Elector anyadido\n");
    
    mostrar_electorado(&elect);
    
    if (comprobar_voto(&elect, elector1.nif) == 0){
        if (votar_elector(&elect, votos, elector1.nif, SI) == 0)
            printf("Voto correcto\n");
        else 
            printf("Error votando\n");
    }
    
    else
        printf("Error votando\n");
    
    if (comprobar_voto(&elect, elector1.nif) == 0){
        if (votar_elector(&elect, votos, elector1.nif, SI) == 0)
            printf("Voto correcto\n");
        else 
            printf("Error votando\n");
    }
    
    else
        printf("Error votando\n");
    
    if (comprobar_voto(&elect, elector2.nif) == 0){
        if (votar_elector(&elect, votos, elector2.nif, SI) == 0)
            printf("Voto correcto\n");
        else 
            printf("Error votando\n");
    }
    
    else
        printf("Error votando\n");
    
    
    mostrar_electorado(&elect);
    
    mostrar_votos(votos);
    
    
    liberar_votos(&votos);
    
    return (EXIT_SUCCESS);
}

/* Responder a continuación las preguntas propuestas 
 * en el enunciado a partir de los resultados obtenidos 
 * mediante la herramienta Valgrind: apartado (f) */