# README

**This file is written by Qimiao Cai to explain the contents of my submissions. All samples are selected from course projects of Foundations of Algorithms and Data Structures.**


## Explanation/description for Code Samples

### Sample 1 

#### Matrix Chain Ordering Problem, MCOP

###### Complete Date: 2021/11/25

Determine the optimal parenthesization of a product of n matrices. 

The value of n can be 5, 10, 15, 20, 25 and the sizes of the matrices is provided in 1_1_input.txt. 

The result and runtime are printed in result.txt and time.txt in the output folder in the form of:

- result.txt: The result of each scale takes two lines.
  - The least times of multiplication.
  - The optimal parenthesization of the product of n matrices.

- time.txt: The runtime of each scale takes one line.

### Sample 2

#### Union By Rank & Path Compression Disjoint-Set

###### Complete Date: 2021/12/14

There are N people.(N could be 10/15/20/25/30). Some of them are relatives while others are not. Their kinship is transitive. If A and B are relatives, B and C are relatives, we can consider A and C are relatives. A family is a set of all relatives. 

Given a matrix M of N * N which shows the kinship between people. If M\[i][j] = 1, person i and person j are relatives, otherwise they are not. The result must provide the number of families in all the N people.

The solution must include using Disjoint-Set, both Union By Rank and Path Compression Optimization should be realized.

Record the elapsed time for different N values.

The value of N can be 5, 10, 15, 20, 25 and the matrices M for each N are provided in 2_2_input.txt. 

The result and runtime are printed in result.txt and time.txt in the output folder in the form of:

- result.txt: The result of each scale takes one line.
  - n=N Family number: result

- time.txt: The runtime of each scale takes one line.

### Sample 3

#### Single-Source Shortest Paths – Bellman–Ford Algorithm

###### Complete Date: 2021/12/31

The value of the number of vertices of the directed sparse graph N can be: 27, 81, 243, 729. The values of the number of edges drawn from each vertex as the starting point are:  ⌈log~5~N⌉, ⌈log~7~N⌉. The adjacency matrices are stored in the input files(input11.txt，input12.txt，...，input42.txt). There are a total of 4*2=8 input scales. The range of edge weight is a non-zero integer in [-100, 1000], and 0 means no edge is connected. There are no negative cycles in the graph.

The results and runtimes are printed in corresponding files in the output folder in the format of:

- result11.txt, result12.txt,……, result42.txt: 
  - The shortest path of a node pair is stored in each line, in the format of: i,j,w;i,u1,u2,...,j(i is always 0). That is, in each line, first prints the node pair serial number and the total length of the path, and then prints the complete path after being separated by a semicolon. If there is an unreachable node starting from node 0, it does not need to be printed in the file.
- time.txt: The runtime of each scale takes one line.

### Sample 4

#### Rabin-Karp Algorithm for Pattern Searching

###### Complete Date: 2022/1/19

Given a text string T and a pattern string P, the length of T is n, and the length of P is m, use the Rabin-Karp algorithm for pattern searching.

There are 5 sets of values for (n, m), namely: (2^8^, 2^3^), (2^9^, 2^4^), (2^10^, 2^5^), (2^11^, 2^6^), (2^12^, 2^7^), see 4_2_input.txt. The data for each scale takes two rows: 

- pattern string P
- text string T

Base number d and prime number q have 4 sets of values, (d, q) are: (2,13), (2,1009), (10,13), (10,1009)

The results and runtimes are printed in corresponding files in the output folder in the format of:

- result.txt: The results of each scale takes four rows(In the order of the previous input documents)
  - number of matched pattern
  - false hits (Print the number of false hits in four (d, q) scales, in the order of (2,13), (2,1009), (10,13), (10,1009))
  - The starting position of all matching T (The subscripts of T and P start from 1)
  - Blank line
- time.txt: The runtime of each scale(n, m) takes two lines.
  - (d, q)
  - Time to find all matches under five (n, m) input sizes(separated by spaces).

### Sample 5 

#### Family Tree system

Design and implement a simple family tree system.

- Create a family relationship tree and store it in a file.
- Realize the addition and deletion of family members
- Search information about parents, ancestors, brothers, children and descendants of family members.
- Print the family tree in tree structure and according to their seniority.

## Instructions for compiling and running the code

All the code samples are written in C++ and are already compiled into executable files. The outputs for Sample1-4 have been printed once in corresponding files in the output folders. If you wish to test(compile and run) the code yourself, please follow the steps:

1. Enter the src folder, open the source code and compile the code in a C++ compiler.
2. Manually clear all the text documents in the output folder but **DO NOT CHANGE THE TEXT DOCUMENTS' NAMES**. (This step is only necessary if you do not want the outputs printed twice.)
3. Run the executable files and open the text documents in the output folder to see the results.

The family tree managing system can be tested directly by compiling and running the code.