#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <set>

#define MAX_SZ 3
#define MAX_PREC 0

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmos voraces + Divide y Vencerás
// Autor: Franco Alla
// Correo: alu0101571669@ull.edu.es
// Fecha: 07/12/2023
// Archivo: point_types.hpp
// Descripción: Declaración de point_types

namespace CyA {
  typedef std::pair<double, double> point; // Representar un punto

  typedef std::pair<point, point> line; // Representar una línea de 2 puntos
  typedef std::vector<point> point_vector; // Vector de puntos

  typedef std::pair<point, point> arc; // Arco formado por un par de puntos
  typedef std::pair<double, arc> weigthed_arc; // Arco ponderado
  typedef std::vector<weigthed_arc> arc_vector; // Vector de arcos ponderados

  typedef std::set<point> point_collection; // Conjunto de puntos

  typedef std::vector<arc> tree; // Árbol representado por un contenedor de arcos
}

// Sobrecarga de los operadores
std::ostream& operator<<(std::ostream& os, const CyA::point_vector& ps);
std::ostream& operator<<(std::ostream& os, const CyA::point& ps);
std::ostream& operator<<(std::ostream& os, const CyA::tree& t);
std::istream& operator>>(std::istream& is, CyA::point_vector& ps);
std::istream& operator>>(std::istream& is, CyA::point& ps);