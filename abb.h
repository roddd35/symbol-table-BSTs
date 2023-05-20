#pragma once
#include "item.h"
#include <string>
#include <iostream>

using namespace std;

class No {
    private:
        No* esq;
        No* dir;
        Item info;
        string palavra;
        int qtdPalavras;

    public:
        No();
        void imprime(No* raiz);
        int contaVogais(string palavra);
        No* insereABB(No* raiz, string palavra);
};
