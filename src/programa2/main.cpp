/**
 * @file	main.cpp
 * @brief	Implementacao do main
 * @author	Airton Neto(netoairton@yahoo.com.br)
 * @since	12/05/2017
 * @date	18/05/2017
 * @sa		lista.h
 */
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;

#include"include/programa2/lista.h"

int main(){
    Lista<int> lista;
    int elemento, opcao, quantidade;
    cout<<endl
        <<"*****  Lista Duplamente encadeada  *****"<<endl
        <<endl
        <<"O que deseja fazer? (1)inserir elemento(s) (2)exibir lista (3)sair : ";
    cin>>opcao;
    cout<<endl;
    switch(opcao){
        case 1:{
            cout<<"Quantos elementos (0 para sair): ";
            cin>>quantidade;
            cout<<endl;
            if(quantidade==0){
                lista.Exibe();
                return 0;
            }
            for(int i=0; i<quantidade; i++){
                cout<<"Digite o valor a ser inserido (-1 para sair): ";
                cin>>elemento; //Pede cada elemento a ser adicionado
                if(elemento== -1){
                    lista.Exibe();
                    return 0;
                }
                lista.Inserir(elemento);//Insere na lista
            }
            cout<<                                endl
                <<"Todos os Elementos inseridos"<<endl
                                                <<endl;
            cout<<"Deseja exibir a lista? (2)Sim (3)Sair:";
            cin>>opcao;
            if(opcao==2){
                lista.Exibe();
                return 0;
            }
            if(opcao==3){
                return 0;
            }
            break;
        }
        case 2:{
            lista.Exibe();
            break;
        }
        case 3:{
            break;
        }
        default:{
            return 0;
        }
    }

    //lista.Exibe();
    return 0;
}