#include "arranjo.h"

class Aluno {
private:
  string nome;
  string matricula;

public:
  Aluno() {}
  Aluno(const char *nome, const char *matricula) : nome(nome), matricula(matricula) {}
  friend class Arranjo<Aluno>; //aqui aluno nao faz parte de arranjo mas pode acessar seus metodos e atributos privadoss.
};

template<>
void Arranjo<Aluno>::set(int idx, const Aluno & aluno) {
// atribua nome e mat individualmente para o item do array
// isto é, pegue o aluno no array, e atribua cada campo um a um
  this->items[idx] = aluno;

}
template<>
void Arranjo<Aluno>::exibir() {
// exiba cada aluno do array no formato "idx : matricula = nome"
  for (int i = 0; i < this->tamanho; i++) {
    cout << i << ": " << this->items[i].matricula << " = " << this->items[i].nome << endl;
  }
}