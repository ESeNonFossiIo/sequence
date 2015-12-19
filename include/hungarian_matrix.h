#ifndef __hungarian_matrix_h__
#define __hungarian_matrix_h__

#include <stdlib.h>
#include <vector>
#include <iostream>
#include "permutation.h"
#include "mask.h"
#include "matrix.h"


/**
 *  Hungarian Matrix Class stores data in matrix form to solve
 *  a maximize trace problem.
 */
class HMatrix : public Matrix<unsigned int>
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
  update(bool complement = true);

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
  solution();

  /**
   *  TODO:
   */
  void
  diagonalize();
  
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
   *  Return the element in postion @p i, @p j.
   */
  unsigned int
  status(unsigned int i, unsigned int j);
  
  /**
   * TODO:
   */
  bool
  check_rank();

  /**
   * TODO:
   */
  bool
  check_result();

  /**
   *  Overload of the output operator <<.
   *  It is possible to check the ouput of the matrix in the following way:
   *  @code{.cpp}
   *   Matrix p;
   *   ...
   *   std::cout << p;
   *  @endcode
   */
  friend std::ostream &operator<< (std::ostream &os, const HMatrix &dt);

protected:
  /**
   *  Mask used to remove entries.
   */
  Mask mask;

  /**
   *  Mask used to remove entries.
   */
  Mask result_mask;
  
private:
  /**
   *  Resulting matrix.
   */
  std::vector<std::vector<unsigned int> > res;

  /**
   *  Permutation on the rows.
   */
  LPermutation p_row;

  /**
   *  Permutation on the coloumns.
   */
  LPermutation p_col;

  /**
   * TODO:
   */
  unsigned int size;

  /**
   * TODO:
   */
  unsigned int max_val;
};

#endif
