/**
 * @file	openarquivo.cpp
 * @brief	Declaracao da classe Pilha e seus metodos
 * @author	Airton Neto(netoairton@yahoo.com.br)
 * @since	09/05/2017
 * @date	14/05/2017
 */
#ifndef PILHA_H
#define PILHA_H

template <typename T>

class Pilha{
    private:
    int maximo;
    int tamanho;
    T *pilha;

    public:
    Pilha(int tamanho);
    int push(T el);
    T pop();
};

template <typename T>
Pilha<T>::Pilha(int t){
    pilha= new T[t];
    maximo=t;
    tamanho=0;
}

template <typename T>
int Pilha<T>::push(T el){
    if(tamanho==maximo){
        return tamanho;
    }
    pilha[tamanho]=el;
    return ++tamanho;
}

template <typename T>
T Pilha<T>::pop(){
    if(tamanho==0){
        return tamanho;
    }
    --tamanho;
    return pilha[tamanho];
}

#endif