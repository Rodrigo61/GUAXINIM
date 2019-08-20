#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>
#define EPS 0.00000000001

struct pt
{
	double x, y;
	pt(){}
	pt(double _x, double _y)
	{
		x = _x;
		y = _y;
	}
};

struct line { double a, b, c; };         

void pointsToLine(pt p1, pt p2, line &l) 
{
	if (fabs(p1.x-p2.x) < EPS)                  // vertical line is fine
		l = {1.0, 0.0, -p1.x};                           // default values
	else 
	{
		double a = -(double)(p1.y-p2.y) / (p1.x-p2.x);
		l = {a,
			 1.0,              // IMPORTANT: we fix the value of b to 1.0
			 -(double)(a*p1.x) - p1.y}; 
    }
}
  
  // returns true (+ intersection point) if two lines are intersect
pair<double, double> areIntersect(line l1, line l2) 
{
  // solve system of 2 linear algebraic equations with 2 unknowns
  double x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
  double y;
  // special case: test for vertical line to avoid division by zero
  if (fabs(l1.b) > EPS) 
	y = -(l1.a*x + l1.c);
  else                  
	y = -(l2.a*x + l2.c);
  return {x, y}; 
}


bool cross(pt O, pt A, pt B)
{
	return ((A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x)) < 0;
}

int main()
{
	vector<pt> vet(4);
	for (int i = 0; i < 4; i++)
	{
		scanf("%lf%lf", &vet[i].x, &vet[i].y);
	}
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			vector<int> others;
			for (int k = 0; k < 4; k++)
			{
				if (k != i && k != j)
					others.pb(k);
			}
			
			if (cross(vet[others[0]], vet[i], vet[j]) != cross(vet[others[1]], vet[i], vet[j]))
			{
				line l1, l2;
				pointsToLine(vet[i], vet[j], l1);
				pointsToLine(vet[others[0]], vet[others[1]], l2);
				auto res = areIntersect(l1, l2);
				printf("%lf %lf", res.fi, res.se);
				return 0;
			}
		}
	}
	
	
}
