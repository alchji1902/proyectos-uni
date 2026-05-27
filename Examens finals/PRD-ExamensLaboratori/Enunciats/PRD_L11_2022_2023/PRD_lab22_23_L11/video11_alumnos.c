#include "video11.h"
#include <string.h>

void grupo11()
{
    t_video_list *list;
    
    list = init();
    
    if (list == NULL){
        printf("Error creando lista. \n");
    }
    
    mostrar_lista_videos(list);
    printf("\n");
    
    if (insertar_video_ordenado_asc(list, leer_video()) != 0){
        printf("El video no se ha insertado. \n");
    }
    printf("\n");
    mostrar_lista_videos(list);
    printf("\n");
    
    if (insertar_video_ordenado_asc(list, leer_video()) != 0){
        printf("El video no se ha insertado. \n");
    }
    printf("\n");
    mostrar_lista_videos(list);
    printf("\n");
    
    if (insertar_video_ordenado_asc(list, leer_video()) != 0){
        printf("El video no se ha insertado. \n");
    }
    printf("\n");
    mostrar_lista_videos(list);
    printf("\n");
}

/* Operaciones video */
t_video leer_video ()
{
    t_video v;
    int able = -1;
    
    do {
        printf("Introduce el id del video > 0: ");
        scanf("%d%*c", &v.id);
        
        printf("Introduce el titulo del vídeo: ");
        fgets(v.titulo, MAX, stdin);

        if (strlen(v.titulo) > 0 && v.titulo[strlen(v.titulo) - 1] == '\n') {
            v.titulo[strlen(v.titulo) - 1] = '\0';
        }
        
        printf("Introduce el número de reproducciones > 0: ");
        scanf("%d", &v.reproducciones);
        
        if (v.id <= 0 || v.reproducciones <= 0){
            printf("Datos incorrectos, vuelve a intentarlo.\n");
        }
        
        else{
            able = 1;
        }
        
        
    }while (able == -1);
	
    
    return v;
}

void mostrar_video (t_video v)
{
    printf("El vídeo %s con id %d tiene %d reproducciones.\n", v.titulo, v.id, v.reproducciones);
}

/* Operaciones lista de vídeos */
t_video_list *init ()
{    
    t_video_list *lista;
    
    lista = (t_video_list *)malloc(sizeof(t_video_list));
    if (lista != NULL)
    {
        lista->size = 0; 
        lista->head = NULL;
    }
    
    return lista;
}

void free_lista_videos (t_video_list *lista)
{
    t_nodo *tmp, *tmp2;
    
    tmp = lista->head;
    while (tmp !=NULL)
    {
        tmp2 = tmp;
        tmp = tmp->next;
        free(tmp2);        
    }
        
    free (lista);    
}

void mostrar_lista_videos (t_video_list *lista) 
{
    t_nodo *tmp;
    
    tmp = lista->head;
    
    if (lista->size == 0){
        printf("La lista esta vacia. \n");
        return;
    }
    
    while(tmp != NULL){
        printf("El vídeo %s con id %d tiene %d reproducciones. \n", tmp->v.titulo, tmp->v.id, tmp->v.reproducciones);
        tmp = tmp->next;
    }
}

int insertar_video_ordenado_asc (t_video_list *lista, t_video v)
{     
    int insertado = 0;
    t_nodo *tmp, *nuevo;
    
    nuevo = (t_nodo *)malloc(sizeof(t_nodo));
    
    if (nuevo == NULL){
        return (EXIT_FAILURE);
    }
    
    nuevo->v = v;
    
    if (lista->head == NULL) {
        lista->head = nuevo;
        lista->head->next = NULL;
        lista->size++;
        return (insertado);
    } 
    
    if (nuevo->v.reproducciones < lista->head->v.reproducciones) {
        nuevo->next = lista->head;
        lista->head = nuevo;
        lista->size++;
        return(insertado);
    }
    
    tmp = lista->head;
    
    while((tmp->next != NULL) && (tmp->next->v.reproducciones < nuevo->v.reproducciones)){
        tmp = tmp->next;
    }
    
    
    nuevo->next = tmp->next; 
    tmp->next = nuevo;
    
    return (insertado);
    
}