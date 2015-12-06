/*
 * Authors: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 */

#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw
#include <vector>
#include <cmath>
#include "permutation.h"
#include <assert.h>

Permutation::Permutation( unsigned int num )
  :
  tot(num)
{
  for (unsigned int i = 0; i < num; ++i)
    sequence.push_back(i);
}

void
Permutation::add_an_element()
{
  sequence.push_back(tot);
  ++tot;
}

void
Permutation::switch_elements(unsigned int i, unsigned int j)
{
  assert(("i can not be greater than " + std::to_string(tot), i < tot));
  assert(("j can not be greater than " + std::to_string(tot), j < tot));
  auto tmp = sequence[i];
  sequence[i] = sequence[j];
  sequence[j] = tmp;
}

unsigned int &
Permutation::operator()(const unsigned int i)
{
  return sequence[i];
};

unsigned int &
Permutation::operator[](const unsigned int i)
{
  return sequence[i];
};

void
Permutation::print()
{
  std::cout << "=================================================="<< std::endl;
  std::cout << " Sequence Length:   " << tot << std::endl;
  std::cout << " Sequence:          <";
  for (unsigned int i = 0; i<tot-1; ++i)
    std::cout << std::setw(2) << sequence[i] << "," ;
  std::cout << std::setw(2) << sequence[tot-1] << " >" << std::endl;
  std::cout << "=================================================="<< std::endl;
}

template<typename T>
GPermutation<T>::GPermutation()
:
Permutation(0)
{}



//The explicit instantiation:
template class GPermutation<char>;
template class GPermutation<int>;
