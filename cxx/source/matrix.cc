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

unsigned int
Matrix::trace (Permutation p_row, Permutation p_col)
{
  unsigned int result=0;
  unsigned int max_minor = ( n_col>n_row ? n_row : n_col );

  for (unsigned int i=0; i<max_minor; ++i)
    result+=mat[p_row[i]][p_col[i]];

  return result;
}

void
Matrix::print (Permutation p_row, Permutation p_col, bool report)
{
  if (report)
    {
      std::vector<std::string> msg;
      msg.push_back(" Number of Rows:      "+std::to_string(n_row));
      msg.push_back(" Number of Coloumns:  "+std::to_string(n_col));
      print_msg(msg);
    }

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

HMatrix::HMatrix(unsigned int rows, unsigned int cols)
  :
  Matrix(rows,cols)
{}

void
HMatrix::first_step(Permutation p_row, Permutation p_col, bool row)
{
  if (row)
    {
      for (unsigned int i = 0; i<n_row; ++i)
        {
          unsigned int min = mat[p_row[i]][p_col[0]];
          for (unsigned int j = 1; j<n_col; ++j)
            if (mat[p_row[i]][p_col[j]]<min)
              min=mat[p_row[i]][p_col[j]];
          for (unsigned int j = 0; j<n_col; ++j)
            mat[p_row[i]][p_col[j]]-=min;
        }
    }
  else
    {
      for (unsigned int j = 0; j<n_col; ++j)
        {
          unsigned int min = mat[p_row[0]][p_col[j]];
          for (unsigned int i = 0; i<n_row; ++i)
            if (mat[p_row[i]][p_col[j]]<min)
              min=mat[p_row[i]][p_col[j]];
          for (unsigned int i = 0; i<n_row; ++i)
            mat[p_row[i]][p_col[j]]-=min;
        }
    }
}
