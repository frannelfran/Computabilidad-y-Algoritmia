#include <iomanip>
#include <cmath>
#include <algorithm>
#include "point_set.hpp"

namespace EMST {

  /**
   * @brief Cosntructor de la clase point_set
   * @param points Vector de puntos
  */

  point_set::point_set(const CyA::point_vector& points) : CyA::point_vector(points), emst_() {}

  /**
   * @brief Destructor de la clase point_set
  */

  point_set::~point_set() {}

  /**
   * @brief Obtener el árbol generador de mínimo coste
   * @return emst
  */

  const CyA::tree& point_set::get_tree() const {
    return emst_; // Emst_ es el atributo privado que almacena el árbol
  }

  /**
   * @brief Obtener los puntos
   * @return Puntos
  */

  const CyA::point_vector& point_set::get_points() const {
    return *this; // Devuelve el vector de puntos heredado de CyA::point_vector
  }

  /**
   * @brief Obtener el costo del árbol
   * @return Costo
  */

  const double point_set::get_cost() const {
    return compute_cost(); // Puedes implementar esta función según tu lógica
  }

  /**
   * @brief Calcular el árbol generador mínimo (EMST)
  */

  void point_set::EMST() {
    CyA::arc_vector av;
    compute_arc_vector(av);

    sub_tree_vector st;

    for (const CyA::point& p : *this) {
      sub_tree s;
      s.add_point(p);

      st.push_back(s);
    }

    for (const CyA::weigthed_arc& a : av) {
      int i, j;
      find_incident_subtrees(st, a.second, i, j);

      if (i != j) {
        merge_subtrees(st, a.second, i, j);
      }
    }

    emst_ = st[0].get_arcs();
  }

  /**
   * @brief Calcular un vector de arcos a partir del conjutno de puntos
   * @param av Conjunto de arcos
  */

  void point_set::compute_arc_vector(CyA::arc_vector& av) const {
    av.clear();

    const int n = size();

    for (int i = 0; i < n - 1; ++i) {
      const CyA::point& p_i = (*this)[i];

      for (int j = i + 1; j < n; ++j) {
        const CyA::point& p_j = (*this)[j];

        const double dist = euclidean_distance(std::make_pair(p_i, p_j));

        av.push_back(std::make_pair(dist, std::make_pair(p_i, p_j)));
      }
    }

    std::sort(av.begin(), av.end());
  }

  /**
   * @brief Encontrar árboles incidentes en un arco
   * @param st Vector de sub-arboles
   * @param a Arco
   * @param i Entero
   * @param j Entero
  */

  void point_set::find_incident_subtrees(const sub_tree_vector& st, const CyA::arc& a, int& i, int& j) const {
    // Buscar los índices de los árboles incidentes en la arista a en el vector de subárboles st
    for (int index = 0; index < st.size(); ++index) {
      if (st[index].contains(a.first)) {
        i = index;
      }
      if (st[index].contains(a.second)) {
        j = index;
      }
    }
  }

  /**
   * @brief Fusionar sub-árboles en función de un arco
   * @param st Vector de sub-árboles
   * @param a Arco
   * @param i Entero
   * @param j Entero
  */

  void point_set::merge_subtrees(sub_tree_vector& st, const CyA::arc& a, int i, int j) const {
    // Fusionar los dos subárboles i y j en uno solo
    st[i].merge(st[j], std::make_pair(euclidean_distance(a), a));
    st.erase(st.begin() + j);
  }

  /**
   * @brief Calcular el costo total del árbol
   * @return Costo total
  */

  double point_set::compute_cost() const {
    // Calcular el costo total del árbol
    double coste_total = 0.0;
    for (const sub_tree& st : sub_tree_vector_) {
      coste_total += st.get_cost();
    }
    return coste_total;
  }

  /**
   * @brief Calcular la distancia euclidiana de un arco
   * @param a Arco
   * @return Distancia euclidiana
  */

  double point_set::euclidean_distance(const CyA::arc& a) const {
    // Calcular la distancia euclidiana entre dos puntos
    double dx = a.first.first - a.second.first;
    double dy = a.first.second - a.second.second;
    return std::sqrt(dx * dx + dy * dy);
  }
}