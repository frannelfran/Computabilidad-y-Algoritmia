#include <iostream>
#include <fstream>
#include "point_set.hpp"
#include "sub_tree.hpp"
#include "point_types.hpp"

using namespace std;

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmos voraces + Divide y Vencerás
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 07/12/2023
// Archivo: main.cpp
// Descripción: Programa que genera un EMST a partir de una nube de puntos

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

  // Crear el vector de puntos
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

  // Costo promedio de las aristas
  const double costo_promedio = pointSet.promedio_aristas();
  cout << "Costo promedio de las aristas: " << costo_promedio << endl;

  // Generar el archivo .dot si el usuario lo solicita
  if (generateDot) {
    pointSet.write_dot_file("emst_tree.dot");
  }

  return 0;
}