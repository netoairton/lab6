#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;

#include"openarquivo.h"
#include"alunos.h"

int main(){
    //Listaalunos<float> lista;
    int quantidade, opcao=0;
    cout<<"***** Listagem de alunos em turmas *****"<<endl
        <<endl
        <<"(0)Sair "<<endl
        <<"Quantas turmas deseja inserir (uma por arquivo) : ";
    cin>>quantidade;
    if(quantidade==0){
        return 0;
    }
    Listaalunos<float> *lista= new Listaalunos<float>[quantidade];
    string *arquivo= new string[quantidade];
    int *total= new int[quantidade];

    for(int i=0; i<quantidade; i++){
        cout<<"Digite o caminho do arquivo: ";
        cin>>arquivo[i];
        total[i]= aberturaturma(arquivo[i]);
        lista[i].Inserir(arquivo[i], total[i]);
        cout<<endl
            <<"Deseja Imprimir os alunos dessa turma (1)Sim (0)Nao : ";
        cin>>opcao;
        if(opcao==1){
            cout<<endl
                <<"Alunos da turma  "<<i+1<<" :"<<endl
                <<endl;
            lista[i].Exibe();
        }
    }
    //vetor que recebe as medias de cada turma, para depois imprimir/salvar
    float *media= new float[quantidade];
    for(int jj=0; jj<quantidade; jj++){
        cout<<"Calculando as medias: "<<jj+1<<"/"<<quantidade<<" turmas calculadas"<<endl;
        media[jj]=lista[jj].Media();
    }
    cout<<endl
        <<"Deseja imprimir as medias das turmas (1)Sim (0)Nao : ";
    cin>>opcao;
    if(opcao==1){
        for(int jj=0; jj<quantidade; jj++){
            cout<<"Media da turma "<<jj+1<<" : "<<media[jj]<<endl;
        }
    }

    cout<<endl
        <<"Salvando os dados em um arquivo....."<<endl
        <<"...Salvo em data/arquivo.csv"<<endl;
    for(int jj=0; jj<quantidade; jj++){
        lista[jj].Salva();
    }
    

    delete [] media;
    delete [] total;
    delete [] arquivo;
    delete [] lista;
    return 0;
}