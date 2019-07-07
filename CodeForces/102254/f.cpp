#include <bits/stdc++.h>

using namespace std;

#define db(x) //cerr << #x << " = " << x << endl
#define vi vector<int>
#define pb push_back
#define INF 0x3f3f3f3f
#define ll long long
#define vll vector<ll>
#define all(x) x.begin(), x.end()

#define MAXN 112345

int N, Q;
map<string, int> name2id;
int p[MAXN], sz[MAXN];

int find_r(int u)
{
	if (p[u] == 0)
	{
		return u;
	}
	return p[u] = find_r(p[u]);
}

int connected(int u, int v)
{
	return find_r(u) == find_r(v);
}

void connect(int u, int v)
{
	int ru = find_r(u);
	int rv = find_r(v);
	
	if (ru == rv) return;
	
	if (sz[ru] > sz[rv])
	{
		sz[ru] += sz[rv] + 1;
		p[rv] = ru;
	}
	else
	{
		sz[rv] += sz[ru] + 1;
		p[ru] = rv;
	}
}

int main()
{
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
	{
		string name;
		cin >> name;
		name2id[name] = i + 1;
	}
	
	for (int i = 0; i < Q; i++)
	{
		int cmd;
		string name1, name2;
		cin >> cmd >> name1 >> name2;
		db(cmd);
		db(name1);
		db(name2);
		if (cmd == 1)
		{
			connect(name2id[name1], name2id[name2]);
		}
		else
		{
			if (connected(name2id[name1], name2id[name2]))
			{
				printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
			
		}
		
		
	}
	
	
}
