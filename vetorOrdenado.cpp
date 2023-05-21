#include "vetorOrdenado.h"

vetorOrdenado::vetorOrdenado(int n){
    this->palavras = (string*)malloc(sizeof(string) * n);
    this->info = (Item*)malloc(sizeof(Item) * n);
    this->qtdPalavras = 0;

    for(int i = 0; i < n; i++){
        this->info[i].setLetras(0);
        this->info[i].setVogais(0);
        this->info[i].setOcorrencias(0);
    }
}

int vetorOrdenado::getQtdPalavras(){
    return this->qtdPalavras;
}

int vetorOrdenado::qtdOcorrencias(string palavra){
    int ini = 0;
    int meio;
    int fim = this->qtdPalavras - 1;

    while(ini <= fim){
        meio = (ini + fim) / 2;
        if(this->palavras[meio] == palavra)
            return (this->info[meio].getOcorrencias());
        if(this->palavras[meio] > palavra)
            fim = meio - 1;
        if(this->palavras[meio] < palavra)
            ini = meio + 1;
    }
    
    return 0;
}

void vetorOrdenado::insereVetor(string key){
    int achou = 0;
    int meio = 0;
    int ini = 0;
    int fim = this->qtdPalavras - 1;

    // não há palavras salvas
    if(this->qtdPalavras == 0){
        this->palavras[0] = key;
        this->info[0].setLetras(key.length());
        this->info[0].setOcorrencias(1);
        this->info[0].setVogais(this->info->contaVogais(key));
        this->qtdPalavras = this->qtdPalavras + 1;
        return;
    }

    // busca binária
    while (ini <= fim){
        meio = (ini + fim) / 2;
        if(this->palavras[meio] == key){
            this->info[meio].setOcorrencias(this->info[meio].getOcorrencias() + 1);
            achou = 1;
            break;
        }
        if(this->palavras[meio] > key)
            fim = meio - 1;
        if(this->palavras[meio] < key)
            ini = meio + 1;
    }

    // não achou o elemento no vetor, armazena
    if (!achou){
        for(int i = this->qtdPalavras; i > meio; i--){
            this->palavras[i] = this->palavras[i - 1];
            this->info[i] = this->info[i - 1];
        }
        
        if(palavras[meio + 1] < key){
            palavras[meio] = palavras[meio + 1];
            info[meio] = info[meio + 1];
            meio = meio + 1;
        }

        this->palavras[meio] = key;
        this->info[meio].setLetras(key.length());
        this->info[meio].setOcorrencias(1);
        this->info[meio].setVogais(this->info[meio].contaVogais(key));
        this->qtdPalavras = this->qtdPalavras + 1;
    }
}

void vetorOrdenado::imprime(){
    for(int i = 0; i < this->qtdPalavras; i++){
        cout << this->palavras[i] << " " << this->info[i].getOcorrencias() << endl;
    }
}

vector<string> vetorOrdenado::palavraMaisFrequente(){
    int maior = -1;
    int total = 0;
    for(int i = 0; i < this->qtdPalavras; i++){
        if(i == 0){
            this->v.push_back(this->palavras[i]);
            total += 1;
        }

        else if(this->info[i].getOcorrencias() >= maior){
            if(this->info[i].getOcorrencias() > maior){
                maior = this->info[i].getOcorrencias();
                this->v.clear();
            }
            this->v.push_back(this->palavras[i]);
        }
    }
    return this->v;
}