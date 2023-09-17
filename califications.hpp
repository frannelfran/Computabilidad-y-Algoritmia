#include<iostream>
#include<fstream>
#include<map>
using namespace std;


class Califications {

    public:
    Califications(char[85]); // Constructor de la clase
    void write();


    private:
    map<string, double> plantilla_;
    string alumno_;
    double nota_;
};