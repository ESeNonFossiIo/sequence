#ifndef __mask_h__
#define __mask_h__

#include <stdlib.h>
#include <vector>
#include <iostream>
#include "permutation.h"
#include "matrix.h"
// #include "hungarian_matrix.h"


/**
 *  TODO:
 */
class Mask : public Matrix<char>
{
public:
  /**
   *  Hungarian Matrix Class constructor.
   */
  Mask();
  
  /**
   *  Hungarian Matrix Class constructor.
   */
  Mask(std::vector<std::vector<unsigned int>> m);

  /**
   *  Copy the value of @p res in @p old_res
   */
  void
  update();

  /**
   * Calulate the numeber of 'x' in each row (coloumn) of mask
   * matrix.
   * If @p row is true it will be made using rows, otherwise
   * coloumns.
   * The result is a vector that indicates the number of 'x'
   * in each row (coloumn).
   */
  std::vector<unsigned int>
  zeroes(bool row=true);

  std::vector<unsigned int>
  zeroes_result(bool row=true);

  /**
   * TODO:
   */
  void
  initialize(std::vector<std::vector<unsigned int>> m);

  /**
   * TODO:
   */
  void
  status();

  /**
   * TODO:
   */
  bool
  rank();

  /**
   * TODO:
   */
   unsigned int
  get_size();

  /**
   * TODO:
   */
  bool
  select_elements(std::vector<std::vector<unsigned int>> m);
  
  /**
   *  Overload of the output operator <<.
   *  It is possible to check the ouput of the matrix in the following way:
   *  @code{.cpp}
   *   Matrix p;
   *   ...
   *   std::cout << p;
   *  @endcode
   */
  friend std::ostream &operator<< (std::ostream &os, const Mask &dt);

protected:
  /**
   * Size of the mask.
   */
  unsigned int size;
};

#endif
