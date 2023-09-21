#include "p01_single_grades.h"

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

Califications::Califications(ifstream &archivo) { // Constructor de la clase
	std::string alumno;
	double nota;
	while (archivo >> alumno >> nota) {
		if (lista_.find(alumno) == lista_.end() || nota > lista_.find(alumno)->second) { // Verificar si el alumno ya esta en la lista y si la nota es menor actualizarla
			lista_[alumno] = nota; // Almacenamiento de la nota de cada alumno
		}
	}
	archivo.close(); // Cerrar el fichero
}

void Califications::add(string alumno, double nota) { // Agregar un alumno con su nota
	if (lista_.find(alumno) == lista_.end() || nota > lista_.find(alumno)->second) { // Verificar si el alumno ya esta en la lista y si la nota es menor actualizarla
		lista_[alumno] = nota; // Almacenamiento de la nota de cada alumno
	}
	else {
		lista_.insert(std::make_pair(alumno, nota));
	}
}

void Califications::write() { // Imprimir por pantalla la lista
	for (map<string, double>::iterator i = lista_.begin(); i != lista_.end(); ++i) { // Recorre la lista de estudiantes
		cout << i->first << " " << i->second << endl;
	}
}