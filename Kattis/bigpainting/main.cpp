#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;
#define MAXN 2123

int hp, wp, hm, wm;
vector<vector<char>> grid;
vector<vector<char>> target;
vector<int> lps;

vector<ll> target_hash1, target_hash2;
vector<vector<ll>> grid_hash1, grid_hash2;

#define MOD1 1000000007
#define MOD2 1000000009
#define MAXLEN 2123
using namespace std;

ll hash1[MAXLEN], hash2[MAXLEN];
ll pot1[MAXLEN], pot2[MAXLEN];

void buildhash(vector<char> &str)
{
	pot1[0] = pot2[0] = 1;
	hash1[0] = hash2[0] = 0;
	for(int i = 0; i < (int)str.size(); i++)
	{
		pot1[i+1] = (26LL*pot1[i])%MOD1;
		pot2[i+1] = (26LL*pot2[i])%MOD2;
		hash1[i+1] = (26LL*hash1[i] + (str[i]-'A'))%MOD1;
		db(str[i]-'A');
		db(hash1[i+1]);
		hash2[i+1] = (26LL*hash2[i] + (str[i]-'A'))%MOD2;
	}
}

ll get1(int st, int en)
{
	db(st);
	db(en);
	db(hash1[en]);
	db(hash1[st]);
	return ((hash1[en] - (hash1[st]*pot1[en-st]) % MOD1) % MOD1 + MOD1)%MOD1;
}

ll get2(int st, int en)
{
	return ((hash2[en] - (hash2[st]*pot2[en-st]) % MOD2) % MOD2 + MOD2)%MOD2;
}

void kmpPre()
{
	int i = 0, j = -1;
	int m = hp;
	lps.resize(m + 1);
	lps[0] = -1;
	while(i < m)
	{
		while(j >= 0 && (target_hash1[i] != target_hash1[j] || target_hash2[i] != target_hash2[j])) j = lps[j];
		i++, j++;
		lps[i] = j;
	}
}

int main()
{
	scanf("%d%d%d%d\n", &hp, &wp, &hm, &wm);
	
	target.resize(hp);
	target_hash1.resize(hp);
	target_hash2.resize(hp);
	for (int i = 0; i < hp; i++)
	{
		target[i].resize(wp);
		for (int j = 0; j < wp; j++)
		{
			scanf("%c", &target[i][j]);
		}
		scanf("\n");
		buildhash(target[i]);
		target_hash1[i] = get1(0, wp);
		target_hash2[i] = get2(0, wp);
		db(target_hash1[i]);
	}
	
	grid.resize(hm);
	for (int i = 0; i < hm; i++)
	{
		grid[i].resize(wm);
		for (int j = 0; j < wm; j++)
		{
			scanf("%c", &grid[i][j]);
		}
		scanf("\n");
	}
	
	
	kmpPre();
	//~ for (int i = 0; i < lps.size(); i++)
	//~ {
		//~ printf("%d ", lps[i]);
	//~ } printf("\n");
	
	//~ db("grid");
	grid_hash1.resize(hm);
	grid_hash2.resize(hm);
	for (int i = 0; i < hm; i++)
	{
		grid_hash1[i].resize(wm);
		grid_hash2[i].resize(wm);
		buildhash(grid[i]);
		for (int j = 0; j + wp <= wm; j++)
		{
			grid_hash1[i][j] = get1(j, j + wp);
			grid_hash2[i][j] = get2(j, j + wp);
			//~ db(grid_hash1[i][j]);
		}
	}
	
	//~ for (int i = 0; i < hm; i++)
	//~ {
		//~ for (int j = 0; j < wm; j++)
		//~ {
			//~ printf("%5lld ", grid_hash1[i][j]);
		//~ }
		//~ printf("\n");
	//~ }
	

	
	int total = 0;
	db(wp);
	for (int j = 0; j + wp <= wm; j++)
	{
		int it_target = 0;
		for (int i = 0; i < hm; i++)
		{
			while (it_target >= hp || (it_target >= 0 && (target_hash1[it_target] != grid_hash1[i][j] || target_hash2[it_target] != grid_hash2[i][j])))
			{
				it_target = lps[it_target];
			}
			
			if (it_target == hp - 1)
			{
				db("match!");
				++total;
			}
			
			it_target++;
		}
	}
	
	
	printf("%d\n", total);
}
