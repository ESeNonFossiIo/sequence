
/*
 * Description
 * Author: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 */

#include "matrix.h"

int main(int argc, char *argv[])
{
  Permutation id(4);
  id.print();
  Matrix m(2,2);
  m.add_one(1,1);
  m.add_one(1,1);
  m.add_one(3,3);
  m.print(id,id);
}
