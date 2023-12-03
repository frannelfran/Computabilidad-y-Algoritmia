#pragma once

#include <iostream>
#include <cmath>

#include "point_types.h"

namespace EMST {
  class Sub_tree {
    // Atributos privados de la clase
    private:
    CyA::tree arcs_; // Acros del árbol
    CyA::point_collection points_; // Conjutno de puntos del árbol
    double cost_; // Costo asociado al sub-árbol

    // Métodos públicos de la clase
    public:
    Sub_tree(void); // Constructor de la clase
    ~Sub_tree(void); // Destructor de la clase

    void add_arc(const CyA::arc &a); // Añadir un arco al árbol
    void add_point(const CyA::point &p); // Añadir un punto al conjunto de puntos
    bool contains(const CyA::point &p) const; // Verificar si un punto está contenido en el conjutno de puntos del sub-árbol
    void merge(const Sub_tree &st, const CyA::weigthed_arc &a); // Fusionar el sub-árbol actual con otro sub-árbol y un arco ponderado

    inline const CyA::tree& get_arcs(void) const { return arcs_; } // Método de acceso que devuelve una referencia constante al árbol de arcos
    inline double get_cost(void) const { return cost_; } // Método para devolver el costo del sub-árbol
  };

  typedef vector<Sub_tree> sub_tree_vector; // Vector de objetos sub-tree
}