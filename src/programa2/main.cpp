#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;

#include"lista.h"

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
                cin>>elemento;
                if(elemento== -1){
                    lista.Exibe();
                    return 0;
                }
                lista.Inserir(elemento);
            //lista.Exibe();
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