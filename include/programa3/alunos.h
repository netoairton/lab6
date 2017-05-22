#ifndef ALUNOS_H
#define ALUNOS_H

#include<iostream>
using std::cout;
using std::endl;
using std::ios;
#include<string>
using std::string;
#include<fstream>
using std::ifstream;
using std::ofstream;
#include <cstdlib> 

template<typename T>
class Listaalunos {
    private:
        string matricula;
        string nome;
        int faltas;
        T nota;
        Listaalunos *ant;
        Listaalunos *prox;
    public:
        Listaalunos();
        ~Listaalunos();
        int vazia();
        void Inserir(string Arquivo, int contador);
        T Media();
        void Exibe();
        void Salva();
};



template<typename T>
Listaalunos<T>::Listaalunos(){
    prox = NULL;
	ant = NULL;
}
template<typename T>
Listaalunos<T>::~Listaalunos(){
    if(prox){
        delete prox;
    }
}
template<typename T>
int Listaalunos<T>::vazia(){
	if(prox == NULL)
		return 1;
	else
		return 0;
}

template<typename T>
void Listaalunos<T>::Inserir(string Arquivo, int contador){
    //Abrir pra armazenar
    ifstream entrada(Arquivo);
    
    if(!entrada){
        cout<<"O arquivo de entrada nao pode ser aberto."<<endl;
        return;
    }
    string null;
    getline(entrada, null); //descartando o cabeçalho
    for(int jj=0; jj<contador; jj++){
        Listaalunos *novo = new Listaalunos();
        if(!novo){
		cout << "Sem memoria disponivel!"<<endl;
		    return;
	    }
        string stringfaltas;
        string stringnota;
        getline(entrada, novo->matricula, ';');
        getline(entrada, novo->nome, ';');
        getline(entrada, stringfaltas, ';');
        novo->faltas= atoi(stringfaltas.c_str());
        getline(entrada, stringnota);
        novo->nota= atof(stringnota.c_str());

        if(vazia()){
		    prox=novo;
		    novo->ant=NULL;
		    novo->prox=NULL;
	    }
        else{
            Listaalunos *tmp = prox;
            while(tmp->prox){
				tmp = tmp->prox;	
            }

            novo->ant = tmp;
			novo->prox=NULL;
		    tmp->prox = novo;
        }
    }
    entrada.close();
}
template<typename T>
T Listaalunos<T>::Media(){
    if(vazia()){
        cout << "Lista vazia!"<<endl
							  <<endl;
        return 0;
    }
    Listaalunos *tmp;
	tmp = prox;
    int ii=0;
    T media=0;

	while( tmp != NULL){
        ii++;
        media=media+ tmp->nota;
		tmp = tmp->prox;
	}
    media=media/ii;
    return media;
}

template<typename T>
void Listaalunos<T>::Exibe(){
    if(vazia()){
        cout << "Lista vazia!"<<endl
							  <<endl;
        return;
    }

    Listaalunos *tmp;
	tmp = prox;
    int ii=0;

	while( tmp != NULL){
        ii++;
        cout<<"______________________________"<<endl
            <<"Aluno  "<<ii<<endl
		    <<"Matricula : "<< tmp->matricula <<endl
            <<"Nome : "<<tmp->nome <<endl
            <<"Faltas : "<<tmp->faltas <<endl
            <<"Nota : "<<tmp->nota <<endl;
		tmp = tmp->prox;
	}
	cout << endl;
}
template<typename T>
void Listaalunos<T>::Salva(){
    ifstream teste("./data/arquivo.csv");
    string check;
    getline(teste, check);
    teste.close();

    ofstream salvar("./data/arquivo.csv", ios::app);
    if(!salvar){
        cout<<"O arquivo de entrada nao pode ser aberto."<<endl;
        return;
    }
    Listaalunos *tmp;
	tmp = prox;
    int ii=0;
    if(teste){
        while( tmp != NULL){
            ii++;
            salvar<<tmp->matricula <<";"
                <<tmp->nome <<";"
                <<tmp->faltas <<";"
                <<tmp->nota <<endl;
		    tmp = tmp->prox;
	    }
    }
    else{
        salvar<<"Matricula;Nome;Faltas;Nota"
        <<endl;
        while( tmp != NULL){
            ii++;
            salvar<<tmp->matricula <<";"
                <<tmp->nome <<";"
                <<tmp->faltas <<";"
                <<tmp->nota <<endl;
		    tmp = tmp->prox;
	    }
    }
    salvar.close();
}
#endif