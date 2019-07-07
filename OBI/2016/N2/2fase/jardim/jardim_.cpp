#include <bits/stdc++.h>

using namespace std;

#define MAXK 45
#define ll long long
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define PI acos(-1)

struct point
{
	int x, y;
	point operator+(point p) {return {x+p.x, y+p.y};}
	point operator-(point p) {return {x-p.x, y-p.y};}
	point operator*(int d) {return {x*d, y*d};}
};

bool operator==(point a, point b) {return a.x == b.x && a.y == b.y;}

int dot(point a, point b)
{
	return a.x * b.x + a.y * b.y;
}

double sq(point a) {return a.x*a.x + a.y*a.y;}

double abs(point a) {return sqrt(sq(a));}

double angle(point a, point b)
{
	double cosTheta = dot(a,b) / (abs(a) * abs(b));
	return acos(max(-1.0, min(1.0, cosTheta)));
}

double angleAOB(point a, point o, point b)
{
	point AO = a-o;
	point BO = b-o;
	return angle(AO, BO);
}

double isAngleAOBacute(point a, point o, point b)
{
	return 2*angleAOB(a, o, b) <= PI;
}

bool collinear(point a, point b)
{
	return a.x*b.y - a.y*b.x == 0;
}

bool arePointsCollinear(vector<point> points)
{
	point o = points[0];
	point a = points[1];
	
	for (int i = 2; i < (int)points.size(); i++)
	{
		if (!collinear(a-o, points[i]-o))
		{
			return false;
		}
	}
	return true;
}

bool perp(point a, point b)
{
	return dot(a, b) == 0;
}

bool orient(point a, point b)
{
	return a.x*b.y - a.y*b.x >= 0;
}

vector<point> p;

int main()
{
	for (int i = 0; i < 7; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		p.pb({(long double)x, (long double)y});
	}
	
	point P1P2 = p[1] - p[0];
	point P1P3 = p[2] - p[0];
	point P2P3 = p[2] - p[1];
	point P4P5 = p[4] - p[3];	
	point P2P5 = p[4] - p[1];
	point P4P6 = p[5] - p[3];
	point P5P7 = p[6] - p[4];
	point P2P1 = p[0] - p[1];
	point P2P6 = p[5] - p[1];	
	
	bool res = isAngleAOBacute(p[1], p[0], p[2]) &&
			   (bool)(abs(P1P2) == abs(P1P3)) &&
			   arePointsCollinear({p[1], p[2], p[3], p[4]}) &&
			   (bool)((P2P3) + (P4P5) == P2P5*2) &&
			   (bool)(sq(P2P3) > sq(P4P5)) &&
			   (bool)(perp(P4P6, P2P3) && perp(P5P7, P2P3)) &&
			   (bool)(sq(P4P6) == sq(P5P7)) &&
			   (bool)(orient(P2P3, P2P1) != orient(P2P3, P2P6));
			   
   if (res)
   {
	   printf("S\n");
   }
   else
   {
	   printf("N\n");
   }

	
	return 0;
}
