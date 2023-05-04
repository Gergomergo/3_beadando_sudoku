//
// Created by Gelegonya Gergő on 2023. 04. 26..
//
#include "graphics.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "widget.h"
#include "string_widget.h"
#include <string>
using namespace std;
using namespace genv;

string_widget::string_widget (int _posx, int _posy) : widget(_posx, _posy) {
    szoveg = "";
    kurzor = 0;
    kurz = false;
    //evx = 0;
    //evy = 0;
}
string string_widget::leker()
{
    return szoveg;
}





void string_widget::kirajzol(event ev)
{

    if (ev.type == ev_mouse)
    {
        evx = ev.pos_x;
        evy = ev.pos_y;
    }

    fokusz = abs(evy - y - 10) < 20 && abs(evx  - x - gout.twidth(szoveg) + 10) < gout.twidth(szoveg) + 20;
    if (ev.type == ev_key && 0 < ev.keycode && fokusz == true)
    {
        if (ev.keycode == key_backspace)
        {
            gout << move_to(x,y) << color(0,0,0) << box(gout.twidth(szoveg) + 20, 20);
            szoveg = szoveg.substr(0, szoveg.length() - 1);

        } else
            szoveg += ev.keycode;
    }
    gout << move_to(x,y) << color(255,255,255) << box(gout.twidth(szoveg) + 20, 20);
    string vonal = "|";
    if (ev.type == ev_timer)
    {
        if (kurz == true)
        {
            gout << move_to(x + gout.twidth(szoveg) + 5, y + 15);
            gout << color(125,0,0);
            gout << text(vonal);
            kurz = false;
        }

        if (kurz == false)
        {
            gout << move_to(x + gout.twidth(szoveg) + 5, y + 15);
            gout << color(255,255,255);
            gout << box(x + gout.twidth(szoveg) + 5 + gout.twidth(vonal), y);
            kurz = true;
        }
    }

    gout << move_to(x + 5, y + 15) << color(125,0,0) <<text(szoveg);
    gout << refresh;
}

