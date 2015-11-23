
/*
 * Authors: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 */

#include <iostream>
#include <vector>
#include <cmath>
#include "linear_algebra.h"

template <int dim, int spacedim>
LinearAlgebra<dim,spacedim>::LinearAlgebra ()
  :
  (),
  ()
{}


template <int dim, int spacedim>
LinearAlgebra<dim,spacedim>::~LinearAlgebra ()
{}


template <int dim, int spacedim>
void LinearAlgebra<dim,spacedim>::print(std::ostream &out) const
{
  out << std::endl;
  return;
}


// explicit instantiations
template class LinearAlgebra<1,1>;
template class LinearAlgebra<1,2>;
template class LinearAlgebra<2,2>;
template class LinearAlgebra<1,3>;
template class LinearAlgebra<2,3>;
template class LinearAlgebra<3,3>;
