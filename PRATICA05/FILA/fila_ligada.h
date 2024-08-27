#include <iostream>
using namespace std;
#include "fila.h"

template <class T> class FilaLigada : public Fila<T> {

private:
  struct No {
    T dado;
    No *prox;
  };

  // criando tudo:
  No *inicio_da_fila;
  No *final_da_fila;
  int tamanho_maximo; // capacida maxima da fila
  int tamanho_atual;  // tamanho atual da fila, vai atualizar sempre que
                      // enfileira ou desenfileira

public:
  FilaLigada(int capacidade) : Fila<T>(capacidade) {
    // inicializando tudo:
    this->inicio_da_fila = nullptr;
    this->final_da_fila = nullptr;
    this->tamanho_atual = 0;           // tamanho atual comeca em 0, pilha vazia
    this->tamanho_maximo = capacidade; // usuario escolhe a capacidade maxima
  }

  ~FilaLigada() {
    while (inicio_da_fila != nullptr) {   // enquanto inicio =/= null
      No *no_temporario = inicio_da_fila; // cria no_temporario recebendo
                                          // inicio_da_fila (primeiro dado add)
      inicio_da_fila =
          inicio_da_fila->prox; // inicio_da_fila aponta pro prox dado
      delete no_temporario;     // vai deletar esse primeiro dado
    }
  }

  void enfileira(const T &item) {
    // se falhar -> “queue overflow”
    if (cheia()) {
      throw "FILA CHEIA";
    }
    // alocar novo NÓ;
    No *no_temporario = new No();
    
    // colocar dados do elemento em NÓ
    no_temporario->dado = item;
    // fazer NÓ->prox igual a NULO
    no_temporario->prox = nullptr;

    //  ------------------------------------------------------- //
    // SE (INICIO é NULO) ENTÃO -- Fila vazia
    if (vazia()) {
      // fazer INICIO apontar para NÓ
      inicio_da_fila = final_da_fila =
          no_temporario; // igualando pq tem os msm atrib.
    }
    //  ------------------------------------------------------- //
    // SENÃO
    else {
      // fazer FINAL->prox apontar para NÓ
      final_da_fila->prox = no_temporario;
      final_da_fila = no_temporario;
    }
    //  ------------------------------------------------------- //
    tamanho_atual++;
  }

  T desenfileira() {
    // verificar se o INICIO é NULO;
    if (vazia()) {
      throw "FILA VAZIA"; // se for -> “queue underflow”
    }
    // pegar INICIO e salvar em TMP
    No *no_temporario = inicio_da_fila;
    // fazer INICIO igual à INICIO->prox
    inicio_da_fila = inicio_da_fila->prox;
    // SE (INICIO é NULO) ENTÃO -- Fila vazia
    if (vazia()) {
      final_da_fila = nullptr; // fazer FINAL apontar para NULO
    }
    tamanho_atual--; // diminuindo pq tamo removendo elemento

    T dado_removido = no_temporario->dado; // criando variavel pra armazenar
                                           // dado pq return acaba o programa

    // desaloca TMP (salvar dados antes (ja ta sendo salvo na linha 65))
    delete no_temporario;
    // retornar dados
    return dado_removido;
  }

  int cheia() {return tamanho_atual == tamanho_maximo;}

  int vazia() {return inicio_da_fila == nullptr;}

  int tamanho() {return tamanho_atual;}
    
};