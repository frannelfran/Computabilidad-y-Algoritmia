#include "califications.h"

Califications::Califications(ifstream& archivo) { // Constructor de la clase
    string alumno;
    double nota;
    while(archivo >> alumno >> nota) {
        lista_[alumno] = nota; // Almacenamiento de la nota de cada alumno
    }
}

void Califications::write() { // Imprimir por pantalla la lista
    for(const auto& elemento : lista_ ) {
        cout << elemento.first << " " << elemento.second << endl;
    }
}