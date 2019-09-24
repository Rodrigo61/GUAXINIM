#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int const N = 100000;
ll const inf = 2e18;
int n;

struct S{
	int fr;
	ll a, b, mn;
	S(){}
	S(int _a, ll _b):fr(1), a(_a), b(_b), mn(_a + _b) {}
	S operator +(S const &o){
		S an;
		an.fr = fr + o.fr;
		an.a = a + o.a;
		an.mn = min(mn, o.mn + a);
		return an;
	}
}s[N << 2];

void st(int i, int a1, ll b1, int l = 1, int r = n, int id = 1){
	if (l == r)return void(s[id] = S(a1, b1));
	int m = l + r >> 1, a = id << 1, b = a | 1;
	if (i <= m)st(i, a1, b1, l, m, a);
	else st(i, a1, b1, m + 1, r, b);
	s[id] = s[a] + s[b];
}

void kl(ll x, ll sm = 0, int l = 1, int r = n, int id = 1){
	if (l == r){
		if(sm + s[id].mn >= x)return;
		s[id].fr = 0;
		s[id].a = 0;
		s[id].b = inf;
		s[id].mn = inf;
		return;
	}
	int m = l + r >> 1, a = id << 1, b = a | 1;
	if (s[b].mn + sm + s[a].a < x)kl(x, sm + s[a].a, m + 1, r, b);
	if (s[a].mn + sm < x)kl(x, sm, l, m, a);
	s[id] = s[a] + s[b];
}

int bs(ll x, ll sm = 0, int l = 1, int r = n, int id = 1){
	if (l == r)return x >= sm + s[id].a ? s[id].fr : 0;
	int m = l + r >> 1, a = id << 1, b = a | 1;
	if (s[a].a + sm > x)return bs(x, sm, l, m, a);
	else return s[a].fr + bs(x, sm + s[a].a, m + 1, r, b);
}

int dead(ll x){
	int fr = s[1].fr;
	kl(x);
	return fr - s[1].fr;
}

int hungry(ll x) { return s[1].fr - bs(x); }

int main(){
	scanf("%d", &n);
	f(i, 1, n + 1){
		int a;
		ll b;
		scanf("%d%lld", &a, &b);
		st(i, a, b);
	}
	int q;
	scanf("%d", &q);
	while (q--){
		int o;
		scanf("%d", &o);
		if (o == 1){
			ll x;
			scanf("%lld", &x);
			int b = hungry(x), a = dead(x);
			printf("%d %d\n", a, b);
		}else {
			int a, c;
			ll b;
			scanf("%d%lld%d", &a, &b, &c);
			st(c, a, b);
		}
	}
}
