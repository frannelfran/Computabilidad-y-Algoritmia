#include "califications.h"

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
// Compilación: g++ -g califications.cc main_califications.cc -o main_califications 

int main() {
    cout << "Programa que muestra la lista de estudiantes y sus correspondientes notas" << endl;
    string archivo = "archivo.txt";
    Califications registro1(archivo);
    cout << "LISTA 1 CON EL ALU Y LA NOTA DE CADA ESTUDIANTE" << endl;
    registro1.write();
    
    return 0;
}