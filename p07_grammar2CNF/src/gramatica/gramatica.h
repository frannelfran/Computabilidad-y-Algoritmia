#ifndef GRAMATICA_H
#define GRAMATICA_H

#include "../alfabeto/alfabeto.h"
#include "../produccion/produccion.h"


class Gramatica {
  public:
    // Constructor y destructor
    Gramatica() = default;
    Gramatica(const Alfabeto& alf, const set<Simbolo>& noTerminales, const vector<vector<Produccion>>& prods);
    ~Gramatica() = default;

    // Métodos
    inline void agregarProduccion(const Produccion& produccion) { producciones_.push_back(produccion); }

    // Getters
    inline vector<Produccion>& getProducciones() { return producciones_; }
    inline const vector<Produccion>& getProducciones() const { return producciones_; }
    inline set<Simbolo> getSimbolosNoTerminales() const { return simbolosNoTerminales_; }

    // Setters
    inline void setSimboloNoTerminal(const Simbolo& simbolo) { simbolosNoTerminales_.insert(simbolo); }

    // Sobrecarga de operadores
    friend ostream& operator<<(ostream& os, const Gramatica& gramatica);

  private:
    Alfabeto alfabeto_;
    set<Simbolo> simbolosNoTerminales_;
    vector<Produccion> producciones_;
};

#endif // GRAMATICA_H