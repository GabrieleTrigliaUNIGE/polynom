#include "CPolinomio.h"

// Costruttore
Polinomio::Polinomio(const double* coefficients, size_t size) {
    grado = size - 1;
    coeff = new double[size];
    std::memcpy(coeff, coefficients, size * sizeof(double));
}

// Costruttore di copia
Polinomio::Polinomio(const Polinomio& altro) {
    grado = altro.grado;
    coeff = new double[grado + 1];
    std::memcpy(coeff, altro.coeff, (grado + 1) * sizeof(double));
}

// Distruttore
Polinomio::~Polinomio() {
    delete[] coeff;
}

// Operatore di assegnazione
Polinomio& Polinomio::operator=(const Polinomio& altro) {
    if (this != &altro) {
        delete[] coeff;
        grado = altro.grado;
        coeff = new double[grado + 1];
        std::memcpy(coeff, altro.coeff, (grado + 1) * sizeof(double));
    }
    return *this;
}

// Valutazione del polinomio dato un valore di x
double Polinomio::valuta(double x) const {
    double risultato = 0.0;
    for (size_t i = 0; i <= grado; ++i) {
        risultato += coeff[i] * std::pow(x, i);
    }
    return risultato;
}

// Somma di due polinomi
Polinomio Polinomio::operator+(const Polinomio& altro) const {
    size_t maxSize = std::max(grado, altro.grado) + 1;
    double* nuovoCoeff = new double[maxSize]{};
    
    for (size_t i = 0; i <= grado; ++i) {
        nuovoCoeff[i] += coeff[i];
    }
    
    for (size_t i = 0; i <= altro.grado; ++i) {
        nuovoCoeff[i] += altro.coeff[i];
    }
    
    return Polinomio(nuovoCoeff, maxSize);
}

// Derivata del polinomio
Polinomio Polinomio::derivata() const {
    if (grado == 0) {
        double zero = 0;
        return Polinomio(&zero, 1);
    }

    double* derivCoeffs = new double[grado];
    for (size_t i = 1; i <= grado; ++i) {
        derivCoeffs[i - 1] = coeff[i] * i;
    }
    
    return Polinomio(derivCoeffs, grado);
}

// Stampa del polinomio
void Polinomio::stampa() const {
    for (size_t i = 0; i <= grado; ++i) {
        if (coeff[i] != 0) {
            std::cout << (coeff[i] > 0 && i > 0 ? " + " : "") << coeff[i];
            if (i > 0) {
                std::cout << "x";
                if (i > 1) {
                    std::cout << "^" << i;
                }
            }
        }
    }
    std::cout << std::endl;
}


