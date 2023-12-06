#include <iostream>
#include <fstream>
#include "point_set.hpp"
#include "sub_tree.hpp"
#include "point_types.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Se debe de introducir un fichero con una nube de puntos." << endl;
    exit(EXIT_FAILURE);
  }
  // Crear un conjunto de puntos a partir del fichero
  ifstream file(argv[1]);
  int num_puntos;
  file >> num_puntos;

  CyA::point_vector points;
  for (int i = 0; i < num_puntos; i++) {
    double x, y;
    file >> x >> y;
    points.push_back({x, y});
  }
  file.close();

  EMST::point_set pointSet(points);
  
  // Calcular el Árbol de Expansión Mínima
  pointSet.EMST();

  // Obtener información del árbol
  const CyA::tree& emstTree = pointSet.get_tree();
  const CyA::point_vector& originalPoints = pointSet.get_points();
  const double cost = pointSet.get_cost();

  // Imprimir resultados
  std::cout << "Conjunto de puntos original:\n" << originalPoints << std::endl;
  std::cout << "Árbol de Expansión Mínima:\n" << emstTree << std::endl;
  std::cout << "Costo total del árbol: " << cost << std::endl;

  return 0;
}