#include <iostream>
#include "CPolynomial.h"
#include "CTrapezoidal.h"

int main() {
    // 1) Definisco i coefficienti del polinomio f(x) = x^2 + 2x + 1
    //    coeffs[0] = termine costante (1)
    //    coeffs[1] = coefficiente di x      (2)
    //    coeffs[2] = coefficiente di x^2    (1)
    double coeffs[] = { 1.0, 2.0, 1.0 };
    int size = sizeof(coeffs) / sizeof(coeffs[0]);

    // 2) Costruisco l'oggetto Polynomial e gli passo i coefficienti
    Polynomial poly;
    poly.SetPolynomial(coeffs, size);

    // 3) Stampo il polinomio a video
    std::cout << "Polinomio: ";
    poly.Dump();

    // 4) Creo l'integratore trapezoidale sul polinomio
    Trapezoidal integrator(&poly);

    // 5) Definisco estremi e numero di intervalli
    double inf       = 0.0;
    double sup       = 1.0;
    int    intervals = 100;  // numero di trapezi

    // 6) Calcolo l'integrale e stampo il risultato
    double result = integrator.GetIntegral(inf, sup, intervals);
    std::cout << "Integrale di f(x) da " << inf
              << " a " << sup
              << " con " << intervals << " intervalli: "
              << result << std::endl;

    return 0;
}
