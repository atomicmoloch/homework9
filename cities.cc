#include "cities.hh"
#include <math.h>

using namespace std;

istream &operator>> Cities(istream&, Cities&)
{
	
}

ostream &operator<< Cities(ostream &output, Cities &city)
{
	for (auto iterator = begin(city.citylist); it != end(city.citylist); ++it) 
	{
    std::cout << *iterator.first << " " << *iterator.second << "\n";
	}
}

double distance(const coord_t start, const coord_t end) const {
  return (pow(pow(start.first() - end.first(), 2) + pow(start.second() - end.second(), 2), 0.5));
  //sqrt((x1-x2)^2   +  (y1-y2)^2)
  //Pythagorean theorem!
}


double Cities::total_path_distance(const permutation_t& ordering) const {
  coord_t prev = ordering.back();
  double total_distance = 0.0;
  for (auto city : ordering) {
    total_distance += distance(prev, city);
    prev = city;
  }
  return total_distance;
}
