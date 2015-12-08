/*
 * Description
 * Author: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 * test: LPermutation and switch_elements
 */

#include "permutation.h"
#include "utilities.h"

int main(int argc, char *argv[])
{
  print_msg("Create a permutation of three elements:");
  LPermutation p;
  p.add_an_element('A');
  p.add_an_element('B');
  p.add_an_element('C');
  p.add_an_element('A',true);
  p.add_an_element('A',true);
  std::cout << p;
  print_msg("Permute 1 and 0:");
  p.switch_elements(0,1);
  std::cout << p;
  print_msg("Permute 2 and 0:");
  p.switch_elements(0,2);
  std::cout << p;
  print_msg("Add an element:");
  p.add_an_element('D');
  std::cout << p;
}
