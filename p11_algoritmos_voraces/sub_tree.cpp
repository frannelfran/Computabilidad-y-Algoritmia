#include <iomanip>
#include <cmath>
#include <algorithm>
#include <utility>
#include "sub_tree.hpp"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmos voraces + Divide y Vencerás
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 07/12/2023
// Archivo: sub_tree.cpp
// Descripción: Implementación de la clase sub_tree

namespace EMST {

  /**
   * @brief Constructor por defecto de la clase
  */

  sub_tree::sub_tree() : arcs_(), points_(), cost_(0) {}

  /**
   * @brief Destructor por defecto de la clase
  */

  sub_tree::~sub_tree() {}

  /**
   * @brief Añadir un arco al sub-árbol
   * @param a Arco a añadir
  */

  void sub_tree::add_arc(const CyA::arc& a) {
    arcs_.push_back(a);
    points_.insert(a.first);
    points_.insert(a.second);
  }

  /**
   * @brief Añadir un punto al sub-árbol
   * @param p Punto a añadir
  */

  void sub_tree::add_point(const CyA::point& p) {
    points_.insert(p);
  }

  /**
   * @brief Verificar que existe un punto en el sub-árbol
   * @param p Punto a comprobar
  */

  bool sub_tree::contains(const CyA::point& p) const {
    return points_.find(p) != points_.end();
  }

  /**
   * @brief Fusionar el sub-arbol actual con otro
   * @param st Sub-árbol actual
   * @param a Otro árbol
  */

  void sub_tree::merge(const sub_tree& st, const CyA::weigthed_arc& a) {
    arcs_.insert(arcs_.end(), st.arcs_.begin(), st.arcs_.end());
    arcs_.push_back(a.second);

    points_.insert(st.points_.begin(), st.points_.end());

    cost_ += a.first + st.get_cost();
  }

  /**
   * @brief Obtener los arcos del árbol
   * @return Arcos
  */

  const CyA::tree& sub_tree::get_arcs() const {
    return arcs_;
  }

  /**
   * @brief Obtener los costos del sub-árbol
   * @return Costos
  */

  double sub_tree::get_cost() const {
    return cost_;
  }
}