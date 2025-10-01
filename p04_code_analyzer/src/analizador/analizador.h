#include "../../include/variable.h"
#include "../../include/bucle.h"
#include "../../include/comentario.h"
#include "../../include/expresionRegular.h"
#include <regex> // Para que las expresiones regulares funcionen
#include <string>
#include <vector>
#include <fstream> // Para manejar archivos
#include <algorithm> // Para transform
#include <iostream>

/**
 * @class Clase que analiza el código fuente en busca de variables, bucles y comentarios.
 */
class Analizador {
  public:
    // Constructor y destructor
    Analizador() = default;
    ~Analizador() = default;

    // Métodos
    void analizar(ifstream& archivo);
    void clasificar(ifstream& archivo, const string& linea, int& numeroLinea); // Clasifica una línea de código
    void crearVariable(string tipo, int linea, string nombre, bool inicializada = false);
    void crearBucle(const string& tipo, int linea);
    void crearComentario(const string& tipo, int principio, int fin, const string& contenido);
    void procesarComentario(ifstream& archivo, string linea, int& numLinea);


    // Sobrecarga de operadores
    friend ostream& operator<<(ostream& os, const Analizador& analizador);

  private:
    vector<Variable*> variables_; // Almacenar las variables encontradas
    vector<Bucle> bucles_;       // Almacenar los bucles encontrados
    vector<Comentario> comentarios_; // Almacenar los comentarios encontrados
    bool main_ = false; // Indica si se ha encontrado la función main
    ExpresionRegular expresiones_; // Instancia de la clase ExpresionesRegulares
};