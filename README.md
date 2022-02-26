# ISO8583
A small header only library to generate and process ISO8583 messages using C++17.

# Dependencies
There are no dependencies.

I do make use of [SPDLog](https://github.com/gabime/spdlog) but it's only in the example main.cpp file.

# Build
## Prerequisites:
  CMake
  C++ compiler supporting 17 standards.
  You only need to copile the example if you want to. 
  
  If you just want to use the library it's in the 'include' folder.

```
mkdir build
cd build
cmake ..
cmake . --build
```

# Highlights of the library
It's header only.

It's now possible to process a message as well as create one from scratch.

It now supports 1987 and 1993 response codes.
