#include <stdio.h>
#include <stdlib.h>
#include "voto_pila.h"
#include "elector.h"

int main(int argc, char** argv) {    
    
    t_votos *v;
    t_electorado el;
    t_elector e1 = {{11111111, 'H'}, "Pepito", "Perez", "Perez", NO};
    t_elector e2 = {{22222222, 'D'}, "Juanito", "Garcia", "Garcia", NO};
    t_elector e3 = {{33333333, 'I'}, "Jorgito", "Lopez", "Lopez", NO};    
    
    inicializar_electorado(&el);
    inicializar_votos(&v);
    
    if (anyadir_elector(&el, e1) == -1)
        printf("Error anyadiendo elector\n");
    else         
        printf("Elector anyadido\n");
    
    if (anyadir_elector(&el, e2) == -1)                
        printf("Error anyadiendo elector\n");
    else         
        printf("Elector anyadido\n");
    
    if (anyadir_elector(&el, e3) == -1)
        printf("Error anyadiendo elector\n");
    else         
        printf("Elector anyadido\n");
    
    mostrar_electorado(&el);
      
    if (votar_elector (&el, v, e1.nif, VOT_NO) == -1)
        printf("Error votando\n");
    else
        printf("Voto correcto\n");
    
    if (votar_elector (&el, v, e1.nif, VOT_SI) == -1)
        printf("Error votando\n");
    else
        printf("Voto correcto\n");

    if (votar_elector (&el, v, e2.nif, VOT_BLANCO) == -1)
        printf("Error votando\n");
    else
        printf("Voto correcto\n");   
   
    mostrar_electorado(&el);    
   
    mostrar_votos (v);    
    
    //liberar_votos (&v);
    
    return (EXIT_SUCCESS);
}

/* Responder a continuación las preguntas propuestas 
 * en el enunciado a partir de los resultados obtenidos 
 * mediante la herramienta Valgrind: apartado (f) */

/*****************************************************
 * Al ejecutar Valgrind, la herramienta acaba mostrando
 * un total de 15 reservas de memoria dinámica (allocs)
 * y 15 liberaciones (frees), sumando un total de 7402
 * bytes reservados. Por tanto no existe ninguna fuga
 * de memoria dinámica.
 * 
 * Sin embargo, los bloques de memoria dinámica que
 * nuestro programa reserva para almacenar votos de los
 * electores son 3, de 16 bytes cada uno (48 bytes en
 * total): el primero almacena la variable de tipo t_votos
 * y los otros dos almacenan variables de tipo t_voto, que
 * representan los votos válidos. La variable de tipo t_votos
 * ocuparía en memoria 4+8 = 12 bytes, aunque C parece reservar
 * 16 bytes para ella. Las variables de tipo t_voto ocupan
 * exactamente 4+4+8 = 16 bytes en memoria. Todo ello puede
 * apreciarse mejor si se provoca una fuga de memoria dejando
 * de liberar la pila de votos al final del código de test,
 * es decir, dejando de invocar la función liberar_votos().
 *****************************************************/