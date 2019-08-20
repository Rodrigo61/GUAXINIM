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
 
int main()
{
	int N;
	string s;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		s += to_string(v);
	}
	string best = "";
	db(s);
	
	bool poss = false;
	for (int i = 0; i < (int)s.size() - 1; i++)
	{
		if (s[i] == '0' || s[i] == '5')
		{
			swap(s[i], s[(int)s.size() - 1]);
			best = max(best, s);
			poss = true;
			swap(s[i], s[(int)s.size() - 1]);
		}
	}
	
	if (poss)
	{
		for (char c : best)
			cout << c << " ";
		cout << endl;
	}
	else
	{
		cout << -1 << endl;
	}
	
	
	
}
