#include <iostream>
#include <fstream>
#include "point_set.hpp"
#include "sub_tree.hpp"
#include "point_types.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    cout << "Modo de empleo: " << argv[0] << " [-d] archivo_entrada" << endl;
    exit(EXIT_FAILURE);
  }

  bool generateDot = false;
  std::string inputFileName;

  // Verificar la opción -d
  if (argc == 3 && std::string(argv[1]) == "-d") {
    generateDot = true;
    inputFileName = argv[2];
  } 
  else if (argc == 2) {
    inputFileName = argv[1];
  }

  // Crear un conjunto de puntos a partir del fichero
  ifstream file(inputFileName);
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
  cout << "Conjunto de puntos original:\n" << originalPoints << endl;
  cout << "Árbol de Expansión Mínima:\n" << emstTree << endl;
  cout << "Costo total del árbol: " << cost << endl;

  // Generar el archivo .dot si el usuario lo solicita
  if (generateDot) {
    pointSet.write_dot_file("emst_tree.dot");
  }

  return 0;
}