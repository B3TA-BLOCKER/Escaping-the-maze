# 🧩 Escaping the Maze 🌀


This repository contains a C++ implementation of a maze solver using backtracking. The program takes a square matrix as input, where `0` represents closed blocks, and `1` represents open blocks. The objective is to find a path from the top-left corner to the bottom-right corner of the maze, moving only through the open blocks.

The code uses a recursive backtracking algorithm to explore all possible paths in the maze. It starts at the top-left corner and tries to move in all possible directions (right and down) until it reaches the bottom-right corner or gets stuck. If a valid path is found, it is displayed as a matrix, with `1` indicating the path taken and `0` indicating blocked or unvisited cells.

Feel free to clone the repository and try it out with your maze configurations. Contributions, bug reports, and suggestions for improvements are welcome!

### How to Use 🚀

1. **Clone the repository:**
   ```bash
   https://github.com/B3TA-BLOCKER/Escaping-the-maze.git
   ```


2. Compile the code using a C++ compiler:
   ```bash
   g++ main.cpp -o main
   ```

4. Run the executable:
   ```bash
   ./main
   ```


6. Follow the on-screen prompts to enter the size of the matrix and provide the values (0s and 1s) for the maze.

7. The program will output the resulting path if it exists. The path is represented by a matrix, where `1` indicates the path taken and `0` indicates blocked or unvisited cells.

