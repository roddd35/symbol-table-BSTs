#include "item.h"

Item::Item(){
    
}

int Item::getVogais(){
    return this->vogaisSemRepeticao;
}

int Item::getLetras(){
    return this->qtdLetras;
}

int Item::getOcorrencias(){
    return this->qtdOcorrencias;
}

int Item::contaVogais(string palavra){
    int totalVogais = 0;
    int v[5];
    for(int i = 0; i < 5; i++)
        v[i] = 0;

    for(int i = 0; i < (int)palavra.length(); i++){
        if(palavra[i] == 'a' || palavra[i] == 'A')
            v[0] += 1;
        if(palavra[i] == 'e'|| palavra[i] == 'E')
            v[1] += 1;
        if(palavra[i] == 'i'|| palavra[i] == 'I')
            v[2] += 1;
        if(palavra[i] == 'o'|| palavra[i] == 'O')
            v[3] += 1;
        if(palavra[i] == 'u'|| palavra[i] == 'U')
            v[4] += 1;
    }

    for(int i = 0; i < 5; i++)
        if(v[i] == 1)
            totalVogais++;

    return totalVogais;
}

void Item::setVogais(int qtd){
    this->vogaisSemRepeticao = qtd;
}

void Item::setLetras(int qtd){
    this->qtdLetras = qtd;
}

void Item::setOcorrencias(int qtd){
    this->qtdOcorrencias = qtd;
}