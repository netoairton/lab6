#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios;
#include<string>
using std::string;

#include<fstream>
using std::ifstream;
using std::ofstream;

#include "openarquivo.h"
#include"alunos.h"

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

/*void salvarturma(Listaalunos<float> *lista, int quantidade){
    //string arquivo;
    cout<<"Digite o nome do arquivo que deseja salvar(serao salvos na pasta data): ";
    //cin>>arquivo;

    ifstream teste("./data/arquivo.txt");
    string check;
    getline(teste, check);
    teste.close();

    ofstream salvar("./data/arquivo.txt", ios::app);
    if(!salvar){
        cout<<"O arquivo de entrada nao pode ser aberto."<<endl;
        return;
    }
    if(teste){
        for(int i=0; i<quantidade; i++){
            salvar<<endl;
            //salvar<<lista[i]<<";";
        }
    }
    salvar.close();
    //return 0;

}*/