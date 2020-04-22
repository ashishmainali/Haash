# haash
C++ implementation of the haash a faster modified secure SHA512 hashing algorithm version.

## Usage
```c++
#include "haash.h" //include SHA512 definition

HAASH haash; //instantiate a SHA512 object
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
4. Output: `5fb61a4da539cce76cf5d0b09954e7689398ec0c8b6aa62f1ab8107126e00c33141621f9de81ee95e31b426c5d2fa14a9b1e69227f4ed27776bf2791be63c55`
