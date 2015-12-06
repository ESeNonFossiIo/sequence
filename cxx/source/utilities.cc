
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

double cclock()
{
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
  return sec;
}

void print_msg(std::string msg)
{
  std::cout << "=================================================="<< std::endl;
  std::cout << " " << msg << std::endl;
  std::cout << "=================================================="<< std::endl;
}

void print_msg(std::vector<std::string> msg)
{
  std::cout << "=================================================="<< std::endl;
  for (std::vector<std::string>::iterator it = msg.begin();
       it != msg.end(); ++it)
    std::cout << " " << *it << std::endl;
  std::cout << "=================================================="<< std::endl;
}

template <typename T>
void print_sequence(std::vector<T> vec, unsigned int space)
{
  std::cout << "=================================================="<< std::endl;

  typename std::vector<T>::iterator it_end=vec.end();
  it_end--;

  std::cout << " < ";
  for (typename std::vector<T>::iterator it=vec.begin();
       it!=it_end; ++it)
    std::cout << std::setw(space) << *it <<  ",";
  std::cout << std::setw(space) << *it_end << " > " << std::endl;;
  std::cout << "=================================================="<< std::endl;
}

template <typename T,typename S>
void print_map(std::map<T,S> map, unsigned int space)
{
  std::cout << "=================================================="<< std::endl;

  typename std::map<T,S>::iterator it_end=map.end();
  it_end--;

  std::cout << " < ";
  for (typename std::map<T,S>::iterator it=map.begin();
       it!=it_end; ++it)
    std::cout << std::setw(space) << it->first <<  ",";
  std::cout << std::setw(space) << it_end->first << " > " << std::endl;;
  std::cout << "=================================================="<< std::endl;
}

// explicit instantiation:
template void print_sequence<unsigned int>(std::vector<unsigned int> vec, unsigned int space);
template void print_map<unsigned int,char>(std::map<unsigned int,char> map, unsigned int space);
template void print_map<char,unsigned int>(std::map<char,unsigned int> map, unsigned int space);
