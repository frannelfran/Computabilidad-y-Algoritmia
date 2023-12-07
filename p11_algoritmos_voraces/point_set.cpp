#include <iomanip>
#include <cmath>
#include <algorithm>
#include "point_set.hpp"

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmos voraces + Divide y Vencerás
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 07/12/2023
// Archivo: point_set.cpp
// Descripción: Implementación de la clase point_set

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

        const double dist = euclidean_distance(make_pair(p_i, p_j));

        av.push_back(make_pair(dist, make_pair(p_i, p_j)));
      }
    }

    sort(av.begin(), av.end());
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
    st[i].merge(st[j], make_pair(euclidean_distance(a), a));
    st.erase(st.begin() + j);
  }

  /**
   * @brief Calcular el costo total del árbol
   * @return Costo total
  */

  double point_set::compute_cost() const {
    // Calcular el costo total del árbol
    double coste_total = 0.0;
    
    const CyA::tree& emst_tree = get_tree();
    for (const auto& arc : emst_tree) {
      coste_total += euclidean_distance(arc);
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
    return sqrt(dx * dx + dy * dy);
  }

  /**
   * @brief Realizar el fichero .dot si se ejecuta -d
   * @param filename Nombre del fichero .dot
  */

  void point_set::write_dot_file(const string& filename) const {
    ofstream dotFile(filename);
    dotFile << "graph {" << endl;

    // Obtener la referencia constante al árbol generador mínimo (EMST)
    const CyA::tree& emst_tree = get_tree();

    // Mapa para asignar identificadores únicos a los puntos
    map<CyA::point, string> pointIds;

    // Asignar identificadores a los puntos basados en su posición
    for (size_t i = 0; i < size(); ++i) {
      const CyA::point& point = at(i);
      pointIds[point] = "p" + to_string(i + 1); // Usar 'p' como prefijo para evitar números iniciales
      dotFile << "  " << pointIds[point] << " [pos=\"" << point.first << "," << -point.second << "!\"]" << endl;
    }

    // Iterar sobre los arcos del EMST y escribir las conexiones
    for (const auto& arc : emst_tree) {
      const CyA::point& point1 = arc.first;
      const CyA::point& point2 = arc.second;

      dotFile << "  " << pointIds.at(point1) << " -- " << pointIds.at(point2) << endl;
    }

    dotFile << "}" << endl;
    dotFile.close();
  }

  // Modificación

  /**
   * @brief Calcular el costo promedio que forman las aristas del árbol
   * @return Costo promedio
  */

  const double point_set::promedio_aristas() const {
    double coste_promedio = 0.0;

    // Obtener la referencia constante al árbol generador mínimo (EMST)
    const CyA::tree& emst_tree = get_tree();

    // Iterar sobre los arcos del EMST y sumar sus costos
    for (const auto& arc : emst_tree) {
      coste_promedio += euclidean_distance(arc);
    }

    // Calcular el promedio dividiendo la suma total por la cantidad de aristas
    int num_arcos = emst_tree.size();
    return coste_promedio / static_cast<double>(num_arcos);
  }
}