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
// Archivo p01_multiple_grades.cc
// Definición: Implementación de la clase Califications

Califications::Califications(ifstream& archivo) { // Constructor de la clase
  std::string alumno;
	double nota;
	while (archivo >> alumno >> nota) {
    lista_[alumno].push_back(nota);
	}
	archivo.close(); // Cerrar el fichero
}

void Califications::add(string alumno, double nota) { // Agregar un alumno
  lista_[alumno].push_back(nota);
}

// Modificación
void Califications::ordenar() { // Ordenar las notas de mayor a menor de los estudiantes
  for(map<string, std::vector<double>>::iterator it = lista_.begin(); it != lista_.end(); it++) {
    std::vector<double>& calificacion = it->second; // Apuntamos al vector de notas
    std::sort(calificacion.rbegin(), calificacion.rend()); // Ordenar las calificaciones de los estudiantes en orden descendente
  }
}

void Califications::write() { // Imprimir por pantalla la lista de estudiantes
  for(std::map<string, std::vector<double>>::iterator it = lista_.begin(); it != lista_.end(); it++) { // Recorremos la lista de estudiantes
    cout << it->first << " "; // Imprimimos el estudiante
    for(const double& nota : it->second) {
      cout << nota << " "; // Imprimimos su nota
    }
    cout << endl;
  }
}