# sequence

# USAGE:

## Run

mkdir build
cd build
cmake ..

## Test

mkdir build
cd build
cmake .. -DENABLE_TESTS=ON
make
ctest -V -R

### Run a specific test:

make run_**name-of-the-test**

## documentation:

mkdir build
cd build
make doc
open ../doc/html/index.html

# What is required:

- C++11
