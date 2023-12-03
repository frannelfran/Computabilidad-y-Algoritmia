#include "point_types.h"

#include <iomanip>

/**
 * @overload Mostrar el vector de puntos
*/

ostream& operator<<(ostream& os, const CyA::point_vector& ps) {
  os << ps.size() << endl;
  for (const CyA::point & p : ps) {
    os << p << endl;
  }
  return os;
}

/**
 * @overload Imprimir un punto
*/

ostream& operator<<(ostream& os, const CyA::point& p) {
  os << setw(MAX_SZ) << fixed << setprecision(MAX_PREC) << p.first << "\t" << setw(MAX_SZ) << setprecision(MAX_PREC) << p.second;
  return os;
}

/**
 * @overload Leer el vector de puntos
*/

istream& operator>>(istream& is, CyA::point_vector& ps) {
  int n;
  is >> n; // Leer el número del vector de puntos
  ps.clear(); // Limpiar el vector de puntos

  // Iterar sobre cada punto del vector, leer el punto e insertarlo
  for (int i = 0; i < n; i++) {
    CyA::point p;
    is >> p;

    ps.push_back(p);
  }
  return is;
}

/**
 * @overload Leer las coordenadas del punto
*/

istream& operator>>(istream& is, CyA::point& p) {
  is >> p.first >> p.second;
  return is;
}