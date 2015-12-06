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
