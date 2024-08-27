 #include <iostream>
using namespace std;
#include "pilha.h"

template <class T> 
class PilhaLigada : public Pilha<T>{

private:
  struct No {
    T dado;
    No *prox;
  };

  No *topo;
  int tamanho_maximo; // capacida maxima da pilha
  int tamanho_atual;  // tamanho atual da pilha, vai atualizar sempre que
                      // empilhar ou desempilhar

public:
  PilhaLigada(int capacidade) : Pilha<T>(capacidade) {
    this->topo = nullptr;
    this->tamanho_atual = 0;           // tamanho atual comeca em 0, pilha vazia
    this->tamanho_maximo = capacidade; // usuario escolhe a capacidade maxima
  }

  virtual ~PilhaLigada() {
    while (topo != nullptr) { // enquanto topo =/= null
      No *temp = topo;        // cria temp recebendo topo (ultimo dado add)
      topo = topo->prox;      // topo aponta pro prox dado
      delete temp;            // vai deletar esse ultimo dado
    }
  }

  void empilha(T value) {
    // falha se tamanho atual for maior ou igual que o tamanho maximo -> “stack
    // overflow”
    if (tamanho_atual >= tamanho_maximo) {
      throw "stack overflow";
      return;
    }
    // alocar novo NÓ;
    No *temp = new No();
    // colocar dados em NÓ->dados
    temp->dado = value;
    // fazer NÓ->prox apontar para TOPO
    temp->prox = topo;
    // fazer TOPO apontar para NÓ
    topo = temp;
    // aumentando tamanho atual da pilha ao inserir novo dado
    tamanho_atual++;
  }

  T desempilha() {
    // verificar se o TOPO é NULO;
    // se for -> “stack underflow”
    if (topo == nullptr) {
      throw "stack underflow";
    }
    // pegar TOPO e salvar em variável TMP
    No *temp = topo;
    // fazer TOPO igual a TMP->prox
    topo = topo->prox;

    T dado_removido = temp->dado; // criando variavel pra armazenar dado
                                  // deletado pq return acaba o codigo

    tamanho_atual--; // diminuindo tamanho atual da pilha pq delete dado

    // desalocar TMP
    delete temp;
    // retorna dados
    return dado_removido;
  }

  int tamanho() {
    // retorna o número de elementos na pilha.
    return tamanho_atual;
  }
};
