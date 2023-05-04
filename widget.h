//
// Created by Gelegonya Gergő on 2023. 05. 03..
//

#ifndef SUDOKU_PROJEKT_WIDGET_H
#define SUDOKU_PROJEKT_WIDGET_H
#include "graphics.hpp"
using namespace std;
class widget
{
protected:
    int x;
    int y;
    int evx;
    int evy;
    bool fokusz;

public:
    widget(int posx, int posy);


    virtual void kirajzol(genv::event ev);


    virtual string leker();

    virtual int getnumb();

    void draw_erase(int i, int j);
    void focuscheck(int evx, int evy, int numbers[9][9]);
    void draw_field ();
    void draw_numbers(int numbers[9][9]);
    void draw_focus(int i, int j, int numbers[9][9]);
    void draw_wrong(int i, int j, int szam);
    void draw_bar(int ido);

    vector<int> get_focus();

};
#endif //SUDOKU_PROJEKT_WIDGET_H
