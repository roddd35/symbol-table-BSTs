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
        int size(redBlackNode* raiz);
        redBlackNode();
        void imprime(redBlackNode* raiz);
        void flipColor(redBlackNode* raiz);
        bool ehVermelho(redBlackNode* no);
        redBlackNode* rotacionaDir(redBlackNode* raiz);
        redBlackNode* rotacionaEsq(redBlackNode* raiz);
        redBlackNode* insereRedBlack(redBlackNode* raiz, string palavra);
};