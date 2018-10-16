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
char aux[30000];
map<string, int> name2id;

long double mat[40][40];

int main() 
{
	
	int tc = 0;
	while (scanf("%d\n", &N), N)
	{
		string name;
		name2id.clear();
		int id = 0;
		
		for (int i = 0; i < N; i++)
		{
			scanf("%s\n", aux);
			name = aux;
			
			name2id[name] = id;
			id++;
		}
		
		int M;
		scanf("%d\n", &M);
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				mat[i][j] = 0;
			}
			mat[i][i] = 1.0;
		}

		
		long double val;
		for (int i = 0; i < M; i++)
		{
			string name1, name2;
			scanf("%s", aux), name1 = aux;
			scanf("%LF", &val);
			scanf("%s\n", aux), name2 = aux;
			
			int id1 = name2id[name1];
			int id2 = name2id[name2];
			
			mat[id1][id2] = val;
		}
		
		
		
		
		bool found = false;
		for (int k = 0; k < N; k++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					mat[i][j] = max(mat[i][j], mat[i][k] * mat[k][j]);
					
					if (i == j && mat[i][j] > 1 && abs(mat[i][j] - 1) > 0.00001)
					{
						found = true;
					}
				}
			}
		}
		
		//~ for (int i = 0; i < N; i++)
		//~ {
			//~ for (int j = 0; j < N; j++)
			//~ {
				//~ printf("%LF ", mat[i][j]);
			//~ }
			//~ printf("\n");
		//~ }
		
		
		if (found)
		{
			printf("Case %d: Yes\n", ++tc);
		}
		else
		{
			printf("Case %d: No\n", ++tc);
		}
		
		scanf("\n");
		
	}
	return 0;
}
