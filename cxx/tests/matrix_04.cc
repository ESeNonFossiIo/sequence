/*
 * Description
 * Author: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 * test: Hmatrix copy constructor and first_step
 */

#include "matrix.h"
#include "utilities.h"

int main(int argc, char *argv[])
{
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

  auto zeroes = m.zeroes();
  auto min    = m.min();
  print_msg("Number of zeroes per row:");
  print_sequence<unsigned int>(zeroes, 2);
  print_msg("Minimum per row:");
  print_sequence<unsigned int>(min,    2);

  zeroes = m.zeroes(false);
  min    = m.min(false);
  print_msg("Number of zeroes per column:");
  print_sequence<unsigned int>(zeroes, 2);
  print_msg("Minimum per column:");
  print_sequence<unsigned int>(min,    2);

  print_msg("First step using row:");
  m.first_step();
  m.update();
  std::cout << m;

  print_msg("First step using coloumns:");
  n.first_step(false);
  n.update();
  std::cout << n;
}
