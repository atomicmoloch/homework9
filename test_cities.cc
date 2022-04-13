#include "cities.hh"
#include <cassert>



int main() {
  Cities city;
  std::vector<Cities::coord_t> points;
  Cities::coord_t point1 = {10, 5};
  Cities::coord_t point2 = {10, 10};
  assert(city.distance(point1, point2) == 5.0);
  
  std::cout << "Successful.\n";
}
