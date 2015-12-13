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
{}

HMatrix::HMatrix(const HMatrix &hm)
  :
  Matrix(hm.n_row, hm.n_col, hm.mat),
  res(hm.res),
  p_row(hm.p_row),
  p_col(hm.p_col),
  size(0),
  max_val(0)
{
  update();
}

void
HMatrix::update(bool complement)
{
  max_val = maximum_value();
  size = n_row > n_col ? n_row : n_col;

  res.resize(size);
  for (unsigned int i = 0; i<size; ++i)
    complement ? res[i].resize(size, max_val) : res[i].resize(size, 0);

  for (unsigned int r=0; r<size; ++r)
    for (unsigned int c=0; c<size; ++c)
      if (r<n_row && c<n_col)
        res[r][c] = complement ?  max_val - mat[r][c] : mat[r][c] ;
      else
        res[r][c] = complement ?  max_val : 0 ;
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
  //TODO: fix for square matrix... std::swap
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
      for (unsigned int i = 0; i<size; ++i)
        for (unsigned int j = 0; j<size; ++j)
          res[i][j]-=min[i];
    }
  else
    {
      for (unsigned int j = 0; j<size; ++j)
        for (unsigned int i = 0; i<size; ++i)
          res[i][j]-=min[j];
    }
}

std::vector<unsigned int>
HMatrix::blank(bool row)
{
  std::vector<unsigned int> out_result;
  if (row)
    {
      for (unsigned int i = 0; i<size; ++i)
        for (unsigned int j = 0; j<size; ++j)
          if (mask[i][j]==' ')
            {
              out_result.push_back(i);
              break;
            }
    }
  else
    {
      for (unsigned int j = 0; j<size; ++j)
        for (unsigned int i = 0; i<size; ++i)
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

  for (unsigned int i = 0; i<size; ++i)
    for (unsigned int j = 0; j<size; ++j)
      if (mask[i][j]==' ')
        elements.push_back(res[i][j]);

  max_element = min(elements).first;

  std::vector<unsigned int> blank_elements;
  blank_elements=blank(row);

  if (row)
    {
      std::vector<unsigned int> tmp_vec;
      for (unsigned int j = 0; j<size; ++j)
        if (res[blank_elements[0]][j]==0)
          tmp_vec.push_back(j);

      for (typename std::vector<unsigned int>::iterator it=tmp_vec.begin();
           it!=tmp_vec.end(); ++it)
        for (unsigned int i = 0; i<size; ++i)
          res[i][*it]+=max_element;

      for (typename std::vector<unsigned int>::iterator it=blank_elements.begin();
           it!=blank_elements.end(); ++it)
        for (unsigned int j = 0; j<size; ++j)
          res[*it][j]-=max_element;
    }
  else
    {
      std::vector<unsigned int> tmp_vec;
      for (unsigned int i = 0; i<size; ++i)
        if (res[blank_elements[i]][0]==0)
          tmp_vec.push_back(i);

      for (typename std::vector<unsigned int>::iterator it=tmp_vec.begin();
           it!=tmp_vec.end(); ++it)
        for (unsigned int j = 0; j<size; ++j)
          res[*it][j]+=max_element;

      for (typename std::vector<unsigned int>::iterator it=blank_elements.begin();
           it!=blank_elements.end(); ++it)
        for (unsigned int i = 0; i<size; ++i)
          res[i][*it]-=max_element;
    }
}

std::vector<unsigned int>
HMatrix::get_min(bool row)
{
  std::vector<unsigned int> return_vector;
  if (row)
    for (unsigned int i=0; i<size; ++i)
      {
        return_vector.push_back(res[i][0]);
        for (unsigned int j=1; j<size; ++j)
          if (res[i][j]<return_vector[i])
            return_vector[i]=res[i][j];
      }
  else
    for (unsigned int j=0; j<size; ++j)
      {
        return_vector.push_back(res[0][j]);
        for (unsigned int i=1; i<size; ++i)
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
    for (unsigned int i=0; i<size; ++i)
      {
        return_vector.push_back(res[i][0]);
        for (unsigned int j=1; j<size; ++j)
          if (res[i][j]>return_vector[i])
            return_vector[i]=res[i][j];
      }
  else
    for (unsigned int j=0; j<size; ++j)
      {
        return_vector.push_back(res[0][j]);
        for (unsigned int i=1; i<size; ++i)
          if (res[i][j]>return_vector[j])
            return_vector[j]=res[i][j];
      }
  return return_vector;
}

std::vector<unsigned int>
HMatrix::zeroes(bool row)
{
  std::vector<unsigned int> return_vector;
  if (row)
    for (unsigned int i=0; i<size; ++i)
      {
        return_vector.push_back(0);
        for (unsigned int j=0; j<size; ++j)
          if (mask[i][j]=='x')
            return_vector[i]++;
      }
  else
    for (unsigned int j=0; j<size; ++j)
      {
        return_vector.push_back(0);
        for (unsigned int i=0; i<size; ++i)
          if (mask[i][j]=='x')
            return_vector[j]++;
      }
  return return_vector;
}

void
HMatrix::initialize_mask()
{
  mask.resize(size);
  for (unsigned int i = 0; i<size; ++i)
    mask[i].resize(size);

  for (unsigned int i = 0; i<size; ++i)
    for (unsigned int j = 0; j<size; ++j)
      if (i<n_row && j<n_col && res[i][j]!=0)
        mask[i][j]=' ';
      else
        mask[i][j]='x';
}

void
HMatrix::status_mask()
{
  std::string row_init = "    ";
  unsigned int spaces  = 2;
  std::cout << std::endl;
  for (unsigned int r = 0; r < size; ++r)
    {
      std::cout << row_init << "+" << "---";
      for (unsigned int c = 1; c < size; ++c)
        std::cout << "+" << "---";
      std::cout << "+" << std::endl
                << row_init << "|";
      for (unsigned int c = 0; c< size; ++c)
        std::cout << std::setw(spaces) << mask[r][c] << " |";
      std::cout << std::endl;
    }
  std::cout << row_init;
  for (unsigned int c = 0; c < size; ++c)
    std::cout << "+" << "---";
  std::cout << "+" << std::endl;
}

void
HMatrix::sort(bool row)
{
  // TODO:
  // How to start each row:
  std::string row_init = "    ";
  // Length of each coloum:
  unsigned int spaces  = 5;

  std::cout << std::endl;
  for (unsigned int r = 0; r < n_row; ++r)
    {
      std::cout << row_init << "+" << "-----";
      for (unsigned int c = 1; c < n_col; ++c)
        std::cout << "+" << "-----";
      std::cout << "+" << std::endl
                << row_init << "|";
      for (unsigned int c = 0; c< n_col; ++c)
        if ( res[r][c] == 0 )
          std::cout << std::setw(spaces) << mat[r][c] << "|";
        else
          std::cout << std::setw(spaces) << " " << "|";
      std::cout << std::endl;
    }
  std::cout << row_init;
  for (unsigned int c = 0; c < n_col; ++c)
    std::cout << "+" << "-----";
  std::cout << "+" << std::endl;
}

bool
HMatrix::check_rank()
{
  bool result = false;
  unsigned int counter     = 0;

  initialize_mask();

  auto row_zeroes = zeroes(true);
  auto col_zeroes = zeroes(false);
  auto max_row = utilities::max(row_zeroes);
  auto max_col = utilities::max(col_zeroes);

  while (max_row.first>0 && max_col.first>0)
    {
      if ( max_row.first < max_col.first )
        {
          for (unsigned int i = 0; i<size; ++i)
            if (mask[i][max_col.second]!='-')
              mask[i][max_col.second]='|';
            else
              mask[i][max_col.second]='+';
          counter++;
        }
      else
        {
          for (unsigned int i = 0; i<size; ++i)
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
  if (counter==size) result = true;

  return result;
}
