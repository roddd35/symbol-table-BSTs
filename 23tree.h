#pragma once
#include "item.h"

#include <iostream>
#include <string>

using namespace std;

class ttNode {
    private:
        bool twoNode;
        Item info1;
        Item info2;
        string palavra1;
        string palavra2;
        ttNode* p1;
        ttNode* p2;
        ttNode* p3;
    
    public:
        ttNode();
        int qtdOcorrencias(ttNode* raiz, string palavra);
        ttNode* insere23(ttNode* raiz, string palavra, bool* cresceu);
};