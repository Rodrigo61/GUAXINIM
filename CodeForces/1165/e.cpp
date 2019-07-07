#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define db(x) cerr << #x << " = " << x << endl;
#define all(x) x.begin(), x.end()
#define MOD 998244353  
#define MAXN 212345
#define fi first
#define se second

ll B[MAXN];
pair<ll, ll> A[MAXN];
int N;

ll add(ll a, ll b)
{
	return (a + b) % MOD;
}

ll sub(ll a, ll b)
{
	return (a - b + MOD) % MOD;
}

ll mul(ll a, ll b)
{
	return (a * b) % MOD;
}

ll calc(ll N)
{
	return ((N*(N-1))/2 + N) % MOD; // TODO
}

ll used[MAXN];

int main()
{
	scanf("%d", &N);
	ll tot = calc(N);

	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &A[i].fi);
		ll le = i;
		ll ri = max(0, (N-1) - i);
		ll total_used = tot - calc(le) - calc(ri);
		used[i] = total_used;
		A[i].fi = mul(total_used, A[i].fi);
		A[i].se = i;
		db(used[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &B[i]);
	}
	sort(A, A + N);
	sort(B, B + N);
	reverse(B, B+N);

	vector<ll> mul_deque(N);
	for (int i = 0; i < N; i++)
	{
		ll v = mul(A[i].fi, B[i]);
		mul_deque[A[i].se] = v;
	}

	ll sum = 0;
	
	for (int i = 0; i < N; i++)
	{
		ll local_sum = mul_deque[i];
		sum = add(sum, local_sum);
	}
	
	printf("%lld\n", sum % MOD);
}
