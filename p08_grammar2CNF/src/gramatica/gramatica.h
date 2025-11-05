// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica x:
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 05/11/2025
// Archivo: gramatica.h
// Descripción: Declaración de la clase Gramatica

#ifndef GRAMATICA_H
#define GRAMATICA_H

#include "../alfabeto/alfabeto.h"
#include "../produccion/produccion.h"
#include "algorithm" // Para std::find

class Gramatica {
  public:
    // Constructor y destructor
    Gramatica() = default;
    Gramatica(const Alfabeto& alf, const set<Simbolo>& noTerminales, const vector<vector<Produccion>>& prods);
    ~Gramatica() = default;

    // Métodos
    void agregarProduccion(const Produccion& produccion);
    void modificarAlternativa(const Produccion& nuevaProduccion);

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