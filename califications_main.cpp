#include "califications.hpp"

int main() {
    char nombre_fichero[85]; 
    cout << "Programa que muestra la lista de estudiantes y sus correspondientes notas" << endl;
    cout << "Introducir el archivo.txt con la lista de estudiantes " << endl;
    cin >> nombre_fichero; // Introducir el nombre del fichero
    
    Califications Listado1(nombre_fichero);
    Listado1.write();





    return 0;
}