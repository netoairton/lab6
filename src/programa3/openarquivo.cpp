/**
 * @file	openarquivo.cpp
 * @brief	Implementacao da funcao que calcula o numero de alunos em um arquivo
 * @author	Airton Neto(netoairton@yahoo.com.br)
 * @since	20/05/2017
 * @date	21/05/2017
 * @sa		alunos.h
 * @sa		openarquivo.h
 */
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

/**
 * @brief Funcao que conta o numero de alunos no arquivo a ser aberto
 * @param Arquivo String com o nome do arquivo
 */
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
