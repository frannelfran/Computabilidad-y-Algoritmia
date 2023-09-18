#include "califications.h"

Califications::Califications(ifstream& archivo) { // Constructor de la clase
    std::string alumno;
    double nota;
    while(archivo >> alumno >> nota) {
        if(lista_.find(alumno) == lista_.end() || nota > lista_.find(alumno) -> second) { // Verificar si el alumno ya esta en la lista y si la nota es menor actualizarla
            lista_[alumno] = nota; // Almacenamiento de la nota de cvada alumno
        }
    }
    archivo.close(); // Cerrar el fichero
}

std::map<string, double> Califications::add(string alumno, double nota) { // Agregar un alumno con su nota
    lista_.insert(std::make_pair(alumno, nota));
    if(lista_.find(alumno) == lista_.end() || nota > lista_.find(alumno) -> second) { // Verificar si el alumno ya esta en la lista y si la nota es menor actualizarla
        lista_[alumno] = nota; // Almacenamiento de la nota de cada alumno
    }
    return lista_;
}

void Califications::write() { // Imprimir por pantalla la lista
    for(const auto& elemento : lista_ ) {
        cout << elemento.first << " " << elemento.second << endl;
    }
}