#pragma once
#include "item.h"
#include <ctime>
#include <string>
#include <iostream>

using namespace std;

void imprimeVector(int q);
typedef struct {
    vector<string> F;
    vector<string> L;
    vector<string> SR;
    vector<string> VD;
} dados;

class treapNode {
    private:
        int prioridade;
        Item info;
        string palavra;
        treapNode* dir;
        treapNode* esq;

    public:
        treapNode();
        void imprime(treapNode* raiz);
        int qtdOcorrencias(treapNode* raiz, string palavra);
        treapNode* rotacionaEsq(treapNode* raiz);
        treapNode* rotacionaDir(treapNode* raiz);
        treapNode* insereTreap(treapNode* raiz, string palavra);
};