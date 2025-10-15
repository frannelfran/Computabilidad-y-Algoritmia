#pragma once
#include "../alfabeto/alfabeto.h"
#include "../transicion/transicion.h" // Incluir primero Transicion
#include "../estado/estado.h"         // Luego Estado
#include <fstream> // Para manejo de archivos
#include <stdexcept> // Para las excepciones
#include <sstream> // Para istringstream

#ifndef TOOLS_H
#define TOOLS_H

/**
 * @struct Tools
 * @brief Estructura para almacenar los datos del fichero de entrada
 */
struct Tools {
  Alfabeto alfabeto;
  set<Estado*> estados;
  string ficheroCadenas; // Fichero de cadenas de entrada
};

Tools leerFichero(const string& nombreFichero); // Leo el fichero para obtener los datos
Tools readData(int argc, char* argv[]); // Leo los datos de la línea de comandos
void leerAlfabeto(istringstream is); // Leo el alfabeto del fichero
void leerTransiciones(istringstream is); // Leo las transiciones del fichero
void comprobarEstado(const int& estado); // Compruebo que el estado es válido
void comprobarSimboloEntrada(const char& simbolo); // Compruebo que el símbolo pertenece al alfabeto de entrada (Σ)
void crearEstados(const int& numEstados); // Creo los estados del autómata
Estado* buscarEstado(const int& estado); // Buscar un estado en el conjunto de estados
void printHelp(); // Imprimir la ayuda del programa
bool esDfa(const set<Estado*>& estados); // Compruebo si el autómata es un DFA

#endif // TOOLS_H