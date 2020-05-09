# ISO8583
A small example of how to decode ISO8583 messages.

In the future I'd like to add the ability to set values as well.

# Build
Prerequisites:
  CMake
  C++ compiler supporting 17 standards.

git clone git@github.com:qcerasmus/ISO8583.git
Make a new folder called build and cd into it using the terminal.
cmake ..

Everything should compile without issues.

# Dependencies
There are no dependencies, but I do make use of SPDLog: https://github.com/gabime/spdlog which is an AMAZING logging library for C++.
I modified it a little bit with regards to color output in the terminal.

# Future work
Actually turn this project into a library.
Adding the ability to generate an ISO8583 message.
