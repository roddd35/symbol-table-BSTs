#pragma once
#include "item.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// template <class Key>
class vetorOrdenado {
    private:
        int qtdPalavras;
        vector<string> v;
        Item* info;
        string* palavras;

    public:
        vetorOrdenado(int n);
        int getQtdPalavras();
        int qtdOcorrencias(string palavra);
        void imprime();
        void insereVetor(string key);
        vector<string> palavraMaisFrequente();
};