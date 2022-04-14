#include "cities.hh"
#include <cassert>
#include <fstream>
#include <iostream>



int main(int argc, char** argv) {


        ifstream infile(argv[1]);
        string newname = argv[1];
        ofstream outfile(newname + ".tsv", ios::out);


  Cities city;
  std::vector<Cities::coord_t> points;
  Cities::coord_t point1 = {10, 5};
  Cities::coord_t point2 = {10, 10};
  assert(city.distance(point1, point2) == 5.0);

  infile >> city;

  std::cout << "Random permutations:\n";
  for (int i = 0; i < 10; i++){
    auto randPerm = city.random_permutation();
    for (auto i: randPerm){
      std::cout << i;
    }
    std::cout << "\n\n";
  }
  std::cout << "End of test file.\n";


outfile << city;


}
