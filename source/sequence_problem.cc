/*
 * Authors: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 */

#include "sequence_problem.h"
#include "utilities.h"

SequenceProblem::SequenceProblem()
{}

void
SequenceProblem::fill(std::vector<std::pair<char, char> > sequence)
{
  for (typename std::vector<std::pair<char, char> >::
       iterator it=sequence.begin();
       it!=sequence.end(); ++it)
    {
      problem_matrix.add_an_element(it->first,it->second);
    }
}

void
SequenceProblem::fill(std::string file1, std::string file2)
{
  std::ifstream infile1(file1);
  std::ifstream infile2(file2);

  unsigned int num1, num2;
  char c1, c2;
  while ((infile1 >> num1 >> c1) && (infile2 >> num2 >> c2))
    {
      problem_matrix.add_an_element(c1,c2);
    }
}

void
SequenceProblem::solve()
{
  utilities::print_msg(" Original Matrix: ");
  problem_matrix.update(false);
  std::cout << problem_matrix;

  utilities::print_msg(" Complement: ");
  problem_matrix.update();
  std::cout << problem_matrix;

  utilities::print_msg(" First step rows: ");
  problem_matrix.first_step(true);
  std::cout << problem_matrix;

  utilities::print_msg(" First step coloumns: ");
  problem_matrix.first_step(false);
  std::cout << problem_matrix;

  bool status = problem_matrix.check_rank();
  problem_matrix.status_mask();
  utilities::print_msg(" Status: " + std::to_string(status));


  while (!status)
    {
      problem_matrix.second_step();
      // std::cout << problem_matrix;
      // problem_matrix.status_mask();
      status = problem_matrix.check_rank();
      // problem_matrix.status_mask();
      // utilities::print_msg(" Status: " + std::to_string(status));
    }
  //
  utilities::print_msg(" Solution: ");
  // std::cout << problem_matrix;
  // problem_matrix.status();

  problem_matrix.check_result();
  problem_matrix.status_result_mask();

  problem_matrix.sort();
}
