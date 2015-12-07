
/*
 * Description
 * Author: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 */

#include "permutation.h"

int main(int argc, char *argv[])
{
  // std::cout << "Create a permutation of three elements:"
  //           << std::endl;
  GPermutation p;
  p.add_an_element('A');
  p.add_an_element('C');
  p.add_an_element('B');
  p.add_an_element('A');
  p.print();
  p.print_elements();
}
