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
map<string, std::vector<double>> Califications::ordenar() { // Ordenar las notas de mayor a menor de los estudiantes
  map<string, std::vector<double>> lista_ordenada;
  for(map<string, std::vector<double>>::iterator it = lista_.begin(); it != lista_.end(); it++) {
    string alumno = it->first;
    std::vector<double> calificacion = it->second; // Apuntamos al vector de notas
    double nota_actual_max, nota_actual_min;
    for(std::vector<double>::iterator it_2 = calificacion.begin(); it_2 != calificacion.end(); it_2++) { // Recorremos el vector que contiene las notas
      double nota = *it_2;
      if(nota > nota_actual_max) { // Comprueba si la nota es mayor
        nota = nota_actual_max;
      }
      if(nota < nota_actual_min) { // Comprueba si la nota es menor
        nota = nota_actual_min;
      }
      lista_ordenada[alumno].push_back(nota_actual_max);
      lista_ordenada[alumno].push_back(nota_actual_min);
    }
  }
  return lista_ordenada;
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