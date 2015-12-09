#ifndef __matrix_h__
#define __matrix_h__

#include <stdlib.h>
#include <vector>
#include <iostream>
#include "permutation.h"

/**
 *  Matrix Class is a generic structure to store data in matrix form.
 */
class Matrix
{
public:
  /**
   * Constructor takes the number of rows and coloumns and
   *  initialize mat with zeroes.
   */
  Matrix (unsigned int rows, unsigned int cols);

  /**
   * Constructor takes the number of rows and coloumns and
   *  initialize mat with the elements of m.
   */
  Matrix(unsigned int rows, unsigned int cols,
         std::vector<std::vector<unsigned int> > m);

  /**
   * Constructor a matrix with the same entries.
   */
  Matrix (const Matrix &m);

  /**
   *  Add one to the element in position @p i and @p j.
   *  @p output_matrix enables the output of the situation.
   */
  void
  add_one (unsigned int i, unsigned int j);

  /**
   * Calulate the numeber of zeroes in each row (coloumn).
   * If @p row is true it will be made using rows, otherwise
   * coloumns.
   * The result is a vector that indicates the number of zeroes
   * in each row (coloumn).
   */
  std::vector<unsigned int>
  zeroes(bool row=true);

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
   * Calulate the maximum value of the matrix;
   */
  unsigned int
  maximum_value();

  /**
   * TODO:
   */
  void
  maximum_complement();

  /**
   *  Permute the matrix according to the Permutation @p p and
   *  evaluate the trace.
   *  If the bool @p row is set on true the Permutation is made
   *  on the rows, otherwise on coloumns.
   */
  unsigned int
  trace ();

  /**
   *  Status of the matrix:
   *  - Number of rows
   *  - Number of coloumns
   *  - Trace
   */
  void
  status();

  /**
   *  Copy operator.
   */
  Matrix &
  operator=(Matrix other);

  /**
   *  Overload of the output operator <<.
   *  It is possible to check the ouput of the matrix in the following way:
   *  @code{.cpp}
   *   Matrix p;
   *   ...
   *   std::cout << p;
   *  @endcode{.cpp}
   */
  friend std::ostream &operator<< (std::ostream &os,
                                   const Matrix &dt);

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

#endif
