#include <bits/stdc++.h>
 
using namespace std;
 
#define vi vector<int>
#define INF 0x3f3f3f3f
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) x.begin(), x.end()

#define MAXN 212345

int N;
string str;
string p[MAXN];

void solve(int &idx, string pu)
{
	string str_u;
	while (idx < str.size() && str[idx] != '(' && str[idx] != ')')
	{
		str_u += str[idx];
		++idx;
	}
	
	p[stoi(str_u)] = pu;
	
	while (idx < str.size() && str[idx] == '(')
	{
		solve(++idx, str_u);
	}
	
	++idx;
	
}

int main()
{
	cin >> N;
	cin >> str;
	int aux = 0;
	solve(aux, "0");
	for (int i = 1; i <= N; i++)
	{
		printf("%s ", p[i].c_str());
	}
	
}
