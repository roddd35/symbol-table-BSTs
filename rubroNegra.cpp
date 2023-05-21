#include "rubroNegra.h"

int redBlackNode::size(redBlackNode* raiz){
    if(raiz == nullptr)
        return 0;
    return raiz->n;
}

int redBlackNode::qtdOcorrencias(redBlackNode* raiz, string palavra){
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

bool redBlackNode::ehVermelho(redBlackNode* no){
    if(no == nullptr)
        return false;
    return (no->cor == 'r');
}

void redBlackNode::flipColor(redBlackNode* raiz){
    raiz->cor = 'r';
    raiz->esq->cor = 'b';
    raiz->dir->cor = 'b';
}

void redBlackNode::imprime(redBlackNode* raiz){
    if(raiz){
        imprime(raiz->esq);
        cout << raiz->palavra << ": " << raiz->info.getOcorrencias() << endl;
        imprime(raiz->dir);
    }
}

redBlackNode::redBlackNode(){

}

redBlackNode* redBlackNode::rotacionaDir(redBlackNode* raiz){
    redBlackNode* x = raiz->esq;
    raiz->esq = x->dir;
    x->dir = raiz;
    x->cor = raiz->cor;
    raiz->cor = 'r';
    x->n = raiz->n;
    raiz->n = 1 + size(raiz->esq) + size(raiz->dir);

    return x;
}

redBlackNode* redBlackNode::rotacionaEsq(redBlackNode* raiz){
    redBlackNode* x = raiz->dir;
    raiz->dir = x->esq;
    x->esq = raiz;
    x->cor = raiz->cor;
    raiz->cor = 'r';
    x->n = raiz->n;
    raiz->n = 1 + size(raiz->esq) + size(raiz->dir);

    return x;
}

redBlackNode* redBlackNode::insereRedBlack(redBlackNode* raiz, string palavra){
    if(raiz == nullptr){
        raiz = (redBlackNode*)malloc(sizeof(redBlackNode));
        raiz->palavra = palavra;
        raiz->n = 1;    // talvez seja 1
        raiz->esq = raiz->dir = nullptr;
        raiz->info.setLetras(palavra.length());
        raiz->info.setOcorrencias(1);
        raiz->info.setVogais(raiz->info.contaVogais(palavra));

        return raiz;
    }

    if(palavra < raiz->palavra) 
        raiz->esq = insereRedBlack(raiz->esq, palavra);
    else if(palavra > raiz->palavra)
        raiz->dir = insereRedBlack(raiz->dir, palavra);
    else
        raiz->info.setOcorrencias(raiz->info.getOcorrencias() + 1);
    if(ehVermelho(raiz->dir) && !ehVermelho(raiz->esq))
        raiz = rotacionaEsq(raiz);
    if(ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq))
        raiz = rotacionaDir(raiz);
    if(ehVermelho(raiz->esq) && ehVermelho(raiz->dir))
        flipColor(raiz);
    raiz->n = size(raiz->esq) + size(raiz->dir) + 1;

    return raiz;
}  