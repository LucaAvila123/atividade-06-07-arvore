#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arvore{
    void* elemento;
    char* key;
    void (*deleteItem) (void*);
    Arv* direita;
    Arv* esquerda;
};

Arv* arv_criavazia (void){
    return NULL;
}

Arv* arv_cria (void* c, Arv* e, Arv* d, char* key, void (*DeleteFunction) (void* elemento)){
    Arv* tree = (Arv*) malloc (sizeof(Arv));
    tree -> elemento = c;
    tree -> esquerda = e;
    tree -> direita = d;
    tree -> key = strdup(key);
    tree -> deleteItem = DeleteFunction;
    return tree;
}

Arv* arv_libera (Arv* a){
    if(!arv_vazia (a)){
        arv_libera(a -> esquerda);
        arv_libera(a -> direita);
        tree -> deleteItem (tree -> elemento);
        free(a -> key);
        free(a);
    }
    return NULL;
}

int arv_vazia (Arv* a){
    return a==NULL;
}

int arv_pertence (Arv* a, void* c){
    if(arv_vazia(a)) return 0;
    else 
        return (a -> elemento == c) || 
                arv_pertence(a -> direita, c) ||
                arv_pertence(a -> esquerda, c);
}

//busca o nó escolhido
static Arv* retornaNo(Arv* a, void* c){
    Arv* aqui = a;
    if(!arv_vazia(a)){
        if(aqui -> elemento == c)
            return aqui;
        else{
            if(arv_pertence(aqui -> direita, c))
                aqui = retornaNo(aqui -> direita, c);
            
            if(arv_pertence(aqui -> esquerda, c))
                aqui = retornaNo(aqui -> esquerda, c);
            
            return aqui;  
        }
    }
    return NULL;
}

Arv* arv_pai (Arv* a, void* c){

    if(!arv_vazia(a)){
        Arv* pai = a;
        Arv* filhaDireita = a -> direita;
        Arv* filhaEsquerda = a -> esquerda;
        
        if(pai -> elemento == c) return NULL; // primeiro nó, sem pai
        else if (filhaDireita -> elemento == c) return pai;
        else if(filhaEsquerda -> elemento == c) return pai;
        else{
            if(arv_pertence(filhaDireita, c)){
                pai = arv_pai(filhaDireita, c);
            }
            if(arv_pertence(pai -> esquerda, c)){
                pai = arv_pai(pai -> esquerda, c);
            }

            return pai;
        }
    }
    return NULL;
        
}
