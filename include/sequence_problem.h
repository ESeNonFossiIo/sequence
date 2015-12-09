#ifndef __sequence_problem_h__
#define __sequence_problem_h__

#include <fstream>

#include "hungarian_matrix.h"

/**
 *  TODO:
 */
class SequenceProblem
{
public:
  /**
   * TODO:
   */
  SequenceProblem();

  /**
   * TODO:
   */
  void
  fill(std::string file1, std::string file2);

  /**
   * TODO:
   */
  void
  fill(std::vector<std::pair<char, char> > sequence);

  /**
   *
   */
  void
  solve();

private:
  /**
   * TODO:
   */
  HMatrix problem_matrix;
};

#endif
