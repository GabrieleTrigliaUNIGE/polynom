#include <iostream>
#include <cmath>
#include <cstring>

class Polinomio {
private:
    double* coeff;
    size_t grado;

public:
    // Costruttore
    Polinomio(const double* coefficients, size_t size);

    // Costruttore di copia
    Polinomio(const Polinomio& altro);

    // Distruttore
    ~Polinomio();

    // Overload operatori
    Polinomio& operator=(const Polinomio& altro);
    Polinomio operator+(const Polinomio& altro) const;
    //Polinomio operator==(const Polinomio& altro) const;

    // Valutazione del polinomio dato un valore di x
    double valuta(double x) const;

    // Derivata del polinomio
    Polinomio derivata() const;

    // Stampa del polinomio
    void stampa() const;
};
