#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;

#include<fstream>
using std::ifstream;
using std::ofstream;

#include "openarquivo.h"

int aberturaturma(string Arquivo){
    int contador=0;
    //Quantidade de alunos
    ifstream tamanho(Arquivo);
    if(!tamanho){
        cout<<"O arquivo de entrada nao pode ser aberto."<<endl;
        return 0;
    }
    string null;
    getline(tamanho, null); //descartando o cabeçalho
        
    string contadora;
    while(getline(tamanho, contadora)){
        ++contador;
    }
        
    tamanho.seekg(0);
    tamanho.close();
    cout<<"Quantidade de alunos nessa turma: "<<contador<<endl;
    return contador;
}