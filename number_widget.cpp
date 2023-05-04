#include "graphics.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "widget.h"
#include "number_widget.h"
using namespace genv;
using namespace std;
number_widget::number_widget (int _posx, int _posy, int _intbal, int _intjobb) : widget(_posx, _posy), intbal(_intbal), intjobb(_intjobb) {
    akt = round((intbal + intjobb) / 2);
    //evx = 0;
    //evy = 0;
}

/*
void number_widget::erzekeljobb(event ev)
{
    if (ev.button == btn_left && abs(ev.pos_x - x - 180) < 10 && abs(ev.pos_y - y - 20) < 10 && akt < intjobb)
    {
        double lepeskoz = double(abs(intbal-intjobb)) / 100;
        akt += lepeskoz*abs(intbal-intjobb);
        gout << move_to(x + 200 - 30, y + 40 - 10 - 20)  << color(255,0,0) << box(20,20) << move_to(x + 200 - 15 - 10, y + 40 - 15) << color(255,255,255) << text(">");
        gout << refresh;
    }

}
void number_widget::erzekelbal(event ev)
{
    if (ev.button == btn_left && abs(ev.pos_x - x - 20) < 10 && abs(ev.pos_y - y - 20) < 10 && akt > intbal)
    {
        double lepeskoz = double(abs(intbal-intjobb)) / 100;
        akt -= lepeskoz*abs(intbal-intjobb);
        gout << move_to(x + 10, y + 10)  << color(255,0,0) << box(20,20) << move_to(x + 15, y + 25) << color(255,255,255) << text("<");
        gout << refresh;
    }
}

void number_widget::csuszka(event ev)
{

    int alap = abs(intjobb - intbal);
    int lepeskoz =
    int csuszkax = x + 30 + lepeskoz * akt;





    gout << move_to(csuszkax, y + 12) << color(129,212, 225) << box(14,14);
    //gout << refresh;
}

void number_widget::kirajzol(genv::event ev)
{
    gout << move_to(x,y) << color(255,255,255) << box_to(x + 200, y + 40);
    gout << move_to(x + 10, y + 10)  << color(0,0,0) << box(20,20) << move_to(x + 15, y + 25) << color(255,255,255) << text("<");
    gout << move_to(x + 200 - 30, y + 40 - 10 - 20)  << color(0,0,0) << box(20,20) << move_to(x + 200 - 15 - 10, y + 40 - 15) << color(255,255,255) << text(">");
    gout << move_to(x + 30, y +15) << color(173, 63, 40) << box(140, 10);
    gout << move_to(x + 90, y - 20) <<color(255,255,255) << box(20,20);
    string s = to_string(akt);
    gout << move_to(x + 95, y - 5) << color(163,123,163) << text(s);
    erzekeljobb(ev);
    erzekelbal(ev);
    csuszka(ev);

    gout << refresh;
}
*/
int number_widget::getnumb()
{
    return akt;
}

void number_widget::kirajzol(event ev)
{
    if (ev.type == ev_mouse)
    {
        evx = ev.pos_x;
        evy = ev.pos_y;
    }
    gout << move_to(x,y) << color(255,255,255) << box_to(x + 200, y + 40);
    gout << move_to(x + 10, y + 10)  << color(0,0,0) << box(20,20) << move_to(x + 15, y + 25) << color(255,255,255) << text("<");
    gout << move_to(x + 200 - 30, y + 40 - 10 - 20)  << color(0,0,0) << box(20,20) << move_to(x + 200 - 15 - 10, y + 40 - 15) << color(255,255,255) << text(">");
    gout << move_to(x + 30, y +15) << color(173, 63, 40) << box(140, 10);


    string s = to_string(akt);
    int boxmeret = gout.twidth(s);
    gout << move_to(x + 90, y - 20) <<color(255,255,255) << box(boxmeret + 20,20);
    gout << move_to(x + 95, y - 5) << color(163,123,163) << text(s);

    if (((ev.button == btn_left && abs(evx - x - 20) < 10 && abs(evy - y - 20) < 10) || ((ev.keycode == key_down || ev.keycode == 's') && abs(evy - y - 20) < 20 && abs(evx - x - 100) < 100)) && akt > intbal)
    {
        if (ev.keycode == 's')
        {

            if (akt - 10 > intbal)
            {
                akt -= 9;
            } else {
                akt = intbal + 1;
            }
        }

        akt -= 1;
        gout << move_to(x + 10, y + 10)  << color(255,0,0) << box(20,20) << move_to(x + 15, y + 25) << color(255,255,255) << text("<");

    }

    if (((ev.button == btn_left && abs(evx - x - 180) < 10 && abs(evy - y - 20) < 10) || ((ev.keycode == key_up || ev.keycode == 'w') && abs(evy - y -20) < 20 && abs(evx - x - 100) < 100)) && akt < intjobb)
    {   if (ev.keycode == 'w')
        {
            if (intjobb > akt + 10)
            {
                akt += 9;
            } else akt = intjobb - 1;
        }
        akt += 1;
        gout << move_to(x + 200 - 30, y + 40 - 10 - 20)  << color(255,0,0) << box(20,20) << move_to(x + 200 - 15 - 10, y + 40 - 15) << color(255,255,255) << text(">");

    }
    gout << refresh;

}
