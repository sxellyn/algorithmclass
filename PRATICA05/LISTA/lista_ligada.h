#include <iostream>
using namespace std;
#include "lista.h"

template <class T> class ListaLigada : public Lista<T> {
private:
  // atributos:
  struct No {
    T dado;
    No *prox;
  };

  int tamanho_maximo_da_lista;
  int tamanho_atual_da_lista;
  No *inicio_da_lista; // ponteiro para o inicio da lista
  No *final_da_lista;  // ponteiro para o final da lista

public:
  ListaLigada(int capacidade) : Lista<T>(capacidade) {
    // inicilização
    this->tamanho_atual_da_lista = 0; // tamanho atual comeca em 0, lista vazia
    this->tamanho_maximo_da_lista =
        capacidade; // usuario escolhe a capacidade maxima
    this->inicio_da_lista = nullptr;
  }
  ~ListaLigada() {
    while (inicio_da_lista != nullptr) {   // enquanto lista =/= null
      No *no_temporario = inicio_da_lista; // cria no_temporario recebendo
                                           // itens_da_lista (primeiro dado add)
      inicio_da_lista =
          inicio_da_lista->prox; // itens da lista aponta pro prox dado
      delete no_temporario;      // vai deletar esse primeiro dado armazenado no
                                 // no_temp junto com ele
    }
  }

  // append - add elemento no final da lista.
  void adiciona(const T &item) {

    if (tamanho_atual_da_lista == tamanho_maximo_da_lista) {
      throw "LISTA CHEIA";
    }

    No *no_temporario = new No();
    no_temporario->dado = item;
    no_temporario->prox = nullptr;

    if (inicio_da_lista == nullptr) {
      inicio_da_lista = final_da_lista =
          no_temporario; // se a lista estiver vazia adiciona o item em inicio e
                         // final
    } else {
      final_da_lista->prox = no_temporario; // se ja tiver algum elemento na
                                            // lista, adiciona no final
      final_da_lista = no_temporario;
    }
    tamanho_atual_da_lista++;
  }

  // retorna NÓ na posição IDX (começando de 1)
  T pega(int idx) {
    if (idx < 1 || idx > tamanho_atual_da_lista) {
      throw "INDICE INVALIDO";
    }
    // fazer TMP igual a INICIO
    No *ponteiro_do_item_atual = inicio_da_lista;
    // ENQUANTO (IDX não é zero)
    for (int i = 1; i < idx && ponteiro_do_item_atual->prox != nullptr; i++) {
      ponteiro_do_item_atual =
          ponteiro_do_item_atual->prox; // movendo pos ponteiro
    }                                   // fim do for

    return ponteiro_do_item_atual->dado;
  }

  // insert -> insere um item na posição indicada (a partir de 1).
  // e move elementos 1 posicao para direita
  void insere(int idx, const T &item) {
    if (idx < 1 || idx > tamanho_atual_da_lista) {
      throw "INDICE INVALIDO";
    }

    if (tamanho_atual_da_lista == tamanho_maximo_da_lista) {
      throw "LISTA CHEIA";
    }
    // alocar novo NÓ;
    No *no_temporario = new No();
    // se falhar -> “list overflow”

    // colocar dados em NÓ
    no_temporario->dado = item;
    no_temporario->prox = nullptr;
    // SE (IDX é 1) ENTÃO -- Primeiro elemento
    if (idx == 1) {
      no_temporario->prox = inicio_da_lista; // fazer NÓ->prox igual a INICIO
      inicio_da_lista = no_temporario;       // fazer INICIO apontar para NÓ

    } else { // SE IDX N FOR 1
      No *ponteiro_do_item_atual = inicio_da_lista;
      for (int i = 1; i < idx - 1 && ponteiro_do_item_atual->prox != nullptr;
           i++) {
        ponteiro_do_item_atual =
            ponteiro_do_item_atual->prox; // movendo pos ponteiro
      }                                   // fim do for
      no_temporario->prox =
          ponteiro_do_item_atual->prox; // o prox do novo elemento
                                        //é igual ao prox do elemento anterior
      ponteiro_do_item_atual->prox =
          no_temporario; // o prox do elemento anterior agora é igual ao novo
                         // elemento
    }
    tamanho_atual_da_lista++;
  }

  // remove da posição IDX e retorna dados
  void remove(int idx) {
    // verificar se índice é válido;
    // do contrário -> “índice inválido”
    if (idx < 1 || idx > tamanho_atual_da_lista) {
      throw "INDICE INVALIDO - COMEÇO";
    }
    if (inicio_da_lista == nullptr) {
      throw "LISTA VAZIA";
    }

    // SE idx == 1 ENTÃO -- Remover do começo
    if (idx == 1) {
      No *no_temporario = inicio_da_lista; // cria no_temporario recebendo
                                           // itens_da_lista (primeiro dado add)

      inicio_da_lista =
          inicio_da_lista->prox; // itens da lista aponta pro prox dado
      delete no_temporario;      // vai deletar esse primeiro dado armazenado no
                                 // no_temp junto com ele

    }

    else {
      No *ponteiro_do_item_atual = inicio_da_lista;
      for (int i = 1; i < idx - 1 && ponteiro_do_item_atual->prox != nullptr;
           i++) {
        ponteiro_do_item_atual =
            ponteiro_do_item_atual->prox; // movendo pos ponteiro
      }                                   // fim do for

      if (ponteiro_do_item_atual->prox == nullptr) {
        throw "INDICE INVALIDO - FINAL";
        return;
      } else {
        No *no_temporario = ponteiro_do_item_atual->prox;

        ponteiro_do_item_atual->prox = ponteiro_do_item_atual->prox->prox;

        delete no_temporario;
      }
    }

    tamanho_atual_da_lista--;
  }

  // exibe os itens da saida padrão separados por espaços
  void exibe() {
    No *ponteiro_do_item_atual = inicio_da_lista;

    while (ponteiro_do_item_atual != nullptr) { // começo while
      cout << ponteiro_do_item_atual->dado << " ";
      ponteiro_do_item_atual = ponteiro_do_item_atual->prox;
    }

    cout << endl;
  }

  int tamanho() { return tamanho_atual_da_lista; }
};