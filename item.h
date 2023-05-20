#pragma once
#include <string>
#include <iostream>

using namespace std;

class Item {
    private:
        int qtdLetras;
        int qtdOcorrencias;
        int vogaisSemRepeticao;
        int qtdPalavras;

    public:
        Item();
        int getVogais();
        int getLetras();
        int getOcorrencias();
        int getQtdPalavras();
        int contaVogais(string palavra);
        void setVogais(int qtd);
        void setLetras(int qtd);
        void setOcorrencias(int qtd);
        void setQtdPalavras(int qtd);
};