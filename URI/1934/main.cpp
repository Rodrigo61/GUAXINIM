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

int main() 
{

	int N, M;
	scanf("%d %d\n", &N, &M);
	
	map<string, int> str2int;
	
	char aux[3];
	string str;
	vector<vi> grid(N, vi(M));
	vi row_sum(N), col_sum(M);
	
	int id = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%s ", aux);
			str = aux;
			
			if (str2int.find(str) == str2int.end())
			{
				str2int[str] = id++;
			}
			
			grid[i][j] = str2int[str];
		}
		scanf("%d\n", &row_sum[i]);
	}
	
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &col_sum[i]);
	}
	
	vi val(id);
	
	vi known(id);
	int unknown = id;
	
	while (unknown--)
	{
		db(unknown);
		bool step_done = false;
		
		for (int i = 0; i < N; i++)
		{
			int last_unknown = -1;
			bool found = true;
			
			for (int j = 0; j < M; j++)
			{
				if (!known[grid[i][j]] && (last_unknown == -1 || last_unknown == grid[i][j]))
				{
					last_unknown = grid[i][j];
				}
				else if(!known[grid[i][j]])
				{
					found = false;
					break;
				}
			}
			
			if (found && last_unknown != -1)
			{
				
				//~ printf("unkown = %d  step i = %d\n", unknown, i);
				int n_vars = M;
				int sum = row_sum[i];
				for (int j = 0; j < M; j++)
				{
					if (known[grid[i][j]])
					{
						sum -= val[grid[i][j]];
						--n_vars;
					}
				}
				
				known[last_unknown] = 1;
				db(sum);
				db(n_vars);
				val[last_unknown] = sum / n_vars;
				db(val[last_unknown]);
				step_done = true;
				break;
			}
		}
		
		if (step_done) continue;
		
		for (int j = 0; j < M; j++)
		{
			int last_unknown = -1;
			bool found = true;
			
			for (int i = 0; i < N; i++)
			{
				if (!known[grid[i][j]] && (last_unknown == -1 || last_unknown == grid[i][j]))
				{
					last_unknown = grid[i][j];
				}
				else if(!known[grid[i][j]])
				{
					found = false;
					break;
				}
			}
			
			if (found && last_unknown != -1)
			{
				
				//~ printf("unkown = %d  step j = %d\n", unknown, j);
				
				int n_vars = N;
				int sum = col_sum[j];
				for (int i = 0; i < N; i++)
				{
					if (known[grid[i][j]])
					{
						sum -= val[grid[i][j]];
						n_vars--;
					}
				}
					db(sum);
				db(n_vars);
				known[last_unknown] = 1;
				val[last_unknown] = sum / n_vars;
				db(val[last_unknown]);
				step_done = true;
			}
		}
		
	}
	
	//~ print_vector_debug(val);
	
	for (auto &s : str2int)
	{
		printf("%s %d\n", s.first.c_str(), val[s.second]);
	}
	

	return 0;
}
