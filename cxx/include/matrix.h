#ifndef __matrix_h__
#define __matrix_h__

#include <stdlib.h>
#include <vector>

/**
 *  Matrix Class is a generic structure to store data in matrix form
 */
class Matrix
{
public:
  /**
   * Constructor takes the number of rows and coloumns
   */
  Matrix (unsigned int rows, unsigned int cols);

  /**
   *  Add one to the element in position @p i,  @p j
   */
  void
  add_one (unsigned int i, unsigned int j);

  /**
   *  Output of the matrix
   */
  void
  print ();

private:
  /**
   *  Matrix
   */
  std::vector<std::vector<unsigned int> > mat;

  /**
   *  Number of rows
   */
  unsigned int n_row;

  /**
   *  Number of coloumns
   */
  unsigned int n_col;
};

#endif
