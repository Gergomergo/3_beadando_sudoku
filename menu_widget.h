//
// Created by Gelegonya Gergő on 2023. 04. 26..
//

#ifndef SUDOKU_PROJEKT_MENU_WIDGET_H
#define SUDOKU_PROJEKT_MENU_WIDGET_H


#include <vector>
#include "widget.h"
#include "graphics.hpp"

using namespace std;
class menu_widget : public widget {
    vector<string> lista;
    int akt;
    bool nyitva;
    int meret;
    int kezdo;
  //  int evx;
   // int evy;

public:
    menu_widget(int _posx, int _posy, vector<string> _lista, int meret);
    void kirajzol(genv::event ev);

    string leker();
};


#endif //ITK_GRAPHICSLIB_MASTER_2_MENU_WIDGET_H
