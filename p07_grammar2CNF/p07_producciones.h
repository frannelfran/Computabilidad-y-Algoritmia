#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "p07_alfabeto.h"
#include "p07_no_terminales.h"
#pragma once

using namespace std;

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Gramáticas en Forma Normal de Chomsky
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 31/10/2023
// Archivo: p07_producciones.h
// Descripción: Declaración de la clase Producciones

class Producciones {
  public:
  Producciones(); // Constructor por defecto
  Producciones(ifstream&, Alfabeto, NoTerminales); // Constructor de la clase
  void ModificarProducciones(); // Modificar las producciones (1er paso del algoritmo)
  void DividirProducciones(); // Dividir las producciones de la gramática (2do paso del algortimo)
  void AgregarProduccion(char, const string&); // Agregar producciones
  friend ostream& operator<<(ostream& os, Producciones& prod); // Sobrecarga del operador de salida
  private:
  Alfabeto alfabeto_;
  NoTerminales no_terminales_;
  map<char, set<string>> producciones_;
};