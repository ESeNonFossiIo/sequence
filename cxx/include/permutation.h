#ifndef __permutation_h__
#define __permutation_h__

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <iostream>

/**
 * Permutation. The constructor takes the variable @p num that is the number
 * of elements
 */
class Permutation
{
public:
  Permutation(unsigned int num);

  /**
   * Add an element to the permutation
   */
  void add_an_element();

  /**
   * Switch element @p i and element @p j
   */
  void switch_elements(unsigned int i, unsigned int j);

  /**
   * Print permutation
   */
  void print();

  /**
   * Access to the element @p i
   */
  unsigned int &operator()(const unsigned int i);
  unsigned int &operator[](const unsigned int i);

private:
  /**
   * Total number of elements
   */
  unsigned int tot;

  /**
   * Current permutation
   */
  std::vector<unsigned int> sequence;
};

#endif
