#include <iostream>
using namespace std;
#include "lista.h"

template <class T> 
class ListaArray : public Lista<T>{
private:
  // atributos:
  // - itens da lista (ponteiro para T usado como array)
  T *itens_da_lista;
  // - capacidade e tamanho atual (inteiros)
  int capacidade_da_lista;
  int tamanho_atual_da_lista;

public:
  ListaArray(int capacidade)  : Lista<T>(capacidade) {
    // inicilização do array de itens, capacidade e tamanho
    this->itens_da_lista = new T[capacidade];
    this->capacidade_da_lista = capacidade;
    this->tamanho_atual_da_lista = 0;
  }
  ~ListaArray() {
    // destruição do array
    delete[] this->itens_da_lista;
  }

  //append - add elemento no final da lista. 
  void adiciona(const T &item) {
    // lança “Lista cheia” caso capacidade esgotada (testar antes)
    if (tamanho_atual_da_lista == capacidade_da_lista) {
      throw "Lista cheia";
    }
    itens_da_lista[tamanho_atual_da_lista++] = item;
  }

  // pega um item pelo indice (começa em 1);
  T pega(int idx) {
    // lança “Item inválido” se posição inválida (testar antes)
    // ATENÇÃO: posições válidas são de 1 a N (= capacidade).
    if (idx < 1 || idx > tamanho_atual_da_lista) {
      throw "Indice inválido";
    }
    return itens_da_lista[idx - 1]; // - 1 pra pegar a partir de 1
                                    // mesmo que idx comece em 0.
  }
  // insere um item na posição indicada (a partir de 1).
                  //e move elementos 1 posicao para direita
  void insere(int idx, const T &item) {
    // lança “Lista cheia” caso cheia
    if (tamanho_atual_da_lista == capacidade_da_lista) {
      throw "Lista cheia";
    }
    // lança “Item inválido” se posição inválida
    if (idx < 1 || idx > tamanho_atual_da_lista + 1) {
      throw "Indice inválido";
    }
    // se a lista contém N itens, só é possivel inserir até a posição N
    // deve deslocar itens existentes uma posição para a direita
    for (int i = tamanho_atual_da_lista; i >= idx ; --i) {
      this->itens_da_lista[i] = itens_da_lista[i - 1];
    }
    this->itens_da_lista[idx - 1] = item;
    ++tamanho_atual_da_lista;
  }

  // remove o item de uma posição indicada (a partir de 1)
  void remove(int idx) { 
    // lança “Item inválido” se posição inválida
    if (idx < 1 || idx > tamanho_atual_da_lista) {
      throw "Indice inválido";
    }

    // desloca itens uma posicao a esquerda sobre o item removido
    for (int i = idx - 1; i < tamanho_atual_da_lista - 1; ++i) {
      this->itens_da_lista[i] = itens_da_lista[i + 1];
    }
    --tamanho_atual_da_lista;
  }

  void exibe() {
    // exibe os itens da saida padrão separados por espaços
    for (int i = 0; i < tamanho_atual_da_lista; ++i) {
      cout << itens_da_lista[i] << " ";
    }
    cout << endl;
  }

  int tamanho() {
    // retorna a quantidade de itens atualmente na lista
    return tamanho_atual_da_lista;
  }
};