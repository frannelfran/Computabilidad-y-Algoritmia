#include "../../include/variable.h"
#include "../../include/bucle.h"
#include "../../include/comentarios.h"
#include <regex> // Para que las expresiones regulares funcionen
#include <string>
#include <vector>
#include <fstream> // Para manejar archivos
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
    void clasificar(const string& linea, int principio, int fin = 0); // Clasifica una línea de código

    void crearVariable(const string& tipo, int linea, const string& nombre, bool inicializada = false);
    void crearBucle(const string& tipo, int linea);

    // Sobrecarga de operadores
    //friend ostream& operator<<(ostream& os, const Analizador& analizador);

  private:
    vector<Variable*> variables_; // Almacenar las variables encontradas
    vector<Bucle> bucles_;       // Almacenar los bucles encontrados
    vector<Comentario> comentarios_; // Almacenar los comentarios encontrados
    bool main_ = false; // Indica si se ha encontrado la función main
};