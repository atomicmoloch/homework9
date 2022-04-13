#include "cities.hh"
#include <fstream>

int main(int argc, char** argv) {
  if (argc < 2){
    std::cerr << "No input file given.\n";
    return -1;
  }
  if (argc > 2){
    std::cerr << "Error: too many inputs.\n";
    return -2;
  }

  std::string file = argv[1];
  std::ifstream ifile(file);
  if (!ifile.is_open()){
    std::cerr << "Error: Can't open file " + file + ".\n";
    return -3;
  }

  unsigned int numberIterations = 1000000;
  Cities fastestRoute;
  ifile >> fastestRoute;
  /*
  std::vector<Cities::coord_t> input;
  auto temppair = std::make_pair(10, 5);
  input.push_back(temppair);
  temppair = std::make_pair(2, 20);
  input.push_back(temppair);
  temppair = std::make_pair(15, 12);
  input.push_back(temppair);
  temppair = std::make_pair(15, 7);
  input.push_back(temppair);
  temppair = std::make_pair(7, 7);
  input.push_back(temppair);

  //cout.precision(17);
  fastestRoute.input_cities(input);
  */
  double shortestDistance = fastestRoute.total_path_distance(fastestRoute.ordered_permutation());
  std::cout << "1   " << shortestDistance << "\n";

  for (unsigned int i = 2; i <= numberIterations; i++){
    auto newPermutation = fastestRoute.random_permutation();
    double newDistance = fastestRoute.total_path_distance(newPermutation);
    //std::cout << "New distance " << newDistance << " compared with " << shortestDistance << "\n";
    if (newDistance < shortestDistance){           //If this route is the new shortest,
      fastestRoute = fastestRoute.reorder(newPermutation);                   //Then set it as the new shortest.
      shortestDistance = newDistance;
      std::cout << i << "   " << shortestDistance << "\n";
      //std::cout << "New best found! " << shortestDistance << "\n";
    }
  }


  file = "shortest.tsv";
  std::ofstream ofile(file);
  ofile << fastestRoute;




  std::cout << "Program terminated.\n";
  return 0;
}
