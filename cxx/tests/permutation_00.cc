/*
 * Description
 * Author: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 * test: Permutation and switch_elements
 */

#include "permutation.h"
#include "utilities.h"

int main(int argc, char *argv[])
{
  using namespace utilities;

  print_msg("Create a permutation of three elements:");
  Permutation p(3);
  std::cout << p;
  print_msg("Permute 1 and 0:");
  p.switch_elements(0,1);
  std::cout << p;
  print_msg("Permute 2 and 0:");
  p.switch_elements(0,2);
  std::cout << p;
}
