#include "graphics.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "sudoku_game.h"
using namespace std;

sudoku_game::sudoku_game(int _difficulty) {
    int numbers[9][9] = {
            {0,0,0,9,2,8,1,0,0},
            {0,8,0,7,0,3,0,2,4},
            {2,6,0,0,0,5,0,7,0},
            {0,9,0,1,0,7,2,0,0},
            {0,1,0,0,0,6,0,4,7},
            {3,0,0,0,8,0,0,9,1},
            {0,2,8,5,4,0,0,0,6},
            {0,0,6,8,3,9,7,5,0},
            {0,0,5,0,7,0,0,0,0},
    };
}




bool sudoku_game::check_row(int numbers[9][9], int row, int num) {
    for (int i = 0; i < 9; i++) {
        if (numbers[row][i] == num) {
            return false;
        }
    }
    return true;
}

bool sudoku_game::check_col(int numbers[9][9], int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (numbers[i][col] == num) {
            return false;
        }
    }
    return true;
}

bool sudoku_game::check_box(int numbers[9][9], int row, int col, int num) {
    for (int i = 0; i< 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (numbers[i + row][j + col] == num) {
                return false;
            }
        }
    }
    return true;
}
bool sudoku_game::is_equal (int numbers[9][9], int row, int col, int num)
{
    return numbers[row][col] == num;
}

bool sudoku_game::check(int numbers[9][9], int row, int col, int num)
{
    return check_row(numbers, row, num) && check_col(numbers, col, num) && check_box(numbers, row - row % 3, col - col % 3, num);
}



