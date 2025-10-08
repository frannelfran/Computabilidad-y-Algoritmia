// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 08/10/2025
// Archivo: tools.h
// Descripción: Herramientas para el manejo de argumentos de la línea de comandos.

#pragma once
#include <iostream>
#include <stdexcept> // Para las excepciones

using namespace std;

/**
 * @struct Struct para almacenar los argumentos de la línea de comandos
 */
struct Tools {
  string filein;  // Fichero de entrada
  string fileout; // Fichero de salida
};

Tools parseArgs(int argc, char* argv[]); // Parsea los argumentos de la línea de comandos
void printHelp();                       // Imprime la ayuda