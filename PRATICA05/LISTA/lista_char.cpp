#include "lista_ligada.h"
#include <iostream>
using namespace std;

int mainLL() {
  ListaLigada<char> lista(10);

  lista.adiciona('a'); // a
  lista.adiciona('b'); // a b
  lista.adiciona('c'); // a b c
  lista.adiciona('d'); // a b c d
  lista.adiciona('e'); // a b c d e
  lista.exibe();       // a b c d e (saida)

  lista.remove(3); // a b d e
  lista.exibe();   // a b d e (saida)

  lista.pega(4);        // e
  lista.insere(2, 'f'); // a f b d e
  lista.exibe();        // a f b d e (saida)

  lista.adiciona('g');  // a f b d e g
  lista.insere(4, 'h'); // a f b h d e g
  lista.pega(2);        // f
  lista.exibe();        // a f b h d e g (saida)

  return 0;
}
