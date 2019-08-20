#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define LEFT(x) x+x+1
#define RIGHT(x) x+x+2

#define MAXN 5123

int N, Q; 
pii painters[MAXN];
int vals[MAXN];
int aux[MAXN];
int pref_aux[MAXN];

void print_vector(int vet[])
{
	//~ for (int i = 1; i <= N; i++)
	//~ {
		//~ printf("%d ", vet[i]);
	//~ }
	//~ printf("\n");
}

int main()
{
	scanf("%d%d", &N, &Q);
	
	for (int i = 0; i < Q; i++)
	{
		scanf("%d%d", &painters[i].fi, &painters[i].se);
		for (int j = painters[i].fi; j <= painters[i].se; j++)
		{
			vals[j]++;
		}
	}
	
	db("vals");
	print_vector(vals);
	int res_final = 0;
	for (int i = 0; i < Q; i++)
	{
		memset(aux, 0, sizeof(aux));
		int curr_res = 0;
		for (int j = painters[i].fi; j <= painters[i].se; j++)
		{
			vals[j]--;
		}
		
		for (int j = 1; j <= N; j++)
		{
			if (vals[j]) ++curr_res;
			if (vals[j] == 1) aux[j] = 1;
		}
		
		db("vals");
		print_vector(vals);
		db("aux");
		print_vector(aux);	
		for (int j = 1; j <= N; j++)
		{
			pref_aux[j] = pref_aux[j - 1] + aux[j];
		}
		db("pref");
		print_vector(pref_aux);
		
		int min_sub = INF;
		for (int j = i + 1; j < Q; j++)
		{
			int sub = pref_aux[painters[j].se] - pref_aux[painters[j].fi - 1];
			min_sub = min(sub, min_sub);
		}
		db(min_sub);
		
		res_final = max(res_final, curr_res - min_sub);
		for (int j = painters[i].fi; j <= painters[i].se; j++)
		{
			vals[j]++;
		}
	}
	
	printf("%d\n", res_final);
	
}
