# C++ Unit Test Example

## Overview

This is just a quick play with code to do the following

* Use CMake to build
* Write unit tests for C++
* Use doxygen for documentation

## Prerequisites

* cmake
* doxygen


## Quickstart

* Create a `build` directory under the repo 
* Run the following command to create the make files

```
mkdir build
cd build
cmake ../CMakeLists.txt
```

Run the tests using this command

```
make cppUnitTestExample_unit_tests
```

Verbose output using this command

```
make VERBOSE=1 cppUnitTestExample_unit_tests
```

Make the executable

```
make cppUnitTestExample
```


## Troubleshooting

### CMake

#### Could not load cache

I'd copied the cloned repo across to another computer and then tried to delete the `build` directory and
run the following command

```
cmake --build .
Error: could not load cache
```

Seems that this command was incorrect.  Using the following seems to work

```
mkdir build
cd build
cmake ../CMakeLists.txt
```





## References

### C++ Test Libraries

* [List of libraries](https://en.wikipedia.org/wiki/List_of_unit_testing_frameworks#C++)


### Boost

* [Boost library](https://en.wikipedia.org/wiki/Boost_(C%2B%2B_libraries))
* [Boost test and CMake](https://www.boost.org/doc/libs/1_68_0/libs/test/doc/html/boost_test/section_faq.html)
* [Brew boost formulae](https://formulae.brew.sh/formula/boost)


### Code Style and Layout

* [Canonical Project structure](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1204r0.html)
* [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
* [Stroustrup Style and Technique FAQ](https://www.stroustrup.com/bs_faq2.html)
* [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md)


### Documentation

* [doxygen](https://doxygen.nl/index.html)


### CMake

* [CMake C++ Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html)
* [CMake Boost Demo](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1204r0.html)
* [CMake mode wiki page](https://www.emacswiki.org/emacs/CMakeMode)
* [CMake mode auxillary file](https://github.com/Kitware/CMake/blob/master/Auxiliary/cmake-mode.el)


### Github Actions

* [Status badge](https://docs.github.com/en/actions/monitoring-and-troubleshooting-workflows/adding-a-workflow-status-badge)
* [Installing packages](https://stackoverflow.com/questions/72994320/building-cmake-project-with-boost-libraries-on-github-actions-gives-error-could)
* [Getting started with github actions](https://docs.github.com/en/actions/learn-github-actions/understanding-github-actions)


