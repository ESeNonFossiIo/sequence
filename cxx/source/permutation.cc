/*
 * Authors: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 */

#include <vector>
#include <cmath>
#include <assert.h>

#include "utilities.h"
#include "permutation.h"



Permutation::Permutation( unsigned int num )
  :
  tot(num)
{
  for (unsigned int i = 0; i < num; ++i)
    sequence.push_back(i);
}

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
Permutation::print(bool show_sequence, bool show_length)
{
  if (tot==0)
    print_msg("Empty permutation");
  else
    {
      if (show_length)
        print_msg("Sequence Length:   "+std::to_string(tot));
      if (show_sequence)
        {
          print_sequence<unsigned int>(sequence);
        }
    }
}

GPermutation::GPermutation()
  :
  Permutation(0)
{}

void
GPermutation::add_an_element(char element)
{
  if (!key_map.count(element))
    {
      sequence_map[tot] = element;
      key_map[element] = tot;
      new_element();
    }
  else
    print_msg("This element is alreary present");
  return;
}

void
GPermutation::print_elements()
{
  if (tot==0)
    print_msg("Empty permutation");
  else
    {
      print_msg(" Sequence Length:   " + std::to_string(tot));
      print_map<unsigned int, char>(sequence_map, 3);
    }
}
