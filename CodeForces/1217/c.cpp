#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll unsigned long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

#define MAXN 212345

char aux[MAXN];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", aux);
		string str = aux;
		int res = 0;
		
		for (int i = 1; i <= min(30, (int)str.size()); i++)
		{
			int mask = (1 << i) - 1;
			int curr = 0;
			for (int k = 0; k < i; k++)
			{
				curr <<= 1;
				if (str[k] == '1')
					curr++;
			}
			
			if (curr == i)
				++res;
			
			for (int k = i; k < (int)str.size(); k++)
			{
				
				curr <<= 1;
				curr &= mask;
				if (str[k] == '1')
					curr++;
					
				if (curr == i)
					res++;
			}
		}
		
		if (str.size() > 30)
		{
			vi left_zeros(str.size());
			int acu = 0;
			for (int i = 0; i < (int)str.size(); i++)
			{
				left_zeros[i] = acu;
				if (str[i] == '0')
				{
					++acu;
				}
				else
				{
					acu = 0;
				}
			}
			
			int mask = (1 << 30) - 1;
			int curr = 0;
			int j = 0;
			for (int i = 0; i < 30; i++)
			{
				curr <<= 1;
				curr &= mask;
				if (str[i] == '1')
					curr++;
			}
			
			if (curr > 30 && 30 + left_zeros[j] >= curr)
			{
				++res;
			}
			
			for (int i = 30; i < (int)str.size(); ++i)		
			{
				++j;
				curr <<= 1;
				curr &= mask;
				if (str[i] == '1')
					curr++;
				if (curr > 30 && 30 + left_zeros[j] >= curr)
				{
					++res;
				}
			}
		}
		printf("%d\n", res);
	}
}
