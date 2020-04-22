# haash
C++ implementation of the haash a faster modified secure SHA512 hashing algorithm version.

## Usage
```c++
#include "haash.h" //include HAASH definition

HAASH haash; //instantiate a HAASH object
haash.hash("Example"); //returns the hash as a string
```

## Compile and run
1. Clone the repository onto your disk: `git clone https://github.com/ashishmainali/haash.git` 
2. Include the header file in your .cpp file: `#include "HAASH.h"`
3. Compile: `g++ yourFileName.cpp SHA512.cpp` OR use `make main` 
4. Run: `./a.out` or `./main`

## Example
main.cpp provides an example usage of this hashing algorithm repository. It hashes the first argument given when running the object file.

1. Clone the repository onto your disk: `https://github.com/ashishmainali/haash.git`
2. Compile: `make main`
3. Run: `./main test`
4. Output: `74b4bc52b89c473b76cf5d0b09954e769f80903618da64248dda1f4ef3fb81d348ab2595bd0e6e1fb579f576d7ae5b2b2b49adb86a42857ec9344405b00e90`
