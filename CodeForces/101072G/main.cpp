#include "bits/stdc++.h"
using namespace std;

#define db(x) //cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;

template<typename T>
void print_vector_debug(const T& t) {
	cout << "[DEBUG] VECTOR:";
	for (auto i = t.cbegin(); i != t.cend(); ++i) {
		if ((i + 1) != t.cend()) {
			cout << *i << " ";
		} else {
			cout << *i << endl;
		}
	}
}

int N;
vi values(N);
vector<double> dp;
int fullmask;

int aux[19];

int to_left(int mask, int x)
{
	
	int sz = 0;
	for (int i = 0; i < N; i++)
	{
		if ((mask & (1 << i)))
		{
			aux[sz] = values[i];
			++sz;
		}
	}
	
	sort(aux, aux + sz);
	for (int i = 0; i < sz; i++)
	{
		if (aux[i] >= x)
		{
			return i;
		}
	}
	
	return 0;
}

int to_right(int mask, int x)
{
	
	int sz = 0;
	for (int i = 0; i < N; i++)
	{
		if ((mask & (1 << i)))
		{
			aux[sz] = values[i];
			++sz;
		}
	}
	
	sort(aux, aux + sz);
	for (int i = sz - 1; i >= 0; i--)
	{
		if (aux[i] <= x)
		{
			return sz - 1 - i;
		}
	}
	
	return 0;
}

double solve(int mask)
{
	if (mask == fullmask)
	{
		return 0;
	}
	
	double &res = dp[mask];
	
	if (res >= 0)
	{
		return res;
	}
	
	res = 0;
	int remaining = 0;
	for (int i = 0; i < N; i++)
	{
		if (!(mask & (1 << i)))
		{
			++remaining;
			res += solve(mask | (1 << i)) + min(to_left(mask, values[i]), to_right(mask, values[i]));
		}
	}
	
	res /= remaining;
	
	return res;
}

int main() 
{
	
	scanf("%d", &N);
	values.resize(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &values[i]);
	}
	
	
	fullmask = (1 << N) - 1;

	dp.resize(fullmask, -1);
	printf("%lf\n", solve(0));

	return 0;
}
