#include "cities.hh"






double Cities::total_path_distance(const permutation_t& ordering) const {
  coord_t prev = ordering.back();
  double total_distance = 0.0;
  for (auto city : ordering) {
    total_distance += distance(prev, city);
    prev = city;
  }

}
