#include <cstring>

template <class temp>
void trocar(
    temp &a,
    temp &b) { /* troca valores de a e b entre si, passagem por referencia */

  temp var_tempo = a;
  a = b;
  b = var_tempo;
}

// < 0 = a < b

// 0 > - a > b

// 0 = a e b são iguais

template <class temp>
temp maximo(temp a, temp b) { /* retorna maior entre a e b */

  char resultado = strcmp(a, b);

  if (resultado > 0) {
    return a;
  } else if (resultado == 0) {
    return a;
  }

  else {
    return b;
  }
}
template <class temp>
temp minimo(temp a, temp b) { /* retorna menor entre a e b */

  char resultado = strcmp(a, b);

  if (resultado > 0) {
    return b;
  } else if (resultado == 0) {
    return a;
  }

  else {
    return a;
  }
}