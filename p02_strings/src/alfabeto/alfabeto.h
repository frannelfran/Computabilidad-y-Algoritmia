#pragma once
#include <iostream>
#include <fstream>
#include <set>

#ifndef ALFABETO_H
#define ALFABETO_H

using namespace std;

class Alfabeto {
  public:
    // Constructor y destructor
    Alfabeto(const string& alfabeto);
    ~Alfabeto() = default;

    // Sobrecarga de operadores
    friend ostream& operator<<(ostream& os, const Alfabeto& alfabeto);
  private:
    set<char> simbolos_;
};

#endif // ALFABETO_H