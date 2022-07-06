#include "arvore.h"
#include "aluno.h"
#include <stdio.h>

void ArvImprime(Arv* a);

int main(){

    tAluno* maria = inicializaAluno("Maria", 123);
    tAluno* joao = inicializaAluno("Joao", 234);
    tAluno* cleber = inicializaAluno("Cleber", 345);
    tAluno* patricia = inicializaAluno("Patricia", 000); //será o nó inicial

    Arv* sad = arv_criavazia();
    Arv* sae = arv_criavazia();

    Arv* arvoreAlunos = arv_cria(patricia, sae, sad, "Patricia", libera);
    return 0;
}