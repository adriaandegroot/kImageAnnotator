# kImageAnnotator [![Build Status](https://travis-ci.org/DamirPorobic/kImageAnnotator.svg?branch=master)](https://travis-ci.org/DamirPorobic/kImageAnnotator)
Tool for annotating images

Version 0.0.1


![kImageAnnotator](https://imgur.com/y9CT0Ia.png "kImageAnnotator")


### Building from source

1. Get latest release from GitHub by cloning the repo:  
    `$ git clone https://github.com/DamirPorobic/kImageAnnotator`
2. Change to repo directory:  
    `$ cd kImageAnnotator`  
3. Resolve dependencies by fetching git submodules:  
    `$ git submodule update --init --recursive`  
4. Make new build directory and enter it:  
    `$ mkdir build && cd build`  
5. Create the makefile and build the project:  
    `$ cmake .. && make`  
6. Install shared library (not required when only using the example):  
    `$ sudo make install`
7. Run the example application:  
    `$ ./example/kImageAnnotator-example`

### Integrate as shared library

1. Let cmake find the shared library, optionally with version  
    `set(KIMAGEANNOTATOR_MIN_VERSION "0.x.x")`  
    `find_package(kImageAnnotator ${KIMAGEANNOTATOR_MIN_VERSION} REQUIRED)`  

2. Link the library with your application  
    `target_link_libraries(myApp kImageAnnotator)`  