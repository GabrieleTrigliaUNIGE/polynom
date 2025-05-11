#ifndef CTRAPEZOIDAL_H
#define CTRAPEZOIDAL_H

#include "CIntegral.h"

/// @brief Classe per il calcolo numerico dell’integrale tramite regola del trapezio
class Trapezoidal : public Integral {
public:

    Trapezoidal();
    /// @brief Costruttore: accetta opzionalmente un puntatore a Polynomial
    Trapezoidal(Polynomial* p);

    /// @brief Distruttore
    ~Trapezoidal();

    Trapezoidal& operator=(Trapezoidal& t);

    /**
     * @brief Calcola l’integrale definito su [inf, sup] usando la regola del trapezio
     * @param inf     Estremo inferiore dell’intervallo
     * @param sup     Estremo superiore dell’intervallo
     * @param intervals Numero di suddivisioni (trapezi)
     * @return Valore numerico dell’integrale
     */
    double GetIntegral(double inf, double sup, int intervals);
};

#endif // CTRAPEZOIDAL_H
