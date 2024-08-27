#include <iostream>
using namespace std;
#include "fila.h"

template <class T> class FilaArray : public Fila<T> {
private:
// array de itens, capacidade, tamanho, posição inicial, etc.
T *itens_da_fila;
int capacidade_da_fila;
int tamanho_da_fila;
int posicao_inicial_da_fila;
// posiçao inicial vai ser o tamanho da fila

public:
  FilaArray(int cap) : Fila<T>(cap) {
    // inicializar array de items, capacidade, tamanho, posição inicial
  this->capacidade_da_fila = cap;
  this->tamanho_da_fila = 0;
  this->posicao_inicial_da_fila = 0;
  this->itens_da_fila = new T[cap];
  }

  ~FilaArray() {
 // destruir array de itens
  delete[] this->itens_da_fila;
}

void enfileira(const T &item) { 
  if (cheia() == 1) { // checando se a fila esta cheia antes de adicionar
    throw "Fila cheia";
  }

  int BufferCicular; //declarando o buffer pra armazenar resultado

  // inicio da fila + tamanho a fila % resto da capacidade = posicao num circulo
  BufferCicular = (posicao_inicial_da_fila + tamanho_da_fila) % capacidade_da_fila;
  itens_da_fila[BufferCicular] = item; //recebendo o item na posição dada pelo buffer
  tamanho_da_fila++; //aumentando tamanho apos add
}

T desenfileira() {
  if (vazia() == 1) {
    throw "Fila vazia";
  }

  T item_desenfileirado;
  item_desenfileirado = itens_da_fila[posicao_inicial_da_fila]; // atribui item a ser removido
                                              // na var.
  posicao_inicial_da_fila = (posicao_inicial_da_fila + 1) % capacidade_da_fila; // move o index/remove item.
  tamanho_da_fila--;
  return item_desenfileirado; // retorna item que foi removido.
}

int cheia() {
  // retorna 1 se cheia, 0 caso contrário
  return tamanho_da_fila == capacidade_da_fila;

}

int vazia() {
  // retorna 1 se vazia, 0 caso contrário
  return (tamanho_da_fila == 0);
  // se a posI e tamanho forem iguais
  // e a fila nao estiver cheia (!fila_cheia)
  // entao a fila esta vazia.
}

int tamanho() { ///------------------- RETORNAR SO O TAMANHO --------------
  // retorna a quantidade de itens atualmente na fila
    return tamanho_da_fila;
}
};