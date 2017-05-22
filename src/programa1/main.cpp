#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
using std::string;

#include<algorithm>

#include"pilha.h"
#include "trata_string.h"

int main(){
    string p1;
    cout<<"Digite a palavra/frase: ";
    getline(cin, p1);
    tratar_string(p1);
    
    if(p1.length()==1){
        cout<<"Palindromo"<<endl;
        return 0;
    }
    if(p1.length()==0){
        cout<<"Erro! Sem letras a serem analisadas!"<<endl;
        return 0;
    }
    Pilha<char> pilha(p1.length()/2);
    string p2;
    if(p1.length()%2 == 1){
        p2 = p1.substr ((p1.length()/2 )+1,p1.length());
    }
    else{
        p2 = p1.substr ((p1.length()/2 ),p1.length());
    }
    cout<<"Conjunto de letras a serem analisadas: "<<p1<<endl;

    bool f= false;
    for(unsigned int i=0; i<p1.length()/2; i++){
        pilha.push( p1[i] );
    }
    
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