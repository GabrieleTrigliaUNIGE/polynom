#include "CTrapezoidal.h"

// Default constructor
Trapezoidal::Trapezoidal(){}

// Constructor with polynomial pointer
Trapezoidal::Trapezoidal(Polynomial* p) : Integral(p) {}

//TODO: copy constructor

// Destructor
Trapezoidal::~Trapezoidal() {}

// Overload operator= 
Trapezoidal& Trapezoidal::operator=(Trapezoidal& other) {
    if (this != &other) {
        // 1) cancello il polinomio attuale (se esiste)
        if (poly) {
            delete poly;
            poly = nullptr;
        }
        // 2) clono quello di 'other'
        if (other.poly) {
            poly = new Polynomial(*other.poly);
        }
        // (non ci sono altri membri di CTrapezoidal da copiare)
    }
    return *this;
}

// Implements the trapezoidal rule to approximate the integral
// of the polynomial from inf to sup using the specified number of intervals.
double Trapezoidal::GetIntegral(double inf, double sup, int intervals) {
    // 1) Calcolo la larghezza di ciascun trapezio
    double h = (sup - inf) / intervals;

    // 2) Valuto la funzione agli estremi
    double f_inf = poly->GetValue(inf);   // f(a)
    double f_sup = poly->GetValue(sup);   // f(b)

    // 3) Somma semiponderata degli estremi:
    //    (f(a) + f(b)) / 2
    double endpointContribution = 0.5 * (f_inf + f_sup);

    // 4) Somma dei nodi intermedi
    double intermediateSum = 0.0;
    for (int i = 1; i < intervals; ++i) {
        double x_i = inf + i * h;            // posizione del nodo
        double f_xi = poly->GetValue(x_i);  // f(x_i)
        intermediateSum += f_xi;
    }

    // 5) Somma totale dei contributi
    double total = endpointContribution + intermediateSum;

    // 6) Moltiplico per h per ottenere l’area finale
    double integral = total * h;
    return integral;
}
