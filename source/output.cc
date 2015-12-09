#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw
#include <algorithm>    // std::find
#include <set>
#include <vector>
#include <cmath>

#include "matrix.h"
#include "hungarian_matrix.h"
#include "permutation.h"
#include "utilities.h"

std::ostream &
operator<<(std::ostream &os, const Matrix &m)
{
  // How to start each row:
  std::string row_init = "    ";
  // Length of each coloum:
  unsigned int spaces  = 5;

  os << std::endl;
  for (unsigned int r = 0; r < m.n_row; ++r)
    {
      os << row_init << "+" << "-----";
      for (unsigned int c = 1; c < m.n_col; ++c)
        os << "+" << "-----";
      os << "+" << std::endl
         << row_init << "|";
      for (unsigned int c = 0; c< m.n_col; ++c)
        os << std::setw(spaces) << m.mat[r][c] << "|";
      os << std::endl;
    }
  os << row_init;
  for (unsigned int c = 0; c < m.n_col; ++c)
    os << "+" << "-----";
  os << "+" << std::endl;

  return os;
}

std::ostream &
operator<<(std::ostream &os, const HMatrix &m)
{
  // How to start each row:
  std::string row_init = "    ";
  // Length of each coloum:
  unsigned int spaces  = 5;

  os << std::endl;
  for (unsigned int r = 0; r < m.n_row; ++r)
    {
      os << row_init << "+" << "-----";
      for (unsigned int c = 1; c < m.n_col; ++c)
        os << "+" << "-----";
      os << "+" << std::endl
         << row_init << "|";
      for (unsigned int c = 0; c< m.n_col; ++c)
        os << std::setw(spaces) << m.res[r][c] << "|";
      os << std::endl;
    }
  os << row_init;
  for (unsigned int c = 0; c < m.n_col; ++c)
    os << "+" << "-----";
  os << "+" << std::endl;

  return os;
}

std::ostream &
operator<<(std::ostream &os, LPermutation &p)
{
  // Length of each entries:
  unsigned int spaces = 3;

  os << "<";
  for (unsigned int i = 0; i<p.tot-1; ++i)
    os << std::setw(spaces) << p[i] <<  ",";
  os << std::setw(spaces) << p[p.tot-1] << ">" << std::endl;
  os << "<";
  for (unsigned int i = 0; i<p.tot-1; ++i)
    os << std::setw(spaces) << p.from_int_to_char[p[i]] <<  ",";
  os << std::setw(spaces) << p.from_int_to_char[p[p.tot-1]] << ">" << std::endl;
  return os;
}
