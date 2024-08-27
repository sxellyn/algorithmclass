#include <iostream>
using namespace std;

template <class T> class Pilha {
private:
  // Atributos para array de items, capacidade e topo da pilha
  T *items_do_array;
  int capacidade_da_pilha;
  int topo_da_pilha;

public:
  Pilha(int size) {
    // instancia array de items, inicializa capacidade e topo
    capacidade_da_pilha = size; // var dinamica =/= var de classe
    items_do_array = new T[capacidade_da_pilha];
    topo_da_pilha = - 1;
  }

  ~Pilha() {
    // destroy array de items
    delete[] this->items_do_array;
  }

  void empilha(T item) {
    // empilha um item no topo da pilha; lança “Estouro da pilha” se cheia
    if (topo_da_pilha == capacidade_da_pilha - 1) {
      throw "Estouro da pilha";
    }
    items_do_array[++topo_da_pilha] = item;
  }

  T desempilha() {
    // remove um item do topo da pilha; lança “Pilha vazia” se vazia
    if (topo_da_pilha == -1) {
      throw "Pilha vazia";
    }
      return items_do_array[topo_da_pilha--];
  }

  int tamanho() {
    // retorna o número de elementos na pilha.
    return topo_da_pilha + 1;
  }
};
