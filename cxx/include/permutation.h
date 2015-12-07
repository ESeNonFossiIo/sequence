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
   * Add an element to the permutation.
   */
  void new_element();

  /**
   * Switch element @p i and element @p j.
   */
  void switch_elements(unsigned int i, unsigned int j);

  /**
   * Print permutation.
   */
  void print(bool sequence = true, bool length = false);

  /**
   * Access to the element @p i.
   */
  unsigned int &operator()(const unsigned int i);
  unsigned int &operator[](const unsigned int i);

protected:
  /**
   * Total number of elements.
   */
  unsigned int tot;

private:
  /**
   * Current permutation.
   */
  std::vector<unsigned int> sequence;
};

/**
 * GPermutation. Generalize the Permutation class and associate to each number.
 * an element of a generic typename T.
 */
class GPermutation : public Permutation
{
public:
  GPermutation();

  /**
   * Add an element @p element of type T to the sequence.
   */
  void add_an_element(char element);

  /**
   * Print permutation.
   */
  void print_elements();

private:
  /**
   * Associate to each number of the sequence an element.
   */
  std::map<unsigned int, char> sequence_map;

  /**
   * Associate to each element the linked number.
   * This map is a kind of inverse of @p sequence_map.
   */
  std::map<char, unsigned int> key_map;
};

#endif
