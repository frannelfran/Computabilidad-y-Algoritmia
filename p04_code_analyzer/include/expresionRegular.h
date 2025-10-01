#pragma once
#include <regex>
#include <string>

using namespace std;

/**
 * @struct Struct que contiene las expresiones regulares utilizadas en el analizador.
 */
struct ExpresionRegular {
  // Expresión para las variables
  regex variableSinInicializar = regex(R"(^\s*(int|double)\s+([a-zA-Z_]\w*)\s*;)");
  regex variableInicializada = regex(R"(^\s*(int|double)\s+([a-zA-Z_]\w*)\s*=\s*([^;]+)\s*;)");
  // Expresion para los bucles
  regex bucle = regex(R"(^\s*(for|while)\s*\([^)]*\)\s*\{?)");
  // Expresion para el main
  regex main = regex(R"(^\s*int\s+main\s*\([^)]*\)\s*\{?)");

  // Comentarios
  regex comentarioSimple = regex(R"(^\s*//.*)");
  regex inicioComentarioMultilinea = regex(R"(^\s*/\*.*)");
  regex finComentarioMultilinea = regex(R"(.*\*/)");
};