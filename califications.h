#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;


class Califications {

    public:
    Califications(const std::string&); // Constructor de la clase
    void write(); // Imprimir por pantalla la lista


    private:
    std::map<std::string, double> lista_;
};