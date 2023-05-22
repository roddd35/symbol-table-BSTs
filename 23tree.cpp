#include "23tree.h"

ttNode::ttNode(){

}

ttNode* ttNode::insere23(ttNode* raiz, string palavra, bool* cresceu){
    if(raiz == nullptr){
        raiz = new ttNode();
        raiz->palavra1 = palavra;
        raiz->palavra2 = nullptr;
        raiz->info1.setLetras(palavra.length());
        raiz->info1.setOcorrencias(1);
        raiz->info1.setVogais(raiz->info1.contaVogais(palavra));
        raiz->twoNode = false;
        raiz->p1 = nullptr;
        raiz->p2 = nullptr;
        raiz->p3 = nullptr;
        *cresceu = true;

        return raiz;
    }
    if(raiz->p1 != nullptr){ //raiz não é folha
        if(raiz->palavra1 > palavra){
            ttNode* p = insere23(raiz->p1, palavra, cresceu);
            if(*cresceu){    // split
                if(raiz->twoNode){
                    raiz->palavra2 = raiz->palavra1;
                    raiz->info2 = raiz->info1;
                    raiz->p3 = raiz->p2;
                    raiz->palavra1 = p->palavra1;
                    raiz->info1 = p->info1;
                    raiz->p2 = p->p2;
                    *cresceu = false;
                    raiz->twoNode = false;
                    return raiz;
                }
                else{
                    ttNode* novo = new ttNode();
                    novo->palavra1 = raiz->palavra2;
                    novo->info1 = raiz->info2;
                    novo->p2 = raiz->p3;
                    novo->p1 = raiz->p2;
                    ttNode* nRaiz = new ttNode();
                    nRaiz->palavra1 = raiz->palavra1;
                    nRaiz->info1 = raiz->info1;
                    nRaiz->p2 = novo;
                    nRaiz->p1 = raiz;
                    raiz->palavra1 = p->palavra1;
                    raiz->info1 = p->info1;
                    raiz->palavra2 = nullptr;
                    raiz->p3 = nullptr;
                    raiz->p2 = p->p2;
                    novo->twoNode = raiz->twoNode = nRaiz->twoNode = true;
                    *cresceu = true;
                    delete(p);
                    return nRaiz;
                }
            }
            else{
                raiz->p1 = p;
                *cresceu = false;
                return raiz;
            }
        }
        else if(raiz->twoNode || raiz->palavra2 > palavra){
            ttNode* p  = insere23(raiz->p2, palavra, cresceu);
            // tem que fazer o resto aqui? if cresceu, else, etc.
        }
        else{
            //insere p3
        }
    }
    else{
        if(raiz->twoNode){
            if(raiz->palavra1 > palavra){
                raiz->palavra2 = raiz->palavra1;
                raiz->info2 = raiz->info1;
                raiz->palavra1 = palavra;
                raiz->info1.setLetras(palavra.length());
                raiz->info1.setOcorrencias(1);
                raiz->info1.setVogais(raiz->info1.contaVogais(palavra));
                raiz->twoNode = false;
                *cresceu = false;

                return raiz;
            }
            else{
                raiz->palavra2 = palavra;
                raiz->info2.setLetras(palavra.length());
                raiz->info2.setOcorrencias(1);
                raiz->info2.setVogais(raiz->info2.contaVogais(palavra));
                raiz->twoNode = false;
                *cresceu = false;

                return raiz;
            }
        }
        else{   // três  nó
            if(palavra < raiz->palavra1){
                ttNode* novo = new ttNode();
                ttNode* nRaiz = new ttNode();
                raiz->twoNode = nRaiz->twoNode = novo->twoNode = true;
                *cresceu = true;
                return nRaiz;
            }
            else if(palavra < raiz->palavra2){

            }
            else{   // palavra > raiz->palavra2

            }
        }
    }
}

int ttNode::qtdOcorrencias(ttNode* raiz, string palavra){
    if(raiz == nullptr)
        return 0;
    if(raiz->twoNode){
        if(raiz->palavra1 == palavra)
            return this->info1.getOcorrencias();
        else if(raiz->palavra1 < palavra)
            return qtdOcorrencias(raiz->p3, palavra);
        else
            return qtdOcorrencias(raiz->p1, palavra);
    }
    else{
        if(raiz->palavra1 == palavra || raiz->palavra2 == palavra){
            if(raiz->palavra1 == palavra)
                return this->info1.getOcorrencias();
            else
                return this->info2.getOcorrencias();
        }
        if(this->palavra1 < palavra)
            return qtdOcorrencias(raiz->p1, palavra);
        if(this->palavra2 < palavra)
            return qtdOcorrencias(raiz->p2, palavra);
        return qtdOcorrencias(raiz->p3, palavra);
    }
}