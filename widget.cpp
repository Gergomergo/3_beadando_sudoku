#include "graphics.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "widget.h"
using namespace std;

widget::widget(int posx, int posy) : x(posx), y(posy) {
    fokusz = false;
    evx = 0;
    evy = 0;
}




void widget::kirajzol(genv::event ev) {}



string widget::leker() {}

int widget::getnumb() {}

void widget::draw_erase(int i, int j) {}
void widget::focuscheck(int evx, int evy, int numbers[9][9]) {}
void widget::draw_field () {}
void widget::draw_numbers(int numbers[9][9]) {}
void widget::draw_focus(int i, int j, int numbers[9][9]) {}
void widget::draw_wrong(int i, int j, int szam) {}
void widget::draw_bar(int ido) {}

vector<int> get_focus() {};
