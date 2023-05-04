#include "graphics.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "widget.h"
#include "number_widget.h"
#include "menu_widget.h"
#include "string_widget.h"
#include "sudoku_grafika.h"
#include "sudoku_game.h"
using namespace genv;
using namespace std;


const int XX=880;
const int YY=940;


bool checknumb(event ev)
{
    return ev.keycode == '1' || ev.keycode == '2' || ev.keycode == '3' || ev.keycode == '4' || ev.keycode == '5' || ev.keycode == '6' || ev.keycode == '7' || ev.keycode == '8' || ev.keycode == '9';
}

int main()
{
    gout.open(XX,YY);
    /*
    int numbers[9][9] = {
            {2 ,2,2,9,2,8,1,2,2},
            {2,8,2,7,2,3,2,2,4},
            {2,6,2,2,2,5,2,7,2},
            {2,9,2,1,2,7,2,2,2},
            {2,1,2,2,2,6,2,4,7},
            {3,2,2,2,8,2,2,9,1},
            {2,2,8,5,4,2,2,2,6},
            {2,2,6,8,3,9,7,5,2},
            {2,2,5,2,7,2,2,2,2},
    };
*/

    int numbers[9][9] = {
            {0,9,7,0,0,0,5,2,4},
            {3,0,2,0,1,0,8,0,7},
            {0,6,0,4,2,7,1,0,0},
            {0,0,0,1,3,0,0,4,9},
            {7,0,4,5,0,0,6,0,0},
            {0,1,9,7,0,0,3,0,8},
            {9,0,0,0,0,1,4,0,0},
            {8,0,0,3,4,0,2,7,0},
            {0,7,0,2,5,6,9,8,0},
    };



    sudoku_grafika grafika(0,0);
    sudoku_game szabaly(3);
    grafika.draw_field();
    grafika.draw_numbers(numbers);



    event ev;
    int evx;
    int evy;

    gin.timer(1000);
    int ido = 0;

    while(gin >> ev && ev.keycode != key_escape) {

        //grafika.kirajzol(ev);
        if (ev.type == ev_mouse && ev.button == btn_left)
        {
            grafika.focuscheck(ev.pos_x, ev.pos_y, numbers);
            grafika.draw_numbers(numbers);
            evx = ev.pos_x;
            evy = ev.pos_y;

        }

        if (ev.type == ev_key && 0 < ev.keycode)
        {
            char b = ev.keycode;
            int num = int(b) - 48;

            if (ev.keycode == key_backspace)
            {
                vector<int> focus = grafika.get_focus();
                numbers[focus[0]][focus[1]] = 0;
                grafika.draw_erase(focus[0], focus[1]);
                grafika.focuscheck(evx, evy, numbers);
                grafika.draw_numbers(numbers);
            }

            if (num < 10 && 0 < num)
            {
                vector<int> focus = grafika.get_focus();

                if (szabaly.check(numbers, focus[0], focus[1], num) == true)
                {
                    numbers[focus[0]][focus[1]] = num;
                    //grafika.draw_erase(focus[0], focus[1]);

                    grafika.draw_bar(ido);
                    grafika.focuscheck(evx, evy, numbers);
                    grafika.draw_numbers(numbers);
                } else
                {
                    if (szabaly.is_equal(numbers, focus[0], focus[1], num) == false)
                    {
                        grafika.draw_numbers(numbers);
                        grafika.draw_wrong(focus[0], focus[1], num);
                        grafika.draw_bar(ido);
                        gout << refresh;
                    }
                }
            }


        }
        if (ev.type == ev_timer)
        {
            ++ido;
            grafika.draw_bar(ido);


        }
        gout <<refresh;


    }
    return 0;
}

