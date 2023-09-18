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

int main(int argc, char* argv[]) {
    string usuario;
    double nota;
    int opcion;
    if (argc != 2) { // Verifica si se proporciono el fichero como argumento
        std::cerr << "Uso: " << argv[0] << "¡SE DEBE DE PASAR EL FICHERO COMO ARGUMENTO!" << std::endl;
        return 1; // Sale del programa con un código de error
    }
    
    cout << "Programa que muestra la lista de estudiantes y sus correspondientes notas" << endl;
    std::string nombre_archivo = argv[1]; // Introducir el nombre del fichero
    ifstream archivo(nombre_archivo); // Cargo los datos del fichero
    cout << "Abriendo " << nombre_archivo << "...." << endl; // Abriendo fichero proporcionado
    Califications registro(archivo);
    do {
        cout << "LISTA CON EL ALU Y LA NOTA DE CADA ESTUDIANTE" << endl;
        registro.write(); // Muestra por pantalla la lista de los alumnos con sus respectivas notas
    // MENÚ
        cout << "______MENÚ_____\n" << endl;
        cout << "1: Introducir usuario " << endl;
        cout << "0: Exit" << endl;
        cout << "_______________" << endl;
        cout << "OPCIÓN? ";
        cin >> opcion;
    
    //OPCIONES
        switch (opcion) {
            case 1: // Agregar un usuario con su nota
            cout << "Introducir usuario: " << endl;
            cin >> usuario;
            cout << "Introducir nota: " << endl;
            cin >> nota;
            registro.add(usuario, nota);
            registro.write();
        }
    } while(opcion != 0); // Salir del programa
    return 0;
}