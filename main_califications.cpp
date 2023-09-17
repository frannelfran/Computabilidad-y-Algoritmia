#include "califications.hpp"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 17/09/2023
// Archivo cya-P01-single-grades.cc: programa cliente.
// Compilación: g++ -g califications.cpp main_califications.cpp -o main_califications 

int main() {
    char nombre_fichero[85]; 
    cout << "Programa que muestra la lista de estudiantes y sus correspondientes notas" << endl;
    cout << "Introducir el archivo.txt con la lista de estudiantes " << endl;
    cin >> nombre_fichero; // Introducir el nombre del fichero
    
    Califications Listado1(nombre_fichero);
    Listado1.write();





    return 0;
}