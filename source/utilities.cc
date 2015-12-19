/*
 * Authors: Luca Ponzoni and Mauro Bardelloni
 * date: 2015-11-23
 * time: 18:34:45
 */

#include <time.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/time.h>
#include <vector>
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw
#include "utilities.h"

double
utilities::cclock()
{
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
  return sec;
}

void
utilities::print_msg(std::string msg)
{
  std::cout << std::endl << std::flush
            << std::endl << std::flush << "=================================================="<< std::endl
            << std::flush;
  std::cout << " " << msg << std::endl
            << std::flush;
  std::cout << "=================================================="<< std::endl
            << std::flush;
}

void
utilities::print_msg(std::vector<std::string> msg)
{
  std::cout << std::endl << std::flush
            << std::endl << std::flush << "=================================================="<< std::endl
            << std::flush;
  for (std::vector<std::string>::iterator it = msg.begin();
       it != msg.end(); ++it)
    std::cout << " " << *it << std::endl
              << std::flush;
  std::cout << "=================================================="<< std::endl
            << std::flush;
}

template <typename T>
void
utilities::print(std::vector<T> vec, unsigned int space)
{
  std::cout << "=================================================="<< std::endl
            << std::flush;

  typename std::vector<T>::iterator it_end=vec.end();
  it_end--;

  std::cout << " < ";
  for (typename std::vector<T>::iterator it=vec.begin();
       it!=it_end; ++it)
    std::cout << std::setw(space) << *it <<  ",";
  std::cout << std::setw(space) << *it_end << " > " << std::endl
            << std::flush;
  std::cout << "=================================================="<< std::endl
            << std::flush;
}
// 
// template <typename T,typename S>
// void
// utilities::print_map(std::map<T,S> map, unsigned int space)
// {
//   std::cout << "=================================================="<< std::endl
//             << std::flush;
// 
//   typename std::map<T,S>::iterator it_end=map.end();
//   it_end--;
// 
//   std::cout << " < ";
//   for (typename std::map<T,S>::iterator it=map.begin();
//        it!=it_end; ++it)
//     std::cout << std::setw(space) << it->first <<  ",";
//   std::cout << std::setw(space) << it_end->first << " > " << std::endl
//             << std::flush;
//   std::cout << "=================================================="<< std::endl
//             << std::flush;
// }

std::pair<unsigned int, int>
utilities::min(std::vector<unsigned int> vec,
               unsigned int lower_bound,
               unsigned int upper_bound)
{
  std::pair<unsigned int, unsigned int> min;
  // std::cout << "here" << std::flush<<std::endl;
  unsigned int counter = 0;
  // std::cout << "here" << std::flush<<std::endl;
  min.first=upper_bound;
  // std::cout << "here" << std::flush<<std::endl;
  min.second=-1;
  // std::cout << "here" << std::flush<<std::endl;
  for (typename std::vector<unsigned int>::iterator it=vec.begin();
       it!=vec.end(); ++it)
    {
      if (*it<min.first && *it >= lower_bound)
        {
          min.first=*it;
          min.second=counter;
        }
      counter++;
    }
  return min;
}

std::pair<unsigned int, unsigned int>
utilities::max(std::vector<unsigned int> vec)
{
  std::pair<unsigned int, unsigned int> max;
  unsigned int counter = 0;
  max.first=*vec.begin();
  max.second=0;
  for (typename std::vector<unsigned int>::iterator it=vec.begin();
       it!=vec.end(); ++it)
    {
      // std::cout << "--> " << *it << " - " << counter << std::endl;
      if (*it>max.first)
        {
          max.first=*it;
          max.second=counter;
        }
      counter++;
    }
  // std::cout << "====> counter ===> " << counter << std::endl << std::flush;
  return max;
}

std::pair<unsigned int, unsigned int>
utilities::size_row_and_col(std::vector<std::vector<unsigned int>> mat)
{
  std::pair<unsigned int, unsigned int> return_pair;
  return_pair.first=mat.size();
  return_pair.second=mat[0].size();  
  return return_pair;
}

// explicit instantiation:
template void utilities::print<unsigned int>(std::vector<unsigned int> vec, unsigned int space);
// template void utilities::print_map<unsigned int,char>(std::map<unsigned int,char> map, unsigned int space);
// template void utilities::print_map<char,unsigned int>(std::map<char,unsigned int> map, unsigned int space);
