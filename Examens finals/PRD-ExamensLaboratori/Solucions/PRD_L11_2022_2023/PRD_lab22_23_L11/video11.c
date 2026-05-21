#include "video11.h"


void grupo11()
{
    /* COMPLETAR */
    t_video v;
    t_video_list *l;    
    int error, i;    
    
    l = init();

    if (l == NULL)
    {
        printf ("Error creando lista.\n");
    }
    else
    {
        mostrar_lista_videos(l);
        for (i = 0; i < 3; i++) 
        {
            v = leer_video();
            error = insertar_video_ordenado_asc(l, v);

            if (error == 0)
                printf("El vídeo no se ha añadido.\n");
            else
                mostrar_lista_videos(l);
        }

        free_lista_videos(l);
    }
}
/* Operaciones video */
t_video leer_video ()
{
    t_video v;
    int correcto = 0;           
    
    do {
        printf("\nIntroduce el id del video > 0: ");
        scanf("%d%*c", &v.id);
        printf("Introduce el titulo del video: ");
        fgets(v.titulo, MAX, stdin);
        if (strlen(v.titulo) > 0)
            v.titulo[strlen(v.titulo)-1] = '\0';
        printf("Introduce el numero de reproducciones > 0: ");
        scanf("%d%*c", &v.reproducciones);
                
        if (v.reproducciones > 0 && v.id > 0)
            correcto = 1;
        else
            printf("Datos incorrectos, vuelve a intentarlo\n");
        
    } while (!correcto);    
 
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
    int i;
    t_nodo *n;

    if (lista->size == 0) 
    {
        printf("La lista está vacía.\n");
    } 
    else 
    {
        n = lista->head;
        i = 0;
        while (i < lista->size) {
            if (n != NULL) {
                mostrar_video(n->v);
                n = n->next;
            }
            i++;
        }
    }
}

int insertar_video_ordenado_asc (t_video_list *lista, t_video v)
{     
    int insertado = 0, i;
    t_nodo *aux, *ant, *nuevo;
    
    nuevo = (t_nodo *)malloc(sizeof(t_nodo));
    if (nuevo == NULL)
        return insertado;
    else
    {
        nuevo->v = v;
        nuevo->next = NULL;
    }        
    
    if (lista->size == 0)
    {
        lista->head = nuevo;
        lista->size++;
        insertado = 1;
    }
    else
    {
        /* Hay que insertarlo por orden de lista */
        aux = lista->head;
        ant = lista->head;
        
        i=0;
        while (aux!=NULL && i<lista->size && !insertado)
        {
            /* Tengo que insertarlo donde está aux */
            if (aux->v.reproducciones > nuevo->v.reproducciones) {
                if (i == 0) {
                    nuevo->next = lista->head;
                    lista->head =  nuevo;
                } else {
                    ant->next = nuevo;
                    nuevo->next = aux;
                }
                lista->size++;
                insertado = 1;
            }
            else
            {
                ant = aux;
                aux = aux->next;
            }  
            
            i++;
        }  
        
        /* Va al final de la lista */
        if (!insertado)
        {                
            ant->next = nuevo; 
            lista->size++;
            insertado = 1;           
        }
    }                        
    
    return insertado;
}

