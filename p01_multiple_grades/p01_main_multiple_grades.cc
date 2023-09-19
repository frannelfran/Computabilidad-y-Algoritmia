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
// Archivo p01_main_single_grades.cc

int main(int argc, char *argv[]) {
	string usuario;
	double nota;
	int opcion;
	if (argc != 2) { // Verifica si se proporciono el fichero como argumento
		cout << "Introduce un fichero, ejecute --help para más información" << endl;
		return 1; // Sale del programa con un código de error
	}
	string ayuda = argv[1];
	if (ayuda == "--help") {
		cout << "Modo de empleo: " << "./p01_multiple_grades grades.txt" << endl;
		exit(EXIT_SUCCESS); // Salir
	}

	cout << "Programa que muestra la lista de estudiantes y sus correspondientes notas" << endl;
	std::string nombre_archivo = argv[1]; // Introducir el nombre del fichero
	ifstream archivo(nombre_archivo); // Cargo los datos del fichero
	cout << "Abriendo " << nombre_archivo << "...." << endl; // Abriendo fichero proporcionado
	Califications registro(archivo);