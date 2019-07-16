#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define db(x) //cerr << #x << " = " << x << endl;

struct pt
{
    int x, y;
    pt(){}
    pt(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    
    bool operator<(const pt &b) const
    {
        if (x != b.x)
        {
            return x < b.x;
        }
        return y < b.y;
    }
    
    pt operator-(const pt &b)
    {
        return {x - b.x, y - b.y};
    }
};

int N;
vector<pt> vet_pt;

int cross(pt last1, pt last2, pt target)
{
    pt last = last1 - last2;
    pt ltarget = target - last1;
    return ltarget.x * last.y - ltarget.y * last.x;
}

int main()
{
    while (scanf("%d", &N), N)
    {
        vet_pt.clear();
        set<pt> in;
        for (int i = 0; i < N; i++)
        {
            int y, x;
            scanf("%d%d", &x, &y);
            in.insert(pt(x, y));
        }
        vet_pt.assign(all(in));
        
        if (vet_pt.size() == 1)
		{
			printf("1\n%d %d\n", vet_pt[0].x, vet_pt[0].y);
			continue;
		}

        pt A = vet_pt[0];
        pt B = vet_pt.back();
        vector<pt> up_hull, down_hull;
        up_hull.pb(A);
        down_hull.pb(A);
        
        for (int i = 1; i < (int)vet_pt.size(); i++)
        {
            if (i == (int)vet_pt.size() - 1 || cross(A, B, vet_pt[i]) > 0)
            {
                while ((int)up_hull.size() >= 2 && 
                        cross(up_hull[(int)up_hull.size() - 1], 
                              up_hull[(int)up_hull.size() - 2],
                              vet_pt[i]) <= 0)
                {
                    up_hull.pop_back();
                }
                up_hull.pb(vet_pt[i]);
            }
            // Perceba que aqui não uso simplesmente um else, pois o B tem
            // que ser avaliado tanto para baixo quanto para cima
            if (i == (int)vet_pt.size() - 1 || cross(A, B, vet_pt[i]) < 0)
            {
                while ((int)down_hull.size() >= 2 && 
                        cross(down_hull[(int)down_hull.size() - 1], 
                             down_hull[(int)down_hull.size() - 2],
                             vet_pt[i]) >= 0)
                {
                    down_hull.pop_back();
                }
                down_hull.pb(vet_pt[i]);
            }
        }
        
        // Removo os pontos A e B repetidos embaixo
        down_hull.erase(down_hull.begin());
        down_hull.pop_back();
        reverse(all(down_hull));

        vector<pt> res;
        for (pt p : up_hull)
        {
            res.pb(p);
        }
        for (pt p : down_hull)
        {
            res.pb(p);
        }
        
        reverse(all(res));
        printf("%d\n", (int)(res.size()));
        for (auto p : res)
            printf("%d %d\n", p.x, p.y);
        
    }
    
}
