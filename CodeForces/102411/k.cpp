#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

struct child{
    char c;
    int x, y, mxX, mnX;

    child(){}

    child(char c, int x, int y):
        c(c), x(x), y(y){}
    
    bool inside(int n, int s, int e, int w){
        return y >= n && y <= s && x >= w && x <= e;
    }
};

char mapa[1123][1123];
vector<child> v;
child A;
int nc, mc;


void fill(){
    for(auto &el : v){
        int x = el.x, y = el.y;
        while(x + 1 < mc && mapa[y][x + 1] == '.'){
            x++;
            mapa[y][x] = (char)((el.c - 'A') + 'a');
        }
        el.mxX = x;
    }

    for(auto &el : v){
        int x = el.x, y = el.y;
        while(x > 0 && mapa[y][x - 1] == '.'){
            x--;
            mapa[y][x] = (char)((el.c - 'A') + 'a');
        }
        el.mnX = x;
    }

    for(auto el : v){
        int x1 = el.mnX, x2 = el.mxX;
        int y = el.y;
        while(y + 1 < nc){
            bool pos = 1;
            for(int i = x1; i <= x2; i++)
                if(mapa[y + 1][i] != '.'){
                    pos = 0;
                    break;
                }
            if(!pos)
                break;
            y++;
            for(int i = x1; i <= x2; i++)
                mapa[y][i] = (char)((el.c - 'A') + 'a');
        }
    }

    for(auto el : v){
        int x1 = el.mnX, x2 = el.mxX;
        int y = el.y;
        while(y > 0){
            bool pos = 1;
            for(int i = x1; i <= x2; i++)
                if(mapa[y - 1][i] != '.'){
                    pos = 0;
                    break;
                }
            if(!pos)
                break;
            y--;
            for(int i = x1; i <= x2; i++)
                mapa[y][i] = (char)((el.c - 'A') + 'a');
        }
    }
}

int main(){
    
    A.c = 'A';

    scanf("%d %d", &nc, &mc);

    for(int i = 0; i < nc; i++)
        for(int j = 0; j < mc; j++){
            scanf(" %c", &mapa[i][j]);
            if(mapa[i][j] != '.'){
                if(mapa[i][j] == 'A'){
                    A.x = j;
                    A.y = i;
                }

                else
                    v.push_back(child(mapa[i][j], j, i));  
            }
        }

    int s, n, w, e;
    int S = A.y, N = A.y, W = A.x, E = A.x;

    int mx = 1;

    for(int i = 0; i <= (int)v.size(); i++){
        if(i < (int)v.size())
            s = v[i].y - 1;
        else
            s = nc - 1;
        
        for(int j = 0; j <= (int)v.size(); j++){
            if(j < (int)v.size())
                n = v[j].y + 1;
            else
                n = 0;

            if(n > s)
                continue;

            for(int k = 0; k <= (int)v.size(); k++){
                if(k < (int)v.size())
                    e = v[k].x - 1;
                else
                    e = mc - 1;

                for(int l = 0; l <= (int)v.size(); l++){
                    if(l < (int)v.size())
                        w = v[l].x + 1;
                    else
                        w = 0;
                    
                    if(w > e)
                        continue;
                    
                    if(!A.inside(n, s, e, w))
                        continue;
                    
                    bool pos = 1;
                    for(auto el : v)
                        if(el.inside(n, s, e, w)){
                            pos = 0;
                            break;
                        }
                    
                    if(!pos)
                        continue;

                    if(mx < (s - n + 1)*(e - w + 1)){
                        mx = (s - n + 1)*(e - w + 1);
                        N = n; S = s; W = w; E = e;
                    }
                }
            }
        }
    }

    //cerr << "ok" << endl;

    for(int i = N; i <= S; i++)
        for(int j = W; j <= E; j++)
            if(mapa[i][j] == '.')
                mapa[i][j] = 'a';
    
    fill();

    for(int i = 0; i < nc; i++){
        for(int j = 0; j < mc; j++)
            printf("%c", mapa[i][j]);
        printf("\n");
    }

    for(int i = 0; i < nc; i++){
        for(int j = 0; j < mc; j++)
            assert(mapa[i][j] != '.');
    }

}