\
#ifndef FUNCS_H
#define FUNCS_H

// f1: incrementa en 1 (sin argumentos extra)
template <typename T>
void f1(T &n) {
    n++;
}

// f2: incrementa en p1 (1 argumento extra)
template <typename T>
void f2(T &n, int p1) {
    n += p1;
}

// f3: operación con múltiples argumentos extra
template <typename T>
void f3(T &n, int a, int b, int c, int d) {
    n = n * a + b - c + d;
}

#endif
