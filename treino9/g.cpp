#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second
#define dbg(x) cerr << #x << " == " << x << endl;	
#define MAXN 101

typedef long long ll;
typedef pair<ll, ll> pii;
ll N;

ll dot(pair<pii,pii> a, pair<pii,pii> b){
	ll ax = a.F.F - a.S.F;
	ll ay = a.F.S - a.S.S;
	
	ll bx = b.F.F - b.S.F;
	ll by = b.F.S - b.S.S;
	
	cout << ax << " " << ay << " " << bx << " " << by << " "<<endl;
	
	return ax*bx + ay*by;  
}


bool intersection(pair<pii,pii> a, pair<pii,pii> b, pair<pii,pii> &novo){
	
	if(a.F > a.S)
		swap(a.F, a.S);
	if(b.F > b.S)
		swap(b.F, b.S);
	
	cout << "(" << a.F.F<<"," << a.F.S << ") " << "(" << b.F.F<<"," << b.F.S << ") " << endl;
	
	if(dot(a, b) == 0){
		if(a.S.S < a.F.S)
			swap(a, b);
		if(b.S.S > b.F.S)
			swap(a, b);
		
		ll k = (b.F.F + b.F.S - (a.F.F + a.F.S));
		cout << "K " << k << endl;
		if(abs(k)%2 == 1)
			return 0;
		if(abs(a.F.F - a.S.F) < k || abs(b.F.F - b.S.F) < a.F.F + k - b.F.F)
			return 0;
		novo.F.F = novo.S.F = a.F.F + k;
		novo.F.S = novo.S.S = a.S.F + k;
		return 1;
	}
	cout << "dot != 0 " << dot(a, b) << endl;
	pii p1 = max(a.F, b.F);
	pii p2 = min(a.S, b.S);
	
	if(p1 > p2)
		return 0;
	novo = {p1, p2};
	return 1;
}

int main()
{
	
	cin >> N;
	ll x, y, d;
	vector<pair<pii, pii> >ini, b;

	scanf("%lld %lld %lld", &x, &y, &d);
	ini.pb({{x - d, y}, {x - 1, y + d - 1}});
	ini.pb({{x, y + d}, {x + d - 1, y + 1}});
	ini.pb({{x + d, y}, {x + 1, y - d + 1}});
	ini.pb({{x, y - d}, {x - d + 1, y - 1}});
	
	for(ll i = 1; i < (ll)N; i++){
		scanf("%lld %lld %lld", &x, &y, &d);
		b.pb({{x - d, y}, {x - 1, y + d - 1}});
		b.pb({{x, y + d}, {x + d - 1, y + 1}});
		b.pb({{x + d, y}, {x + 1, y - d + 1}});
		b.pb({{x, y - d}, {x - d + 1, y - 1}});
	}
	
	//cout << "aqui" << endl;
	
	pair<pii, pii> novo, aux;
	
	
	ll lado_ok;
	bool ok[8] = {1, 1, 1, 1, 1, 1, 1, 1};
	for(ll i = 0; i < (ll)ini.size(); i++){
		lado_ok = 1;
		dbg(i);
		for(ll j = 0; j < (ll)b.size() && lado_ok; j += 4){
			dbg(j);
			ll pel = 0;
			for(ll k = j; k < j + 4; k++){
				dbg(k);
				cout << intersection(ini[i], b[k], novo) << endl;
				if(intersection(ini[i], b[k], novo)){
					if(pel == 0){
						pel = 1;
						aux = novo;
					}
					else{
						//ini.pb(novo);
					}
				}
			}
			if(pel == 0){
				lado_ok = 0;
				ok[i] = 0;
			}
			else
				ini[i] = aux;
		}
	}
	
	ll tot = 0;
	for(ll i = 0; i < (ll)ini.size(); i++)
		tot += (int)ok[i];
		
	if(tot == 0)
		printf("impossible\n");
	else if(tot > 1){
		printf("uncertain\n");
	}
	else{
		for(ll i = 0; i < (ll)ini.size(); i++){
			if(ok[i] == 1){
				if(ini[i].F != ini[i].S){
					printf("uncertain\n");
				}
				
				else
					printf("%lld %lld\n", ini[i].F.F, ini[i].F.S);
			}
		}
	}
	return 0;
}
