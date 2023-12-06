#pragma once

#include <iostream>
#include <cmath>
#include "point_types.hpp"

namespace EMST {
  class sub_tree {
    private:
    CyA::tree arcs_;
    CyA::point_collection points_;
    double cost_;

    public:
    sub_tree();
    ~sub_tree();

    void add_arc(const CyA::arc& a);
    void add_point(const CyA::point& p);
    bool contains(const CyA::point& p) const;
    void merge(const sub_tree& st, const CyA::weigthed_arc& a);

    const CyA::tree& get_arcs() const;
    double get_cost() const;
  };
  typedef std::vector<sub_tree> sub_tree_vector;
}