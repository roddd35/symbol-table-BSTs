#pragma once

#include <iostream>
#include <string>

#include "item.h"

class redBlackNode {
    private:
        int n;
        char cor;   //'r', para vermelho, 'b' para preto
        Item info;
        string palavra;
        redBlackNode* esq;
        redBlackNode* dir;

    public:
        redBlackNode();
        int size(redBlackNode* raiz);
        int qtdOcorrencias(redBlackNode* raiz, string palavra);
        void imprime(redBlackNode* raiz);
        void flipColor(redBlackNode* raiz);
        bool ehVermelho(redBlackNode* no);
        redBlackNode* rotacionaDir(redBlackNode* raiz);
        redBlackNode* rotacionaEsq(redBlackNode* raiz);
        redBlackNode* insereRedBlack(redBlackNode* raiz, string palavra);
        vector<string> palavraMaisFrequente(redBlackNode* raiz, palavrasMaisFrequentes* p);
};