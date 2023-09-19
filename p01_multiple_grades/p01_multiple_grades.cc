#include "p01_multiple_grades.h"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 17/09/2023
// Archivo p01_single_grades.cc
// Definición: Implementación de la clase Califications

Califications::Califications(ifstream& archivo) {
  std::string alumno;
	double nota;
	while (archivo >> alumno >> nota) {
		lista_.insert(std::make_pair(alumno, nota)); // Almacenamiento de la nota de cada alumno
	}
	archivo.close(); // Cerrar el fichero
}

void Califications::write() {
  for(const auto& pair : lista_) {
    cout << pair.first << " " << pair.second << endl;
  }
}

