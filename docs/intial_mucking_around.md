# Initial Mucking Around

## Overview

Some notes from problems I encountered blundering around.  Kept in case they may be of some use


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


