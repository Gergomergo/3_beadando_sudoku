//
// Created by Gelegonya Gergő on 2023. 05. 03..
//

#ifndef SUDOKU_PROJEKT_SUDOKU_GAME_H
#define SUDOKU_PROJEKT_SUDOKU_GAME_H

using namespace std;
class sudoku_game
{
protected:
    int difficulty;
    int numbers[9][9];
public:
    sudoku_game(int difficulty);

    virtual bool check_row(int numbers[9][9], int row, int num);
    virtual bool check_col(int numbers[9][9], int col, int num);
    virtual bool check_box(int numbers[9][9], int row, int col, int num);
    virtual bool check(int numbers[9][9], int row, int col, int num);
    virtual bool is_equal(int numbers[9][9], int row, int col, int num);

};

#endif //SUDOKU_PROJEKT_SUDOKU_GAME_H
