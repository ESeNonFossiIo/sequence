/*
 * Description
 * Author: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 * test: Hmatrix copy constructor and first_step
 */

#include "hungarian_matrix.h"
#include "utilities.h"

int main(int argc, char *argv[])
{
  using namespace utilities;

  HMatrix m;
  char c[4]= {'A', 'B', 'C'};
  for (unsigned int i=0; i<3; ++i)
    for (unsigned int j=0; j<3; ++j)
      m.add_an_element(c[i],c[j]);
  m.add_an_element(c[1],c[1]);
  m.add_an_element(c[0],c[1]);
  m.add_an_element(c[0],c[1]);
  m.add_an_element(c[1],c[0]);
  m.add_an_element(c[0],c[1]);
  m.add_an_element(c[0],c[1]);
  m.add_an_element(c[0],c[1]);
  m.add_an_element(c[1],c[1]);
  m.add_an_element(c[2],c[1]);
  HMatrix n(m);

  print_msg("Original matrix:");
  m.update();
  std::cout << m;

  auto min    = m.get_min();
  print_msg("Minimum per row:");
  print<unsigned int>(min,    2);

  min    = m.get_min(false);
  print_msg("Minimum per column:");
  print<unsigned int>(min,    2);

  print_msg("First step using row:");
  m.first_step();
  m.update();
  std::cout << m;

  print_msg("First step using coloumns:");
  n.first_step(false);
  n.update();
  std::cout << n;
}
