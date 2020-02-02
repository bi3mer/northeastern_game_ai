# A Star

**Code Location**: .\a_star <br/>
**Data Location**: .\data

A* is implemented in `.\a_star\AStar.cpp` and `.\a_star\AStarNode.cpp` with corresponding header files.

Heirarchal pathfindng is implemented in `.\a_star\HeirarchalPath.cpp` with a corresponding header file. This uses the rectangle/square method discussed in class without the additional steps for removing smaller rectangles/squares.

Path simplification is implmetned in `.\a_star\PathSimplfication.cpp` with a corresponding header file. 

## Setting Maps

Run the executable and you will be able to input the map files that you want.

```
Please input path to map file:
..\\data\\Problem1.json
Please input path to solution path:
..\\data\\Solution1.json
```

## How to Run

Execute executable.

I also have included the visual studio project that you can work with. I used [vcpkg](https://github.com/microsoft/vcpkg) to install the 64 bit version of [jsoncpp](https://github.com/open-source-parsers/jsoncpp). 

### Modified Input

The input for problem 2 and 3 is incorrect given the solutions. As a result I have two additional files in .\data.

* .\data\accurateProblem2.json
* .\data\impossibleProblem3.json