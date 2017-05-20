#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;

#include"openarquivo.h"
#include"alunos.h"

int main(){
    Listaalunos<float> lista;
    int quantidade;
    cout<<"***** Listagem de alunos em turmas *****"<<endl
        <<endl
        <<"(0)Sair "<<endl
        <<"Quantas turmas deseja inserir (uma por arquivo) : ";
    cin>>quantidade;
    if(quantidade==0){
        return 0;
    }
    string *arquivo= new string[quantidade];
    int *total= new int[quantidade];

    for(int i=0; i<quantidade; i++){
        cout<<"Digite o caminho do arquivo: ";
        cin>>arquivo[i];
        total[i]= aberturaturma(arquivo[i]);
        lista.Inserir(arquivo[i], total[i]);
        cout<<endl
            <<"Alunos da turma  "<<i+1<<" :"<<endl
            <<endl;
        lista.Exibe();
    }
    return 0;
}