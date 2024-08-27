#include "funcoes.h"
#include "aluno.h"
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  float x = 5.5, y = 10.15, z = 30.7;
  cout << z << endl; // z n esta sendo usado e precisava do print para passar
  cout << endl; // espaço pra ficar bonito

  cout << "Antes: x = " << x << " y = " << y << endl;
  trocar(x, y);
  cout << "Depois : x = " << x << " y = " << y << endl;

  //cout << "Minimo entre " << x << " e " << y << ": " << minimo(x, y) << endl;
  //cout << "Maximo entre " << y << " e " << z << ": " << maximo(y, z) << endl;

  char strA[] = "bananas";
  char strB[] = "applesandbananas";

  // < 0 = a < b

  // 0 > - a > b

  //0 = a e b são iguais
  
  cout << endl; // espaço pra ficar bonito

  cout << "Minimo de \"strA\" e \"strB\": " << minimo(strA, strB) << endl;
  cout << "Maximo de \"strA\" e \"strB\": " << maximo(strA, strB) << endl;

  Arranjo<int> arr(10);

  arr.set(4, 5);
  arr.set(7, 15);
  arr.set(8, 22);
  arr.exibir();

  cout << endl; // espaço pra ficar bonito

  Arranjo<float> arra(5);
  arra.set(1, 6.7);
  arra.set(2, 23.4);
  arra.set(3, 20.4);
  arra.exibir();
  
  cout << endl; // espaço pra ficar bonito

  try {
    arra.get(6); //pegar o tamanho, nao o index
    cout << "o elemento que esta sendo testado eh: " << arra.get(6) << endl;

  } catch (const char *e) {
    cout << "indice invalido" << endl;
  }
  
  cout << endl; // espaço pra ficar bonito
  
  Arranjo<Aluno> turma(3);
  turma.set(0, Aluno("Joao","1234"));
  turma.set(1, Aluno("Maria","5235"));
  turma.set(2, Aluno("Jose","2412"));
  turma.exibir();
}