# ISO8583
A small example of how to decode and generate ISO8583 messages.

# Build
Prerequisites:
  CMake
  C++ compiler supporting 17 standards.

mkdir build
cd build
cmake ..
cmake . --build

# Dependencies
There are no dependencies, but I do make use of SPDLog: 
https://github.com/gabime/spdlog 
which is an AMAZING logging library for C++.

# Highlights of the library
It's header only.
It's now possible to process a message as well as create one from scratch.
It now supports 1987 response codes and 1993 response codes.

