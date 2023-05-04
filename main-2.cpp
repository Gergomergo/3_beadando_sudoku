#include "graphics.hpp"
#include <fstream>
#include <vector>
#include <cmath>

using namespace genv;
using namespace std;

int xx = 1600;
int yy = 1000;
bool alive = true;
int score = 0;

struct pont
{
    int x;
    int y;
    int r;
    int g;
    int b;
};

pont olvas(ifstream& f)
{
    pont p;
    char kuka;
    string nagykuka;
    f>>p.x>>kuka>>p.y>>kuka>>kuka>>p.r>>kuka>>p.g>>kuka>>p.b;
    getline(f, nagykuka);

    return p;
}

struct kezdokepernyo
{
    private:
    vector<vector<int>> v;
    vector<vector<int>> szinek;
    int mx = xx/2;
    int my = yy/2;

    public:
    void kezdokepernyobeolv()
    {
        pont p;
        ifstream f;
        f.open("start1szerk.txt");
        p = olvas(f);
        while(f.good())
        {
            vector<int> w;
            w.push_back(p.x);
            w.push_back(p.y);
            v.push_back(w);

            vector<int> rgb;
            rgb.push_back(p.r);
            rgb.push_back(p.g);
            rgb.push_back(p.b);
            szinek.push_back(rgb);
            p = olvas(f);
        }
        f.close();
    }

    void kezdokepernyotombol()
    {
        for(double i=0; i<v.size(); i++)
        {
            gout<<move_to((mx-380/2)+v[i][0],(my-80/2)+v[i][1])<<color(szinek[i][0],szinek[i][1],szinek[i][2])<<box(1,1);
        }
    }

};

struct halalkepernyo
{
    private:
    vector<vector<int>> v;
    vector<vector<int>> szinek;
    int mx = xx/2;
    int my = yy/2;

    public:
    void halalkepernyobeolv()
    {
        pont p;
        ifstream f;
        f.open("GAME_OVER1szerk.txt");
        p = olvas(f);
        while(f.good())
        {
            vector<int> w;
            w.push_back(p.x);
            w.push_back(p.y);
            v.push_back(w);

            vector<int> rgb;
            rgb.push_back(p.r);
            rgb.push_back(p.g);
            rgb.push_back(p.b);
            szinek.push_back(rgb);
            p = olvas(f);
        }
        f.close();
    }

    void halalkepernyotombol()
    {
        for(double i=0; i<v.size(); i++)
        {
            gout<<move_to((mx-981/2)+v[i][0],(my-(yy/4))+v[i][1])<<color(szinek[i][0],szinek[i][1],szinek[i][2])<<box(1,1);
        }
    }

};

struct kurzor
{
    private:

    vector<vector<int>> v;
    vector<vector<int>> szinek;

    public:
    void kurzorbeolv()
    {
        pont p;
        ifstream f;
        f.open("kurzor1szerk.txt");
        p = olvas(f);
        while(f.good())
        {
            vector<int> w;
            w.push_back(p.x);
            w.push_back(p.y);
            v.push_back(w);

            vector<int> rgb;
            rgb.push_back(p.r);
            rgb.push_back(p.g);
            rgb.push_back(p.b);
            szinek.push_back(rgb);
            p = olvas(f);
        }
        f.close();
    }

    void kurzortombol(event ev)
    {
        for(double i=0; i<v.size(); i++)
        {
            gout<<move_to((ev.pos_x-25)+v[i][0],(ev.pos_y-25)+v[i][1])<<color(szinek[i][0],szinek[i][1],szinek[i][2])<<box(1,1);
        }
    }
};

struct repulo
{
    private:

    vector<vector<int>> v;
    vector<vector<int>> szinek;

    public:
    void enrepulombeolv()
    {
        pont p;
        ifstream f;
        f.open("repuloszerk1.txt");
        p = olvas(f);
        while(f.good())
        {
            vector<int> w;
            w.push_back(p.x);
            w.push_back(p.y);
            v.push_back(w);

            vector<int> rgb;
            rgb.push_back(p.r);
            rgb.push_back(p.g);
            rgb.push_back(p.b);
            szinek.push_back(rgb);
            p = olvas(f);
        }
        f.close();
    }

    void enrepulomtombol(int mx)
    {
        for(double i=0; i<v.size(); i++)
        {
            gout<<move_to((mx-100)+v[i][0],(yy-150)+v[i][1])<<color(szinek[i][0],szinek[i][1],szinek[i][2])<<box(1,1);
        }
    }
};

struct bumm
{
    private:

    vector<vector<int>> v;
    vector<vector<int>> szinek;

    public:
    void bummbeolv()
    {
        pont p;
        ifstream f;
        f.open("robbanas1szerk.txt");
        p = olvas(f);
        while(f.good())
        {
            vector<int> w;
            w.push_back(p.x);
            w.push_back(p.y);
            v.push_back(w);

            vector<int> rgb;
            rgb.push_back(p.r);
            rgb.push_back(p.g);
            rgb.push_back(p.b);
            szinek.push_back(rgb);
            p = olvas(f);
        }
        f.close();
    }

    void bummtombol(int x, int y)
    {
        for(double i=0; i<v.size(); i++)
        {
            gout<<move_to(x+v[i][0],y+v[i][1])<<color(szinek[i][0],szinek[i][1],szinek[i][2])<<box(1,1);
        }
    }
};

struct csillagok
{
    private:
    vector<int> csillagkoordx;
    vector<int> csillagkoordy;
    int csillagszam = 200;

    public:
    csillagok()
    {
        csillagkoordx = csillagkoordxytolto();
        csillagkoordy = csillagkoordxytolto();
    }
    vector<int> csillagkoordxytolto()
    {
        vector<int> v;
        int xy;
        for(int i=0; i<csillagszam; i++)
        {
            xy = rand()%xx;
            v.push_back(xy);
        }
        return v;
    }

    void csillagmozgas()
    {
        for(double i=0; i<csillagkoordx.size(); i++)
        {
            gout<<move_to(csillagkoordx[i],csillagkoordy[i])<<color(255,255,0)<<box(4,4);
            csillagkoordy[i]+=15;
            if(csillagkoordy[i] >= yy)
            {
                csillagkoordy[i] = rand()%(yy/2);
            }
        }
    }
};

struct enemyk
{
    vector<vector<int>> v;
    vector<vector<int>> szinek;
    vector<int> enemykoordx;
    vector<int> enemykoordy;
    int enemyszam = 2;
    int randx = rand()%xx;
    halalkepernyo h;

    public:
    enemyk()
    {
        enemykoordx = enemykoordxtolto();
        enemykoordy = enemykoordytolto();
    }

    vector<int> enemykoordxtolto()
    {
        vector<int> v;
        int x;
        for(int i=0; i<enemyszam; i++)
        {
            x = rand()%xx;
            v.push_back(x);
        }
        return v;
    }

    vector<int> enemykoordytolto()
    {
        vector<int> v;
        int y;
        for(int i=0; i<enemyszam; i++)
        {
            y = 0;
            v.push_back(y);
        }
        return v;
    }

    void enemybeolv()
    {
        pont p;
        ifstream f;
        f.open("ufo1szerk.txt");
        p = olvas(f);
        while(f.good())
        {
            vector<int> w;
            w.push_back(p.x);
            w.push_back(p.y);
            v.push_back(w);

            vector<int> rgb;
            rgb.push_back(p.r);
            rgb.push_back(p.g);
            rgb.push_back(p.b);
            szinek.push_back(rgb);
            p = olvas(f);
        }
        f.close();
    }

    void enemymozgastombol(event ev)
    {

        for(double j=0; j<enemykoordx.size(); j++)
        {
            if(enemykoordx[j]<=xx-200)
            {
                for(double i=0; i<v.size(); i++)
                {
                   gout<<move_to(enemykoordx[j]+v[i][0],enemykoordy[j]+v[i][1])<<color(szinek[i][0],szinek[i][1],szinek[i][2])<<box(1,1);
                }
            }
            //if((enemykoordx[j]>=ev.pos_x-300 && enemykoordy[j]>=yy-300) ||  (enemykoordx[j]<=ev.pos_x+100 && enemykoordy[j]>=yy-300))   //sajnos egyik feltetel sem jo. Az elso a szuksegesnel tobb, latszatra ranom esetekre is igaz,  a masik meg majnem semmire.
            //if(enemykoordx[j] >= ev.pos_x-100-200 && enemykoordx[j] <=ev.pos_x+100 && enemykoordy[j] >= yy-150)
            gout << color(255,0,0) << move_to(enemykoordx[j], enemykoordy[j]) << box(5,5);
            gout << color(255,255,0) << move_to(ev.pos_x, yy-160) << box(5,5);


            if (abs(enemykoordx[j] - ev.pos_x-150) < 300 && abs(enemykoordy[j]) < yy-300)
            {
                alive = false;
                enemykoordy[j]=0;
                enemykoordx[j]=rand()%xx;
                break;
            }
            else
            {
                if(enemykoordy[j]>=yy)
                {
                    score-=10;
                    enemykoordy[j] = 0;
                    enemykoordx[j] = rand()%xx;
                }
            }
            enemykoordy[j]+=15;
            if(alive == false)
                break;
        }
    }

    void loves(int mx, bumm b)
    {

        for(double i=0; i<enemykoordx.size(); i++)
        {
            if(mx+2>enemykoordx[i] && mx-2<enemykoordx[i]+200)
            {
                gout<<move_to(mx-2,yy-150)<<color(0,255,0)<<line_to(mx-2,enemykoordy[i]+150);
                gout<<move_to(mx-1,yy-150)<<color(0,255,0)<<line_to(mx-1,enemykoordy[i]+150);
                gout<<move_to(mx,yy-150)<<color(0,255,0)<<line_to(mx,enemykoordy[i]+150);
                gout<<move_to(mx+1,yy-150)<<color(0,255,0)<<line_to(mx+1,enemykoordy[i]+150);
                gout<<move_to(mx+2,yy-150)<<color(0,255,0)<<line_to(mx+2,enemykoordy[i]+150);
                b.bummtombol(enemykoordx[i],enemykoordy[i]);

                score+=1;
                enemykoordx[i]=rand()%xx;
                enemykoordy[i]=0;
            }
            else
            {
                gout<<move_to(mx-2,yy-150)<<color(0,255,0)<<line_to(mx-2,0);
                gout<<move_to(mx-1,yy-150)<<color(0,255,0)<<line_to(mx-1,0);
                gout<<move_to(mx,yy-150)<<color(0,255,0)<<line_to(mx,0);
                gout<<move_to(mx+1,yy-150)<<color(0,255,0)<<line_to(mx+1,0);
                gout<<move_to(mx+2,yy-150)<<color(0,255,0)<<line_to(mx+2,0);
            }
        }
        gout<<refresh;
    }

};

int main()
{
    gout.open(xx,yy,true);
    gout<<move_to(0,0)<<color(32,0,128)<<box(xx,yy);
    kurzor ku;
    ku.kurzorbeolv();
    csillagok cs;
    enemyk e;
    e.enemybeolv();
    repulo r;
    r.enrepulombeolv();
    bumm b;
    b.bummbeolv();
    kezdokepernyo k;
    k.kezdokepernyobeolv();
    halalkepernyo h;
    h.halalkepernyobeolv();
    event ev;
    int mx = xx/2-100;
    gin.timer(40);
    while(gin>>ev && ev.keycode != key_escape)
    {
        if(ev.type == ev_timer)
        {
            gout<<move_to(0,0)<<color(32,0,128)<<box(xx,yy);
            cs.csillagmozgas();
            if(alive == false)
                h.halalkepernyotombol();
            k.kezdokepernyotombol();
            gout<<refresh;
        }
        /*                          Ez itt még nem az igazi
        if(ev.type == ev_mouse)
        {
            ku.kurzortombol(ev);
            gout<<refresh;
        }
        */

        if(ev.pos_x>=xx/2-380/2 && ev.pos_x <=xx/2+380/2 && ev.pos_y>=yy/2-80/2  && ev.pos_y<=yy/2+80/2 &&  ev.button == btn_left)
        {
            alive = true;
            while(gin>>ev && ev.keycode != key_escape && alive == true)
            {
                gout.showmouse(false);
                if (ev.pos_x > 100 && ev.pos_x < xx-100)
                    mx = ev.pos_x;

                if(ev.button == btn_left)
                {
                    gin.timer(100);
                    e.loves(mx, b);
                    gin.timer(40);
                }

                if (ev.type == ev_timer)
                {
                    gout<<move_to(0,0)<<color(32,0,128)<<box(xx,yy);
                    cs.csillagmozgas();
                    e.enemymozgastombol(ev);
                    r.enrepulomtombol(mx);
                    gout<<refresh;
                }
            }
            e.enemykoordy = e.enemykoordytolto();
        }
        gout.showmouse(true);
    }
    return 0;
}
