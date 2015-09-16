# Cruise KnightBoard
A solution to Cruise's Kight's Board problem.

## Usage
The KnightBoard object contains all the key datastructures and methods. To begin, you must supply the KnightBoard with the size
of the board, and a char array containing the board information. If the board only consists of the '.' character, then only the
board size needs to be supplied. For example:

``` c++
char board[] = {
        '.','.','.','B','.','.','.',
        '.','.','.','B','.','.','.',
        '.','T','.','B','.','.','.',
        '.','.','.','B','.','.','.',
        '.','.','.','B','.','T','.',
        '.','.','.','B,'.','.','.',
        '.','.','.','B','.','.','.',
};
KnightBoard *kn = new KnightBoard(7);         // Constructs a 7x7 board containing only '.'
KnightBoard *kn2 = new KnightBoard(board, 7); // Constructs a 7x7 board containing the map

pair<int,int> begin(0,0); // Start
pair<int,int> end(6,6);   // End

vector<Square *> path = kn->findShortestPath(begin, end);   // Path through the first board
vector<Square *> path2 = kn->findShortestPath(begin, end);  // Path through the second board

kn->validSequence(path, false);
kn->validSequence(path2, false);
```

## Compiling/Running
To compile and run the project, first clone the repository somewhere on your filesystem. It requires CMake >= 2.8, and 
gcc/g++ >= 2.8 (that I've tested with. It might work with 4.7).

``` bash
$ git clone https://github.com/wheelium-m/cruiseKnightBoard.git
$ cd cruiseKnightBoard
```

Make a build folder, and generate the makefiles.

``` bash
$ mkdir build && cd build
$ cmake .. && make
```

To run the main program, simply type
``` bash
$ ./cruise
```

To run the tests, type
``` bash
$ ctest
```

## Approach

### Levels 1-4
The board is treated as a graph, where valid knight moves correspond to edges. The board is preprocessed to find all valid
moves that can be made from a particular square, and then traversed using dijkstra's algorithm to find the shortest path.
As is mentioned in the comments, A* might be a better approach for very large boards, but for only a 32x32 dijkstra was
sufficient. Furthermore, the presence of teleporters might throw off A*'s hueristic distance hueristic.

### Level 5
Since the graph is not a DAG, it was hard (NP hard, anyway :) ) to find an efficient solution. It's very possible that there 
was some sort of tree-pruning I missed, but I didn't have time to implement anything other than a brute force solution.


## Implementation Time
The breakdown for my work hours is approximately as follows:
* Getting cmake configuring ---------------- 1hr.
* Implementing the graph/board ----------- 5hrs
* Implementing dijkstra's -------------------- 3hrs
* Implementing longest path ---------------- 2 hrs
* Adding tests/commenting ------------------ 1.5 hrs

TOTAL                                     12.5 hrs

Although I consider myself a C++/Python/Linux style programmer, I am currently working with a Java/Windows development stack, so 
it took somewhat longer to implement this than I feel it otherwise would. For this project, I used Jetbrains CLion on Windows 
for the brunt of the development, and switched to Emacs/Ubuntu towards the end.

If you would like to see projects on my other gitHub account, you can find them here: https://github.com/wmarshall484
I am currently contributing to IBMStreams, a realtime datastreaming framework.

Thanks for reviewing this! Please let me know if you have any questions.
