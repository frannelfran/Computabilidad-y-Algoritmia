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

  // Reduzco las producciones largas del estilo A -> BCD... a producciones binarias
  reducirProduccionesLargas(nuevaGramatica);

  return nuevaGramatica;
}

/**
 * @brief Sustituye los terminales en las producciones de la gramática.
 * @param gramatica La gramática a modificar.
 * @return void
 */
void FNC::sustituirTerminalesEnProducciones(Gramatica& gramatica) {
  vector<Produccion> produccionesOriginales = gramatica.getProducciones();
  // Para cada producción de la gramática
  for (auto& produccion : produccionesOriginales) {
    if (produccion.getSimbolosDerecha()[0].size() >= 2) {
      // Recorro cada alternativa de la producción
      for (auto& alternativa : produccion.getSimbolosDerecha()) {
        // Recorro cada símbolo en la alternativa
        for (auto& simbolo : alternativa) {
          // Si el símbolo es terminal y la produccion es del estilo A -> aB o A -> Ba
          if ((simbolo.esTerminal() && !next(&simbolo)->esTerminal() || simbolo.esTerminal() && next(&simbolo)->esTerminal()) && alternativa.size() >= 2) {
            // Crear un nuevo símbolo no terminal para el terminal
            Simbolo nuevoNoTerminal("X_" + simbolo.getNombre(), false);
            // Agregar la nueva producción al alfabeto de la gramática
            Produccion nuevaProduccion(nuevoNoTerminal);
            nuevaProduccion.agregarAlternativa({simbolo});
            // Reemplazar el terminal en la alternativa por el nuevo no terminal
            simbolo = nuevoNoTerminal;
            // Agrego el simbolo no terminal a la lista de no terminales
            gramatica.setSimboloNoTerminal(nuevoNoTerminal);

            // Agrego la nueva producción a la gramática
            gramatica.agregarProduccion(nuevaProduccion);
          }
        }
      }
    }
  }

  // Sustituyo las producciones modificadas en la grmática
  for (auto& produccionModificada : produccionesOriginales) {
    gramatica.modificarAlternativa(produccionModificada);
  }
}

/**
 * @brief Reduce las producciones largas (más de 2 símbolos) a producciones binarias.
 * @param gramatica La gramática a modificar.
 */
void FNC::reducirProduccionesLargas(Gramatica& gramatica) {
  int contador = 0;
  vector<Produccion> produccionesOriginales = gramatica.getProducciones();
  // Recorremos las producciones por índice (para evitar invalidar el iterador)
  for (auto& produccion : produccionesOriginales) {
    for (auto& alternativa : produccion.getSimbolosDerecha()) {
      // Mientras la producción tenga más de 2 símbolos, dividirla
      while (alternativa.size() > 2) {
        // Crear nuevo no terminal con nombre único
        string nombreNuevo = "Y_" + std::to_string(contador++);
        Simbolo nuevoNoTerminal(nombreNuevo, false);

        // Crear nueva producción: Y_i → X2 X3
        vector<Simbolo> nuevaAlternativa = {
          alternativa[1], alternativa[2]
        };
        Produccion nuevaProduccion(nuevoNoTerminal);
        nuevaProduccion.agregarAlternativa(nuevaAlternativa);

        // Registrar el nuevo no terminal y su producción directamente
        gramatica.setSimboloNoTerminal(nuevoNoTerminal);
        gramatica.agregarProduccion(nuevaProduccion);

        // Modificar la alternativa original:
        // A → X1 X2 X3 ...  →  A → X1 Y_i ...
        alternativa.erase(alternativa.begin() + 1, alternativa.begin() + 3);
        alternativa.insert(alternativa.begin() + 1, nuevoNoTerminal);
      }
    }
  }

  // Sustituyo las producciones modificadas en la gramática
  for (auto& produccionModificada : produccionesOriginales) {
    gramatica.modificarAlternativa(produccionModificada);
  }
}

