/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "ejercicios.h"
#include "colours.h"

void sesion3_ej1()
{
    /* Completar con el código del ejercicio 1 */
    
    t_fraccion frac1, frac2, fracres;
    
    int suma, resta, multiplicacion;
    
    double division;
    
    
    
    printf("Fraccion 1 (formato x/y): ");
    scanf("%d/%d", &frac1.num, &frac1.den);
    printf("Fraccion 2 (formato x/y): ");
    scanf("%d/%d", &frac2.num, &frac2.den);
    
    printf("RESULTADO DE LAS OPERACIONES: \n\n");
    
    /*Resultado de la suma*/
    
    fracres.num = (frac1.num * frac2.den) + (frac2.num * frac1.den);
    fracres.den = (frac1.den * frac2.den);
    
    
    printf("Suma: %d/%d + %d/%d = %d/%d\n\n", frac1.num, frac1.den, frac2.num, frac2.den, fracres.num, fracres.den);
    
    /*Resultado de la resta*/
    
    fracres.num = (frac1.num * frac2.den) - (frac2.num * frac1.den);
    fracres.den = (frac1.den * frac2.den);
    
    
    printf("Resta: %d/%d - %d/%d = %d/%d\n\n", frac1.num, frac1.den, frac2.num, frac2.den, fracres.num, fracres.den);
    
    
    /*Resultado de la multiplicación*/
    
    
    fracres.num = (frac1.num * frac2.num);
    fracres.den = (frac1.den * frac2.den);
    
    
    printf("Multiplicación: %d/%d * %d/%d = %d/%d\n\n", frac1.num, frac1.den, frac2.num, frac2.den, fracres.num, fracres.den);
    
    
    /*Resultado de la división*/
    
    fracres.num = (frac1.num * frac2.den);
    fracres.den = (frac1.den * frac2.num);
    
    
    printf("División: %d/%d / %d/%d = %d/%d\n\n", frac1.num, frac1.den, frac2.num, frac2.den, fracres.num, fracres.den);
   
}


void sesion3_ej2a()
{
    /* Completar con el código del ejercicio 2.a */
    
    t_carta carta;
    
    printf("Figura carta: r o R, c o C, s o S, 9, ... , 1\nPalo carta: o o O(OROS), c o C(COPAS), e o E(ESPADAS) o b o B(BASTOS)\n");
    
    printf("Carta (figura, palo): ");
    
    scanf("(%c,%c)", &carta.fig, &carta.pal);
    
    if ((carta.fig >= 'a') && (carta.fig <= 'z')) {carta.fig = carta.fig-32;}
    if ((carta.pal >= 'a') && (carta.pal <= 'z')) {carta.pal = carta.pal-32;}
    
    /*printf("(%c,%c)", carta.fig, carta.pal);*/
    
    switch (carta.pal) {
        case 'C':
            printf("(%c,", carta.fig);
            cambiar_color(RED);
            printf("%c", carta.pal);
            cambiar_color(DEFAULT);
            printf(")");
            break;
            
        case 'O':
            printf("(%c,", carta.fig);
            cambiar_color(YELLOW);
            printf("%c", carta.pal);
            cambiar_color(DEFAULT);
            printf(")");
            break;
        case 'B':
            printf("(%c,", carta.fig);
            cambiar_color(GREEN);
            printf("%c", carta.pal);
            cambiar_color(DEFAULT);
            printf(")");
            break;
        case 'E':
            printf("(%c,", carta.fig);
            cambiar_color(BLUE);
            printf("%c", carta.pal);
            cambiar_color(DEFAULT);
            printf(")");
            break;
        
        
    }
    
    
    
    
    
    
    
    
    
    
}


void sesion3_ej2b()
{
    /* Completar con el código del ejercicio 2.b */
    t_carta carta, alta;
    
    
    char pals[4] = {'B', 'E', 'C', 'O'};

    char figuras[12] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'S', 'C', 'R'};
    
    char car;
    
    int i, pos, pos_fig, j;
    
    
    int pos_max = -1;
    
    int pos_max_fig = -1;
    
    
    printf("Figura carta: r o R, c o C, s o S, 9, ... , 1\nPalo carta: o o O(OROS), c o C(COPAS), e o E(ESPADAS) o b o B(BASTOS)\n");
    
    printf("Carta (figura, palo): ");
    
    do {
        
        scanf(" ( %c, %c ) %c", &carta.fig, &carta.pal, &car);
        
        
        if ((carta.fig >= 'a') && (carta.fig <= 'z')) {carta.fig = carta.fig-32;}
        
        if ((carta.pal >= 'a') && (carta.pal <= 'z')) {carta.pal = carta.pal-32;}
        
        
        
        for (i=0; i<4; i++) {
            if (pals[i] == carta.pal){
                pos = i;
            }    
        }
        
        
        for (j=0; j<12; j++){
            if (figuras[j] == carta.fig){
                pos_fig = j;
            }    
                
        }
        
        
        
        
        
               
        if (pos > pos_max){
            pos_max = pos;
            pos_max_fig = pos_fig;
            alta.fig = carta.fig;
            alta.pal = carta.pal;
        }
        
        else if ((pos == pos_max) && (pos_fig > pos_max_fig)){
            pos_max_fig = pos_fig;
            alta.fig = carta.fig;
            alta.pal = carta.pal;
     
            
        }
        
    }while (car != '.');
    
    
    switch (alta.pal) {
        case 'C':
            printf("(%c,", alta.fig);
            cambiar_color(RED);
            printf("%c", alta.pal);
            cambiar_color(DEFAULT);
            printf(")");
            break;
            
        case 'O':
            printf("(%c,", alta.fig);
            cambiar_color(YELLOW);
            printf("%c", alta.pal);
            cambiar_color(DEFAULT);
            printf(")");
            break;
        case 'B':
            printf("(%c,", alta.fig);
            cambiar_color(GREEN);
            printf("%c", alta.pal);
            cambiar_color(DEFAULT);
            printf(")");
            break;
        case 'E':
            printf("(%c,", alta.fig);
            cambiar_color(BLUE);
            printf("%c", alta.pal);
            cambiar_color(DEFAULT);
            printf(")");
            break;
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}


void sesion3_ej3()
{
    /* Completar con el código del ejercicio 3 */
    
    t_estudiante lista_alumnos[NUM_ESTUDIANTES];
    
    
    int i, j, indice_ganador, k;
    
    int max_aprovados = -1;
    
    int count = 0;
    
    
    for (i = 0; i < NUM_ESTUDIANTES; i++) {
        
        printf("Id del estudiante: ");
        scanf("%d", &lista_alumnos[i].id);
        
        printf("Nota promedio: ");
        scanf("%f", &lista_alumnos[i].nota_promedio);

        printf("Fecha nacimiento (aaaammdd): ");
        scanf("%d", &lista_alumnos[i].fecha_nacimiento);

        printf("Total de asignaturas aprovadas: ");
        scanf("%d", &lista_alumnos[i].num_asignaturas_aprobadas);
        
        printf("\n\n");
    }
    
    for (j=0;j<NUM_ESTUDIANTES;j++){
        if (lista_alumnos[j].num_asignaturas_aprobadas > max_aprovados){
            max_aprovados = lista_alumnos[j].num_asignaturas_aprobadas;
            indice_ganador = j;
            
        }
        
    }
    
    printf("Estudiante con mas asignaturas aprovadas: \n");
    printf("Id: %d\n", lista_alumnos[indice_ganador].id);
    printf("Nota promedio: %.2f\n", lista_alumnos[indice_ganador].nota_promedio);
    printf("Fecha nacimiento: %d\n", lista_alumnos[indice_ganador].fecha_nacimiento);
    printf("Total de asignaturas aprovadas: %d\n", lista_alumnos[indice_ganador].num_asignaturas_aprobadas);
    
    
    for (k=0;k<NUM_ESTUDIANTES;k++){
        if ((lista_alumnos[k].nota_promedio >= 9.0) && (lista_alumnos[k].num_asignaturas_aprobadas > 5))
            count ++;
        
    }
    
    
    printf("Total de estudiantes con nota >= 9.0 y mas de 5 asignaturas aprobadas: %d", count);
    
    
}


void sesion3_ej4a()
{
    /* Completar con el código del ejercicio 4.a */
    
    int id1, id2;
    
    int distancias[MAX_CAPITALES][MAX_CAPITALES] = {
        {0, 1720, 456, 1845, 1473}, /* LONDRES */
        {1720, 0, 1272, 1965, 2399}, /* MADRID */
        {456, 1272, 0, 1468, 1280}, /* PARIS */
        {1845, 1965, 1468, 0, 1130}, /* ROMA */
        {1473, 2399, 1280, 1130, 0} /* VIENA */
    };
    
    
    
    printf("Introduce el identificador de las dos capitales (id1, id2): ");
    scanf("%d,%d", &id1, &id2);
    
    if ((0 <= id1 && id1 < MAX_CAPITALES) && (0 <= id2 && id2 < MAX_CAPITALES)){
        
        printf("La distancia entre las capitales %d y %d es %d", id1, id2, distancias[id1][id2]);
        
    }
    else{
        printf("Alguno de los identificadores es invalido.");
    }    
    
}


void sesion3_ej4b()
{
    /* Completar con el código del ejercicio 4.b */
    int distancias[MAX_CAPITALES][MAX_CAPITALES] = {
        {0, 1720, 456, 1845, 1473},  // 0: Londres
        {1720, 0, 1272, 1965, 2399}, // 1: Madrid
        {456, 1272, 0, 1468, 1280},  // 2: París
        {1845, 1965, 1468, 0, 1130}, // 3: Roma
        {1473, 2399, 1280, 1130, 0}  // 4: Viena
    };
    
    int id_actual;
    int id_anterior = -1; 
    int distancia_total = 0;
    int es_invalido = 0;

    printf("Introduce el id de las ciudades a visitar (id1, id2, ...): ");
       
    do {
        scanf("%d,", &id_actual); /* Si no hay coma (como en el -1 final), no pasa nada, devuelve 1 igual. */
        
        if (id_actual != -1) {
            
            if (id_actual < 0 || id_actual >= MAX_CAPITALES) {
                es_invalido = 1;
            } 
            else if (!es_invalido) {
                if (id_anterior != -1) {
                    distancia_total += distancias[id_anterior][id_actual];
                }
                id_anterior = id_actual;
            }
        }
        
    } while (id_actual != -1);

    if (es_invalido) {
        printf("Alguno de los identificadores es invalido.\n");
        distancia_total = 0;
    }

    printf("La distancia del camino es: %d\n", distancia_total);
    
    
    
}