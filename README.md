# 16x16-Sudoku-Solver-Optimized-Backtracking-with-Heuristics-
This is a fast and simple 16x16 Sudoku solver I wrote in C++. It uses optimized backtracking with a simple but powerful heuristic(Always fill the cell with the fewest valid options first)

How it works

    The Sudoku grid is 16x16 — supports numbers 1-9 and letters A-G (base 16 logic).

    The grid is read as a single block of input, row by row.

    Hex conversion

    Empty cells are represented by 0 (or input '0').
    
    
It uses a simple recursive solve() function with backtracking:

    Always picks the empty cell with the least number of possibilities.

    This greatly improves performance — the puzzle solves much faster.

    If stuck, it backtracks cleanly.

Example of input:

  1 2 3 4 5 6 7 8 9 A B C D E F G
  5 6 7 8 9 A B C D E F G 1 2 3 4
  9 A B C D E F G 1 2 3 4 5 6 7 8
  D E F G 1 2 3 4 5 6 7 8 9 A B C
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

    

How to compile & run:

  g++ -O2 -o sudoku_solver sudoku_solver.cpp
  
  ./sudoku_solver  

    
