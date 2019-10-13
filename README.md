# PERCOLATE
# Table of Contents

  * [Background](#background) 
  * [Environment](#environment)
  * [Structure](#structure)
  * [Install](#install)
  * [Usage](#usage)
  * [Additional Infromation](#additional-infromation)


# Background 
#### Percolate
The program solves the following problem. Suppose we have a grid of squares (e.g. 5 × 5) in which a certain number of squares are “filled” (grey) and the rest are “empty” (white). The problem to be solved is whether there is a path from an empty (white) square on the top row to an empty square on the bottom row, following only empty squares. This is a bit like solving a maze. The connected squares form clusters. If a cluster touches both the top and bottom of the grid, i.e. there is a path of empty squares from top to bottom through the cluster, then we say that the cluster “percolates”.
#### Sloving percolate
One solution to identify whether there is a cluster such that a path of empty squares from top to bottom through a cluster, that a cluster “percolates”, is as follows. First, we initialise each of the empty squares with a unique positive integer (all the filled squares are set to zero) Then, we loop over all the squares in the grid many times and during each pass of the loop we replace each square with the maximum of its four neighbours. In all cases, we can ignore the filled (grey) squares. The large numbers gradually fill the gaps so that each cluster eventually contains a single, unique number. This then allows us to count and identify the clusters. If we find a part of a cluster on both the top and bottom row of the grid and it shares the same number, then we know that this is the same cluster and so we can conclude that the cluster percolates.

#### My work
Though the program works, and has no bugs that the authors are aware of, it is poorly commented, badly laid out, has cryptic variable names and is not modular. It need to be refactored in following goals:
- Clean up and refactor the source code to make it more readable, better commented, and more modular. 
- Extend the program to allow the user to specify the values for the grid size, data file name, PGM file name, rho, seed and maximum number of clusters in the PGM file via the command-line as commandline arguments or parameters.
- Write a build script which allows a user to:
&nbsp;&nbsp;&nbsp;&nbsp;Compile and link the source code into an executable.
&nbsp;&nbsp;&nbsp;&nbsp;Remove any auto-generated files created during compilation, linking or when running the program.
&nbsp;&nbsp;&nbsp;&nbsp;Show the help document of how to use it.
- Write documentation, in a plain-text file, on how a user can build and run the program and provide any other information you think a user would find useful.
 
# Environment
 - GNU Compiler
 - Linux Operating System

# Structure

.
├── Makefile   
├── README.md   
├── config.mk   
├── src   
│   ├── arralloc.c  
│   ├── arralloc.h  
│   ├── getColourInfo.h  
│   ├── gridInitialise.h  
│   ├── gridResult.h  
│   ├── gridUpdate.h  
│   ├── initAll.h  
│   ├── percolate.c  
│   ├── structlib.h  
│   ├── uni.c  
│   ├── uni.h  
│   ├── writeDataFile.h  
│   └── writePgmFile.h  
└── tree.txt  

- The src folder contains the source code 
- Make is the script to compile and link the source code
- The config contains the environment variables used in Makefile
- tree.txt contains the structure of the whole project  

For files in src folder, they are sparated from previous percolate.c. The functions of them are:

| Filename | Function |
| ------ | ------ |
| structlib.h     | store the struct to be used in program |
| initAll.h   | get and set the user input, checking whether they are valid |
| gridInitialise.h   | Initialize the grid depends on target density  |
| gridUpdate.h   | update the grid until the value in square not change |
| gridResult.h   | get the result from the updated grid |
| writeDataFile.h   | write data to data file |
| getColourInfo.h   | get colour information from clusters |
| writePgmFile.h     | write data to pgm file |


# Install

Percolate requires GCC to compile.

You can build the program as follows:

```sh
$ unzip B157734-PS-Assessment1.zip
$ cd B157734-PS-Assessment1
$ make
```

You can also build the program by  

```sh
$ unzip B157734-PS-Assessment1.zip
$ cd B157734-PS-Assessment1
$ make all
```

It will strat the Makefile which is a script to build and link the program to generate the execute file and create an archive to package them together.
# Usage

Run the percolate.out executable file with the proper input. There are total 7 input need to entered in command line:  
- $(execute_file): here is the percolate.out which will be executed
- $(grid_length): the length of the grid
- $(target_density): the expected density of the grid (rho)
- $(seed): Random number seed to generate the random number
- $(max_coloured_cluster_num): the max number of clusters to be coloured
- $(datafile): write the final grid to the .dat file 
- $(pgmfile): write the coloured grid to the .pgm file

Then run:

```sh
$ ./percolate.out $(grid_length) $(target_density) $(seed) $(max_coloured_cluster_num) $(datafile) $(pgmfile)
```

You will get the output like follow:

```sh
Parameters are rho=0.400000, L=20, seed=1564
rho = 0.400000, actual density = 0.425000
Number of changes on loop 1 is 199
Number of changes on loop 2 is 170
Number of changes on loop 3 is 149
Number of changes on loop 4 is 132
Number of changes on loop 5 is 118
Number of changes on loop 6 is 113
Number of changes on loop 7 is 78
Number of changes on loop 8 is 64
Number of changes on loop 9 is 63
Number of changes on loop 10 is 58
Number of changes on loop 11 is 54
Number of changes on loop 12 is 48
Number of changes on loop 13 is 40
Number of changes on loop 14 is 38
Number of changes on loop 15 is 30
Number of changes on loop 16 is 28
Number of changes on loop 17 is 25
Number of changes on loop 18 is 22
Number of changes on loop 19 is 11
Number of changes on loop 20 is 2
Number of changes on loop 21 is 0
Cluster DOES percolate. Cluster number: 225
Opening file <map.dat>
Writing data ...
...done
File closed
Opening file <map.pgm>
Map has 21 clusters, maximum cluster size is 121
Displaying all clusters
Writing data ...
...done
File closed
```
To slove the percolate problem, the program creates a grid. Each square is randomly assigned to be empty 1 or filled 0 according to the designed density distribution of filled squares. Each empty square is then assigned a unique number. The program iteratively updates the grid, updating each square is updated with the maximum of its neighbours. When an iteration results in no squares being updated, the iteration exits. The program then checks whether there is a cluster on the top row of the grid that has the same number as one on the bottom row i.e. it checks whether percolation has occurred.  

The program will also write out two files. The first is a data file which contains the values of each empty square when each square can be no longer updated i.e. the final state of the grid. This file is plain-text so you can view them as you would any plain-text file e.g.:
```sh
$ cat $(datafile)
```
You will get output like follow:
```sh
   24   24    0  225    0    0  225    0  225  225  225  225  225  225    0    0  225    0  225    0
    0    0  225  225    0  225  225  225  225  225  225  225  225  225  225  225  225  225  225    0
    0   23    0  225    0    0    0  225    0  225    0    0    0  225  225  225  225    0    0    0
   11    0  225  225  225  225  225  225    0    0  225    0    0    0  225  225    0  206    0  230
    0   22    0    0  225  225  225  225    0  225  225    0    0  225  225  225  225    0  230  230
    0    0   82    0    0  225  225  225    0    0  225  225    0    0  225  225    0  205    0  230
   82   82   82   82   82    0    0  225  225  225  225    0    0    0  225    0  225    0  216    0
   82    0   82   82   82    0    0    0    0  225  225    0    0  225  225    0  225    0    0  227
   82    0   82    0    0   82    0  110  110    0    0  133    0  225  225    0  225    0  227  227
   82   82   82   82   82   82   82    0  110    0  120    0  225  225  225    0  225    0    0    0
    0   82    0    0   82   82    0    0  110  110    0    0  225  225    0  225  225  225  225    0
    0   82   82    0   82   82   82    0  110    0  225  225  225  225  225  225  225  225    0    0
    0   82    0    0   82    0    0   89    0    0    0  225    0  225  225  225    0  225  225    0
   82   82   82   82   82   82    0    0    0    0    0    0    0    0  225    0  225  225  225  225
   82   82    0   82   82   82   82    0  118  118    0  130    0    0  225  225  225  225    0  225
    0   82    0   82   82   82   82    0    0  118  118    0    0  225  225  225    0    0  211    0
   82   82   82   82   82   82    0    0    0  118    0    0    0  225    0  225    0    0    0  223
   82    0   82    0   82   82    0    0    0    0  225  225    0  225    0    0    0    0  223  223
   82    0   82   82    0   82    0   88    0  106    0  225  225  225  225    0    0  223  223  223
   82    0   82   82   82    0    0    0    0  106    0    0    0  225  225    0  223  223  223  223
```
You can do the same thing to the second file to see it in plain text:
```sh
$ display $(pgmfile)
```
You will get output like follow:
```sh
P2
20 20
21
    8    8   21    0   21   21    0   21    0    0    0    0    0    0   21   21    0   21    0   21
   21   21    0    0   21    0    0    0    0    0    0    0    0    0    0    0    0    0    0   21
   21   18   21    0   21   21   21    0   21    0   21   21   21    0    0    0    0   21   21   21
   20   21    0    0    0    0    0    0   21   21    0   21   21   21    0    0   21   11   21    5
   21   19   21   21    0    0    0    0   21    0    0   21   21    0    0    0    0   21    5    5
   21   21    1   21   21    0    0    0   21   21    0    0   21   21    0    0   21   12   21    5
    1    1    1    1    1   21   21    0    0    0    0   21   21   21    0   21    0   21    9   21
    1   21    1    1    1   21   21   21   21    0    0   21   21    0    0   21    0   21   21    6
    1   21    1   21   21    1   21    3    3   21   21   13   21    0    0   21    0   21    6    6
    1    1    1    1    1    1    1   21    3   21   15   21    0    0    0   21    0   21   21   21
   21    1   21   21    1    1   21   21    3    3   21   21    0    0   21    0    0    0    0   21
   21    1    1   21    1    1    1   21    3   21    0    0    0    0    0    0    0    0   21   21
   21    1   21   21    1   21   21   16   21   21   21    0   21    0    0    0   21    0    0   21
    1    1    1    1    1    1   21   21   21   21   21   21   21   21    0   21    0    0    0    0
    1    1   21    1    1    1    1   21    4    4   21   14   21   21    0    0    0    0   21    0
   21    1   21    1    1    1    1   21   21    4    4   21   21    0    0    0   21   21   10   21
    1    1    1    1    1    1   21   21   21    4   21   21   21    0   21    0   21   21   21    2
    1   21    1   21    1    1   21   21   21   21    0    0   21    0   21   21   21   21    2    2
    1   21    1    1   21    1   21   17   21    7   21    0    0    0    0   21   21    2    2    2
    1   21    1    1    1   21   21   21   21    7   21   21   21    0    0   21    2    2    2    2
```
Actually the second file is a type of image file, a Portable Grey Map (PGM) file. This file can be viewed with standard visualisation tools for example:
```sh
$ display $(pgmfile)
```
or:
```sh
$ gimp $(pgmfile)
```
After running the program, if you want to remove any auto-generated files created during compilation, linking or when running the program, you can use following command:
```sh
$ make clean
```
It will clean all the .o files, .out files, .dat files, .pgm files as well as the archive and have follow output:
```sh
rm -f  arralloc.o  percolate.o  uni.o
rm -f ./percolate.out
rm -f *.dat
rm -f *.pgm
rm -rf zipf_percolate
rm -rf zipf_percolate.tar.gz
```
For variables in make, you can see by command:
```sh
$ make variables
```
You will get:
```sh
C_FILES: src/arralloc.c src/percolate.c src/uni.c
O_FILES: arralloc.o percolate.o uni.o
EXE_FILE: ./percolate.out
ZIPF_DIR: zipf_percolate
ZIPF_ARCHIVE: zipf_percolate.tar.gz
```
If you want to see all the commands in detail, you could use:
```sh
$ make help
```
Then you will get:
```sh
 all: Generate the .o file from .c files and link them to generate execute file and package them.
 clean: Clean all the auto generated files when compile and run program.
 variables: Print variables.
```
# Additional Infromation
The main idea of refactoring code:
- First, I use two structs to store the grid data and file name respectively, so that each function will not receive extra input parameters. All the structs are stored in structlib.h. 
- Then I change the variables' name and type in previous percolate.c to let them fit my struct.
- Then I add the init function to receive user input from the command line and assign these value to struct variables.
- In order to achieve modularity, I separate the whole percolate.c to a lot of functions. Each method is only responsible for one type of task i.e. print, calculation. 
- I find it's too large to put all the code into percolate.c, so I separate the functions out of percolate.c and only remain the main function inside it.
- For error tolerance, I add some simple checks for user input including checking whether the user's input is integer or float as well as whether the total number of user input is correct.
- After that I add some comments to describe the code to make it more readable.
- Add the Makefile scipt
- Eventually, I write the readme to show how to install and use my project



