#include "abb.h"

No::No(){

}

void No::imprime(No* raiz){
    if(raiz == nullptr)
        return;
    this->imprime(raiz->esq);
    if(raiz->info.getOcorrencias() >= 1)
        cout << raiz->palavra << ":" << " " << raiz->info.getOcorrencias() << endl;
    this->imprime(raiz->dir);
}

No* No::insereABB(No* raiz, string palavra){
    if(raiz == nullptr){
        raiz = (No*)malloc(sizeof(No));
        raiz->palavra = palavra;
        raiz->dir = raiz->esq = nullptr;
        raiz->info.setLetras(palavra.length());
        raiz->info.setOcorrencias(1);
        raiz->info.setVogais(raiz->info.contaVogais(palavra));
        return raiz;
    }

    if(palavra == raiz->palavra)
        raiz->info.setOcorrencias(raiz->info.getOcorrencias() + 1);
    else if(palavra < raiz->palavra)
        raiz->esq = raiz->insereABB(raiz->esq, palavra);
    else if(palavra > raiz->palavra)
        raiz->dir = raiz->insereABB(raiz->dir, palavra);

    return raiz;
}
