#include "abb.h"
#include "treap.h"
#include "rubroNegra.h"
#include "vetorOrdenado.h"
#include <iostream>
#include <cstring>
#define MAX 256

using namespace std;

int main(){
    int n;
    // int nomeEstrutura;
    char nomeArquivo[MAX];
    char* linha = nullptr;
    char* palavra = nullptr;
    FILE* arquivo;
    size_t read;
    size_t len = 0;    

    cout << "-*- Bem Vinde à tabela de símbolos -*-" << endl;
    cout << "1. Vetor dinâmico ordenado" << endl << "2. Árvore de Busca Binária" << endl << "3. Treaps" << endl << "4. Árvore 2-3" << endl << "5. Árvore rubro-negra" << endl;
    // cout << "Informe qual estrutura você deseja testar: ";
    // cin >> nomeEstrutura;
    
    // exemplo: 39
    // hamlet: 33287
    // mobydick: 209329
    cout << "Digite o número de palavras no texto: ";
    cin >> n;

    // OBS TEREMOS QUE INSTANCIAR TODOS OS OBJETOS NO COMEÇO DO CODIGO OK NAO ESQUECE
    // redBlackNode* dados = new redBlackNode();   // REDBLACK
    // vetorOrdenado* dados = new vetorOrdenado(n); // VO
    // No* dados = new No();   // ABB
    treapNode* dados = new treapNode(); // TREAP

    // leitura do arquivo e palavra a palavra
    cout << "Digite o nome do arquivo de leitura: ";
    cin >> nomeArquivo;

    arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL)
        return 0;
    
    while((read = getline(&linha, &len, arquivo)) != (long unsigned int)-1){
        palavra = strtok(linha, "  ,`’‘’.-—_?![](){}@#$%&*+=|;/><1234567890:\n");
        while(palavra != NULL){
            if(*palavra != '\n' && *palavra != '\0')
                // dados = dados->insereRedBlack(dados, palavra);
                dados = dados->insereTreap(dados, palavra);
                // dados = dados->insereABB(dados, palavra);
                // dados->insereVetor(palavra);
            palavra = strtok(NULL, "  ,`’‘’.-—_?![](){}@#$%&*+=|;/><1234567890:\n");
        }
    }
    dados->imprime(dados);
    fclose(arquivo);

    return 0;
}