#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct pessoa{
    int id;
    char nome[20];
};
struct lista{
    struct pessoa info;
    struct lista *next;
};

void insert (struct lista **l, struct pessoa p){
    struct lista *aux;
    if (*l == NULL){
        *l = (struct lista*) malloc (sizeof (struct lista));
        (*l)->info.id = p.id;
        strcpy((*l)->info.nome, p.nome);
        (*l)->next = NULL;
        return;
    }
    aux = (struct lista*) malloc (sizeof (struct lista));
    aux->info.id = p.id;
    strcpy (aux->info.nome, p.nome);
    aux->next = *l;
    *l = aux;
}
void lista (struct lista *l){
    struct lista *aux;
    for (aux = l; aux != NULL; aux = aux->next){
	    printf ("%d, ", aux->info.id);
	    printf ("%s\n", aux->info.nome);
    }
}
void busca(struct lista *l, char *nome){
    struct lista *aux;
    for (aux = l; aux != NULL; aux = aux->next){
        if (strcmp (aux->info.nome, nome) == 0){
            printf ("\n%s encontrado.\n", nome);
            return;
        }
        printf("\n%s nao encontrado\n", nome);
    }
}
void tira (struct lista **l, int id){
    struct lista *aux, *aux2;
    for(aux = *l, aux2 = (*l)->next; aux2 != NULL; aux = aux->next, aux2 = aux2->next){
        if (aux2->info.id == id){
            aux->next = aux2->next;
            free(aux2);
        }
    }
}
int main(){
    struct lista *ML = NULL;
    struct pessoa p[3];
    p[0].id = 10;
    p[1].id = 20;
    p[2].id = 30;
    strcpy (p[0].nome, "bom dia");
    strcpy (p[1].nome, "boa tarde");
    strcpy (p[2].nome, "boa noite");


    insert(&ML, p[0]);
    printf("\n%s inserido!", p[0].nome);

    insert(&ML, p[1]);
    printf("\n%s inserido!", p[1].nome);

    insert(&ML, p[2]);
    printf("\n%s inserido!", p[2].nome);

    tira(&ML, 10);
    printf("\n%s excluido!", p[1].nome);

    busca (ML, "boa noite");
    printf("\n");

    lista(ML);
    return 0;
}