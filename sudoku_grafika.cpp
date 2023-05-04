//
// Created by Gelegonya Gergő on 2023. 04. 26..
//
#include "graphics.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include "widget.h"
#include "sudoku_grafika.h"
using namespace std;
using namespace genv;


string time_convert(int inttime)
{
    string stringtime = "";
    int act = inttime / 60;
    if (act < 10)
    {
        stringtime += "0" + to_string(act) + ":";
    } else {
        stringtime += to_string(act) + ":";
    }
    inttime %= 60;
    if (inttime < 10)
    {
        stringtime += "0" + to_string(inttime);
    } else {
        stringtime += to_string(inttime);
    }
    return stringtime;

}


sudoku_grafika::sudoku_grafika (int _posx, int _posy) : widget(_posx, _posy) {
    focus.push_back(0);
    focus.push_back(0);

}



void sudoku_grafika::draw_bar(int ido)
{
    //for (int i = 1; i < 11; ++i)
    {
        gout << font("LiberationSans-Regular.ttf",30);
        string s = time_convert(ido);
        gout << move_to(720, 50);
        gout << color(255,255,255);
        gout << box(80, 30);

        gout << color(50,50,50);

        gout << move_to(720, 50) << text(s);

        gout << refresh;
    }
}




void sudoku_grafika::draw_erase(int i, int j)
{
    gout << color(234,234,234);
    gout << move_to((i + 1) * 80 + 1, (j + 1) * 80 + 1);
    gout << box(79,79);

}




void sudoku_grafika::draw_field ()
{
    gout << move_to(0,0) << color(255,255,255) << box(880, 940);

    for (int i = 1; i < 11; ++i)
    {
        if (i == 1 || (i - 1) % 3 == 0)
        {
            gout << color(0,0,0);
        } else gout << color(190,190,190);

        gout << move_to(80, i * 80) << line(720, 0);
        gout << move_to(i * 80, 80) << line(0,720);
        if (i < 10)
        {
            for (int j = 0; j < 9; ++j)
            {
                draw_erase( i - 1, j);
            }
        }



        gout << color(0,0,0);

    }

}
void sudoku_grafika::draw_numbers(int numbers[9][9])
{

    gout << font("LiberationSans-Regular.ttf",80);
    int num;
    string s;
    gout << color(0,0,0);
    for (int i = 1; i < 11; ++i)
    {
        if (i < 10)
        {
            for (int j = 1; j < 10; ++j)
            {
                num = numbers[i - 1][j -1];
                if (num == 0)
                {
                    s = "";
                }else
                    s = to_string(num);
                gout << move_to(i * 80 + 15, j * 80 - 5) << text(s);
            }
        }
    }
    gout << refresh;
}





void sudoku_grafika::draw_focus(int i, int j, int numbers[9][9])
{
    for (int k = 1; k < 10; ++k)
    {
        //gout << color(255,215,163);
        gout << color(220,220,220);
        gout << move_to((i + 1) * 80 + 1, k * 80 + 1);
        gout << box(79,79);
        gout << move_to((k) * 80 + 1, (j + 1) * 80 + 1);
        gout << box(79,79);
    }

    if (numbers[i][j] != 0)
    {
        for (int k = 1; k < 10; ++k)
        {
            for (int z = 1; z < 10; ++z)
            {
                if (numbers[k - 1][z - 1] == numbers[i][j])
                {
                    gout << color(200,200,200);
                    gout << move_to((k) * 80 + 1, z * 80 + 1);
                    gout << box(79,79);
                }
            }
        }
    }


    gout << move_to(( i + 1) * 80 + 1, (j + 1) * 80 + 1);
    gout << color(178,244,255);
    gout << box(79,79);
    //draw_numbers();
}







void sudoku_grafika::draw_wrong(int i, int j, int szam)
{
    draw_erase(i, j);
    gout << color(193,0,0);
    string s = to_string(szam);
    gout << move_to((i + 1) * 80 + 15, (j + 1) * 80 - 5) << text(s);
}
void sudoku_grafika::focuscheck(int evx, int evy, int numbers[9][9])
{

    if (abs (evx - 360 - 80) < 360 && abs(evy - 360 - 80) < 360)
    {
        for (int i = 1; i < 10; ++i)
        {
            for (int j = 1; j < 10; ++j)
            {
                if (abs(evx - i * 80 - 40) <  40 && (abs(evy - j * 80 - 40)) < 40)
                {
                    draw_field();
                    draw_focus(i - 1, j - 1, numbers);
                    focus[0] = i - 1;
                    focus[1] = j - 1;
                }
            }
        }
    }
}

vector<int> sudoku_grafika::get_focus ()
{
    return focus;
}



void sudoku_grafika::kirajzol(event ev)
{
    if (ev.type == ev_mouse)
    {
        evx = ev.pos_x;
        evy = ev.pos_y;
    }



    //draw_field();
    //draw_numbers();


    //draw_focus(3,3);
    //draw_wrong(3,3, 0);
   // focuscheck(evx, evy);
    gout << refresh;
}



