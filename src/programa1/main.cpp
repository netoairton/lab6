/**
 * @file	main.cpp
 * @brief	Implementacao do main
 * @author	Airton Neto(netoairton@yahoo.com.br)
 * @since	09/05/2017
 * @date	14/05/2017
 * @sa		trata_string.h
 * @sa		pilha.h
 */
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
using std::string;

#include<algorithm>

#include"include/programa1/pilha.h"
#include "include/programa1/trata_string.h"

int main(){
    string p1;
    cout<<"Digite a palavra/frase: ";
    getline(cin, p1);
    tratar_string(p1);
    //Se só tiver 1 letra, automaticamente é palindromo
    if(p1.length()==1){
        cout<<"Palindromo"<<endl;
        return 0;
    }
    //Se a palavra estiver vazia não pode ser analisada
    if(p1.length()==0){
        cout<<"Erro! Sem letras a serem analisadas!"<<endl;
        return 0;
    }
    //Declara a pilha com o tamanho da metade da palavra
    Pilha<char> pilha(p1.length()/2);
    string p2;
    //Checa se a palavra tem numero de caracteres impar ou par
    if(p1.length()%2 == 1){
        p2 = p1.substr ((p1.length()/2 )+1,p1.length());
    }
    else{
        p2 = p1.substr ((p1.length()/2 ),p1.length());
    }
    cout<<"Conjunto de letras a serem analisadas: "<<p1<<endl;

    bool f= false;
    //coloca os caracteres na pilha
    for(unsigned int i=0; i<p1.length()/2; i++){
        pilha.push( p1[i] );
    }
    //Checa se é palindromo
    for(unsigned int i=0; i<p1.length()/2; i++){
        if(pilha.pop()==p2[i]){
            f=true;
        }
        else{
            f=false;
            break;
        }
    }
    
    if(f==true){
        cout<<"Palindromo"<<endl;
    }
    else{
        cout<<"NAO eh palindromo"<<endl;
    }
    

    return 0;
}