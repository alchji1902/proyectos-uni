/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef NIF_H
#define NIF_H

typedef struct
{
    int numero;
    char letra;
    
}t_nif;

t_nif generar_nif_aleatorio();
void mostrar_nif(t_nif nif);
int comparar_nifs(t_nif nif1, t_nif nif2);

#endif /* NIF_H */

