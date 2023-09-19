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
    lista_[alumno].push_back(nota);
	}
	archivo.close(); // Cerrar el fichero
}

void Califications::write() {
    for(std::map<string, vector<double> >::iterator i; i != lista_.end(); i++) {
      cout << i->first << " ";
      for(double nota : i->second) {
        cout << nota << endl;
      }
    }
  }




