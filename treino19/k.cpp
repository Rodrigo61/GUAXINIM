#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

#define EPS 1e-9

struct point{
	long double x, y;
	point (){
	}
	
	point(long double _x, long double _y):
	x(_x), y(_y)
	{
	} 
};

struct event{
	long double ang;
	int in, out;
	
	event()
	{
			
	}
	
	event(long double _ang, int _in, int _out):
	ang(_ang), in(_in), out(_out)
	{
			
	}
	
	bool operator < (event other){
		return ang < other.ang;
	}
	
	void operator += (event other){
		in += other.in;
		out += other.out;
	}
};

event entra(point p, long double d){
	event e;
	long double a = atan2(p.y, p.x);
	if(a < EPS)
		a += 2*acos(-1);
	
	if(d*d + EPS> p.x*p.x + p.y*p.y){
		e = event(fmod(a - asin(1) + 2*acos(-1), 2*acos(-1)), 1, 0);
	}
	else{
		long double b = atan2(sqrt(p.x*p.x + p.y*p.y - d*d), d);
	if(b < EPS)
		b += 2*acos(-1);
		e = event(fmod((a + b - asin(1) + 2*acos(-1)),2*acos(-1)), 1, 0);
}
	return e;
}

event sai(point p, long double d){
	event e;
	long double a = atan2(p.y, p.x);
	if(a < EPS)
		a += 2*acos(-1);
	
	
	if(d*d + EPS > p.x*p.x + p.y*p.y){
		e = event(fmod(a + asin(1) + 2*acos(-1), 2*acos(-1)), 0, 1);
	}
	else{
		long double b = atan2(sqrt(p.x*p.x + p.y*p.y - d*d), d);
		if(b < EPS)
		b += 2*acos(-1);
		e = event(fmod((a - b + asin(1) + 2*acos(-1)),2*acos(-1)), 0, 1);
	}
	return e;
}

int main(){
	int T;
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	cin >> T;
	while(T--){
		int n, m;
		long double z;
		cin >> n >> m >> z;
		point p;
		vector<event> s, sfinal;
		
		int current = 0;
		
		for(int i = 0; i < n; i++){
			cin >> p.x >> p.y;
			
			if(p.x >= -EPS && fabs(p.y) <= z/2 + EPS){
				current++;
			}
			
			// 0 < ang <= 2pi	
			p = point(p.x, p.y);
			event e = entra(p, z/2); 
			s.push_back(e);
			e = sai(p, z/2); 
			s.push_back(e);
		}
		
		sort(s.begin(), s.end());
		
		//for(int i = 0; i < s.size(); i++)
		//	printf("%d: %lf\n", s[i].in, s[i].ang);
		
		for(int i = 0; i < s.size(); i++){
			if(sfinal.size() == 0 || fabs(sfinal[sfinal.size() - 1].ang - s[i].ang) > EPS)
				sfinal.push_back(s[i]);
			else if(sfinal.size() != 0)	
				sfinal[sfinal.size() - 1] += s[i]; 
		}
		
		//for(int i = 0; i < s.size(); i++)
			//printf("%d: %lf\n", sfinal[i].in, sfinal[i].ang);
		
		int mx = current;
		
		for(int i = 0; i < sfinal.size(); i++){
			//printf("val = %d\n", current);
			//printf("%(%d %d)%lf\n", sfinal[i].in, sfinal[i].out, sfinal[i].ang);
			current += sfinal[i].in;
			if(mx < current)
				mx = current;
			current -= sfinal[i].out;
		}
		
		if(mx >= m)
			printf("Yes\n");
			
		else
			printf("No\n");
		
	}
	return 0;
}
