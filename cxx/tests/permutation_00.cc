
/*
 * Description
 * Author: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 */

#include "permutation.h"

int main(int argc, char *argv[])
{
  std::cout << "Create a permutation of three elements:"
            << std::endl;
  Permutation p(3);
  p.print();
  std::cout << "Add an element:"
            << std::endl;
  p.new_element();
  p.print();
  std::cout << "Permute the element in position"
            << std::endl
            << "1 with the one in position 2:"
            << std::endl;
  p.switch_elements(1,2);
  p.print();
  std::cout << "Permute the element in position"
            << std::endl
            << "1 with the one in position 3:"
            << std::endl;
  p.switch_elements(1,3);
  p.print();
}
