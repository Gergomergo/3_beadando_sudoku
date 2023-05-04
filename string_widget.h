//
// Created by Gelegonya Gergő on 2023. 05. 03..
//

#ifndef SUDOKU_PROJEKT_STRING_WIDGET_H
#define SUDOKU_PROJEKT_STRING_WIDGET_H
#include "widget.h"
#include "graphics.hpp"

using namespace std;
class string_widget : public widget {
    string szoveg;
    int kurzor;
    bool kurz;
    //  int evx;
    // int evy;

public:
    string_widget(int _posx, int _posy);
    void kirajzol(genv::event ev);

    string leker();
};

#endif //SUDOKU_PROJEKT_STRING_WIDGET_H
