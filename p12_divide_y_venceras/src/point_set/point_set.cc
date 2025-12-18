#include "point_set.h"
#include <iomanip>

namespace CyA
{

  PointSet::PointSet(const std::vector<point> &points) : point_vector(points), recursive_calls_(0) {}

  PointSet::~PointSet() {}

  void PointSet::QuickHull() {
    hull_.clear();
  
    point min_x_point, max_x_point;
    XBounds(min_x_point, max_x_point);

    // Dividimos el problema en dos mitades (arriba y abajo de la línea principal)
    QuickHull(line(min_x_point, max_x_point), Side::LEFT);
    QuickHull(line(min_x_point, max_x_point), Side::RIGHT);

    // Limpieza: eliminar duplicados y ordenar para una salida consistente
    std::sort(hull_.begin(), hull_.end());
    hull_.erase(std::unique(hull_.begin(), hull_.end()), hull_.end());
  }

  void PointSet::QuickHull(const line &l, int side) {
    recursive_calls_++;
    point farthest;
    if (FarthestPoint(l, side, farthest)) {
      // El punto más lejano forma un triángulo, recursión en las nuevas fronteras
      QuickHull(line(l.first, farthest), -FindSide(line(l.first, farthest), l.second));
      QuickHull(line(farthest, l.second), -FindSide(line(farthest, l.second), l.first));
    } else {
      // Caso base: no hay puntos fuera de la línea en este lado
      hull_.push_back(l.first);
      hull_.push_back(l.second);
    }
  }

  void PointSet::XBounds(point &min_x, point &max_x) const
  {
    auto min_max = std::minmax_element(begin(), end(), [](const point &a, const point &b) {
      return a.first < b.first;
    });
    min_x = *min_max.first;
    max_x = *min_max.second;
  }

  double PointSet::Point2Line(const line &l, const point &p) const
  {
    const point &p1 = l.first;
    const point &p2 = l.second;
    // Producto vectorial para determinar posición relativa
    return (p.second - p1.second) * (p2.first - p1.first) -
           (p2.second - p1.second) * (p.first - p1.first);
  }

  double PointSet::Distance(const line &l, const point &p) const {
    return std::abs(Point2Line(l, p));
  }

  int PointSet::FindSide(const line &l, const point &p) const {
    double val = Point2Line(l, p);
    if (val > 0)
      return Side::LEFT;
    if (val < 0)
      return Side::RIGHT;
    return Side::CENTER;
  }

  bool PointSet::FarthestPoint(const line &l, int side, point &farthest) const {
    double max_dist = 0;
    bool found = false;
    for (const point &p : *this) {
      if (FindSide(l, p) == side) {
        double dist = Distance(l, p);
        if (dist > max_dist) {
          max_dist = dist;
          farthest = p;
          found = true;
        }
      }
    }
    return found;
  }

  void PointSet::WriteHull(std::ostream &os) const {
    for (const auto &p : hull_) {
      os << "(" << p.first << ", " << p.second << ")" << std::endl;
    }
  }

  void PointSet::WriteDot(std::ostream &os) const {
    os << "digraph G {\n";
    // Dibujar todos los puntos
    for (size_t i = 0; i < size(); ++i) {
      os << "  p" << i << " [label=\"\", pos=\"" << (*this)[i].first
      << "," << (*this)[i].second << "!\"];\n";
    }
    os << "}\n";
  }

} // namespace CyA