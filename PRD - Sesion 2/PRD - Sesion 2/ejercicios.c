/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "ejercicios.h"
#include <string.h>

void sesion2_ej1()
{
    /* Completar con el código del ejercicio 1 */
    int h, m, s, nh, nm, ns;
    printf("Introduce una hora en formato hh:mm:ss: ");
    scanf("%d:%d:%d%*c", &h, &m, &s);
    
    s++;
    
    ns = s % 60;
    m = m + s / 60;
    nm = m % 60;
    h = h + m/60;
    nh = h % 24;
    
    printf("%02d:%02d:%02d", nh, nm, ns);
    
}


void sesion2_ej2() {
    char caracter;
    
    printf("Introduzca un caracter: ");
    scanf(" %c", &caracter); // He añadido un espacio antes de %c por si hay un salto de línea previo

    // 1. ¿Es una letra?
    if ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z')) {
        printf("Es una letra\n");
    } else {
        printf("No es una letra\n");
    }

    // 2. ¿Es una vocal?
    if (caracter == 'A' || caracter == 'E' || caracter == 'I' || caracter == 'O' || caracter == 'U' ||
        caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u') {
        printf("Es una vocal\n");
    } else {
        printf("No es una vocal\n");
    }

    // 3. ¿Es una consonante? 
    if (((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z')) && 
        !(caracter == 'A' || caracter == 'E' || caracter == 'I' || caracter == 'O' || caracter == 'U' ||
          caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u')) {
        printf("Es una consonante\n");
    } else {
        printf("No es una consonante\n");
    }

    // 4. ¿Es mayúscula?
    if (caracter >= 'A' && caracter <= 'Z') {
        printf("Es una mayuscula\n");
    } else {
        printf("No es una mayuscula\n");
    }

    // 5. ¿Es minúscula?
    if (caracter >= 'a' && caracter <= 'z') {
        printf("Es una minuscula\n");
    } else {
        printf("No es una minuscula\n");
    }

    // 6. ¿Es un dígito?
    if (caracter >= '0' && caracter <= '9') {
        printf("Es un digito\n");
    } else {
        printf("No es un digito\n");
    }

    // 7. Capitalización invertida (Solo si es letra)
    if (caracter >= 'A' && caracter <= 'Z') {
        printf("El caracter con la capitalizacion invertida es %c\n", caracter + 32);
    } else if (caracter >= 'a' && caracter <= 'z') {
        printf("El caracter con la capitalizacion invertida es %c\n", caracter - 32);
    }
    }


void sesion2_ej3()
{
    /* Completar con el código del ejercicio 3 */
    float nota;
    
    printf("Introduzca su nota de PRD (numero entre 0 y 10): ");
    scanf("%f", &nota);
    if (nota >= 9.0) {printf("Tiene un sobresaliente :-))");}
    else if (nota >= 7.0){printf("Tiene un notable :-))");}
    else if (nota >= 5.0) {printf("Tiene un aprobado :-))");}
    else {printf("Ha suspendido; tiene que matricularse de PRD de nuevo :-(");}
    
    
}


void sesion2_ej4()
{
    /* Completar con el código del ejercicio 4 */
    /* int i, k;
    k = 5;
    for (i=0;i<3;i++){
        k=k+10;
        printf("%d %d\n", i, k);
        
    }
    printf("%d %d\n", i, k); */
    
    /* int i, k;

    i = 0;
    k = 5;

    while (i < 3) {
        k = k + 10;
        printf("%d %d\n", i, k);
        i = i + 1;
    }

    printf("%d %d\n", i, k); */
    
    int i, k;

    i = 0;
    k = 5;

    do {
        k = k + 10;
        printf("%d %d\n", i, k);
        i = i + 1;
    } while (i < 3);

    printf("%d %d\n", i, k);
}


void sesion2_ej5a()
{
    /* Completar con el código del ejercicio 5.a */
    
    int valores[10], i;
    
    int suma = 0;
    
    printf("Introduzca una secuencia de 10 numeros: \n");

    for (i = 0; i < 10; i++) {
        scanf("%d", &valores[i]);
    }
    
    for (i = 0; i < 10; i++) {
        suma = suma + valores[i];
    }
    
    printf("Suma: %d", suma);
    
    
}


void sesion2_ej5b()
{
    /* Completar con el código del ejercicio 5.b */
    printf("Introduzca una secuencia de 10 numeros naturales: \n");
    
    int num;
    int suma = 0;

  
    scanf("%d", &num);

    while (num != -1) {
        suma = suma + num;

        scanf("%d", &num);
    }
    
    
    printf("Suma: %d", suma);
    
}


void sesion2_ej5c()
{
    /* Completar con el código del ejercicio 5.c */
    printf("Introduzca una secuencia de 10 numeros naturales: \n");
    
    int num;
    int suma = 0;

  
    scanf("%d", &num);
    while (num == -1){
        scanf("%d", &num);
    }

    do {
        suma = suma + num;

        scanf("%d", &num);
    }while (num != -1);
    
    
    printf("Suma: %d", suma);
}


void sesion2_ej6a()
{
    /* Completar con el código del ejercicio 6.a */
    int i;
    int m;
    unsigned long long factorial = 1;
    
    
    
    printf("Introduce un numero natural: ");
    
    scanf("%d", &m);
    
    for (i = 1; i <= m; i++){
        factorial = factorial * i;
        
    }
    printf("%d! = %llu", m, factorial);
    
    
    
}


void sesion2_ej6b()
{
    /* Completar con el código del ejercicio 6.b */
    
    int i, n;
    unsigned long long factorial = 1;
    double nume = 1.0;
    
    
    printf("Introduzca el valor de n: ");
    
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++){
        
        factorial = factorial * i;
        
        nume = nume + 1.0 / factorial;
        
        
    }
    printf("Numero e = %.15f", nume);
    
    
    
}

void sesion2_ej7()
{
    /* Completar con el código del ejercicio opcional 7 */
    
    
    char car;
    
    int i = 0;
    int num_car;
    
    int count = 0;
    
    char frase[100];
    
    
    
    printf("Introduzca una frase acabada en punto: ");
    
    
    do {
        scanf("%c", &car);
            
        if (((car == ' ') || (car == '.')) && (frase[i-1] != ' ') && (i > 0)) {count += 1;}
        
        frase[i] = car;
        i++;
       
    }while (car != '.');
    
    frase[i] = '\0';
    
    printf("Numero de palabras: %d\n", count);
    
    printf("La frase es: %s", frase); 
    
    
    
}


void sesion2_ej8()
{
    /* Completar con el código del ejercicio opcional 8 */
    
    double real;
    
    unsigned int n;
    
    double res = 1;
    
    int i;
    
    printf("Introduzca el valor de x (real): ");
    scanf("%lf", &real);
    
    
    
    printf("Introduzca el valor de n (natural): ");
    scanf("%d", &n);
    
    
    
    /*Calculo de la potencia*/
    
    
    for (i = 1; i <= n; i++) {
        
        res = res * real;
        
               
        
    }
    
    
    printf("El resultado de %lf elevado a %d es: %.2lf", real, n, res);
    
    
    
    
    
    
    
    
    
    
    
    
}