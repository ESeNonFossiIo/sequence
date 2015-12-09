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
#include "hungarian_matrix.h"
#include "utilities.h"

using namespace utilities;

HMatrix::HMatrix()
  :
  Matrix(0,0)
{
  update();
}

HMatrix::HMatrix(const HMatrix &hm)
  :
  Matrix(hm.n_row, hm.n_col, hm.mat),
  res(hm.res),
  p_row(hm.p_row),
  p_col(hm.p_col)
{
  update();
}

void
HMatrix::update()
{
  res.resize(n_row);
  for (unsigned int i = 0; i<n_row; ++i)
    res[i].resize(n_col, 0);

  for (unsigned int r=0; r<n_row; ++r)
    for (unsigned int c=0; c<n_col; ++c)
      res[r][c]=mat[r][c];
}

void
HMatrix::add_an_element(char c_row, char c_col)
{
  p_row.add_an_element(c_row);
  p_col.add_an_element(c_col);
  add_one(p_row.get_int(c_row), p_col.get_int(c_col));
}

void
HMatrix::switch_elements(unsigned int i, unsigned int j, bool row)
{
  if (row)
    p_row.switch_elements(i,j);
  else
    p_col.switch_elements(i,j);

  for (unsigned int r = 0; r<n_row; ++r)
    for (unsigned int c = 0; c<n_row; ++c)
      res[r][c]=mat[p_row[r]][p_col[c]];
}

void
HMatrix::first_step(bool row)
{
  std::vector<unsigned int> min = get_min(row);
  if (row)
    {
      for (unsigned int i = 0; i<n_row; ++i)
        for (unsigned int j = 0; j<n_col; ++j)
          res[i][j]-=min[i];
    }
  else
    {
      for (unsigned int j = 0; j<n_col; ++j)
        for (unsigned int i = 0; i<n_row; ++i)
          res[i][j]-=min[j];
    }
}

std::vector<unsigned int>
HMatrix::blank(bool row)
{
  std::vector<unsigned int> out_result;
  if (row)
    {
      for (unsigned int i = 0; i<n_row; ++i)
        for (unsigned int j = 0; j<n_col; ++j)
          if (mask[i][j]==' ')
            {
              out_result.push_back(i);
              break;
            }
    }
  else
    {
      for (unsigned int j = 0; j<n_col; ++j)
        for (unsigned int i = 0; i<n_row; ++i)
          if (mask[i][j]==' ')
            {
              out_result.push_back(j);
              break;
            }
    }
  return out_result;
}

void
HMatrix::second_step(bool row)
{
  std::vector<unsigned int> elements;
  unsigned int max_element;

  for (unsigned int i = 0; i<n_row; ++i)
    for (unsigned int j = 0; j<n_col; ++j)
      if (mask[i][j]==' ')
        elements.push_back(res[i][j]);

  max_element = min(elements).first;

  std::vector<unsigned int> blank_elements;
  blank_elements=blank(row);

  if (row)
    {
      std::vector<unsigned int> tmp_vec;
      for (unsigned int j = 0; j<n_col; ++j)
        if (res[blank_elements[0]][j]==0)
          tmp_vec.push_back(j);

      for (typename std::vector<unsigned int>::iterator it=tmp_vec.begin();
           it!=tmp_vec.end(); ++it)
        for (unsigned int i = 0; i<n_row; ++i)
          res[i][*it]+=max_element;

      for (typename std::vector<unsigned int>::iterator it=blank_elements.begin();
           it!=blank_elements.end(); ++it)
        for (unsigned int j = 0; j<n_col; ++j)
          res[*it][j]-=max_element;
    }
  else
    {
      std::vector<unsigned int> tmp_vec;
      for (unsigned int i = 0; i<n_row; ++i)
        if (res[blank_elements[i]][0]==0)
          tmp_vec.push_back(i);

      for (typename std::vector<unsigned int>::iterator it=tmp_vec.begin();
           it!=tmp_vec.end(); ++it)
        for (unsigned int j = 0; j<n_col; ++j)
          res[*it][j]+=max_element;

      for (typename std::vector<unsigned int>::iterator it=blank_elements.begin();
           it!=blank_elements.end(); ++it)
        for (unsigned int i = 0; i<n_row; ++i)
          res[i][*it]-=max_element;
    }
}

std::vector<unsigned int>
HMatrix::get_min(bool row)
{
  std::vector<unsigned int> return_vector;
  if (row)
    for (unsigned int i=0; i<n_row; ++i)
      {
        return_vector.push_back(res[i][0]);
        for (unsigned int j=1; j<n_col; ++j)
          if (res[i][j]<return_vector[i])
            return_vector[i]=res[i][j];
      }
  else
    for (unsigned int j=0; j<n_col; ++j)
      {
        return_vector.push_back(res[0][j]);
        for (unsigned int i=1; i<n_row; ++i)
          if (res[i][j]<return_vector[j])
            return_vector[j]=res[i][j];
      }
  return return_vector;
}

std::vector<unsigned int>
HMatrix::get_max(bool row)
{
  std::vector<unsigned int> return_vector;
  if (row)
    for (unsigned int i=0; i<n_row; ++i)
      {
        return_vector.push_back(res[i][0]);
        for (unsigned int j=1; j<n_col; ++j)
          if (res[i][j]>return_vector[i])
            return_vector[i]=res[i][j];
      }
  else
    for (unsigned int j=0; j<n_col; ++j)
      {
        return_vector.push_back(res[0][j]);
        for (unsigned int i=1; i<n_row; ++i)
          if (res[i][j]>return_vector[j])
            return_vector[j]=res[i][j];
      }
  return return_vector;
}

std::vector<unsigned int>
HMatrix::zeroes(bool row)
{
  unsigned int max_row_col = ( n_row>n_col ? n_row : n_col );

  std::vector<unsigned int> return_vector;
  if (row)
    for (unsigned int i=0; i<max_row_col; ++i)
      {
        return_vector.push_back(0);
        for (unsigned int j=0; j<max_row_col; ++j)
          if (mask[i][j]=='x')
            return_vector[i]++;
      }
  else
    for (unsigned int j=0; j<max_row_col; ++j)
      {
        return_vector.push_back(0);
        for (unsigned int i=0; i<max_row_col; ++i)
          if (mask[i][j]=='x')
            return_vector[j]++;
      }
  return return_vector;
}

void
HMatrix::initialize_mask()
{
  unsigned int max_row_col = ( n_row>n_col ? n_row : n_col );
  mask.resize(max_row_col);
  for (unsigned int i = 0; i<max_row_col; ++i)
    mask[i].resize(max_row_col);

  for (unsigned int i = 0; i<max_row_col; ++i)
    for (unsigned int j = 0; j<max_row_col; ++j)
      if (i<n_row && j<n_col && res[i][j]!=0)
        mask[i][j]=' ';
      else
        mask[i][j]='x';
}

void
HMatrix::status_mask()
{
  unsigned int max_row_col = ( n_row>n_col ? n_row : n_col );
  std::string row_init = "    ";
  unsigned int spaces  = 2;
  std::cout << std::endl;
  for (unsigned int r = 0; r < max_row_col; ++r)
    {
      std::cout << row_init << "+" << "---";
      for (unsigned int c = 1; c < max_row_col; ++c)
        std::cout << "+" << "---";
      std::cout << "+" << std::endl
                << row_init << "|";
      for (unsigned int c = 0; c< max_row_col; ++c)
        std::cout << std::setw(spaces) << mask[r][c] << " |";
      std::cout << std::endl;
    }
  std::cout << row_init;
  for (unsigned int c = 0; c < max_row_col; ++c)
    std::cout << "+" << "---";
  std::cout << "+" << std::endl;
}

void
HMatrix::sort(bool row)
{
  // TODO:
}

bool
HMatrix::check_rank()
{
  bool result = false;
  unsigned int counter     = 0;
  unsigned int max_row_col = ( n_row>n_col ? n_row : n_col );

  initialize_mask();

  auto row_zeroes = zeroes(true);
  auto col_zeroes = zeroes(false);
  auto max_row = utilities::max(row_zeroes);
  auto max_col = utilities::max(col_zeroes);

  while (max_row.first>0 && max_col.first>0)
    {
      if ( max_row.first < max_col.first )
        {
          for (unsigned int i = 0; i<max_row_col; ++i)
            if (mask[i][max_col.second]!='-')
              mask[i][max_col.second]='|';
            else
              mask[i][max_col.second]='+';
          counter++;
        }
      else
        {
          for (unsigned int i = 0; i<max_row_col; ++i)
            if (mask[max_row.second][i]!='|')
              mask[max_row.second][i]='-';
            else
              mask[max_row.second][i]='+';
          counter++;
        }

      row_zeroes = zeroes(true);
      col_zeroes = zeroes(false);
      max_row = utilities::max(row_zeroes);
      max_col = utilities::max(col_zeroes);
    }
  if (counter==max_row_col) result = true;

  return result;
}
