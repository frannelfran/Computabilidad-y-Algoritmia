#include <iostream>
#include <utility>
#include <vector>
#include <set>

#define MAX_SZ 3
#define MAX_PREC 0

using namespace std;

namespace CyA {
  typedef pair<double, double> point; // Representar un punto en el plano

  typedef pair<point, point> line; // Segmento de línea formado 
  typedef vector<point> point_vector;

  typedef pair<point, point> arc;
  typedef pair<double, arc> weigthed_arc;
  typedef vector<weigthed_arc> arc_vector;

  typedef set<point> point_collection;

  typedef vector<arc> tree;
}