#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) cerr << #x << " = " << x << endl;
#define MAXN 112345

int N;
string number;
char vals[10];

int main()
{
	cin >> N;
	cin >> number;
	for (int i = 1; i <= 9; i++)
	{
		cin >> vals[i];
	}
	
	string res;
	
	bool taking = false;
	bool can_take = true;
	for (int i = 0; i < N; i++)
	{
		
		res += number[i];
		if (can_take && vals[number[i]-'0'] > number[i])
		{
			res[i] = vals[number[i]-'0'];
			taking = true;
		}
		
		if (taking && vals[number[i]-'0'] < number[i])
		{
			can_take = false;
		}
		
	}
	
	cout << res << endl;
}
