#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct palavrasMaisFrequentes {
    vector<string> palavras;
    int frequencia = 0;
};
class Item {
    private:
        int qtdLetras;
        int qtdOcorrencias;
        int vogaisSemRepeticao;

    public:
        Item();
        int getVogais();
        int getLetras();
        int getOcorrencias();
        int contaVogais(string palavra);
        void setVogais(int qtd);
        void setLetras(int qtd);
        void setOcorrencias(int qtd);
};