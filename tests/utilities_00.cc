/*
 * Description
 * Author: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-12-09
 * time: 10:34:45
 * test: utilities::max anc utilities::min
 */

#include <string>
#include "utilities.h"

int main()
{
  using namespace utilities;
  std::vector<unsigned int> test;
  test.push_back(1);
  test.push_back(2);
  test.push_back(3);
  test.push_back(3);
  test.push_back(0);
  test.push_back(1);

  print<unsigned int>(test, 2);

  std::pair<unsigned int, unsigned int> minimum, maximum;
  maximum = max(test);
  minimum = min(test);

  std::vector<std::string> msg;
  msg.push_back("MINIMUM:  " + std::to_string(minimum.first));
  msg.push_back("POSITION: " + std::to_string(minimum.second));
  msg.push_back("MAXIMUM:  " + std::to_string(maximum.first));
  msg.push_back("POSITION: " + std::to_string(maximum.second));
  print_msg(msg);
}
