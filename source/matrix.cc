/*
 * Authors: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 */

#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw
#include <algorithm>    // std::find
#include <set>
#include <vector>
#include <cmath>

#include "matrix.h"
#include "utilities.h"

using namespace utilities;

Matrix::Matrix(unsigned int rows, unsigned int cols)
  :
  n_row(rows),
  n_col(cols)
{
  mat.resize(rows);
  for (unsigned int i = 0; i<rows; ++i)
    mat[i].resize(cols, 0);
}

Matrix::Matrix(unsigned int rows, unsigned int cols,
               std::vector<std::vector<unsigned int> > m)
  :
  n_row(rows),
  n_col(cols)
{
  mat.resize(rows);
  for (unsigned int i = 0; i<rows; ++i)
    mat[i].resize(cols, 0);
  for (unsigned int i = 0; i<rows; ++i)
    for (unsigned int j = 0; j<cols; ++j)
      mat[i][j]=m[i][j];
}

Matrix::Matrix(const Matrix &m)
  :
  n_row(m.n_row),
  n_col(m.n_col),
  mat(m.mat)
{}

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

std::vector<unsigned int>
Matrix::zeroes(bool row)
{
  std::vector<unsigned int> return_vector;
  if (row)
    for (unsigned int i=0; i<n_row; ++i)
      {
        return_vector.push_back(0);
        for (unsigned int j=0; j<n_col; ++j)
          if (mat[i][j]==0)
            return_vector[i]++;
      }
  else
    for (unsigned int j=0; j<n_col; ++j)
      {
        return_vector.push_back(0);
        for (unsigned int i=0; i<n_row; ++i)
          if (mat[i][j]==0)
            return_vector[j]++;
      }
  return return_vector;
}

std::vector<unsigned int>
Matrix::get_min(bool row)
{
  std::vector<unsigned int> return_vector;
  if (row)
    for (unsigned int i=0; i<n_row; ++i)
      {
        return_vector.push_back(mat[i][0]);
        for (unsigned int j=1; j<n_col; ++j)
          if (mat[i][j]<return_vector[i])
            return_vector[i]=mat[i][j];
      }
  else
    for (unsigned int j=0; j<n_col; ++j)
      {
        return_vector.push_back(mat[0][j]);
        for (unsigned int i=1; i<n_row; ++i)
          if (mat[i][j]<return_vector[j])
            return_vector[j]=mat[i][j];
      }
  return return_vector;
}

std::vector<unsigned int>
Matrix::get_max(bool row)
{
  std::vector<unsigned int> return_vector;
  if (row)
    for (unsigned int i=0; i<n_row; ++i)
      {
        return_vector.push_back(mat[i][0]);
        for (unsigned int j=1; j<n_col; ++j)
          if (mat[i][j]>return_vector[i])
            return_vector[i]=mat[i][j];
      }
  else
    for (unsigned int j=0; j<n_col; ++j)
      {
        return_vector.push_back(mat[0][j]);
        for (unsigned int i=1; i<n_row; ++i)
          if (mat[i][j]>return_vector[j])
            return_vector[j]=mat[i][j];
      }
  return return_vector;
}

unsigned int
Matrix::maximum_value()
{
  unsigned int maximum = mat[0][0];
  for (unsigned int i=0; i<n_row; ++i)
    for (unsigned int j=0; j<n_col; ++j)
      if(mat[i][j]>maximum)
        maximum = mat[i][j];
  return maximum;
}

void
Matrix::maximum_complement()
{
  unsigned int maximum = maximum_value();
  for (unsigned int i=0; i<n_row; ++i)
    for (unsigned int j=0; j<n_col; ++j)
      mat[i][j] = maximum - mat[i][j];
}

unsigned int
Matrix::trace ()
{
  unsigned int result=0;
  unsigned int max_minor = ( n_col>n_row ? n_row : n_col );

  for (unsigned int i=0; i<max_minor; ++i)
    result+=mat[i][i];

  return result;
}

void
Matrix::status()
{
  std::vector<std::string> msg;
  msg.push_back(" Number of Rows:      "+std::to_string(n_row));
  msg.push_back(" Number of Coloumns:  "+std::to_string(n_col));
  msg.push_back(" Trace:               "+std::to_string(trace()));
  print_msg(msg);
}

Matrix &
Matrix::operator=(Matrix other)
{
  this->n_row=other.n_row;
  this->n_col=other.n_col;
  this->mat=other.mat;
  return *this;
}
