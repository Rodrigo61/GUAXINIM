#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
 
map<ll, ll> freq_row, freq_col;
int N, Q;
 
int main()
{
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < Q; i++)
	{
		int cmd;
		scanf("%d", &cmd);
		switch (cmd)
		{
			case 1:
			{
				int X, R;
				scanf("%d%d", &X, &R);
				freq_row[X] = R;
				break;
			}
			case 2:
			{
				int X, R;
				scanf("%d%d", &X, &R);
				freq_col[X] = R;
				break;
			}
			case 3:
			{
				int X;
				scanf("%d", &X);
				ll maxi = 0;
				for (auto p : freq_col)
					maxi = max(maxi, p.se);
				printf("%lld\n", maxi);
				break;
			}
			case 4:
			{
				int X;
				scanf("%d", &X);
				ll maxi = 0;
				for (auto p : freq_row)
					maxi = max(maxi, p.se);
				printf("%lld\n", maxi);
				break;
			}	
		}
		
	}
	
}
