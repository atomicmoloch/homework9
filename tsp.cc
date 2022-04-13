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

  unsigned int numberIterations = 1000;
  Cities fastestRoute;
  ifile >> fastestRoute;

  unsigned int length = fastestRoute.get_length();
  double shortestDistance = fastestRoute.total_path_distance();
  std::cout << "1   " << shortestDistance << "\n";
  for (unsigned int i = 2; i <= numberIterations; i++){
    auto newRoute = fastestRoute.reorder(random_permutation(length)); //Create random route
    if (newRoute.total_path_distance() < shortestDistance){           //If this route is the new shortest,
      fastestRoute = newRoute;                                        //Then set it as the new shortest.
      shortestDistance = fastestRoute.total_path_distance();
      std::cout << i << "   " << shortestDistance << "\n";
    }
  }


  file = "shortest.tsv";
  std::ofstream ofile(file);
  ofile << fastestRoute;




  std::cout << "Program terminated.\n";
  return 0;
}
