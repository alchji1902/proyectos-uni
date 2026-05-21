#include "video11.h"

void grupo11()
{
	/* COMPLETAR */
}

/* Operaciones video */
t_video leer_video ()
{
    t_video v;
	
	/* COMPLETAR */   
 
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

void mostrar_lista_videos (t_video_list *lista) {
	
	/* COMPLETAR */
	
}

int insertar_video_ordenado_asc (t_video_list *lista, t_video v)
{     
    int insertado = 0;

	/* COMPLETAR */	
    
    return insertado;
}

