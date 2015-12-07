#ifndef __matrix_h__
#define __matrix_h__

#include <stdlib.h>
#include <vector>
#include "permutation.h"

/**
 *  Matrix Class is a generic structure to store data in matrix form.
 */
class Matrix
{
public:
  /**
   * Constructor takes the number of rows and coloumns.
   */
  Matrix (unsigned int rows, unsigned int cols);

  /**
   *  Add one to the element in position @p i and @p j.
   */
  void
  add_one (unsigned int i, unsigned int j);

  /**
   *  Permute the matrix according to the Permutation @p p and
   *  evaluate the trace.
   *  If the bool @p row is set on true the Permutation is made
   *  on the rows, otherwise on coloumns.
   */
  unsigned int
  trace (Permutation p_row, Permutation p_col);

  /**
   *  Output of the matrix.
   */
  void
  print (Permutation p_row, Permutation p_col, bool report = true);

protected:
  /**
   *  Number of rows.
   */
  unsigned int n_row;

  /**
   *  Number of coloumns.
   */
  unsigned int n_col;

  /**
   *  Matrix.
   */
  std::vector<std::vector<unsigned int> > mat;
};

/**
 *  Hungarian Matrix Class stores data in matrix form to solve
 *  a maximize trace problem.
 */
class HMatrix : public Matrix
{
public:
  HMatrix(unsigned int rows, unsigned int cols);

  void
  first_step(Permutation p_row, Permutation p_col, bool row = true);

private:
  /**
   *  Resulting matrix.
   */
  std::vector<std::vector<unsigned int> > res;
};

#endif
