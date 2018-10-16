#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

pair< pair<ll, ll>, ll> vet[100000];
int inicios[100001];
int fins[100001];
ll acum[100001];

int main()
{
	int T, N,  ind;
	ll ma, K;
	scanf("%d", &T);
	while(T--)
	{
		ma = 0;
		scanf("%d %lld", &N, &K);
		for(int i = 1; i <= N; i++)
			scanf("%lld %lld %lld", &vet[i].fi.fi, &vet[i].fi.se, &vet[i].se);
		sort(vet+1, vet+N+1);
		for(int i = 1; i <= N; i++)
		{
			inicios[i] = vet[i].fi.fi;
			fins[i] = vet[i].fi.se;
			acum[i] = acum[i-1] + (vet[i].se)*(vet[i].fi.se-vet[i].fi.fi+1);
		}
		for(int i = 1; i <= N; i++)
		{
			ind = (upper_bound(inicios+1, inicios+N+1, vet[i].fi.fi+K-1)-inicios)-1;
			ma = max(ma, acum[ind-1]-acum[i-1] + vet[ind].se*(min(vet[ind].fi.se, vet[i].fi.fi+K-1)-vet[ind].fi.fi+1));
			
			ind = lower_bound(fins+1, fins+N+1, vet[i].fi.se-K+1)-fins;
			ma = max(ma, acum[i]-acum[ind]+vet[ind].se*(vet[ind].fi.se - max(vet[ind].fi.fi, vet[i].fi.se-K+1) + 1));
		}
		printf("%lld\n", ma);
	}
	return 0;
}
