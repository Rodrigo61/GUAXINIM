#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
 
string s;
char aux[112345];
int numbers[112345];
int mask;
int t;
 
bool possible(int sz)
{
	for (int i = 0; i <= mask; i++)
	{
		if (numbers[i] != t)
		{
			return true;
		}
	}
	
	return false;
}
 
void generate_numbers(int M)
{
	int num = 0;
	mask = pow(2, M) - 1;
	t++;
	for (int i = 0; i < (int)s.size(); i++)
	{
		num = num << 1;
		num &= mask;
		num |= s[i] - '0';
		if (i >= M - 1)
		{
			numbers[num] = t;
		}
	}
	
}
 
int main()
{
	scanf("%s", aux);
	s = aux;
	int up = log2(s.size()) + 1;
	int lo = 1;
	int best;
	
	while (lo <= up)
	{
		int mid = lo + (up - lo)/2;
		generate_numbers(mid);
		if (possible(mid))
		{
			best = mid;
			up = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}
	
	printf("%d\n", best);
	
}
