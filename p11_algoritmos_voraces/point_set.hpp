#pragma once

#include "point_types.hpp"
#include "sub_tree.hpp"
#include <fstream>
#include <map>

using namespace std;

namespace EMST {
  class point_set : public CyA::point_vector {
    private:
    CyA::tree emst_; // Árbol generador mínimo

    public:
    point_set(const CyA::point_vector& points); // Constructor de la clase
    ~point_set(); // Destructor de la clase
    sub_tree_vector sub_tree_vector_; // Vector de sub-árboles

    void EMST(); // Construir el árbol generador mínimo

    const CyA::tree& get_tree() const; // Obtener el árbol
    const CyA::point_vector& get_points() const; // Obtener los puntos
    const double get_cost() const; // Obtener el costo
    void write_dot_file(const std::string& filename) const; // Generar el archivo .dot

    private:
    void compute_arc_vector(CyA::arc_vector& av) const; // Calcular un vector de arcos a partir del conjunto de puntos
    void find_incident_subtrees(const sub_tree_vector& st, const CyA::arc& a, int& i, int& j) const; // Encontrar sub-árboles incidentes a un arco
    void merge_subtrees(sub_tree_vector& st, const CyA::arc& a, int i, int j) const; // Fusionar subárboles en función de un arco 
    double compute_cost() const; // Calcular el costo total de árbol

    double euclidean_distance(const CyA::arc& a) const; // Calcular la distancia euclidiana de los arcos
  };
}