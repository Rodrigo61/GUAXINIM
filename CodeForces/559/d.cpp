#include <bits/stdc++.h>
 
using namespace std;
 
#define vi vector<int>
#define ll long long
#define INF 0x3f3f3f3f
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define pii pair<int, int>
#define x first
#define y second
#define pll pair<ll, ll>
#define vll vector<ll>
#define vii vector<pii>
#define ld long double
#define all(x) x.begin(), x.end()


inline int prev(int i, int n) { return i == 0 ? n-1 : i-1; }
inline int next(int i, int n) { return i == n-1 ? 0 : i+1; }

double area(vii &poly) {
  int n = (int)poly.size();
  double area = 0;
  for (int i = 0; i < n; ++i)
    area += poly[i].x * (poly[next(i, n)].y - poly[prev(i, n)].y);
  return area;
}

int border_pts(vii &poly)
{
	int total = 0;
	for (int i = 1; i < (int)poly.size(); i++)
	{
		total += __gcd(abs(poly[i].x - poly[i - 1].x), abs(poly[i].y - poly[i - 1].y));
	}
	total += __gcd(abs(poly.front().x - poly.back().x), abs(poly.front().y - poly.back().y));
	return total;
}

int main()
{
	int n;
	scanf("%d", &n);
	vii points(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &points[i].x, &points[i].y);
	}
	
	double total_area = area(points)/2;
	int total_border_pts = border_pts(points);
	int total_interns = total_area - total_border_pts/(double)2 + 1;
	
	db(total_interns);
	double ev_remove = 0;
	for (int i = 0; i < n - 2; i++)
	{
		db(i);
		vii current_poly;
		current_poly.pb(points[i]);
		current_poly.pb(points[i + 1]);
		for (int j = 2; i + j < n && j < 60; j++)
		{
			if (i == 0 && i + j == n - 1)
				continue;
				
			current_poly.pb(points[i + j]);
			double curr_area = area(current_poly)/2;
			int curr_border_pts = border_pts(current_poly);
			int interns_on_poly = (curr_area - curr_border_pts/(double)2 + 1);
			int interns_on_line = __gcd(abs(points[i + j].x - points[i + j - 1].x),
										  abs(points[i + j].y - points[i + j - 1].y)) - 1;
			
			int interns_to_remove = interns_on_poly + interns_on_line;

			db(curr_area);
			db(curr_border_pts);
			db(interns_on_poly);
			db(interns_on_line);
			db(interns_to_remove);
			
			long double p_up = 1;
			if (n - j - 1 <= 60)
				p_up = 1/pow(2, n - j - 1);
			long double p_down = 1/pow(2, j - 1);
			
			db(p_down);
			db(p_up);
			db(interns_to_remove);
			ev_remove += 1/(ld)4 * ((p_down * (1.0 - p_up) * (ld)interns_to_remove));
			db(1/(ld)4 * ((p_down * (1.0 - p_up) * (ld)interns_to_remove)));
			ev_remove += 1/(ld)4 * ((p_up * (1.0 - p_down) * (ld)(total_interns - interns_on_poly)));
			db(1/(ld)4 * ((p_up * (1.0 - p_down) * (ld)(total_interns - interns_on_poly))));
		}
	}
	
	db(ev_remove);
	
	printf("%lf\n", total_interns - ev_remove);
	
	
}
