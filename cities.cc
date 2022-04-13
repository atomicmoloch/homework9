#include "cities.hh"
#include <string>
#include <math.h>
#include <random>
#include <algorithm>

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
			citylist_.push_back(tempc);
		}

	}
}

ostream &operator<< Cities(ostream &output, Cities &city)
{
	for (auto iterator = begin(city.citylist_); it != end(city.citylist_); ++it)
	{
    std::cout << *iterator.first << " " << *iterator.second << "\n";
	}
}

double Cities::distance(const Cities::coord_t start, const Cities::coord_t end) const {
  return (pow(pow(start.first - end.first, 2) + pow(start.second - end.second, 2), 0.5));
  //sqrt((x1-x2)^2   +  (y1-y2)^2)
  //Pythagorean theorem!
}


double Cities::total_path_distance(const Cities::permutation_t& ordering) const {
  unsigned int prev = ordering.back();
  double total_distance = 0.0;
  for (auto i : ordering) {
    total_distance += distance(citylist_[prev], citylist_[i]);
    prev = i;
  }
  return total_distance;
}

Cities Cities::reorder(const Cities::permutation_t& ordering) const {
  Cities newCities;
  for (auto i : ordering){
    newCities.citylist_.push_back(citylist_[i]);
  }
  return newCities;
}

Cities::permutation_t Cities::random_permutation(unsigned len) {
	std::random_device generator;
	//std::default_random_engine generator;

	permutation_t randomList; //Create an empty permutation
	for (unsigned i = 0; i < len; i++){
		randomList.push_back(i); //Populate the permutation with ordered numbers, (1, 2, 3, 4, ... len-1)
	}
	std::shuffle(std::begin(randomList), std::end(randomList), generator);
	return randomList;
}
