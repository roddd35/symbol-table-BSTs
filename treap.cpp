#include "treap.h"

treapNode::treapNode(){
    
}

treapNode* treapNode::insereTreap(treapNode* raiz, string palavra){
    if(raiz == nullptr){
        raiz = (treapNode*)malloc(sizeof(treapNode));
        raiz->palavra = palavra;
        raiz->prioridade = rand()%100;
        raiz->esq = raiz->dir = nullptr;
        raiz->info.setLetras(palavra.length());
        raiz->info.setOcorrencias(1);
        raiz->info.setVogais(raiz->info.contaVogais(palavra));

        return raiz;
    }

    if(palavra == raiz->palavra){
        raiz->info.setOcorrencias(raiz->info.getOcorrencias() + 1);
    }

    else if(palavra < raiz->palavra){
        raiz->esq = raiz->insereTreap(raiz->esq, palavra);
        if(raiz->esq->prioridade > raiz->prioridade)
            raiz = raiz->rotacionaDir(raiz);
    }
    else{
        raiz->dir = raiz->insereTreap(raiz->dir, palavra);
        if(raiz->dir->prioridade > raiz->prioridade)
            raiz = raiz->rotacionaEsq(raiz);
    }
    return raiz;
}

treapNode* treapNode::rotacionaDir(treapNode* no){
    treapNode* x = no->esq;
    treapNode*  T2 = x->dir;

    x->dir = no;
    no->esq = T2;

    return x;
}

treapNode* treapNode::rotacionaEsq(treapNode* no){
    treapNode* y = no->dir;
    treapNode*  T2 = y->esq;

    y->esq = no;
    no->dir = T2;

    return y;
}

void treapNode::imprime(treapNode* raiz){
    if(raiz){
        imprime(raiz->esq);
        cout << raiz->palavra << ": " << raiz->info.getOcorrencias() << endl;
        imprime(raiz->dir);
    }
}

int treapNode::qtdOcorrencias(treapNode* raiz, string palavra){
    if(raiz == nullptr)
        return 0;
    if(raiz->palavra == palavra)
        return raiz->info.getOcorrencias();
    if(raiz->palavra < palavra)
        return qtdOcorrencias(raiz->dir, palavra);
    if(raiz->palavra > palavra)
        return qtdOcorrencias(raiz->esq, palavra);
    return 0;
}