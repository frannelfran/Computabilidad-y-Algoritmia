#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <iostream>
#include <string>

using namespace std;

class Simbolo {
public:
    // Constructor y destructor
    Simbolo() = default;
    Simbolo(const string& nombre, bool esterminal = false) : nombre_(nombre), esTerminal_(esterminal) {};
    ~Simbolo() = default;

    // Getters
    inline string getNombre() const { return nombre_; }
    inline bool esTerminal() const { return esTerminal_; }

    // Sobrecarga de operadores
    inline friend ostream& operator<<(ostream& os, const Simbolo& simbolo) {
      os << simbolo.nombre_;
      return os;
    }

    inline bool operator<(const Simbolo& otro) const {
      return nombre_ < otro.nombre_;
    }
private:
    string nombre_;
    bool esTerminal_;
};

#endif // SIMBOLO_H