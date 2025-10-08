// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 08/10/2025
// Archivo: variable.h
// Descripción: Clase para representar las variables del programa.

#pragma once
#include <string>
#include <stdexcept>

using namespace std;

/**
 * @class Clase para representar las variables del programa.
*/
class Variable {
  public:
    // Constructor y destructor
    Variable(const string& tipo, const int& linea, const string& nombre, bool inicializada = false) : tipo_(tipo), linea_(linea), nombre_(nombre), inicializada_(inicializada) {}
    ~Variable() = default;

    // Getters
    inline virtual double getValor() const { throw runtime_error("La variable no está inicializada"); }
    inline int getLinea() const { return linea_; }
    inline string getTipo() const { return tipo_; }
    inline string getNombre() const { return nombre_; }
    inline bool inicializada() const { return inicializada_; }

  protected:
    string tipo_;   // Tipo de la variable (int o double)
    int linea_;     // Línea en la que se declara la variable
    string nombre_; // Nombre de la variable
    bool inicializada_; // Indica si la variable ha sido inicializada
};

/**
 * @class Clase que representa las variables inicializadas
 */
class VariableInicializada : public Variable {
  public:
    // Constructor y destructor
    VariableInicializada() = default;
    VariableInicializada(const string& tipo, const int& linea, const string& nombre, const double& valor) : Variable(tipo, linea, nombre, true), valor_(valor) {}
    ~VariableInicializada() = default;

    inline double getValor() const override { return valor_; }

  private:
    double valor_; // Valor de la variable
};
