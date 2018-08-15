#include "bits/stdc++.h"
using namespace std;

#define db(x) //cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;

template<typename T>
void print_vector_debug(const T& t) {
	cout << "[DEBUG] VECTOR:";
	for (auto i = t.cbegin(); i != t.cend(); ++i) {
		if ((i + 1) != t.cend()) {
			cout << *i << " ";
		} else {
			cout << *i << endl;
		}
	}
}

int N;
int tree[100001];

void update(int i, int val)
{
	++i;
	while (i <= N)
	{
		tree[i] += val;
		i += (i&-i);
	}
}

int sum(int i)
{
	int s = 0;
	++i;
	while (i > 0)
	{
		s += tree[i];
		i -= (i & -i);
	}
	return s;
}

int main() 
{
	
	int T;
	scanf("%d", &T);
	
	while (T--)
	{
		scanf("%d", &N);
		
		vi upper(N);
		vi lower(N);

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &upper[i]);
		}
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &lower[i]);
		}
		
		//~ print_vector_debug(upper);
		//~ print_vector_debug(lower);
		
		int ativo = 0;
		memset(tree, 0, sizeof(tree));
		vi visited(N + 1, -1);
		int res_ativos = 0;
		int res = 0;
		for (int i = 0; i < N; i++)
		{
			int U = upper[i];
			int L = lower[i];
			
			db(i);
			db(U);
			db(L);
			db(visited[U]);
			db(visited[L]);
			db(res);
			
			if (visited[U] != -1)
			{
				--ativo;
				db(sum(N - 1));
				db(sum(visited[U] - 1));
				res += sum(N - 1) - sum(visited[U] - 1);
				res_ativos += ativo;
				db("U ended");
				
			}
			
			if (visited[L] != -1)
			{
				--ativo;
				db(sum(N - 1));
				db(sum(visited[L] - 1));
				res += sum(N - 1) - sum(visited[L] - 1);
				
				res_ativos += ativo;
				db("L ended");
			}
			
			if (visited[U] != -1 && visited[L] != -1)
			{
				res += 1;
			}
			
			if (visited[U] != -1)
			{
				update(visited[U], 1);
			}
			if (visited[L] != -1)
			{
				update(visited[L], 1);
			}
			if (U == L)
			{
				update(i, 1);
			}
			
			if (visited[U] == -1)
			{
				db("U visited");
				visited[U] = i;
				++ativo;
			}
			if (visited[L] == -1)
			{
				db("L visited");
				visited[L] = i;
				++ativo;
			}
		}
		
		printf("%d\n", res + res_ativos/2);
		
	}

	return 0;
}
