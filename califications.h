#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;


class Califications {

    public:
    Califications(ifstream&); // Constructor de la clase
    std::map<string, double> add(string, double); // Agregar un alumno
    void write(); // Imprimir por pantalla la lista

    private:
    std::map<std::string, double> lista_;
};