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

  Permutation( unsigned int num,
               std::vector<unsigned int> sequence );

  Permutation(const Permutation &p);

  /**
   * Add an element to the permutation.
   */
  void new_element();

  /**
   * Switch element @p i and element @p j.
   */
  void switch_elements(unsigned int i, unsigned int j);

  /**
   *  Status of the matrix:
   *  - Number of elements
   */
  void
  status();

  /**
   *  Overload of the output operator <<.
   *  It is possible to check the ouput of the permutations in the following way:
   *  @code{.cpp}
   *   Permutation p;
   *   ...
   *   std::cout << p;
   *  @endcode
   */
  friend std::ostream &operator<< (std::ostream &os, Permutation &dt);

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

  /**
   * Current permutation.
   */
  std::vector<unsigned int> sequence;
};

/**
 * LPermutation stands for labeled permutation. It adds to
 * the Permutation class a map of labels.
 */
class LPermutation : public Permutation
{
public:
  LPermutation();

  LPermutation(const LPermutation &p);

  /**
   * Add an element @p element of type char to the sequence.
   * If this label exists the function return false, otherwise
   * true.
   */
  bool add_an_element(char element, bool output=false);

  /**
   *  Overload of the output operator <<.
   *  It is possible to check the ouput of the permutations in the following way:
   *  @code{.cpp}
   *   LPermutation p;
   *   ...
   *   std::cout << p;
   *  @endcode
   */
  friend std::ostream &operator<< (std::ostream &os,
                                   LPermutation &dt);

  /**
   * TODO:
   */
  char
  get_char(unsigned int i);

  /**
   * TODO:
   */
  unsigned int
  get_int(char c);

private:
  /**
   * Associate to each number of the sequence an element.
   */
  std::map<unsigned int, char> from_int_to_char;

  /**
   * Associate to each element the linked number.
   * This map is a kind of inverse of @p sequence_map.
   */
  std::map<char, unsigned int> from_char_to_int;
};

#endif
