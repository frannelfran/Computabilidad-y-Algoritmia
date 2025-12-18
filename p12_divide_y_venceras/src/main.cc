#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "point_set/point_set.h"

int main(int argc, char* argv[]) {
  std::string input_filename;
  bool dot_mode = false;

  // Validación de argumentos
  // Caso 1: ./quickhull entrada.txt (argc = 2)
  // Caso 2: ./quickhull -d entrada.txt (argc = 3)
  if (argc == 2) {
    input_filename = argv[1];
  } else if (argc == 3 && std::string(argv[1]) == "-d") {
    dot_mode = true;
    input_filename = argv[2];
  } else {
    std::cerr << "Uso: " << argv[0] << " [-d] archivo_entrada" << std::endl;
    return 1;
  }

  std::ifstream input_file(input_filename);
  if (!input_file.is_open()) {
    std::cerr << "Error: No se pudo abrir " << input_filename << std::endl;
    return 1;
  }

  // Lectura del número de puntos y los puntos
  int n;
  if (!(input_file >> n)) return 1;

  std::vector<CyA::point> points;
  double x, y;
  for (int i = 0; i < n; ++i) {
    if (input_file >> x >> y) points.push_back({x, y});
  }
  input_file.close();

  // Proceso
  CyA::PointSet ps(points);
  ps.QuickHull();

  // Salida 
  std::cout << "Envoltura Convexa:" << std::endl;
  ps.WriteHull(std::cout);

  // Mostrar número de llamadas recursivas
  std::cout << "\nNúmero de llamadas recursivas: " << ps.get_recurive_calls() << std::endl;

  // Generación del fichero .dot
  if (dot_mode) {
    std::ofstream dot_file("point_set.dot");
    if (dot_file.is_open()) {
      ps.WriteDot(dot_file);
      dot_file.close();
      std::cout << "\n[OK] Fichero 'point_set.dot' generado." << std::endl;
    }
  }

  return 0;
}