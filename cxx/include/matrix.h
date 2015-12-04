#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <iostream>

template <typename T>
class hungarian_matrix
{
private:
  size_t n_row;
  size_t n_col;
  std::vector< std::vector<T> > m;
  std::map<int, size_t> map1;
  std::map<int, size_t> map2;
public:  
  hungarian_matrix()
  {
    m.resize(1);
    m[0].resize(1);
    n_row = 0;
    n_col = 0;
  }
 
  void insert(int i, int j, T x)
  {
    // update the index maps (which translate each input label 
    // into a matrix index) and resize the matrix
    if(!map2.count(j))
    {
      // add new index
      size_t n = map2.size();
      map2[j] = n;
      // add a column to the matrix
      ++n_col;
      for(size_t k=0; k<m.size(); ++k) m[k].resize(n_col);
    }
    if(!map1.count(i)) 
    {  
      // add new index
      size_t n = map1.size();
      map1[i] = n;
      // add a row to the matrix
      ++n_row;
      m.resize(n_row);
      m[n_row-1].resize(n_col);
    }
    // fill the matrix
    m[map1[i]][map2[j]] = x;
  }

  size_t row_map(int i) 
  {
    if(!map1.count(i))
    {
      std::cerr << "hungarian_matrix: row_map() couldn't find label " << i << std::endl;
      exit(1);
    }
    return map1[i];
  }

  size_t column_map(int i) 
  {
    if(!map2.count(i))
    {
      std::cerr << "hungarian_matrix: column_map() couldn't find label " << i << std::endl;
      exit(1);
    }
    return map2[i];
  }

  T operator() (int i, int j)
  {
    row_map(i);
    column_map(j);
    return m[map1[i]][map2[j]];
  }

  void row_swap(int i, int j)
  {
    row_map(i);
    row_map(j);
    int tmp = map1[i];
    map1[i] = map1[j];
    map1[j] = tmp;
  }

  void column_swap(int i, int j)
  {
    column_map(i);
    column_map(j);
    int tmp = map2[i];
    map2[i] = map2[j];
    map2[j] = tmp;
  }

};

