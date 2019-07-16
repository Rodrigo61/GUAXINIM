#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define db(x) cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

vi v;

int mex(set<int> &s)
{
	auto it = s.begin();
	for (int i = 0; it != s.end(); i++)
	{
		if (*it != i)
			return i;
		++it;
	}
	return (int)s.size();
}

int grundy(int idx, int offset)
{
	if (idx == (int)v.size())
	{
		return 0;
	}
	
	set<int> next_grundy;
	next_grundy.insert(grundy(idx + 1, 0));
	for (int i = offset + 1; i < v[idx]; i++)
	{
		next_grundy.insert(grundy(idx, i));
	}
	
	return mex(next_grundy);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, M;
		scanf("%d%d", &N, &M);
		int xr = 0;
		for (int i = 0; i < N; i++)
		{
			v.clear();
			v.resize(M);
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &v[j]);
			}
			xr ^= grundy(0, 0);
		}
		
		if (xr != 0)
		{
			printf("FIRST\n");
		}
		else
		{
			printf("SECOND\n");	
		}
		
		
		
	}
	
}
