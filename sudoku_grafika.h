//
// Created by Gelegonya Gergő on 2023. 05. 03..
//

#ifndef SUDOKU_PROJEKT_SUDOKU_GRAFIKA_H
#define SUDOKU_PROJEKT_SUDOKU_GRAFIKA_H
#include "widget.h"
#include "graphics.hpp"

using namespace std;
class sudoku_grafika : public widget {

     int evx;
     int evy;
     vector<int> focus;

public:
    sudoku_grafika(int _posx, int _posy);
    void kirajzol(genv::event ev);

    void draw_erase(int i, int j);
    void focuscheck(int evx, int evy, int numbers[9][9]);
    void draw_field ();
    void draw_numbers(int numbers[9][9]);
    void draw_focus(int i, int j, int numbers[9][9]);
    void draw_wrong(int i, int j, int szam);
    vector<int> get_focus();
    void draw_bar(int ido);

};
#endif //SUDOKU_PROJEKT_SUDOKU_GRAFIKA_H
