#include "23tree.h"

A23::A23(string palavra)
{
    this->palavra1 = palavra;
    this->palavra2 = " ";
    this->info1.setLetras(palavra1.length());
    this->info1.setOcorrencias(1);
    this->info1.setVogais(this->info1.contaVogais(palavra1));
    this->p1 = this->p2 = this->p3 = nullptr;
    this->twoNode = true;
}

A23* A23::insert(A23* raiz, string palavra, bool &cresceu){
    if(raiz == nullptr){
        raiz = new A23(palavra);
        cresceu = true;
        return raiz;
    }
    else if(palavra == raiz->palavra1 || palavra == raiz->palavra2){
        if(palavra == raiz->palavra1)
            raiz->info1.setOcorrencias(raiz->info1.getOcorrencias() + 1);
        if(palavra == raiz->palavra2)
            raiz->info2.setOcorrencias(raiz->info2.getOcorrencias() + 1);
        return raiz;
    }

    else if(raiz->p1 != nullptr){
        if(palavra < raiz->palavra1){
            A23* aux = insert(raiz->p1,palavra,cresceu);
            if(cresceu){
                if(raiz->twoNode){
                    raiz->palavra2 = raiz->palavra1;
                    raiz->info2 = raiz->info1;
                    raiz->palavra1 = aux->palavra1;
                    raiz->info1 = aux->info1;
                    raiz->p3 = raiz->p2;
                    raiz->p2 = aux->p2;
                    raiz->p1 = aux->p1;
                    cresceu = false;
                    raiz->twoNode = false;
                    return raiz;
                }
                else{
                    A23* node = new A23(palavra);
                    node->palavra1 = raiz->palavra2;
                    node->info1 = raiz->info2;
                    node->p2 = raiz->p3;
                    node->p1 = raiz->p2;
                    A23* novaRaiz = new A23(palavra);
                    novaRaiz->palavra1 = raiz->palavra1;
                    novaRaiz->info1 = raiz->info1;
                    novaRaiz->p2 = node;
                    novaRaiz->p1 = raiz;
                    raiz->palavra1 = aux->palavra1;
                    raiz->info1 = aux->info1;
                    raiz->palavra2 = " ";
                    raiz->info2.setLetras(0);
                    raiz->info2.setOcorrencias(0);
                    raiz->info2.setVogais(0);
                    raiz->p3 = nullptr;
                    raiz->p2 = aux->p2;
                    raiz->p1 = aux->p1;
                    node->twoNode = raiz->twoNode = novaRaiz->twoNode = true;
                    cresceu = true;
                    return novaRaiz;
                }
            }
            else{
                raiz->p1 = aux;
                cresceu = false;
                return raiz;
            }
        }
        else if(raiz->twoNode || palavra < raiz->palavra2){
            A23* aux = insert(raiz->p2, palavra, cresceu);
            if(cresceu){
                if(raiz->twoNode){
                    raiz->palavra2 = aux->palavra1;
                    raiz->info2 = aux->info1;
                    raiz->p2 = aux->p1;
                    raiz->p3 = aux->p2;
                    cresceu = false;
                    raiz->twoNode = false;
                    return raiz;
                }
                else{
                    A23* node = new A23(palavra);
                    node->palavra1 = raiz->palavra2;
                    node->info1 = raiz->info2;
                    node->p2 = raiz->p3;
                    node->p1 = aux->p2;
                    A23* novaRaiz = new A23(palavra);
                    novaRaiz->palavra1 = aux->palavra1;
                    novaRaiz->info1 = aux->info1;
                    novaRaiz->p2 = node;
                    novaRaiz->p1 = raiz;
                    raiz->palavra2 = " ";
                    raiz->info2.setLetras(0);
                    raiz->info2.setOcorrencias(0);
                    raiz->info2.setVogais(0);
                    raiz->p2 = aux->p1;
                    raiz->p3 = nullptr;
                    node->twoNode = raiz->twoNode = novaRaiz->twoNode = true;
                    cresceu = true;
                    return novaRaiz;
                }
            }
            else{
                raiz->p2 = aux;
                cresceu = false;
                return raiz;
            }
        }
        else
        {
            A23* aux = insert(raiz->p3, palavra, cresceu);
            if(cresceu){
                if(raiz->twoNode){
                    raiz->palavra2 = aux->palavra1;
                    raiz->info2 = aux->info1;
                    raiz->p2 = aux->p1;
                    raiz->p3 = aux->p2;
                    cresceu = false;
                    raiz->twoNode = false;
                    return raiz;
                }
                else{
                    A23* novaRaiz = new A23(palavra);
                    novaRaiz->palavra1 = raiz->palavra2;
                    novaRaiz->info1 = raiz->info2;
                    novaRaiz->p2 = aux;
                    novaRaiz->p1 = raiz;
                    raiz->palavra2 = " ";
                    raiz->p3 = nullptr;
                    raiz->twoNode = novaRaiz->twoNode = true;
                    return novaRaiz;
                }
            }
            else{
                raiz->p3 = aux;
                cresceu = false;
                return raiz;
            }
        }
    }
    else{
        if(raiz->twoNode){
            if(palavra < raiz->palavra1){
                raiz->palavra2 = raiz->palavra1;
                raiz->info2 = raiz->info1;
                raiz->palavra1 = palavra;
                raiz->twoNode = false;
                cresceu = false;
                return raiz;
            }
            else{
                raiz->palavra2 = palavra;
                raiz->twoNode = false;
                cresceu = false;
                return raiz;
            }
        }
        else{
            if(palavra < raiz->palavra1){
                A23* node = new A23(palavra);
                A23* novaRaiz = new A23(raiz->palavra1);
                novaRaiz->p1 = node;
                novaRaiz->p2 = raiz;
                raiz->palavra1 = raiz->palavra2;
                raiz->info1 = raiz->info2;
                raiz->palavra2 = " ";
                raiz->info2.setLetras(0);
                raiz->info2.setOcorrencias(0);
                raiz->info2.setVogais(0);
                raiz->twoNode = true;
                cresceu = true;
                return novaRaiz;
            }
            else if(palavra < raiz->palavra2){
                A23* node = new A23(raiz->palavra2);
                A23* novaRaiz = new A23(palavra);
                novaRaiz->p2 = node;
                novaRaiz->p1 = raiz;
                raiz->palavra2 = " ";
                raiz->twoNode = true;
                cresceu = true;
                return novaRaiz;
            }
            else{
                A23* node = new A23(palavra);
                A23* novaRaiz = new A23(raiz->palavra2);
                novaRaiz->p2 = node;
                novaRaiz->p1 = raiz;
                raiz->palavra2 = " ";
                raiz->twoNode = true;
                cresceu = true;
                return novaRaiz;
            }
        }
    }
    return raiz;
}

int A23::qtdOcorrencias(A23* raiz, string palavra){
    if(raiz == nullptr)
        return 0;
    if(raiz->twoNode){
        if(raiz->palavra1 == palavra)
            return raiz->info1.getOcorrencias();
        else if(raiz->palavra1 < palavra)
            return qtdOcorrencias(raiz->p2, palavra);
        else
            return qtdOcorrencias(raiz->p1, palavra);
    }
    else{
        if(raiz->palavra1 == palavra || raiz->palavra2 == palavra){
            if(raiz->palavra1 == palavra)
                return raiz->info1.getOcorrencias();
            else
                return raiz->info2.getOcorrencias();
        }
        if(palavra < raiz->palavra1)
            return qtdOcorrencias(raiz->p1, palavra);
        if(palavra < raiz->palavra2) 
            return qtdOcorrencias(raiz->p2, palavra);
        return qtdOcorrencias(raiz->p3, palavra);
    }
}

void A23::inOrder(A23* raiz){
    if(raiz == nullptr)
        return;
    if(!raiz->twoNode){
        inOrder(raiz->p1);
        cout << raiz->palavra1 << raiz->info1.getOcorrencias() << endl << raiz->palavra2  << raiz->info2.getOcorrencias() << endl;
        inOrder(raiz->p2);
        cout << raiz->palavra1 << raiz->info1.getOcorrencias() << endl << raiz->palavra2 << raiz->info2.getOcorrencias() << endl;
        inOrder(raiz->p3);
    }
    if(raiz->twoNode){
        inOrder(raiz->p1);
        cout << raiz->palavra1 << raiz->info1.getOcorrencias() << endl;
        inOrder(raiz->p2);
    }
}

vector<string> A23::palavraMaisFrequente(A23* raiz, palavrasMaisFrequentes* p){
    if(raiz->p1 != nullptr)
        palavraMaisFrequente(raiz->p1, p);
    if(raiz->info1.getOcorrencias() >= p->frequencia || raiz->info2.getOcorrencias() >= p->frequencia){
        if(raiz->info1.getOcorrencias() > p->frequencia){
            p->palavras.clear();
            p->frequencia = raiz->info1.getOcorrencias();
            p->palavras.push_back(raiz->palavra1);
        }
        if(raiz->info2.getOcorrencias() > p->frequencia){
            p->palavras.clear();
            p->frequencia = raiz->info2.getOcorrencias();
            p->palavras.push_back(raiz->palavra2);
        }
    }
    if(raiz->p2 != nullptr)
        palavraMaisFrequente(raiz->p2, p);
    if(raiz->p3 != nullptr)
        palavraMaisFrequente(raiz->p3, p);
    return p->palavras;
}