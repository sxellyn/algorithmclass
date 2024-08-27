#include <iostream>
using namespace std;

class IndiceInvalido {
public:
  IndiceInvalido() { throw "indice ultrapassa tamanho do array"; }
};

template <class T> class Arranjo {

private:
  int tamanho; // tamanho do arranjo
  T *items;    // items do arranjo

public:
  Arranjo(int tam) {
    // instanciar o array de items com new (pratica 1) e setar tamanho;
    this->tamanho = tam;
    this->items = new T[tam];
  }

  virtual ~Arranjo() {
    // destruir o array de items (prática 1);
    delete[] this->items;
  }

  virtual T get(int idx) {
    // retornar um item do array a partir do indice;
    if (idx > tamanho - 1) {
      IndiceInvalido();
    }
      return this->items[idx];
  }

  virtual void set(int idx, const T &item) {
    // set o item do array apontado pelo indice usando =
    if (idx > tamanho - 1) {
      IndiceInvalido();
    }
    this->items[idx] = item;
  }

  virtual void exibir();
};

template <class T> void Arranjo<T>::exibir() {
  // exibir cada item numa linha da forma "<idx>: <item>"
  for (int i = 0; i < this->tamanho; i++) {
    cout << i << ": " << this->items[i] << endl;
  }
}