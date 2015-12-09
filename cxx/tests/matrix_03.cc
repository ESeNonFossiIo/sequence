/*
 * Description
 * Author: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 * test: Switch rows and coloumns
 */

#include "matrix.h"
#include "utilities.h"

int main(int argc, char *argv[])
{
  using namespace utilities;

  HMatrix m;
  m.add_an_element('A','A');
  m.add_an_element('A','B');
  m.add_an_element('A','C');
  m.add_an_element('B','A');
  m.add_an_element('B','B');
  m.add_an_element('B','C');
  m.add_an_element('C','A');
  m.add_an_element('C','B');
  m.add_an_element('C','C');

  m.add_an_element('B','B');
  m.add_an_element('A','B');
  m.add_an_element('A','B');
  m.add_an_element('B','A');

  m.status();
  m.update();

  print_msg("Matrix:");
  std::cout << m;

  print_msg("Switch rows:");
  m.switch_elements(0,1);
  std::cout << m;

  print_msg("Switch coloumns:");
  m.switch_elements(0,1,false);
  std::cout << m;
}
