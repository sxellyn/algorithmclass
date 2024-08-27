#include <iostream>
using namespace std;

template <class T> class Lista {
public:
  Lista(int capacidade) {}

  virtual ~Lista() {}

  virtual void adiciona(const T &item){};

  virtual T pega(int idx) { return 0; };

  virtual void insere(int idx, const T &item){};

  virtual void remove(int idx) { return; };

  virtual void exibe() { return; };

  virtual int tamanho() { return 0; };
};