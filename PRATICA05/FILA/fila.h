#include <iostream>
using namespace std;

template <class T> class Fila {
public:
  Fila(int capacidade) {}

  virtual ~Fila() {}

  virtual void enfileira(const T &elemento) {};

  virtual T desenfileira() { return 0; };

  virtual int vazia() { return 0; };

  virtual int cheia() { return 0; };

  virtual int tamanho() { return 0; };
};