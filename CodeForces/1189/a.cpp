#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define pb push_back
#define db(x) cerr  << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define vi vector<int>
#define ll long long
#define vll vector<ll>

int main()
{
	int N;
	string str;
	cin >> N >> str;
	
	int one = 0, zero = 0;
	for (auto c : str)
		if (c == '0') ++zero;
		else ++one;
	
	if (one != zero || N & 1)
	{
		printf("1\n");
		printf("%s\n", str.c_str());
	}
	else
	{
		printf("2\n");
		printf("%s %c\n", str.substr(0, N - 1).c_str(), str.back());
	}
	
	
}
