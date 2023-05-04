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
#include "menu_widget.h"
using namespace std;
using namespace genv;

menu_widget::menu_widget (int _posx, int _posy, vector<string> _lista, int _meret) : widget(_posx, _posy), lista(_lista), meret(_meret) {
    akt = 0;
    nyitva = false;
    kezdo = 1;
    //evx = 0;
    //evy = 0;
}
string menu_widget::leker()
{
    return lista[akt];
}


int szelesseg(vector<string> lista)
{

    int max = 0;
    for (int i = 0; i < lista.size(); ++i)
    {
        if (max < gout.twidth(lista[i]))
        {
            max = gout.twidth(lista[i]);
        }
    }
    return max + 20;

}



void menu_widget::kirajzol(event ev)
{
    //gout << move_to(x, y) << color(255,255,255);

    //szélesség
    int max = szelesseg(lista);
    //fókusz

    if (ev.type == ev_mouse)
    {
        evx = ev.pos_x;
        evy = ev.pos_y;
    }


    if (abs(evy - y - 20*(meret + 1)) < (20* meret + 1) && abs(evx  - x - max/2) < (max)/2)
    {
        //iranyitas
        if ((ev.button == btn_wheeldown || ev.keycode == key_down) && kezdo < lista.size() - meret - 1)
        {
            ++kezdo;
        }
        if ((ev.button == btn_wheelup || ev.keycode == key_up) && 0 < kezdo)
        {
            --kezdo;
        }
    }




    //első sor rajz
    gout << color(130,142,142) << move_to(x,y) << box(max + 10, 20);
    gout << color(0,0,0);
    gout << move_to(x + 5, y + 20- 5) << text(lista[akt]);
    gout << move_to(x + max + 10 - 20, y) << color(255,255,255) << box(20,20);

    //nyitás/csukás
    if (ev.type == ev_mouse && ev.button == btn_left && abs(evy - y - 10) < 10 && abs(evx - (x + max) < 10))
    {
        if (nyitva == true)
        {
            nyitva = false;
        } else nyitva = true;
        gout << move_to(x, y + 20) << color(0,0,0) << box(max + 10, 20*(lista.size() - 1));
    }
    //nyitás/csukás gomb rajz
    gout << color(0,0,0);
    if (nyitva == true)
    gout << move_to(x + max + 10 - 20, y + 15) << text(" |");
    else gout << move_to(x + max + 10 - 20, y + 15) << text(" -");


    //menü

    if (nyitva == true)
    {
        int z = 0;

        for (int i = kezdo; i < kezdo + meret + z; ++i)
        {
            if (i != akt)
            {
                gout <<  color(255,255,255);
                //z = 1;
                if (ev.type == ev_mouse && abs(evy - y - (20*(i - kezdo - z + 1))) < 10 && abs(evx  - x - max/2) < (max)/2)
                {
                    gout << color(0,0,255);
                    if (ev.button == btn_left)
                    {
                        akt = i;
                        kezdo = 0;
                        nyitva = false;
                        z = 0;
                        gout << move_to(x, y + 20) << color(0,0,0) << box(max + 10, 20*(meret));
                        break;
                    }


                } else gout << color(255,255,255);
                gout << move_to(x, y + (20*(i - kezdo + 1 - z))) << box(max + 10,20);
                gout << color(0,0,0);
                gout << move_to(x + 5,y + 20*(i - kezdo + 2 - z) - 5) << text(lista[i]);
            } else {

                z = 1;
            }

        }
        gout << move_to(x + max - 6, y + 30) << color(0,0,0) << text("/") <<move_to(x + max - 2, y + 30) << text("\\");
        gout << move_to(x + max - 6, y + 20 * (meret + 1) -4) << color(0,0,0) << text("\\") <<move_to(x + max - 2, y + 20 * (meret + 1) -4) << text("/");
    }

    gout << refresh;




}

