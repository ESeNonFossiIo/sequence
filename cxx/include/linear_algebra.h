
/*
 * Authors: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 */

#ifndef __linear_algebra__
#define __linear_algebra__

#include <iostream>
#include <vector>

template <int dim, int spacedim=dim>
class LinearAlgebra
{
public:
  LinearAlgebra ();
  ~LinearAlgebra ();

  void print(std::ostream &out = std::cout) const;
private:

};

#endif
