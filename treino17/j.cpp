#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll tree[300010];	

#define MAXN 300010

int N;

void update(int i, ll val){
	++i;
	
	while(i <= N){
		tree[i] += val;
		i += (i&-i);
	}
}

ll sum(int i){
	ll s = 0;
	++i;
	while(i > 0){
		s += tree[i];
		i -= (i&-i);
	}
	return s;
}

int main(){
	int t;
	int A, B, C;
	int a[MAXN], b[MAXN], c[MAXN];

	cin >> t;
	
	while(t--){
		
		int cnt = 0;
		
		map<int, int> mapa;
		set<int> s;
		
		scanf("%d", &A);
		for(int i = 0; i < A; i++){
			scanf("%d", &a[i]);
			s.insert(a[i]);
		}
			
		scanf("%d", &B);
		for(int i = 0; i < B; i++){
			scanf("%d", &b[i]);
			s.insert(b[i]);
		}
		
		scanf("%d", &C);
		for(int i = 0; i < C; i++){
			scanf("%d", &c[i]);
			s.insert(c[i]);
		}
		
		for(set<int>::iterator it = s.begin(); it != s.end(); it++){
			mapa[*it] = cnt++;
		}
		
		for(int i = 0; i < A; i++){
			a[i] = mapa[a[i]];
		}
		for(int i = 0; i < B; i++){
			b[i] = mapa[b[i]];
		}
		for(int i = 0; i < C; i++){
			c[i] = mapa[c[i]];
		}
		
		int i = 0, j = 0;
		
		int aux[MAXN];
		memset(aux, 0, sizeof(aux));
			
		N = cnt;	
			
		while(j < B){
			if(i < A)
				update(a[i++], 1LL);
			aux[j] = sum(b[j]);
			j++; 
		}
		
	//	for(int i = 0; i < B; i++)
		//	printf("%d ", aux[i]);
		//printf("\n");
		
		memset(tree, 0LL, sizeof(tree));
		
		i = 0; j = 0;
		
		ll res = 0LL;
		
		
		
		while(j < C){
			if(i < B){
				update(b[i], (ll)aux[i]);
				i++;
			}
			res += sum(c[j]); 
			j++;
		}
		
		printf("%lld\n", res);
		
		memset(tree, 0LL, sizeof(tree));
	}
}
