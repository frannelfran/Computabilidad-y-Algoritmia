#pragma once

#include "point_types.hpp"
#include "sub_tree.hpp"

namespace EMST {
  class point_set : public CyA::point_vector {
    private:
    CyA::tree emst_;

    public:
    point_set(const CyA::point_vector& points);
    ~point_set();

    void EMST();

    void write_tree(std::ostream& os) const;
    void write(std::ostream& os) const;

    const CyA::tree& get_tree() const;
    const CyA::point_vector& get_points() const;
    const double get_cost() const;

    private:
    void compute_arc_vector(CyA::arc_vector& av) const;
    void find_incident_subtrees(const sub_tree_vector& st, const CyA::arc& a, int& i, int& j) const;
    void merge_subtrees(sub_tree_vector& st, const CyA::arc& a, int i, int j) const;

    double compute_cost() const;

    double euclidean_distance(const CyA::arc& a) const;
  };
}