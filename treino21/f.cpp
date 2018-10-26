#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define F first
#define S second

#define MAXN 100005
#define INF 300000

int main()
{
	int T;
	scanf("%d", &T);
	vector<int> v[MAXN];
	int a[MAXN], pont[MAXN];
	set<int> s;
	while(T--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		for(int i = 1; i <= n; i++)
			v[i].clear();
			
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			s.insert(a[i]);
		}
		
		vector<int> aux;
		
		set<pair<int, int> > pq;
		
		aux.assign(s.begin(), s.end());
		
		//for(auto x : aux){
		//	printf("aux : %d\n", x);
		//}
		
		s.clear();
		
		for(int i = 0; i < n; i++){
			a[i] = (lower_bound(aux.begin(), aux.end(), a[i]) - aux.begin() + 1);
			v[a[i]].push_back(i);
		}
		for(int i = 1; i <= int(aux.size()); i++)
			v[i].push_back(INF);
		
		//for(int i = 0; i < n; i++)
		//	printf("%d%c", a[i], " \n"[i == n-1]);
		
		memset(pont, 0, sizeof(pont));
		
		int i = 0;
		
		int res = 0;
		
		while(i < n && int(s.size()) < k){
			if(s.find(a[i]) == s.end())
			{
				res++;
				s.insert(a[i]);
				
				if(upper_bound(v[a[i]].begin(), v[a[i]].end(), i) != v[a[i]].begin() &&
				pq.count({*(upper_bound(v[a[i]].begin(), v[a[i]].end(), i)-1), a[i]}))
					pq.erase({*(upper_bound(v[a[i]].begin(), v[a[i]].end(), i)-1), a[i]});
				pq.insert({*upper_bound(v[a[i]].begin(), v[a[i]].end(), i), a[i]});
			}
			else
			{
				
				if(upper_bound(v[a[i]].begin(), v[a[i]].end(), i) != v[a[i]].begin() &&
				pq.count({*(upper_bound(v[a[i]].begin(), v[a[i]].end(), i)-1), a[i]}))
					pq.erase({*(upper_bound(v[a[i]].begin(), v[a[i]].end(), i)-1), a[i]});
				pq.insert({*upper_bound(v[a[i]].begin(), v[a[i]].end(), i), a[i]});
			}
			i++;
		}
		
		//printf("%d\n", res);
		while(i < n){

			if(s.find(a[i]) == s.end())
			{
				//printf("CIMA %d\n", i);
				auto it = *pq.rbegin();
				//printf("%d %d\n", it.F, it.S);
				s.erase(it.second);
				pq.erase(it);
				res++;
				s.insert(a[i]);
				if(upper_bound(v[a[i]].begin(), v[a[i]].end(), i) != v[a[i]].begin() &&
				pq.count({*(upper_bound(v[a[i]].begin(), v[a[i]].end(), i)-1), a[i]}))
					pq.erase({*(upper_bound(v[a[i]].begin(), v[a[i]].end(), i)-1), a[i]});
				pq.insert({*upper_bound(v[a[i]].begin(), v[a[i]].end(), i), a[i]});
			}
			
			else
			{
				//printf("BAIXO %d\n", i);
				
				if(upper_bound(v[a[i]].begin(), v[a[i]].end(), i) != v[a[i]].begin() &&
				pq.count({*(upper_bound(v[a[i]].begin(), v[a[i]].end(), i)-1), a[i]}))
					pq.erase({*(upper_bound(v[a[i]].begin(), v[a[i]].end(), i)-1), a[i]});
				//printf("%d %d\n", *upper_bound(v[a[i]].begin(), v[a[i]].end(), i), a[i]);
				pq.insert({*upper_bound(v[a[i]].begin(), v[a[i]].end(), i), a[i]});
			}
			
			i++;
		}
		
		printf("%d\n", res);
		
	}
	return 0;
}
