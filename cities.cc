#include "cities.hh"
#include <string>  
#include <math.h>

using namespace std;

istream &operator>> Cities(istream&, Cities&)
{
	string line;
	bool first = true; 
	coord_t tempc;
	while(getline(inp, line, ' '))
	{
		int num = stoi(line);
		if (first)
		{
			tempc.first = num;
		}
		else
		{
			tempc.second = num;
			citylist.push_back(tempc);
		}
		
	}
}

ostream &operator<< Cities(ostream &output, Cities &city)
{
	for (auto iterator = begin(city.citylist); it != end(city.citylist); ++it) 
	{
    std::cout << *iterator.first << " " << *iterator.second << "\n";
	}
}

double Cities::distance(const Cities::coord_t start, const Cities::coord_t end) const {
  return (pow(pow(start.first - end.first, 2) + pow(start.second - end.second, 2), 0.5));
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
