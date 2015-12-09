/*
 * Authors: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 */

#include <vector>
#include <cmath>
#include <assert.h>
#include <iomanip>      // std::setw
#include <utility>      // std::swap
#include "utilities.h"
#include "permutation.h"

using namespace utilities;

Permutation::Permutation( unsigned int num )
  :
  tot(num)
{
  for (unsigned int i = 0; i < num; ++i)
    sequence.push_back(i);
}

Permutation::Permutation( unsigned int num, std::vector<unsigned int> sequence )
  :
  tot(num),
  sequence(sequence)
{}


Permutation::Permutation(const Permutation &p)
  :
  tot(p.tot),
  sequence(p.sequence)
{};

void
Permutation::new_element()
{
  sequence.push_back(tot);
  ++tot;
}

void
Permutation::switch_elements(unsigned int i, unsigned int j)
{
  assert(("i can not be greater than " + std::to_string(tot), i < tot));
  assert(("j can not be greater than " + std::to_string(tot), j < tot));
  std::swap(sequence[i],sequence[j]);
}

unsigned int &
Permutation::operator()(const unsigned int i)
{
  return sequence[i];
};

unsigned int &
Permutation::operator[](const unsigned int i)
{
  // const return_value = sequence[i];
  return sequence[i];
};

void
Permutation::status()
{
  if (tot==0)
    print_msg("Empty permutation");
  else
    print_msg("Sequence Length:   "+std::to_string(tot));
}

std::ostream &
operator<<(std::ostream &os, Permutation &p)
{
  // Length of each entries:
  unsigned int spaces = 3;

  os << "<";
  for (unsigned int i = 0; i<p.tot-1; ++i)
    os << std::setw(spaces) << p[i] <<  ",";
  os << std::setw(spaces) << p[p.tot-1] << ">" << std::endl;
  return os;
}

LPermutation::LPermutation()
  :
  Permutation(0)
{}

LPermutation::LPermutation(const LPermutation &p)
  :
  Permutation(p.tot, p.sequence),
  from_int_to_char(p.from_int_to_char),
  from_char_to_int(p.from_char_to_int)
{};

char
LPermutation::get_char(unsigned int i)
{
  return from_int_to_char[i];
}

unsigned int
LPermutation::get_int(char c)
{
  return from_char_to_int[c];
}

bool
LPermutation::add_an_element(char element, bool output)
{
  bool status=false;
  if (!from_char_to_int.count(element))
    {
      from_int_to_char[tot] = element;
      from_char_to_int[element] = tot;
      new_element();
      status = true;
    }
  else if (output)
    print_msg("This element is alreary present");
  return status;
}
