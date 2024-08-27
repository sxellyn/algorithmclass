#include <iostream> // cout
#include <stdlib.h> // rand()

#include <chrono>
#include <thread>
#define PAUSA(tempo)                                                           \
  std::this_thread::sleep_for(std::chrono::milliseconds(tempo * 1000));

//#include "fila_array.h"
#include "fila_ligada.h"

using namespace std;

int mainI() {
  FilaLigada<int> impressora(10);
  int i = 0;
  while (1) {
    // 70% de chance do usuario mandar imprimir um documento
    if ((rand() % 100) < 70) {
      if (!impressora.cheia()) {
        cout << "Adicionado documento " << ++i << endl;
        impressora.enfileira(i);
      }
    }

    cout << "Status: " << impressora.tamanho() << " item(s) na fila" << endl;

    // 30% de chance da impressora imprimir um documento
    if ((rand() % 100) < 30) {
      if (!impressora.vazia()) {
        cout << "Imprimindo documento " << impressora.desenfileira() << endl;
      }
    }

    PAUSA(1);
  }

  return 0;
}
