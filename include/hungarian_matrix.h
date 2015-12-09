#ifndef __hungarian_matrix_h__
#define __hungarian_matrix_h__

#include <stdlib.h>
#include <vector>
#include <iostream>
#include "permutation.h"
#include "matrix.h"

/**
 *  Hungarian Matrix Class stores data in matrix form to solve
 *  a maximize trace problem.
 */
class HMatrix : public Matrix
{
public:
  /**
   *  Hungarian Matrix Class constructor.
   */
  HMatrix();

  /**
   * Constructor a matrix with the same entries.
   */
  HMatrix (const HMatrix &m);

  /**
   *  Copy the value of @p res in @p old_res
   */
  void
  update();

  /**
   *  TODO:
   */
  void
  switch_elements(unsigned int i, unsigned int j, bool row=true);

  /**
   *  TODO:
   */
  void
  sort(bool row=true);

  /**
   *  TODO:
   */
  void
  add_an_element(char c_row, char c_col);

  /**
   *  Remove from each row (coloumn) the minimun element.
   *  @p row set if operation will be made on rows (true)
   *  or coloumns (false). Default value is trues.
   */
  void
  first_step(bool row = true);

  /**
   *  TODO:
   */
  void
  second_step(bool row = true);

  /**
   * TODO:
   */
  std::vector<unsigned int>
  blank(bool row=true);

  /**
   * Calulate the min value in each row (coloumn).
   * If @p row is true it will be made using rows, otherwise
   * coloumns.
   * The result is a vector that indicates the min value
   * in each row (coloumn).
   */
  std::vector<unsigned int>
  get_min(bool row=true);

  /**
   * Calulate the max value in each row (coloumn).
   * If @p row is true it will be made using rows, otherwise
   * coloumns.
   * The result is a vector that indicates the max value
   * in each row (coloumn).
   */
  std::vector<unsigned int>
  get_max(bool row=true);

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

  /**
   * TODO:
   */
  void
  initialize_mask();

  /**
   * TODO:
   */
  void
  status_mask();

  /**
   * TODO:
   */
  bool
  check_rank();

  /**
   *  Overload of the output operator <<.
   *  It is possible to check the ouput of the matrix in the following way:
   *  @code{.cpp}
   *   Matrix p;
   *   ...
   *   std::cout << p;
   *  @endcode{.cpp}
   */
  friend std::ostream &operator<< (std::ostream &os, const HMatrix &dt);

private:
  /**
   *  Resulting matrix.
   */
  std::vector<std::vector<unsigned int> > res;

  /**
   *  Mask used to remove entries.
   */
  std::vector<std::vector<char> > mask;

  /**
   *  Permutation on the rows.
   */
  LPermutation p_row;

  /**
   *  Permutation on the coloumns.
   */
  LPermutation p_col;
};

#endif
