#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;

#define MAXN 212345

int vals[MAXN];
int N;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	
	string res;
	string d;
	int l = 0, r = N - 1;
	int last = 0;
	
	while (l <= r)
	{
		if (l < r && vals[l] == vals[r])
		{
			break;
		}
		
		if (vals[l] > last && vals[l] < vals[r])
		{
			db("L");
			res += 'L';
			last = vals[l];
			++l;
		}
		else if (vals[r] > last)
		{
			db("R");
			res += 'R';
			last = vals[r];
			--r;
		}
		else if (vals[l] > last)
		{
			db("L");
			res += 'L';
			last = vals[l];
			++l;
		}
		else
		{
			break;
		}
	}
	
	string res_left = res;
	string res_right = res;
	
	if (l < r && vals[l] == vals[r])
	{
		int last_a = last;
		while (vals[l] > last_a)
		{
			res_left += 'L';
			last_a = vals[l];
			++l;
		}
		
		
		last_a = last;
		while (vals[r] > last_a)
		{
			db(last_a);
			db(vals[r]);
			res_right += 'R';
			last_a = vals[r];
			--r;
		}
	}
	
	if ((int)res_left.size() > (int)res_right.size())
	{
		printf("%d\n%s\n", (int)res_left.size(), res_left.c_str());
	}
	else
	{
		printf("%d\n%s\n", (int)res_right.size(), res_right.c_str());
	}
	
	
}
