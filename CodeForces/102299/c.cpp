#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define a first
#define b second
#define ll long long
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pll pair<ll, ll>
#define vii vector<pii>

int main()
{
	int N, Q;
	scanf("%d%d", &N, &Q);
	multiset<ll> mset;
	map<int, ll> id2val;
	
	for (int i = 0; i < N; i++)
	{
		ll v;
		scanf("%lld", &v);
		id2val[i + 1] = v;
		mset.insert(v);
	}
	
	for (int i = 0; i < Q; i++)
	{
		char cmd;
		scanf(" %c", &cmd);
		if (cmd == '?')
		{
			int id;
			scanf("%d", &id);
			mset.erase(mset.find(id2val[id]));
			int res = 0;
			ll acu = 0;
			auto it = mset.begin();
			ll target = id2val[id];
			vll aux;
			aux.pb(target);
			while (it != mset.end())
			{
				if (acu + *it > target) break;
				aux.pb(*it);
				mset.erase(it);
				res++;
				acu += *it;
				it = mset.lower_bound(acu);
			}
			acu += target;
			++res;
			it = mset.lower_bound(acu);
			while (it != mset.end())
			{
				++res;
				acu += *it;
				aux.pb(*it);
				mset.erase(it);
				it = mset.lower_bound(acu);	
			}
			printf("%d\n", res);
			for (ll v : aux)
				mset.insert(v);
			
		}
		else if (cmd == '+')
		{
			ll val;
			int id;
			scanf("%lld%d", &val, &id);
			id2val[id] = val;
			mset.insert(val);
		}
		else
		{
			int id;
			scanf("%d", &id);
			mset.erase(mset.find(id2val[id]));
		}
		
	}
	
}
