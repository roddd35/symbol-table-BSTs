#pragma once
#include "item.h"

#include <iostream>
#include <string>

using namespace std;

class A23 {
    private:
        bool twoNode;
        Item info1;
        Item info2;
        string palavra1;
        string palavra2;
        A23* p1;
        A23* p2;
        A23* p3;
    
    public:
        void inOrder(A23* raiz);
        int qtdOcorrencias(A23* raiz, string palavra);
        A23(string key);
        A23* insert(A23* raiz, string palavra, bool &cresceu);
        vector<string> palavraMaisFrequente(A23* raiz, palavrasMaisFrequentes* p);
};