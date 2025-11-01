#include "fnc.h"

/**
 * @brief Convierte una gramática a su forma normal de Chomsky (FNC).
 * @param gramatica La gramática de entrada.
 * @return La gramática convertida a FNC.
 */
Gramatica FNC::ejecutar(const Gramatica& gramatica) {
  Gramatica nuevaGramatica = gramatica;
  // Sustituyo los terminales en las producciones del estilo A -> aB o A -> Ba
  sustituirTerminalesEnProducciones(nuevaGramatica);
  
}