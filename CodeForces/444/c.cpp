#include <bits/stdc++.h>

using namespace std;

#define db(x) //cerr << #x << " = " << x << endl;
#define MAXN 112345
#define ll long long
#define ini first
#define fim second.first
#define val second.second
#define int long long

int N, M;
set<pair<int, pair<int, int>>> interval_clusters;
ll BIT[MAXN], BIT2[MAXN];

void update(int x, ll v)
{
	for (; x <= N; x += x&(-x))
		BIT[x] += v;
}

void update2(int x, ll v)
{
	for (; x <= N; x += x&(-x))
		BIT2[x] += v;
}	 

ll query(int x)
{ 	
	ll sum = 0;
	for(; x > 0; x -= x&(-x))
    	sum += BIT[x];
	return sum;
}

ll query2(int x)
{ 	
	ll sum = 0;
	for(; x > 0; x -= x&(-x))
    	sum += BIT2[x];
	return sum;
}

void update_range(int l, int r, int v)
{
	if (l == 0 || r > N)
	{
		return;
	}
	update(l, v);
	update(r + 1, -v);
	update2(l, v * (l-1));
	update2(r + 1, -v * r);
}

ll value_range(int l, int r)
{
	if (l == 0 || r > N)
	{
		return 0;
	}
	return query(r) * r - query2(r) - query(l-1) * (l-1) + query2(l-1);
}

signed main()
{
	scanf("%lld%lld", &N, &M);
	
	for (int i = 1; i <= N; i++)
	{
		interval_clusters.insert({i, {i, i}});
	}
	
	int type, l, r, x;
	for (int i = 0; i < M; i++)
	{
		scanf("%lld", &type);
		if (type == 1)
		{
			scanf("%lld%lld%lld", &l, &r, &x);
			auto it = interval_clusters.lower_bound({l, {0, 0}});
			if (it == interval_clusters.end() || it->ini != l)
			{
				--it;
			}
			
			
			if (it->ini <= l && r <= it->fim)
			{
				//contido num intervalo so
				update_range(l, r, abs(it->val - x));
				interval_clusters.insert({it->ini, {l - 1, it->val}});
				interval_clusters.insert({r + 1, {it->fim, it->val}});
				interval_clusters.insert({l, {r, x}});
				interval_clusters.erase(it);
				continue;
			}
				
			if (it->ini < l)
			{
				auto partial_left = it;
				++it;	
				update_range(l, partial_left->fim, abs(partial_left->val - x));
				interval_clusters.insert({partial_left->ini, {l - 1, partial_left->val}});
				interval_clusters.erase(partial_left);
			}
			
			bool has_partial_right = true;
			while (it != interval_clusters.end() && it->fim <= r)
			{
				if (it->fim == r)
				{
					has_partial_right = false;
				}
				update_range(it->ini, it->fim, abs(it->val - x));
				auto aux = it;
				++it;
				interval_clusters.erase(aux);
			}
			
			if (has_partial_right)
			{
				auto partial_right = it;
				update_range(partial_right->ini, r, abs(partial_right->val - x));
				interval_clusters.insert({r + 1, {partial_right->fim, partial_right->val}});
				interval_clusters.erase(partial_right);	
			}
			
			interval_clusters.insert({l, {r, x}});
			
		}
		else
		{
			scanf("%lld%lld", &l, &r);
			printf("%lld\n", value_range(l, r));
		}
	}
	
}


