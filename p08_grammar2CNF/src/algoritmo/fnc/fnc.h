// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica x:
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 05/11/2025
// Archivo: fnc.h
// Descripción: Declaración de la clase FNC para convertir gramáticas a Forma Normal de Chomsky

#ifndef FNC_H
#define FNC_H

#include "../algoritmo.h"

class FNC : public Algoritmo {
  public:
    Gramatica ejecutar(const Gramatica& gramatica) override;

  private:
    void sustituirTerminalesEnProducciones(Gramatica& gramatica);
    void reducirProduccionesLargas(Gramatica& gramatica);
};

#endif // FNC_H