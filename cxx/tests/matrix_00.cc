
/*
 * Usage:
 * cd build
 * cmake ..
 * make
 * make run
 *
 * Description
 * Author: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 */


#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include "linear_algebra.h"
#include "matrix.h"

int main(int argc, char *argv[])
{

  hungarian_matrix<int> overlap_matrix;

  // test
  std::cout << "fill the matrix:" << std::endl;
  for(size_t i=0; i<3; ++i) 
  {
    for(size_t j=0; j<10; ++j) 
    {
      overlap_matrix.insert(i,j,i*10+10+j);
      std::cout << overlap_matrix(i,j) << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  // swap tests:
  std::cout << "swap row 0 and 2:" << std::endl;
  overlap_matrix.row_swap(0,2);
  std::cout << "swap column 4 and 3:" << std::endl;
  overlap_matrix.column_swap(4,3);
  for(size_t i=0; i<3; ++i)
  {
    for(size_t j=0; j<10; ++j)   
    {
      std::cout << overlap_matrix(i,j) << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  // fail test
  overlap_matrix.row_swap(0,10);

  return 0;
}
