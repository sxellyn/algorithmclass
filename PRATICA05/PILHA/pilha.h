#include <iostream>
using namespace std;

template <class T> class Pilha {
public:
  Pilha(int capacidade) {}
  virtual ~Pilha() {}

  virtual void empilha(T value) {};

  virtual T desempilha() { return 0; };

  virtual int tamanho() { return 0; };
};