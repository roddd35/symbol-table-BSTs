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
        ~vetorOrdenado();
        int getQtdPalavras();
        void insereVetor(string key);
        void imprime(vetorOrdenado* dados);
        string* getPalavras();
};