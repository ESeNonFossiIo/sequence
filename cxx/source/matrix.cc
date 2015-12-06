/*
 * Authors: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 */

#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw
#include <vector>
#include <cmath>
#include "matrix.h"
#include "utilities.h"

Matrix::Matrix(unsigned int rows, unsigned int cols)
  :
  n_row(rows),
  n_col(cols)
{
  mat.resize(rows);
  for (unsigned int i = 0; i<rows; ++i)
    mat[i].resize(cols, 0);
}

void
Matrix::add_one(unsigned int i, unsigned int j)
{
  if (i>=n_row)
    {
      n_row=i+1;
      mat.resize(n_row);
    }
  if (j>=n_col)
    n_col=j+1;

  for (unsigned int h = 0; h<n_row; ++h)
    {
      mat[h].resize(n_col, 0);
    }
  mat[i][j]++;
}

void
Matrix::print (Permutation p_row, Permutation p_col)
{
  std::vector<std::string> msg;
  msg.push_back(" Number of Rows:      "+std::to_string(n_row));
  msg.push_back(" Number of Coloumns:  "+std::to_string(n_col));
  print_msg(msg);

  std::cout << std::endl << std::endl;
  for (unsigned int i = 0; i < n_row; ++i)
    {
      for (unsigned int j = 0; j < n_col; ++j)
        std::cout << "+" << "---";
      std::cout << "+" << std::endl << "|";
      for (unsigned int j = 0; j<n_col; ++j)
        std::cout << std::setw(3) << mat[p_row[i]][p_col[j]] << "|";
      std::cout << std::endl;
    }
  for (unsigned int j = 0; j < n_col; ++j)
    std::cout << "+" << "---";
  std::cout << "+" << std::endl;
}
