#include <bits/stdc++.h>

using namespace std;

#define db(x) //cerr << #x << " = " << x << endl
#define vi vector<int>
#define pb push_back
#define INF 0x3f3f3f3f
#define ll long long
#define vll vector<ll>
#define all(x) x.begin(), x.end()

int N;
int children[8000006][26];
int isWord[8000006];
int id = 1;
char res[10000006];

bool add(string &s)
{
	int curr = 0;
	for (char c : s)
	{
		if (children[curr][c-'a'] == 0)
		{
			children[curr][c-'a'] = id;
			id++;
		}
		curr = children[curr][c-'a'];
	}
	
	if (isWord[curr])
	{
		return true;
	}
	isWord[curr] = 1;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	string s;
	int word_count = 0;
	int it = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		if (add(s))
		{
			for (auto c : s)
			{
				res[it] = c;
				it++;
			}
			res[it] = 0;
			++it;
			word_count++;
		}
	}
	
	if (!word_count)
	{
		printf("SAFO\n");
	}
	else
	{
		printf("%d\n", word_count);
		it = 0;
		for (int i = 0; i < word_count; i++)
		{
			while (res[it] != 0)
			{
				printf("%c", res[it]);
				++it;
			}
			printf("\n");
			++it;
		}
	}
	
}
