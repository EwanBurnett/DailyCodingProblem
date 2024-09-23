# Daily Coding Problem 

My solutions to various Coding interview questions via [DailyCodingProblem](https://www.dailycodingproblem.com)
Each solution is implemented as a console application. To view output, the executable must be run from a terminal. 

## Unit Testing
Unit Tests are supported via [Google Test](https://github.com/google/googletest.git). 
To enable Unit Testing, set the `ENABLE_UNIT_TESTS` CMake option during [Project Generation](#build-instructions). 

e.g. 
```
# build preamble...
cmake .. -DENABLE_UNIT_TESTS=ON
```

This will add Unit Test results to the executable's output. 


## Build Instructions
- Clone the Repository via git
```
git clone https://github.com/EwanBurnett/DailyCodingProblem.git
cd DailyCodingProblem
```

### Reqirements
- [CMake 3.14](https://cmake.org) or higher

### Command Line with CMake
- Generate the project files via CMake
```
mkdir build
cd build
cmake ..
```
- Build the project using your platform's build system 
```
# e.g. building via make
make 
```

### Visual Studio with CMake [Windows]
- Install [C++ CMake tools for Windows](https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170) for your Visual Studio Distribution. 
- Open the repository folder in Visual Studio
- Select a project to build from the dropdown, and run. 

