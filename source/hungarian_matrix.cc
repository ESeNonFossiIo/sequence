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
          // std::cout << min[i] << std::endl << std::flush;
          res[i][j]-=min[i];
    }
  else
    {
      for (unsigned int j = 0; j<size; ++j)
        for (unsigned int i = 0; i<size; ++i)
          // std::cout << min[i] << std::endl << std::flush;
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
      print_sequence(out_result);
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
      print_sequence(out_result);
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

  if (elements.size())
    max_element = min(elements).first;
  else
    return;

  std::vector<unsigned int> blank_elements;
  blank_elements=blank(row);

  if (row)
    {
      std::vector<unsigned int> tmp;
      std::vector<unsigned int> tmp_vec_col;
      unsigned int r=0;

      while (!tmp.size())
        {
          tmp_vec_col.clear();
          for (unsigned int j = 0; j<size; ++j)
            if (mask[blank_elements[r]][j]==' ')
              tmp.push_back(j);
            else
              tmp_vec_col.push_back(j);
          ++r;
        }

      // std::cout << "-----------------" << std::endl;
      // print_sequence(tmp);
      // print_sequence(tmp_vec_col);
      // print_sequence(blank_elements);

      for (typename std::vector<unsigned int>::iterator it=tmp.begin();
           it!=tmp.end(); ++it)
        for (unsigned int i = 0; i<size; ++i)
          res[i][*it]-=max_element;

      unsigned int this_coloum = tmp[0];
      // std::cout << "(" << this_coloum << ")" << std::endl;
      for (unsigned int i = 0; i<size; ++i)
        {
          if (mask[i][this_coloum]!=' ')
            {
              unsigned int this_row=i;
              for (unsigned int j = 0; j<size; ++j)
                res[this_row][j]+=max_element;
            }
        }
    }
  else
    {
      //TODO:
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
  // std::cout << "size = " << size << std::flush << std::endl;
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

std::vector<unsigned int>
HMatrix::zeroes_result(bool row)
{
  std::vector<unsigned int> return_vector;
  // std::cout << "size = " << size << std::flush << std::endl;
  if (row)
    for (unsigned int i=0; i<size; ++i)
      {
        return_vector.push_back(0);
        for (unsigned int j=0; j<size; ++j)
          if (result_mask[i][j]=='x')
            return_vector[i]++;
      }
  else
    for (unsigned int j=0; j<size; ++j)
      {
        return_vector.push_back(0);
        for (unsigned int i=0; i<size; ++i)
          if (result_mask[i][j]=='x')
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
      if (i<size && j<size  && res[i][j]!=0)
        mask[i][j]=' ';
      else
        mask[i][j]='x';
}

void
HMatrix::initialize_result_mask()
{
  result_mask.resize(size);
  for (unsigned int i = 0; i<size; ++i)
    result_mask[i].resize(size);

  for (unsigned int i = 0; i<size; ++i)
    for (unsigned int j = 0; j<size; ++j)
      if (i<size && j<size  && res[i][j]!=0)
        result_mask[i][j]=' ';
      else
        result_mask[i][j]='x';
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
HMatrix::status_result_mask()
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
        std::cout << std::setw(spaces) << result_mask[r][c] << " |";
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
  unsigned int tot  = 0;

  std::cout << std::endl;
  for (unsigned int r = 0; r < n_row; ++r)
    {
      std::cout << row_init << "+" << "-----";
      for (unsigned int c = 1; c < n_col; ++c)
        std::cout << "+" << "-----";
      std::cout << "+" << std::endl
                << row_init << "|";
      for (unsigned int c = 0; c< n_col; ++c)
        if ( result_mask[r][c] == 'O' )
        { 
          tot+=mat[r][c];
          std::cout << std::setw(spaces) << mat[r][c] << "|";
        }
        else
          std::cout << std::setw(spaces) << " " << "|";
      std::cout << std::endl;
    }
  std::cout << row_init;
  for (unsigned int c = 0; c < n_col; ++c)
    std::cout << "+" << "-----";
  std::cout << "+" << std::endl;


  utilities::print_msg( "max trace = " + std::to_string(tot) );
  std::cout << p_row;
  std::cout << p_col;
  for (unsigned int r = 0; r < n_row; ++r)
      for (unsigned int c = 0; c< n_col; ++c)
        if(result_mask[r][c] == 'O')
        {
          std::cout << "r = " << r << std::endl;
          std::cout << "c = " << c << std::endl;
          std::cout << "===== "<< std::endl;
          switch_elements(c,r,false);
          break;
        }

          std::cout << std::endl;
          for (unsigned int r = 0; r < n_row; ++r)
            {
              std::cout << row_init << "+" << "-----";
              for (unsigned int c = 1; c < n_col; ++c)
                std::cout << "+" << "-----";
              std::cout << "+" << std::endl
                        << row_init << "|";
              for (unsigned int c = 0; c< n_col; ++c)
                if ( r==c )
                { 
                  // tot+=mat[r][c];
                  std::cout << std::setw(spaces) << res[r][c] << "|";
                }
                else
                  std::cout << std::setw(spaces) << " " << "|";
              std::cout << std::endl;
            }
          std::cout << row_init;
          for (unsigned int c = 0; c < n_col; ++c)
            std::cout << "+" << "-----";
          std::cout << "+" << std::endl;

          utilities::print_msg( "max trace = " + std::to_string(tot) );
          std::cout << p_row;
          std::cout << p_col;
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
      if ( max_row.first <= max_col.first )
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

      // status_mask();
      row_zeroes = zeroes(true);
      col_zeroes = zeroes(false);
      max_row = utilities::max(row_zeroes);
      max_col = utilities::max(col_zeroes);
      // std::cout << "max_row = " << max_row.first << std::endl << std::flush;
      // std::cout << "max_col = " << max_col.first << std::endl << std::flush;
    }
  if (counter==size) result = true;

  return result;
}


bool
HMatrix::check_result()
{
  bool result = false;


  initialize_result_mask();

  auto row_zeroes = zeroes_result(true);
  auto col_zeroes = zeroes_result(false);
  auto min_row = utilities::min(row_zeroes);
  auto min_col = utilities::min(col_zeroes);
  auto max_row = utilities::max(row_zeroes);
  auto max_col = utilities::max(col_zeroes);
  utilities::print_sequence(row_zeroes);
  utilities::print_sequence(col_zeroes);
  while (min_row.second!=-1)
    {
      unsigned int counter = 0;
      for (unsigned int i = 0; i<size; ++i)
        {
          if (result_mask[min_row.second][i]=='x')
            {
              // std::cout << "----=====>>"<< min_row.second << "," << i<< std::endl;
              result_mask[min_row.second][i]='O';
              // std::cout << "----=====>>"<< result_mask[min_row.second][i] << std::endl;
              for (unsigned int j = 0; j<size; ++j)
                {
                  if (result_mask[min_row.second][j]!='O')
                    result_mask[min_row.second][j]='.';

                  if (
                      result_mask[j][i]!='O')
                    result_mask[j][i]='.';
                }

              // std::cout << "----=====>>"<< result_mask[min_row.second][i] << std::endl;
              // status_mask();
              row_zeroes = zeroes_result(true);
              col_zeroes = zeroes_result(false);
              min_row = utilities::min(row_zeroes, 1);
              min_col = utilities::min(col_zeroes, 1);
              max_row = utilities::max(row_zeroes);
              max_col = utilities::max(col_zeroes);
              // utilities::print_sequence(row_zeroes);
              // utilities::print_sequence(col_zeroes);
              // std::cout << "min_row = " << min_row.first << std::endl << std::flush;
              // std::cout << "min_col = " << min_col.first << std::endl << std::flush;
              // std::cout << "max_row = " << max_row.first << std::endl << std::flush;
              // std::cout << "max_col = " << max_col.first << std::endl << std::flush;
              i=size;
              // status_result_mask();
            }
        }
    }
  return result;
}
