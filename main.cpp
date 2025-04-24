#include <iostream>
#include "CPolinomio.h"

int main() {
    // Polinomio p(x) = 1 + 2x + 3x^2
    double coeff1[] = {1.0, 2.0, 3.0};
    Polinomio p(coeff1, 3);
    std::cout << "P(x) = ";
    p.stampa();

    // Valutazione in x = 2
    double x = 2.0;
    std::cout << "P(" << x << ") = " << p.valuta(x) << std::endl;

    // Polinomio q(x) = -1 + 0x + 4x^2 + 5x^3
    double coeff2[] = {-1.0, 0.0, 4.0, 5.0};
    Polinomio q(coeff2, 4);
    std::cout << "Q(x) = ";
    q.stampa();

    // Somma r(x) = p(x) + q(x)
    Polinomio r = p + q;
    std::cout << "R(x) = P(x) + Q(x) = ";
    r.stampa();

    // Derivata di p e q
    Polinomio dp = p.derivata();
    Polinomio dq = q.derivata();
    std::cout << "P'(x) = ";
    dp.stampa();
    std::cout << "Q'(x) = ";
    dq.stampa();

    return 0;
}