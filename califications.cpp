#include "califications.hpp"

Califications::Califications(char nombre_fichero[85]) { // Constructor
    ifstream lista;
    lista.open(nombre_fichero); // Abrimos el fichero con los estudiantes
    string alumno = alumno_;
    double nota = nota_;
    map<string, double> plantilla; // Creamos el mapa donde se almacenarán los alumnos con sus notas
    while(lista >> alumno >> nota) {
        plantilla[alumno] = nota; // Almacenamos cada alumno con su nota
    }
    plantilla = plantilla_;
}

void Califications::write() { // Imprimir por pantalla la lista
    for(const auto& elemento : plantilla_) {
        cout << elemento.first << elemento.second << endl;
    }
}




