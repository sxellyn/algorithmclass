#include <iostream>

using namespace std;

class ListaOrdenada {
private:
  int *items;
  int tamanho, capacidade;

  int buscaBinariaPrivate(int inicio, int final, int item) {
    // Se INICIO > FINAL, não achou, retorna -1
    if (inicio > final) {
      return -1;
    }

    // Fazer MEIO = (INICIO + FINAL) / 2
    int meio = (inicio + final) / 2;

    // Se items[MEIO] igual a ITEM, retorna MEIO
    if (items[meio] == item) {
      return meio;
    }

    // Se items[MEIO] maior que ITEM
    if (items[meio] > item) {
      // Retorna busca binária na metade esquerda
      return buscaBinariaPrivate(inicio, meio - 1, item);
    } else {
      // Retorna busca binária na metade direita
      return buscaBinariaPrivate(meio + 1, final, item);
    }
  }

public:
  ListaOrdenada(int cap) {
    this->capacidade = cap;
    this->tamanho = 0;
    items = new int[cap];
  }

  ~ListaOrdenada() { delete[] items; }

  // Função para inserir um item na lista ordenada
  void insere(int item) {
    if (tamanho >= capacidade) {
      cout << "Lista cheia. Não é possível inserir o item." << endl;
      return;
    }

    // Encontra a posição correta para inserir o item
    int i;
    for (i = tamanho - 1; (i >= 0 && items[i] > item); i--) {
      items[i + 1] = items[i];
    }

    // Insere o item na posição correta
    items[i + 1] = item;
    tamanho++;
  }

  // Função para remover um item da lista
  void remove(int item) {
    int pos = buscaSequencial(item);
    if (pos == -1) {
      throw "Item nao encontrado";
    }

    // Move todos os elementos após o item para a esquerda
    for (int i = pos; i < tamanho - 1; i++) {
      items[i] = items[i + 1];
    }

    tamanho--;
  }

  // Função para buscar um item na lista usando busca sequencial
  int buscaSequencial(int key) {
    for (int i = 0; i < tamanho; i++) {
      if (items[i] == key) {
        return i; // Retorna o índice onde o item foi encontrado
      }
    }
    return -1; // Retorna -1 se o item não for encontrado
  }

  int valida() {
    for (int i = 0; i < tamanho - 1; i++) {
      if (items[i] > items[i + 1])
        return 0;
    }
    return 1;
  }

  void exibe() {
    for (int i = 0; i < tamanho; i++) {
      cout << i << ": " << items[i] << "; ";
    }
    cout << endl;
  }

  int getTamanho() { return tamanho; }

  int buscaBinaria(int item) {
    return buscaBinariaPrivate(0, tamanho - 1, item);
  }
};

int mainORDENADAAAAAAAAAAAAAAA() {

  ListaOrdenada lista(10);

  int elementos[] = {10, 5, 25, 1, 64, 13, 50, 99, 33, 12};

  cout << "Testando inserao ..." << endl;
  for (int i = 0; i < 10; i++) {
    lista.insere(elementos[i]);
  }

  cout << "Lista: ";
  lista.exibe();

  if (lista.getTamanho() == 10) {
    cout << "Tamanho OK." << endl;
  } else {
    cout << "ERRO: Tamanho errado (!= 10): " << lista.getTamanho() << endl;
    exit(1);
  }

  if (lista.valida()) {
    cout << "Lista esta ordenada." << endl;
  } else {
    cout << "ERRO: Lista nao esta ordenada." << endl;
    exit(1);
  }

  cout << endl << "Testando remocao..." << endl;
  try {
    lista.remove(5);
    lista.remove(50);
    lista.remove(33);
    lista.remove(-100); // erro
    cout << "ERRO: Exceçao nao lancada na remoco. Abortando." << endl;
    exit(1);
  } catch (...) {
    cout << "Excecao lancada na remocao." << endl;
  }

  cout << "Lista: ";
  lista.exibe();

  if (lista.getTamanho() == 7) {
    cout << "Tamanho OK." << endl;
  } else {
    cout << "ERRO: Tamanho errado (!= 7): " << lista.getTamanho() << endl;
    exit(1);
  }

  if (lista.valida()) {
    cout << "Lista esta ordenada." << endl;
  } else {
    cout << "ERRO: Lista nao esta ordenada." << endl;
    exit(1);
  }

  cout << endl << "Testando buscas..." << endl;

  cout << "- Itens presentes: ";

  int bs10 = lista.buscaSequencial(10);
  int bb10 = lista.buscaBinaria(10);

  int bs25 = lista.buscaSequencial(25);
  int bb25 = lista.buscaBinaria(25);

  if ((bs10 == 1) && (bb10 == 1) && (bs25 == 4) && (bb25 == 4)) {
    cout << "OK" << endl;
  } else {
    cout << "ERRO" << endl;
    exit(1);
  }

  cout << "- Itens ausentes: ";

  int bs20 = lista.buscaSequencial(20);
  int bb20 = lista.buscaBinaria(20);

  int bs77 = lista.buscaSequencial(77);
  int bb77 = lista.buscaBinaria(77);

  if ((bs20 == -1) && (bb20 == -1) && (bs77 == -1) && (bb77 == -1)) {
    cout << "OK" << endl;
  } else {
    cout << "ERRO" << endl;
    exit(1);
  }

  cout << "- Itens removidos: ";

  int bs5 = lista.buscaSequencial(5);
  int bb5 = lista.buscaBinaria(5);

  int bs33 = lista.buscaSequencial(33);
  int bb33 = lista.buscaBinaria(33);

  if ((bs5 == -1) && (bb5 == -1) && (bs33 == -1) && (bb33 == -1)) {
    cout << "OK" << endl;
  } else {
    cout << "ERRO" << endl;
    exit(1);
  }

  return 0;
}
