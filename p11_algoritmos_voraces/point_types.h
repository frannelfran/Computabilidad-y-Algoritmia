#include <iostream>
#include <utility>
#include <vector>
#include <set>

#define MAX_SZ 3
#define MAX_PREC 0

using namespace std;

namespace CyA {
  typedef pair<double, double> point; // Representar un punto en el plano

  typedef pair<point, point> line; // Segmento de línea formado por 2 puntos 
  typedef vector<point> point_vector; // Vector de puntos

  typedef pair<point, point> arc; // Arcos mediante un par de puntos
  typedef pair<double, arc> weigthed_arc; // Arco ponderado
  typedef vector<weigthed_arc> arc_vector; // Vector de arcos ponderados

  typedef set<point> point_collection; // Conjunto ordenado de puntos

  typedef vector<arc> tree; // Arbol representado por un vector de arcos
}

std::ostream& operator<<(std::ostream& os, const CyA::point_vector& ps); // Imprimir un vector de puntos
std::ostream& operator<<(std::ostream& os, const CyA::point& ps); // Imprimir un punto

std::istream& operator>>(std::istream& is, CyA::point_vector& ps); // Leer los vectores de puntos
std::istream& operator>>(std::istream& is, CyA::point& ps); // Leer un punto