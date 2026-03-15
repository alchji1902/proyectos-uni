/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef EJERCICIOS_H
#define EJERCICIOS_H

/*Ejercicio3*/
#define NUM_ESTUDIANTES 3

/*Ejercicio4*/
#define MAX_CAPITALES 5


/*Ejercicio2*/
typedef struct {
    
    int num;        /* Numerador */
    int den;        /* Denominador */
    
} t_fraccion;

typedef struct {
    
    char fig;       /* Figura: 'R' (Rey), 'C' (Caballo), 'S' (Sota),
                    *           '9','8','7','6','5','4','3','2','1' */
                    
    char pal;       /* Palo: 'O' (Oros), 'C' (Copas), 'E' (Espadas),
                    *           'B' (Bastos) */
} t_carta;


/*Ejercicio3*/
typedef struct {
    int id;
    float nota_promedio;
    int fecha_nacimiento; /* Formato: aaaammdd */
    int num_asignaturas_aprobadas;
    
} t_estudiante;



void sesion3_ej1();
void sesion3_ej2a();
void sesion3_ej2b();
void sesion3_ej3();
void sesion3_ej4a();
void sesion3_ej4b();

#endif /* EJERCICIOS_H */

