#include "point_set.h"

/**
 * @brief Constructor de la clase point_set
*/

point_set::point_set(const point_vector &points) : point_vector(points), emst_() {}

/**
 * @brief Destructor de la clase
*/

point_set::~point_set() {}

/**
 * @brief Escribir el árbol mínimo de expansión
*/

void point_set::write_tree(ostream& os) const {
  for (const auto& arc : emst_) {
    os << arc.first.second << " " << arc.first.second << " " << arc.second.first << " " << arc.second.second << endl;
  }
}

/**
 * @brief Escribir el conjunto de puntos
*/

void point_set::write(ostream& os) const {
  for (const auto& point : points_) {
    os << point.first << " " << point.second << endl;
  }
}


/**
 * @brief Calcular el vector de arcos ponderados basado en el conjunto de puntos y el EMST
 * @param av Vector de arcos
*/

void point_set::compute_arc_vector(arc_vector &av) const {
  av.clear();

  const int n = size(); // Obtener el número de puntos del conjunto

  for (int i = 0; i < n -1; i++) {
    const point &p_i = (*this)[i]; // Obtener el punto en la posición i
    for (int j = i + 1; j < n; j++) {
      const point &p_j = (*this)[j]; // Obtener el punto en la posición j

      const double dist = euclidean_distance(make_pair(p_i, p_j)); // Calcular la distancia entre los puntos i y j

      av.push_back(make_pair(dist, make_pair(p_i, p_j))); // Agregar un arco ponderado al vector de arcos ponderados
    }
  }
  sort(av.begin(), av.end()); // Ordenar el vector de arcos en orden ascendente
}