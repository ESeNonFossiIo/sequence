#ifndef __hungarian_matrix_h__
#define __hungarian_matrix_h__

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <iostream>

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

/**
 * HungarianMatrix specializes Matrix to deal with the problem of maximizing
 * the trance
 */
template<typename T>
class HungarianMatrix : public Matrix
{
  public:
    HungarianMatrix(unsigned int rows, unsigned int cols);

    void row_swap(unsigned int i, unsigned int j);
    void col_swap(unsigned int i, unsigned int j);

  private:
    std::map<unsigned int, unsigned int> map1;
    std::map<unsigned int, unsigned int> map2;
};


//
//   T operator() (int i, int j)
//   {
//     row_map(i);
//     column_map(j);
//     return m[map1[i]][map2[j]];
//   }
//
//   void row_swap(int i, int j)
//   {
//     row_map(i);
//     row_map(j);
//     int tmp = map1[i];
//     map1[i] = map1[j];
//     map1[j] = tmp;
//   }
//
//   void column_swap(int i, int j)
//   {
//     column_map(i);
//     column_map(j);
//     int tmp = map2[i];
//     map2[i] = map2[j];
//     map2[j] = tmp;
//   }
//
// };

#endif
