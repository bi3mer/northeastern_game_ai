# A Star

**Code Location**: .\a_star <br/>
**Data Location**: .\data

A* is implemented in `.\a_star\AStar.cpp` and `.\a_star\AStarNode.cpp` with corresponding header files.

Path simplification is implmetned in `.\a_star\PathSimplfication.cpp` with a corresponding header file. I didn't use floats, they aren't required for the taxicab scenario which is what I worked in. 

I didn't do the heirachal path planning even though there is a file. I decided not to bother. 

## Setting Maps

Run the executable and you will be able to input the map files that you want.

```
$ ./a_star.exe
Please input path to map file:
..\\..\\data\\Problem1.json
Please input path to solution path:
..\\..\\data\\Solution1.json
----> And then output you can see after running.
```

If you input something bad, it will break. I do some things but if you input two json files that don't have the expected values then it will crash.

## How to Run

Execute executable.

I also have included the visual studio project that you can work with. I used [vcpkg](https://github.com/microsoft/vcpkg) to install the 64 bit version of [jsoncpp](https://github.com/open-source-parsers/jsoncpp). 

### Modified Input

The input for problem 2 and 3 is incorrect given the solutions. As a result I have two additional files in .\data.

* .\data\accurateProblem2.json
* .\data\impossibleProblem3.json

I also updated the solution file ot have empty brackets so it could be parsed without error.

## Notes on A* Implementation

The solutions given didn't care about path length. Instead it was only about cost. So you'll notice that AstarNode.cpp constructor has:

```c++
g = node.g + tileCost;
```

Instead of the more common implementation:

```c++
g = 1 + node.g + tileCost;
```

Where path length is also considered. As a result this is a lowest cost where length is not considered.