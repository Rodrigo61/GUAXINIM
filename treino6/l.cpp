#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define F first
#define S second

struct question{
	ll val;
	long double prob;
	bool safe;
	question(ll v,long double p,bool s){
		val = v;
		prob = p;
		safe = s;
	}
	question(){
		val = 0;
		prob = 0;
		safe = 0;
	}
	question(ll v){
		val = v;
		prob = 0;
		safe = 1;
	}
};

int main(){
	ll n, f;
	cin >> n >> f;
	long double w = f;
	vector<question> v, vs;
	char s[100];
	long double p;
	ll x;
	vs.push_back(0);
	
	for(int i = 0; i < n; i++){
		scanf(" %s %Lf %lld", s, &p, &x);
		v.push_back(question(x, p, strcmp(s, "safe") == 0));
		if(strcmp(s, "safe") == 0)
			vs.push_back(question(x));
	}
	
	int j = 0;
	
	long double mx = -1;
	
	int ind = -1;
	
	long double prob = 1;
	
	long double happy_value = 0;
	
	for(int i = 0 ; i < n; i++){
		//cout << happy_value + prob*(v[i].prob*log(1 + v[i].val/w) + (1 - v[i].prob)*log(1 + vs[j].val/w)) << endl;
		if(happy_value + prob*(v[i].prob*log(1 + v[i].val/w) + (1 - v[i].prob)*log(1 + vs[j].val/w)) > mx){
			mx = happy_value + prob*(v[i].prob*log(1 + v[i].val/w) + (1 - v[i].prob)*log(1 + vs[j].val/w));
			ind = i;
		}
		happy_value += prob*(1 - v[i].prob)*log(1 + vs[j].val/w);
		vs[j].prob += prob*(1 - v[i].prob);
		prob *= v[i].prob;
		if(v[i].safe){
			j++;
		}
	}
	
	long double d = 0;
	long long last_safe  = 0;
	p = 1;
	
	//cout << "mx = " << mx << "ind = " <<  ind << endl;
	
	/*for(int i = 0; i <= ind; i++){
		d += (1 - v[i].prob)*p*last_safe;
		if(i == ind)
			d += v[i].prob*p*v[i].val;
		if(v[i].safe){
			last_safe = v[i].val;
		}
		p *= v[i].prob;
	}*/
	
	//cout << mx << endl;
	
	d = w*(exp(mx) - 1);
	
	cout << setprecision(2) << fixed;
	cout << "$" << d << endl;
}
