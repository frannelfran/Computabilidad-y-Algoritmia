#include "sub_tree.h"

typedef vector<sub_tree> forest; // Definir un alias forest

class point_set : public point_vector {
  private:
  tree emst_; // Árbol mínimo de expansión sobre el conjunto de puntos
  point_collection points_; // Conjunto de puntos

  public:
  point_set(const point_vector &points); // Construtor de la clase point_set
  ~point_set(void); // Destructor de la clase

  void EMST(void); // Calcular el árbol mínimo de expansión para el conjunto de puntos

  void write_tree(ostream &os) const; // Escribir el árbol mínimo de expansión
  void write(ostream& os) const; // Escribir el conjunto de puntos

  inline const tree& get_tree(void) const { return emst_; } // Referencia constante al árbol mínimo de expansión
  inline const point_vector& get_points(void) const { return *this; } // Referencia constante al conjunto de puntos
  inline const double get_cost(void) const { return compute_cost(); } // Obtener el costo total del EMST

  private:
  void compute_arc_vector(arc_vector &av) const; // Calcular el vector de arcos ponderados basado en el conjunto de puntos y el EMST
  void find_incident_subtrees(const forest& st, const arc &a, int& i, int& j) const; // Encontrar los sub-árboles incidentes en un arco
  void merge_subtrees(forest& st, const arc &a, int i, int j) const; // Fusionar dos sub-árboles incidentes en un arco

  double compute_cost(void) const; // Calcular el costo total del EMST

  double euclidean_distance(const arc& a) const; // Calcular la distancia euclidiana entre los extremos de un arco
};