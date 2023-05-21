#include "abb.h"
#include "treap.h"
#include "rubroNegra.h"
#include "vetorOrdenado.h"
#include <iostream>
#include <cstring>
#define MAX 256

using namespace std;

void imprimeSep();
void imprimeVector(int q, vector<string> v);
void imprime(int estrutura, vetorOrdenado* vector, No* noABB, treapNode* noTreap, redBlackNode* noRubroNegra);
void consulta(int q, int estrutura, vetorOrdenado* v, No* noABB, treapNode* noTreap, redBlackNode* noRubroNegra, vector<string> F, vector<string> L, vector<string> SR, vector<string> VD);

int main(){
    int n;
    int nomeEstrutura;
    int qtdConsultas;
    int q;
    int total = 0;
    char nomeArquivo[MAX];
    char* linha = nullptr;
    char* palavra = nullptr;
    FILE* arquivo;
    size_t read;
    size_t len = 0;

    // VECTORS PARA CONSULTAS
    vector<string> F;
    vector<string> L;
    vector<string> SR;
    vector<string> VD;

    //INÍCIO DO PROGRAMA
    cout << "-*- Bem Vinde à tabela de símbolos -*-" << endl;
    cout << "1. Vetor dinâmico ordenado" << endl << "2. Árvore de Busca Binária" << endl << "3. Treaps" << endl << "4. Árvore 2-3" << endl << "5. Árvore rubro-negra" << endl;
    cout << "Informe qual estrutura você deseja testar (número): ";
    cin >> nomeEstrutura;
    
    // exemplo: 39
    // hamlet: 33287
    // mobydick: 209329
    imprimeSep();

    cout << "Digite o número de palavras no texto: ";
    cin >> n;

    // leitura do arquivo e palavra a palavra
    cout << "Digite o nome do arquivo de leitura: ";
    cin >> nomeArquivo;

    imprimeSep();

    //Instanciar Objetos
    No* noABB = new No();
    treapNode* noTreap = new treapNode(); 
    vetorOrdenado* vector = new vetorOrdenado(n);
    redBlackNode* noRubroNegra = new redBlackNode();

    arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL)
        return 0;
    
    while((read = getline(&linha, &len, arquivo)) != (long unsigned int)-1){
        palavra = strtok(linha, "  ,`’‘’.-—_?![](){}@#$%&*+=|;/><1234567890:\n");
        while(palavra != NULL){
            if(*palavra != '\n' && *palavra != '\0'){
                // PRE PROCESSAMENTO DE (L)
                if(total == 0){
                    L.push_back(palavra);
                    total += 1;
                }
                else if(strlen(palavra) > L[0].length()){
                    L.clear();
                    L.push_back(palavra);
                }
                else if(strlen(palavra) == L[0].length())
                    L.push_back(palavra);

                if(nomeEstrutura == 1)
                    vector->insereVetor(palavra);
                else if(nomeEstrutura == 2)
                    noABB = noABB->insereABB(noABB, palavra);
                else if(nomeEstrutura == 3)
                    noTreap = noTreap->insereTreap(noTreap, palavra);
                else if(nomeEstrutura == 5)
                    noRubroNegra = noRubroNegra->insereRedBlack(noRubroNegra, palavra);
                else{
                    cout << "Estrutura não encontrada!";
                    return 0;
                }
            }
            palavra = strtok(NULL, "  ,`’‘’.-—_?![](){}@#$%&*+=|;/><1234567890:\n");
        }
    }
    // imprime(nomeEstrutura, vector, noABB, noTreap, noRubroNegra);

    // consultas
    cout << "Digite a quantidade de consultas: ";
    cin >> qtdConsultas;
    imprimeSep();
    for(int i = 0; i < qtdConsultas; i++){
        cout << "1. Palavras mais frequentes (F)" << endl << "2. Ocorrências de uma palavra (O(palavra))" << endl << "3. Palavras mais longas (L)" << endl << "4. Maiores palavras sem repetição de letras (SR)" << endl << "5. Menores palavras com mais vogais sem repetição (VD)" << endl;
        cout << "Por favor, selecione uma consulta: ";
        cin >> q;
        consulta(q, nomeEstrutura, vector, noABB, noTreap, noRubroNegra, F, L, SR, VD);
        imprimeSep();
    }
    
    fclose(arquivo);

    return 0;
}

void imprimeSep(){
    cout << endl << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl << endl;
}

void imprime(int estrutura, vetorOrdenado* vector, No* noABB, treapNode* noTreap, redBlackNode* noRubroNegra){
    if(estrutura == 1) 
        vector->imprime();
    else if(estrutura == 2)
        noABB->imprime(noABB);
    else if(estrutura == 3)
        noTreap->imprime(noTreap);
    else if(estrutura == 5)
        noRubroNegra->imprime(noRubroNegra);
}

void consulta(int q, int estrutura, vetorOrdenado* v, No* noABB, treapNode* noTreap, redBlackNode* noRubroNegra, vector<string> F, vector<string> L, vector<string> SR, vector<string> VD){    
    int qtdOcorrencias;
    string palavra;

    imprimeSep();
    // CONSULTA PALAVRAS MAIS FREQUENTES (F)
    // if(q == 1){
    //     if(estrutura == 1){
            
    //     }
    //     else if(estrutura == 2)
    //         qtdOcorrencias = noABB->qtdOcorrencias(noABB, palavra);
    //     else if(estrutura == 3)
    //         qtdOcorrencias = noTreap->qtdOcorrencias(noTreap, palavra);
    //     else if(estrutura == 5)
    //         qtdOcorrencias = noRubroNegra->qtdOcorrencias(noRubroNegra, palavra);
    // }

    // CONSULTA O(PALAVRA)
    if(q == 2){
        cout << "Digite a palavra que deseja consultar: ";
        cin >> palavra;
        if(estrutura == 1)
            qtdOcorrencias = v->qtdOcorrencias(palavra);
        else if(estrutura == 2)
            qtdOcorrencias = noABB->qtdOcorrencias(noABB, palavra);
        else if(estrutura == 3)
            qtdOcorrencias = noTreap->qtdOcorrencias(noTreap, palavra);
        else if(estrutura == 5)
            qtdOcorrencias = noRubroNegra->qtdOcorrencias(noRubroNegra, palavra);
        
        cout << endl << "A palavra " << palavra << " ocorreu " << qtdOcorrencias << " vezes";
        
        return;  
    }

    // CONSULTA PALAVRAS MAIS LONGAS (L)
    if(q == 3){
        cout << "As palavras mais longas são: " << endl;
        imprimeVector(q, L);
    }

    // CONSULTA MAIORES PALAVRAS QUE NAO REPETEM LETRAS (SR)
    if(q == 4){

    }

    return;
}

void imprimeVector(int q, vector<string> v){
    for(int i = 0; i < (int)v.size(); i++)  
        cout << v[i] << endl;
}