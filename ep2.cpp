#include "abb.h"
#include "treap.h"
#include "rubroNegra.h"
#include "vetorOrdenado.h"
#include "23tree.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 256

using namespace std;

int repeteLetra(string palavra);
int qtdVogaisSemRepeticao(string palavra);
void imprimeSep();
void imprimeVector(int q, vector<string> v);
void imprime(int estrutura, vetorOrdenado* vector, No* noABB, treapNode* noTreap, redBlackNode* noRubroNegra);
void consulta(int q, int estrutura, vetorOrdenado* v, No* noABB, treapNode* noTreap, A23* noTwoThree, redBlackNode* noRubroNegra, vector<string> maisFrequentes, vector<string> longestWords, vector<string> maioresSemRepeticao, vector<string> vogaisSemRepeticao);

// exemplo: 39
// hamlet: 33287
// mobydick: 209329

int main(){
    int n;
    int q;
    int totalLongest = 0;
    int totalSR = 0;
    int totalVD = 0;
    int qtdConsultas;
    int nomeEstrutura;
    char nomeArquivo[MAX];
    char* linha = nullptr;
    char* palavra = nullptr;
    FILE* arquivo;
    size_t read;
    size_t len = 0;

    // VECTORS PARA CONSULTAS
    vector<string> maisFrequentes;
    vector<string> longestWords;
    vector<string> maioresSemRepeticao;
    vector<string> vogaisSemRepeticao;

    // INÍCIO
    cout << "-*- Bem Vinde à tabela de símbolos -*-" << endl;
    cout << "1. Vetor dinâmico ordenado" << endl << "2. Árvore de Busca Binária" << endl << "3. Treaps" << endl << "4. Árvore 2-3" << endl << "5. Árvore rubro-negra" << endl;
    cout << "Informe qual estrutura você deseja testar (número): ";
    cin >> nomeEstrutura;
    
    imprimeSep();

    cout << "Digite o número de palavras no texto: ";
    cin >> n;

    cout << "Digite o nome do arquivo de leitura: ";
    cin >> nomeArquivo;

    imprimeSep();

    //Instanciar Objetos
    No* noABB = new No();
    treapNode* noTreap = new treapNode(); 
    vetorOrdenado* vector = new vetorOrdenado(n);
    redBlackNode* noRubroNegra = new redBlackNode();
    A23* noTwoThree = new A23(" ");

    arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL)
        return 0;

    // Leitura das palavras
    while((read = getline(&linha, &len, arquivo)) != (long unsigned int)-1){
        palavra = strtok(linha, "  ,`’‘’.-—_?![](){}@#$%&*+=|;/><1234567890:\n");
        while(palavra != NULL){
            if(*palavra != '\n' && *palavra != '\0'){
                // Pré Processamento
                if(totalVD == 0){
                    if(qtdVogaisSemRepeticao(palavra) > 0){
                        vogaisSemRepeticao.push_back(palavra);
                        totalVD += 1;
                    }
                }
                else if(qtdVogaisSemRepeticao(palavra) >= qtdVogaisSemRepeticao(vogaisSemRepeticao[0])){
                    if(qtdVogaisSemRepeticao(palavra) > qtdVogaisSemRepeticao(vogaisSemRepeticao[0])){
                        vogaisSemRepeticao.clear();
                        vogaisSemRepeticao.push_back(palavra);
                    }
                    else if(strlen(palavra) <= vogaisSemRepeticao[0].length()){
                        if(strlen(palavra) < vogaisSemRepeticao[0].length())
                            vogaisSemRepeticao.clear();
                        vogaisSemRepeticao.push_back(palavra);
                    }
                }

                if(totalSR == 0){
                    if(!repeteLetra(palavra)){
                        maioresSemRepeticao.push_back(palavra);
                        totalSR += 1;
                    }
                }
                else if(strlen(palavra) >= maioresSemRepeticao[0].length() && !repeteLetra(palavra)){
                    if(strlen(palavra) > maioresSemRepeticao[0].length())
                        maioresSemRepeticao.clear();
                    maioresSemRepeticao.push_back(palavra);
                }

                if(totalLongest == 0){
                    longestWords.push_back(palavra);
                    totalLongest += 1;
                }
                else if(strlen(palavra) >= longestWords[0].length()){
                    if(strlen(palavra) > longestWords[0].length())
                        longestWords.clear();
                    longestWords.push_back(palavra);
                }
                bool cresceu;
                // Enviar palavras para as estruturas
                if(nomeEstrutura == 1)
                    vector->insereVetor(palavra);
                else if(nomeEstrutura == 2)
                    noABB = noABB->insereABB(noABB, palavra);
                else if(nomeEstrutura == 3)
                    noTreap = noTreap->insereTreap(noTreap, palavra);
                else if(nomeEstrutura == 4)
                    noTwoThree = noTwoThree->insert(noTwoThree, palavra, cresceu);
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
    
    // consultas
    cout << "Digite a quantidade de consultas: ";
    cin >> qtdConsultas;
    imprimeSep();
    for(int i = 0; i < qtdConsultas; i++){
        cout << "1. Palavras mais frequentes (F)" << endl << "2. Ocorrências de uma palavra (O(palavra))" << endl << "3. Palavras mais longas (L)" << endl << "4. Maiores palavras sem repetição de letras (SR)" << endl << "5. Menores palavras com mais vogais sem repetição (VD)" << endl;
        cout << "Por favor, selecione uma consulta: ";
        cin >> q;
        consulta(q, nomeEstrutura, vector, noABB, noTreap, noTwoThree, noRubroNegra, maisFrequentes, longestWords, maioresSemRepeticao, vogaisSemRepeticao);
        imprimeSep();
    }

    fclose(arquivo);
    return 0;
}

int qtdVogaisSemRepeticao(string palavra){
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

int repeteLetra(string palavra){
    sort(palavra.begin(), palavra.end());
    for(int i = 0; i < (int)palavra.length() - 1; i++)
        if(palavra[i] == palavra[i+1])
            return 1;
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

void consulta(int q, int estrutura, vetorOrdenado* v, No* noABB, treapNode* noTreap, A23* noTwoThree, redBlackNode* noRubroNegra, vector<string> maisFrequentes, vector<string> longestWords, vector<string> maioresSemRepeticao, vector<string> vogaisSemRepeticao){    
    int qtdOcorrencias;
    string palavra;

    imprimeSep();

    // CONSULTA PALAVRAS MAIS FREQUENTES (F)
    if(q == 1){
        palavrasMaisFrequentes* p = new palavrasMaisFrequentes();
        p->palavras = maisFrequentes;
        cout << "As palavras mais frequentes do texto são: " << endl;
        if(estrutura == 1)
            imprimeVector(q, v->palavraMaisFrequente());
        else if(estrutura == 2)
            imprimeVector(q, noABB->palavraMaisFrequente(noABB, p));
        else if(estrutura == 3)
            imprimeVector(q, noTreap->palavraMaisFrequente(noTreap, p));
        else if(estrutura == 4)
            imprimeVector(q, noTwoThree->palavraMaisFrequente(noTwoThree, p));
        else if(estrutura == 5)
            imprimeVector(q, noRubroNegra->palavraMaisFrequente(noRubroNegra, p));
    }

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
        else if(estrutura == 4)
            qtdOcorrencias = noTwoThree->qtdOcorrencias(noTwoThree, palavra);
        else if(estrutura == 5)
            qtdOcorrencias = noRubroNegra->qtdOcorrencias(noRubroNegra, palavra);
        
        cout << endl << "A palavra " << palavra << " ocorreu " << qtdOcorrencias << " vezes";
        
        return;  
    }

    // CONSULTA PALAVRAS MAIS LONGAS (L)
    if(q == 3){
        cout << "As palavras mais longas são: " << endl;
        imprimeVector(q, longestWords);
    }
    
    // CONSULTA MAIORES PALAVRAS QUE NÃO REPETEM LETRAS (SR)
    if(q == 4){
        cout << "As maiores palavras que não repetem letras são: " << endl;
        imprimeVector(q, maioresSemRepeticao);
    }

    // CONSULTA MENORES PALAVRAS COM MAIS VOGAIS (VD)
    if(q == 5){
        cout << "As menores palavras que não repetem vogais são: " << endl;
        imprimeVector(q, vogaisSemRepeticao);
    }
    return;
}

void imprimeVector(int q, vector<string> v){
    for(int i = 0; i < (int)v.size(); i++)  
        cout << v[i] << endl;
}