
/*
 * Description
 * Author: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 */

#include "matrix.h"

int main(int argc, char *argv[])
{
  Permutation p(3);
  Permutation q(4);
  Matrix m(2,2);

  m.add_one(1,1);
  m.add_one(2,1);
  m.add_one(1,2);
  m.add_one(1,2);
  m.add_one(1,3);

  m.print(p,q,false);
  std::cout << "trace = " << m.trace(p,q) << std::endl;

  std::cout << std::endl << std::endl << std::endl
            << " Switch 0 and 1 rows: "
            << std::endl;
  p.switch_elements(0,1);
  m.print(p,q,false);
  std::cout << "trace = " << m.trace(p,q) << std::endl;

  std::cout << std::endl << std::endl << std::endl
            << " Switch 0 and 2 coloumns: "
            << std::endl;
  q.switch_elements(0,2);
  m.print(p,q,false);
  std::cout << "trace = " << m.trace(p,q) << std::endl;
}
