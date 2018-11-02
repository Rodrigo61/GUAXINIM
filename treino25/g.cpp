#include<bits/stdc++.h>

using namespace std;

#define PI acos(-1)

typedef long long ll;

int main(){
	double a, t;
	ll d;
	int n, x;
	scanf("%d %d", &n, &x);
	
	double ans = 0.0;
	
	scanf("%lf %lf %lld", &a, &t, &d);
	
	ans += (a/360.0)*t*floor(x/t);
	
	double res = x - t*floor(x/t);
	
	
	a *= PI/180.0;
	
	//printf("ans = %lf f = %lf\n",ans, res*360.0/t);
	
	for(int i = 0; i < n; i++){
		ll x, y;
		scanf("%lld %lld", &x, &y);
		if(x*x + y*y > d*d)
			printf("0.00000000\n");
		else{
			double ang = atan2(y, x);
			double ent = 0.0;
			double sai = (ang + a/2)*t/(2*PI);
			
			//printf("sai = %lf\n", sai*360/(2*PI));
			if(a < 2*ang){
				ent = (ang - a/2)*t/(2*PI);
				printf("%.8lf\n", ans + max(0.0, min(sai, res) - ent)); 
			}
			
			else{
				double result = min(sai, res);
				ent = (2*PI - (a/2 - ang))*t/(2*PI);
				result += max(0.0, res - ent);
				printf("%.8lf\n", ans + result);
			}
		}
	}
	
	
}
