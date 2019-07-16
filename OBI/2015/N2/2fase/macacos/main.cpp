#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define db(x) cerr << #x << " = " << x << endl
#define ll long long

struct pt
{
	ll x, y;
	pt(ll _x, ll _y)
	{
		x = _x;
		y = _y;
	};
	
	bool operator<(const pt &o)
	{
		return x < o.x || (x == o.x && y < o.y);
	}
	
	pt operator-(const pt &o)
	{
		return {x - o.x, y - o.y};
	}
};

int N;
vector<pt> vet_pt;

ll cross(pt l1, pt l2, pt t)
{
	pt l = l1 - l2;
	pt r = t - l1;
	return l.x*r.y - l.y*r.x;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		vet_pt.pb({x, y});
	}
	sort(all(vet_pt));
	
	vector<pt> res;
	for (int i = 0; i < N; i++)
	{
		while ((int)res.size() >= 2 && 
			   cross(res[(int)res.size() - 1], 
					 res[(int)res.size() - 2], 
					 vet_pt[i]) >= 0)
		{
			res.pop_back();
		}
		res.push_back(vet_pt[i]);
	}
	
	printf("%d\n", (int)res.size() - 1);
}
