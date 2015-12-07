
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
  HMatrix m(2,2);

  for (unsigned int i=0; i<3; ++i)
    for (unsigned int j=0; j<4; ++j)
      m.add_one(i,j);
  m.add_one(1,1);
  m.add_one(2,1);
  m.add_one(1,2);
  m.add_one(1,2);
  m.add_one(1,3);
  m.add_one(1,3);
  m.add_one(0,3);
  m.add_one(1,3);
  m.add_one(2,3);

  m.print(p,q,false);

  m.first_step(p,q);
  m.print(p,q,false);

  m.first_step(p,q,false);
  m.print(p,q,false);
}
