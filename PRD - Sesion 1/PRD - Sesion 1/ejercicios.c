/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "ejercicios.h"
#include "colours.h"
#define PI 3.1416

void sesion1_ej1() {
    char a, b, c;
    int any;
    int edad;

    printf("Introduce tu anyo de nacimiento: ");
    scanf(" %d", &any);

    printf("Introduce tus tres iniciales: ");
    scanf(" %c %c %c", &a, &b, &c);

    edad = 2030 - any;

    
    printf("Hola ");
    cambiar_color(0); 
    printf("%c%c%c\n", a, b, c);
    cambiar_color(-1);

    
    printf("El 31/DIC/2030 tendras ");
    cambiar_color(2); 
    printf("%d", edad);
    cambiar_color(-1); 
    printf(" anys\n");
}


void sesion1_ej2()
{
    /* Completar con el código del ejercicio 2 */
    float radio, area, perimetro;
    printf("Introduaca el radio del circulo: ");
    scanf("%f", &radio);
    area = PI*radio*radio;
    perimetro = 2*PI*radio;
    printf("Area del circulo: %f\n", area);
    printf("Perimetro del circulo: %f\n", perimetro);
    
}


void sesion1_ej3()
{
    /* Completar con el código del ejercicio 3 */
    int k =7, resi;
    char c='a', resc;
    float f=5.5, g=-3.25, resf;
    
    
    resi = -2 + k;
    printf("%d\n", resi);
    
    resi = resi + 2;
    printf("%d\n", resi);
    
    resc = c;
    printf("%c\n", resc);
    
    resi = k % 5;
    printf("%d\n", resi);
    
    resf = (f - g) / 2;
    printf("%f\n", resf);
    
    resi = resi * (k - 3);
    printf("%d\n", resi);
    
    resf = k / (resi - 2);
    printf("%f\n", resf);
    
    resf = f / (resi - 2);
    printf("%f\n", resf);
    
    resi = 2 * (k - 3) % 3 / 2;
    printf("%d\n", resi);
    /* la variable resi vale ___5____ */
    /* la variable resi vale ___7____ */
    /* la variable resc vale ___a____ */
    /* la variable resi vale ___2____ */
    /* la variable resf vale ___4.375____ */
    /* la variable resi vale ___8____ */
    /* la variable resf vale ___1.0____ */
    /* la variable resf vale ___0.91666____ */
    /* la variable resi vale ___1____ */
}


void sesion1_ej4()
{
    /* Completar con el código del ejercicio 4 */
    int a,b,c,d,e,f,g;
    
    a= 5 / 2 + 20 % 6;
    b = 4 * 6 / 2 - 15 / 2;
    c = 5 * 15 / 2 / (4 - 2);
    d = 8 == 16 || 7 != 4 && 4 < 1;
    e = (4 * 3 < 6 || 3 > 5 - 2) && 3 + 2 < 12;
    f = 2 || 0;
    g = 1 && 0;
    
    printf("a. %d\n", a);
    printf("b. %d\n", b);
    printf("c. %d\n", c);
    printf("d. %d\n", d);
    printf("e. %d\n", e);
    printf("f. %d\n", f);
    printf("g. %d\n", g);
    
    
    
}


void sesion1_ej5()
{
    /* Completar con el código del ejercicio 5 */
    int hora, min, seg;
    printf("Introduzca una hora en formato hh:mm:ss: ");
    scanf("%d:%d:%d", &hora, &min, &seg);
    
    if (seg >= 59) {
        min += 1;
        seg = 00;
        if (min >= 59) {
            hora += 1;
            min = 00;
            if (hora >= 23) {
                hora = 00;
            }
            
        }
    }
    else {
        seg +=1;
    }
    
    printf("%02d:%02d:%02d", hora, min, seg);
    
    
}