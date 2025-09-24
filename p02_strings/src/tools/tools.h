// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y Lenguajes
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 24/09/2025
// Archivo: tools.h
// Descripción: Funciones para manejar los argumentos y ficheros

#pragma once
#include "../cadena/cadena.h"
#include "../alfabeto/alfabeto.h"
#include <fstream> // Para los ficheros
#include <vector>
#include <stdexcept> // Para las excepciones

using namespace std;


struct Tools {
  string filein;  // Fichero de entrada
  string fileout; // Fichero de salida
  int opcode;     // Operación a realizar
};

Tools parseArgs(int argc, char* argv[]); // Parsea los argumentos de la línea de comandos
vector<Cadena> readFile(const string& fileName); // Lee el fichero de entrada y devuelve un vector de Cadenas
void printHelp();                      // Imprime la ayuda
bool perteneceAlfabeto(const string& cadena, const string& alfabeto); // Comprueba si una cadena pertenece a un alfabeto
void mostrarMenu();              // Muestra el menú de opciones