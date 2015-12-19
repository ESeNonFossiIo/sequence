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

#include "mask.h"
#include "utilities.h"

using namespace utilities;

Mask::Mask()
:
Matrix(1,1,' ') 
{}

Mask::Mask(std::vector<std::vector<unsigned int>> m)
:
Matrix(1,1,' ') 
{
  initialize(m);
}

void
Mask::
initialize(std::vector<std::vector<unsigned int>> m)
{
  unsigned int n_row = utilities::size_row_and_col(m).first;
  unsigned int n_col = utilities::size_row_and_col(m).second;
  size = std::max(n_col, n_row);
  resize(size,size);

  for (unsigned int i = 0; i<size; ++i)
    for (unsigned int j = 0; j<size; ++j)
      if (i<size && j<size  && m[i][j]!=0)
        mat[i][j]=' ';
      else
        mat[i][j]='x';
}

unsigned int
Mask::
get_size()
{
  return size;
}

std::vector<unsigned int>
Mask::
zeroes(bool row)
{
  std::vector<unsigned int> return_vector;
  if (row)
    for (unsigned int i=0; i<size; ++i)
      {
        return_vector.push_back(0);
        for (unsigned int j=0; j<size; ++j)
          if (mat[i][j]=='x')
            return_vector[i]++;
      }
  else
    for (unsigned int j=0; j<size; ++j)
      {
        return_vector.push_back(0);
        for (unsigned int i=0; i<size; ++i)
          if (mat[i][j]=='x')
            return_vector[j]++;
      }
  return return_vector;
}

/**
 * TODO:
 */
bool
Mask::select_elements(std::vector<std::vector<unsigned int>> m)
{
  
    bool result = false;

    initialize(m);

    auto row_zeroes = zeroes(true);
    auto col_zeroes = zeroes(false);
    auto min_row = utilities::min(row_zeroes);
    auto min_col = utilities::min(col_zeroes);
    auto max_row = utilities::max(row_zeroes);
    auto max_col = utilities::max(col_zeroes);

    while (min_row.second!=-1)
      {
        unsigned int counter = 0;
        for (unsigned int i = 0; i<size; ++i)
          {
            if (mat[min_row.second][i]=='x')
              {
                mat[min_row.second][i]='O';
                for (unsigned int j = 0; j<size; ++j)
                  {
                    if (mat[min_row.second][j]!='O')
                      mat[min_row.second][j]='.';

                    if (
                      mat[i][j]!='O')
                      mat[i][j]='.';
                  }

                row_zeroes = zeroes(true);
                col_zeroes = zeroes(false);
                min_row = utilities::min(row_zeroes, 1);
                min_col = utilities::min(col_zeroes, 1);
                max_row = utilities::max(row_zeroes);
                max_col = utilities::max(col_zeroes);
                i=size;
              }
          }
      }
      
    return result;
};