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
	
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("\n");
	db(n);
	db(m);
	
	vector<vector<char>> grid(n, vector<char>(m));
	vector<vector<int>> rechead(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%c", &grid[i][j]);
			//~ printf("%c", grid[i][j]);
		}		
		scanf("\n");
		//~ printf("\n");
	}
	
	vector<pair<pair<int,int>, int>> ans;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int maxL = 0, maxR = 0, maxU = 0, maxD = 0;	
			if (grid[i][j] != '*') continue;
			
			if (j > 0 && grid[i][j - 1] == '*')
			{
				maxL
			}
			
			for (int k = j; k >= 0; k--)
			{
				if (grid[i][k] == '.')
				{
					break;
				}
				++maxL;
			}
			
			for (int k = j; k < m; k++)
			{
				if (grid[i][k] == '.')
				{
					break;
				}
				++maxR;
			}
			
			for (int k = i; k >= 0; k--)
			{
				if (grid[k][j] == '.')
				{
					break;
				}
				++maxU;
			}
			
			for (int k = i; k < n; k++)
			{
				if (grid[k][j] == '.')
				{
					break;
				}
				++maxD;
			}
			
			int mini = min({maxL, maxR, maxD, maxU});
			
			if (mini > 1)
			{
				db(maxL);
				db(maxR);
				db(maxU);
				db(maxD);
				ans.pb({{i, j}, mini - 1});
					
					db("d1");
					db(i);
					db(j);
					
				rechead[i][j] = 1;
				for (int k = 1; k < mini; k++)
				{
					db(k);
					rechead[i + k][j] = 1;
					rechead[i - k][j] = 1;
					rechead[i][j + k] = 1;
					rechead[i][j - k] = 1;
				}
				db("d2");
				
			}
			
		}
		
	}
	
	//~ for (int i = 0; i < n; i++)
	//~ {
		//~ for (int j = 0; j < m; j++)
		//~ {
			//~ printf("%d ", rechead[i][j]);
		//~ }
		//~ printf("\n");
	//~ }
	//~ printf("\n");
	
	
	db("aqui");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == '*' && rechead[i][j] == 0)
			{
				return !printf("-1\n");
			}
		}
	}
	
	printf("%d\n", ans.size());
	for (auto &r : ans)
	{
		printf("%d %d %d\n", r.first.first + 1, r.first.second + 1, r.second);
	}

	return 0;
}
