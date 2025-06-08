#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

//VARIABLES AND CONSTANTS
const int N = 16; // Size
vector<vector<int>> grid(N, vector<int>(N, 0));

// Arrays to track used numbers in rows, columns, and subgrids
array<array<bool, N + 1>, N> rowUsed = {false};
array<array<bool, N + 1>, N> colUsed = {false};
array<array<bool, N + 1>, N> boxUsed = {false};

array<int, N * N> emptyCells;
int emptyNum = 0;

// FUNCTIONS

inline int hexToDecimal(char ch) {
    if (ch == '.' || ch == '0') return 0;
    return (ch >= '1' && ch <= '9') ? ch - '0' : (ch >= 'A' && ch <= 'G') ? 10 + (ch - 'A') : 0;
}

inline char decimalToHex(int num) {
    return (num >= 1 && num <= 9) ? '0' + num : (num >= 10 && num <= 16) ? 'A' + (num - 10) : '.';
}

inline int getBoxIndex(int row, int col) {
    return (row / 4) * 4 + (col / 4);
}

inline bool isValid(int row, int col, int num) {
    return !rowUsed[row][num] && !colUsed[col][num] && !boxUsed[getBoxIndex(row, col)][num];
}

inline void setNumber(int row, int col, int num) {
    grid[row][col] = num;
    rowUsed[row][num] = true;
    colUsed[col][num] = true;
    boxUsed[getBoxIndex(row, col)][num] = true;
}

inline void unsetNumber(int row, int col, int num) {
    grid[row][col] = 0;
    rowUsed[row][num] = false;
    colUsed[col][num] = false;
    boxUsed[getBoxIndex(row, col)][num] = false;
}

inline int possibleNumbers(int row, int col) {
    int count = 0;
    for (int num = 1; num <= N; ++num) {
        if (isValid(row, col, num)) {
            ++count;
        }
    }
    return count;
}

bool solve() {
    if (emptyNum == 0) return true;

    int minOptions = N + 1;
    int bestIndex = -1;

    for (int i = 0; i < emptyNum; ++i) {
        int cell = emptyCells[i];
        int row = cell / N, col = cell % N;
        int options = possibleNumbers(row, col);

        if (options == 0) return false;
        if (options < minOptions) {
            minOptions = options;
            bestIndex = i;
            if (options == 1) break;
        }
    }

    int cell = emptyCells[bestIndex];
    int row = cell / N, col = cell % N;

    for (int num = 1; num <= N; ++num) {
        if (isValid(row, col, num)) {
            setNumber(row, col, num);

            swap(emptyCells[bestIndex], emptyCells[emptyNum - 1]);
            --emptyNum;

            if (solve()) return true;

            ++emptyNum;
            swap(emptyCells[bestIndex], emptyCells[emptyNum - 1]);

            unsetNumber(row, col, num);
        }
    }

    return false;
}

// MAIN
int main() {
    cout << "Enter 16x16 Sudoku grid (use '.' or '0' for empty cells):" << endl;
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            char input;
            cin >> input;
            int num = hexToDecimal(input);
            if (num != 0) {
                if (!isValid(row, col, num)) {
                    cout << "Invalid initial puzzle! Conflict at (" << row << "," << col << ") with number " << num << endl;
                    return 1;
                }
                setNumber(row, col, num);
            } else {
                emptyCells[emptyNum++] = row * N + col;
            }
        }
    }

    cout << "Initial empty cells: " << emptyNum << endl;

    if (solve()) {
        cout << "Solved Sudoku:" << endl;
        for (int row = 0; row < N; ++row) {
            for (int col = 0; col < N; ++col) {
                cout << decimalToHex(grid[row][col]) << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No Solution" << endl;
    }

    return 0;
}
