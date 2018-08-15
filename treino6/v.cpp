#include<bits/stdc++.h>
#define ll long long
using namespace std;

int X[1000], Y[1000], R[1000];

int vis[1000];

ll a[1000], b[1000];

int sqr(int x)
{
	return x*x;
}

int check(int x, int y)
{
	return sqr(X[x]-X[y])+sqr(Y[x]-Y[y]) == sqr(R[x]+R[y]);
}

main()
{
	int N, u;
	ll na, nb, md;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d %d %d", &X[i], &Y[i], &R[i]);
	a[0] = b[0] = 1;
	queue<int> fila;
	fila.push(0);
	vis[0] = 1;
	while(!fila.empty())
	{
		u = fila.front();
		fila.pop();
		for(int i = 0; i < N; i++)
		{
			if(i == u)
				continue;
			if(check(i, u))
			{
				na = -a[u]*R[u];
				nb = b[u]*R[i];
				md = __gcd(abs(na), abs(nb));
				na /= md;
				nb /= md;
				if(!vis[i])
				{
					vis[i] = 1;
					a[i] = na;
					b[i] = nb;
					fila.push(i);
				}
				else
				{
					if(na != a[i] || nb != b[i])
						return !printf("The input gear cannot move.\n");
				}
			}
		}
	}
	if(!vis[N-1])
		return !printf("The input gear is not connected to the output gear.\n");
	printf("%lld:%lld\n", a[N-1], b[N-1]);
	return 0;
}
