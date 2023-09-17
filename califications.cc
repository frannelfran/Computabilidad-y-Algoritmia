#include "califications.h"

Califications::Califications(const std::string& archivo) { // Constructor de la clase
    string alumno;
    double nota;
    map<std::string, double> lista;
    while(archivo >> alumno >> nota) {
        lista[alumno] = nota;
    }
    lista = lista_;
}

void Califications::write() { // Imprimir por pantalla la lista
    for(const auto& elemento : lista_ ) {
        cout << elemento.first << " " << elemento.second << endl;
    }
}



