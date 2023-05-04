//
// Created by Gelegonya Gergő on 2023. 05. 03..
//

#ifndef SUDOKU_PROJEKT_NUMBER_WIDGET_H
#define SUDOKU_PROJEKT_NUMBER_WIDGET_H
#include "widget.h"
#include "graphics.hpp"


class number_widget : public widget {
    int intbal;
    int intjobb;
    int akt;
    //int evx;
    // int evy;
public:
    number_widget(int _posx, int _posy, int _intbal, int _intjobb);
    void kirajzol(genv::event ev);
    int getnumb();
    //void erzekeljobb(genv::event ev);
    //void erzekelbal(genv::event ev);
    //void csuszka(genv::event ev);
};
#endif //SUDOKU_PROJEKT_NUMBER_WIDGET_H
