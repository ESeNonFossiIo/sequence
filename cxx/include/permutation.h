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

/**
 * GPermutation. Generalize the Permutation class and associate to each number
 * an element of a generic typename T
 */
template<typename T>
class GPermutation : public Permutation
{
public:
  GPermutation();

  /**
   * Add an element @p element of type T to the sequence
   */
  void add_an_element(T element);

private:
  /**
   * Associate to each number of the sequence an element
   */
  std::map<unsigned int, T> sequence_map;
};

#endif
