#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 17/09/2023
// Archivo p01_multiple_grades.h
// Definición: Definición de la clase Califications

class Califications {

public:
	Califications(ifstream&); // Constructor de la clase
	void add(string, double); // Agregar un alumno
	void ordenar(); // Ordenar las notas de los estudiantes de mayor a menor
	void write();	// Imprimir por pantalla la lista

private:
	map<std::string, vector<double> > lista_; // Atributo privado de la clase
};