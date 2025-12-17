#ifndef POINT_SET_H_
#define POINT_SET_H_

#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cmath>

namespace CyA {

typedef std::pair<double, double> point;
typedef std::pair<point, point> line;
typedef std::vector<point> point_vector;

enum Side {
  LEFT = -1,
  CENTER = 0,
  RIGHT = 1
};

class PointSet : public point_vector {
 public:
  explicit PointSet(const std::vector<point> &points);
  ~PointSet();

  void QuickHull();

  void WriteHull(std::ostream &os) const;
  void Write(std::ostream &os) const;
  void WriteDot(std::ostream &os) const; // Requisito opcional

  const point_vector& get_hull() const { return hull_; }
  const point_vector& get_points() const { return *this; }

 private:
  point_vector hull_;

  void QuickHull(const line &l, int side);
  double Distance(const line &l, const point &p) const;
  int FindSide(const line &l, const point &p) const;
  void XBounds(point &min_x, point &max_x) const;
  double Point2Line(const line &l, const point &p) const;
  bool FarthestPoint(const line &l, int side, point &farthest) const;
};

}  // namespace CyA

#endif  // POINT_SET_H_