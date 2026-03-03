/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.145

void exercici1()
{
    /* Codi de l'enunciat 1.1 */
    int valor1, valor2;
    printf("Primer valor: ");
    scanf("%d", &valor1);
    printf("Segon valor: ");
    scanf("%d", &valor2);
    
    
    /* Mostrem 1 si valor1 >= valor2; 0 altrament*/
    
    printf("El resultat es: %d\n", valor1>=valor2);
}

void exercici2(){
    /* Codi de l'enunciat*/
    float angle_deg, angle_rad;
    
    printf("Introdueix angle en graus [0,360]: ");
    scanf("%f", &angle_deg);
    
    angle_rad = angle_deg * 2 * PI / 360;
    
    printf("L'angle en radians es: %f\n", angle_rad);

}

void exercici3(){
    /*Codi de l'enunciat*/
    
    float a, b, c, x1, x2;
    /*
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f", &c);
    */
    
    
    printf("Eq. de 2n grau (ax^2+bx+c=0): ");
    scanf("%fx^2+%fx+%f=0", &a, &b, &c);
    /*printf("%f %f %f",a,b,c);*/
    x1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
    x2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
    
    printf("x1 = %f\n", x1);
    printf("x2 = %f\n", x2);
    


}

void exercici4(){
    srand(time(NULL));
    int ocult = rand() % 100;
    int intent;
    
    do
    {
        printf("Descobreix el valor ocult: \n");
        scanf("%d", &intent);
        
        if (ocult < intent){
            printf("El valor ocult es menor....\n");
        }
        else if (ocult > intent){
            printf("El valor ocult es major....\n");
        }
        else{
            printf("Fantastic! L'has descobert!!\n");
        }
    
    }while (intent != ocult);

}

void exercici5(){
    int n, i;
    long res = 1;
    
    printf("Introdueix el valor de n>=0: ");
    scanf("%d", &n);
    for (i = n; i >= 2; i--){
        res *= i;
    }
    printf("%d ! = %ld\n", n, res);
}

void exercici6(){
    int ant1 = 0, ant2 = 1, actual, i;
    
    printf("%d, %d", ant1, ant2);
    
    for (i=3; i <= 30; i++){
        
        actual = ant1 + ant2;
        printf(", %d", actual);
        
        /*Actualitzarem variables ant1 i ant2*/
        
        ant1 = ant2;
        ant2 = actual; 
    }
}


void exercici8(){
    int valors[10] = {1,2,3,4,5,6,7,8,9,10};
    int i, aux;
    
    
    /*Mostrem vector original*/
    printf("Vector original: %d", valors[0]);
    for (i = 1; i < 10; i++){
        printf(",  %d", valors[i]);
    }
    for (i = 0; i < 5; i++){
        aux = valors[i];
        valors[i] = valors[10-1-i];
        valors[10-1-i] = aux;
        
    }
    
    
    /*Mostrem vector intvertit*/
    
    printf("\nVector invertit: %d", valors[0]);
    for (i = 1; i < 10; i++){
        printf(",  %d", valors[i]);
    }
}


void exercici9(){
    
    float matriu[3][3] = {1.0, 0.0, 0.0,
                          0.0, 1.0, 0.0, 
                          0.0, 0.0, 1.0};
    
    
    int i, j, simetrica = 1;
    
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (matriu[i][j] != matriu[j][i]){
                simetrica = 0;
            }
        }
    }
    if (simetrica){printf("Es simetrica \n");}
    else {printf("No es simetrica \n");}
    
    
}