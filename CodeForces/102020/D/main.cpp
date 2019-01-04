#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) cerr << #x << " = " << x << endl;

int N, Q;
map<string, int> m;
char aux[100000];

struct node
{
	int peso;
	int adj[26];
	node()
	{
		peso = 0;
		for(int i = 0; i < 26; i++)
			adj[i] = -1;
	}
};

node trie[1010000];
int sz, bol;

void add(string &str)
{
	int p = 0;
	for(int i = 0; i < (int)str.size(); i++)
	{
		trie[p].peso++;
		if(trie[p].adj[str[i]-'0'] == -1)
		{
			trie[p].adj[str[i]-'0'] = sz;
			trie[sz++] = node();
		}
		p = trie[p].adj[str[i]-'0'];
	}
	trie[p].peso++;
}

char convert(char c)
{
	if (c == 'a' || c == 'b' || c == 'c')
	{
		return '2';
	}
	if (c == 'd' || c == 'e' || c == 'f')
	{
		return '3';
	}
	if (c == 'g' || c == 'h' || c == 'i')
	{
		return '4';
	}
	if (c == 'j' || c == 'k' || c == 'l')
	{
		return '5';
	}
	if (c == 'm' || c == 'n' || c == 'o')
	{
		return '6';
	}
	if (c == 'p' || c == 'q' || c == 'r' || c == 's')
	{
		return '7';
	}
	if (c == 't' || c == 'u' || c == 'v')
	{
		return '8';
	}
	return '9';
}

int solve(string &str, int idx, int curr_node)
{
	if (curr_node == -1)
	{
		return 0;
	}
	
	if (idx == (int)str.size())
	{
		return trie[curr_node].peso;
	}
	
	return solve(str, idx + 1, trie[curr_node].adj[str[idx]-'0']);
}

int main()
{

	scanf("%d%d\n", &N, &Q);
	string s;
	
	sz = 1;
	trie[0] = node();
	
	for (int i = 0; i < N; i++)
	{
		scanf("%s\n", aux);
		s = aux;
		for (char &c : s)
		{
			c = convert(c);
		}
		
		add(s);
	}
	
	for (int i = 0; i < Q; i++)
	{
		scanf("%s\n", aux);
		s = aux;
		
		printf("%d\n", solve(s, 0, 0));
	}
	
	return 0;
}
