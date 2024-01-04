# App-Template-Selector (in development)

This repository contains a simple application for selecting an application template.
The motivation behind creating this application was to facilitate the work of programmers by providing them with ready-made project templates for various programming languages.

# Build requirements 

Project has been build on Linux environment. Windows is not currently supported. 
- CMake 3.5 or newer
- g++ or any compiler which supports C++20
- QT 6
- GoogleTest

# Build instructions

You can open this project in QT Creator and then build it by running "Run CMake" and "Build".

# Third-party Libraries

The project uses the following third-party library:

- [nlohmann/json](https://github.com/nlohmann/json) - A modern C++ JSON library

# Future improvements
- reading project from .json file
- separate view for adding custom projects
- GitHub repository support
