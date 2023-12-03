#include <iomanip>
#include <cmath>
#include "sub_tree.h"
#include <algorithm>
#include <utility>

/**
  * @brief Constructor de la clase sub_tree
*/

sub_tree::sub_tree(void) : arcs_(), points_(), cost_(0) {}

/**
  * @brief Destrutor de la clase sub_tree
*/

sub_tree::~sub_tree(void) {}

/**
  * @brief Agregar un arco al árbol de arcos
  * @param a Arco a agregar al sub-árbol
*/

void sub_tree::add_arc(const arc &a) {
  arcs_.push_back(a);

  // Agregar las coordenadas del punto al conjunto de puntos
  points_.insert(a.first);
  points_.insert(a.second);
}

/**
  * @brief Agregar un punto al conjunto de puntos
  * @param p Punto a agregar
*/

void sub_tree::add_point(const point &p) {
  points_.insert(p);
}

/**
  * @brief Verificar si un punto se encuentra en el conjunto de puntos
  * @param p Punto a verificar
  * @return 1 en caso de verdadero y 0 en caso contrario
*/

bool sub_tree::contains(const point &p) const {
  return points_.find(p) != points_.end();
}

/**
  * @brief Fusionar el sub-árbol actual con otro sub-árbol y un arco ponderado
  * @param st Sub-árbol que se va a fusionar con el sub-árbol actual
  * @param a Arco ponderado que se va a agregar al sub-árbol resultante
*/

void sub_tree::merge(const sub_tree &st, const weigthed_arc &a) {
  arcs_.insert(arcs_.end(), st.arcs_.begin(), st.arcs_.end());
  arcs_.push_back(a.second);

  points_.insert(st.points_.begin(), st.points_.end());

  cost_ += a.first + st.get_cost();
}