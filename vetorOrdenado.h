#pragma once
#include "item.h"
#include <string>
#include <iostream>

using namespace std;

// template <class Key>
class vetorOrdenado {
    private:
        int qtdPalavras;
        Item* info;
        string* palavras;

    public:
        vetorOrdenado(int n);
        int getQtdPalavras();
        int qtdOcorrencias(string palavra);
        void imprime();
        void imprimeVector(int q);
        void insereVetor(string key);
};