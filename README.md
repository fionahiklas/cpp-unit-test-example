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


#### No `make test`

Seem to be able to go to `build/test` and run `ctest` to try and pick up tests


### Boost

#### Trying to link _main missing

Having problems running/building tests in general, tried to compile without cmake
using this command

```
g++ -I $HOME/tools/homebrew/include -I ../src -L $HOME/tools/homebrew/lib -o test_test channel_test.cpp test_main.cpp ../src/channel.cpp  -lboost_system-mt -lboost_thread-mt -lboost_unit_test_framework-mt
```

__NOTE:__ the `-mt` seems to be needed to pick up the correct libraries

This gives the following output

```
Undefined symbols for architecture arm64:
  "_main", referenced from:
     implicit entry/start for main executable
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```

Tried the suggestion from [this post](https://stackoverflow.com/questions/13547771/g-project-compilation-with-boost-unit-test) but got this massive output

```
g++ -I $HOME/tools/homebrew/include -I ../src -L $HOME/tools/homebrew/lib -o test_test channel_test.cpp test_main.cpp ../src/channel.cpp  -lboost_system-mt -lboost_thread-mt -lboost_unit_test_framework-mt
In file included from test_main.cpp:3:
In file included from /Users/fiona/tools/homebrew/include/boost/test/included/unit_test.hpp:18:
In file included from /Users/fiona/tools/homebrew/include/boost/test/impl/compiler_log_formatter.ipp:19:
In file included from /Users/fiona/tools/homebrew/include/boost/test/output/compiler_log_formatter.hpp:19:
/Users/fiona/tools/homebrew/include/boost/test/utils/setcolor.hpp:92:31: warning: 'sprintf' is deprecated: This function is provided for compatibility reasons only.  Due to security concerns inherent in the design of sprintf(3), it is highly recommended that you use snprintf(3) instead. [-Wdeprecated-declarations]
        m_command_size = std::sprintf( m_control_command, "%c[%c;3%c;4%cm",
                              ^
/Users/fiona/Downloads/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/stdio.h:188:1: note: 'sprintf' has been explicitly marked deprecated here
__deprecated_msg("This function is provided for compatibility reasons only.  Due to security concerns inherent in the design of sprintf(3), it is highly recommended that you use snprintf(3) instead.")
^
/Users/fiona/Downloads/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h:215:48: note: expanded from macro '__deprecated_msg'
        #define __deprecated_msg(_msg) __attribute__((__deprecated__(_msg)))
                                                      ^
In file included from test_main.cpp:3:
In file included from /Users/fiona/tools/homebrew/include/boost/test/included/unit_test.hpp:18:
In file included from /Users/fiona/tools/homebrew/include/boost/test/impl/compiler_log_formatter.ipp:19:
In file included from /Users/fiona/tools/homebrew/include/boost/test/output/compiler_log_formatter.hpp:19:
/Users/fiona/tools/homebrew/include/boost/test/utils/setcolor.hpp:103:31: warning: 'sprintf' is deprecated: This function is provided for compatibility reasons only.  Due to security concerns inherent in the design of sprintf(3), it is highly recommended that you use snprintf(3) instead. [-Wdeprecated-declarations]
        m_command_size = std::sprintf(m_control_command, "%c[%c;3%c;4%cm",
                              ^
/Users/fiona/Downloads/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/stdio.h:188:1: note: 'sprintf' has been explicitly marked deprecated here
__deprecated_msg("This function is provided for compatibility reasons only.  Due to security concerns inherent in the design of sprintf(3), it is highly recommended that you use snprintf(3) instead.")
^
/Users/fiona/Downloads/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h:215:48: note: expanded from macro '__deprecated_msg'
        #define __deprecated_msg(_msg) __attribute__((__deprecated__(_msg)))
                                                      ^
2 warnings generated.
duplicate symbol 'init_unit_test_suite(int, char**)' in:
    /var/folders/x1/7_2v30bs4mz7bppcjpnylv140000gp/T/channel_test-9e7361.o
    /var/folders/x1/7_2v30bs4mz7bppcjpnylv140000gp/T/test_main-207cfd.o
ld: 1 duplicate symbol for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```

This [post](https://stackoverflow.com/questions/33143345/boosttest-compiling-and-running-a-hello-world-program) seemed to suggest a solution to the problem, there is no need for `test_main.cpp` the 
`#define BOOST_TEST_DYN_LINK` does the generation of `main`.

Tried this compilation

```
g++ -I $HOME/tools/homebrew/include -I ../src -L $HOME/tools/homebrew/lib -o test_test channel_test.cpp ../src/channel.cpp  -lboost_system-mt -lboost_thread-mt -lboost_unit_test_framework-mt
```

This seemed to compile



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


