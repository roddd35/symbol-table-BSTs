#pragma once
#include "item.h"
#include <ctime>
#include <string>
#include <iostream>

using namespace std;

class treapNode {
    private:
        int prioridade;
        Item info;
        string palavra;
        treapNode* dir;
        treapNode* esq;

    public:
        void imprime(treapNode* raiz);
        treapNode();
        treapNode* insereTreap(treapNode* raiz, string palavra);
        treapNode* rotacionaEsq(treapNode* raiz);
        treapNode* rotacionaDir(treapNode* raiz);
};