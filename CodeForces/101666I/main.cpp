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

int Q;
int P;

int cost(int is, int js, int it, int jt)
{
	if (is != it)
	{
		//irma
		int delta = it != -1 ? (is - it): (is + 1);
		if ((delta * (Q - js)) & 1)
		{
			if ((is + js) & 1)
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		//irmao
		int delta = (jt != Q) ? (jt - js):(Q - js);
		if ((delta * (is + 1)) & 1)
		{
			if (js & 1)
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 0;
		}
	}
}

vector<vector<vi>> dp;

int solve(int i, int j, int turn)
{
	
	if (j == Q || i == -1)
	{
		return 0;
	}
	
	int &res = dp[i][j][turn];
	
	if (res != -1000000)
	{
		return res;
	}
	
	if (turn)
	{
		res = -9999;

		for (int k = j + 1; k <= Q; k++)
		{
			int felicidade_irmao = cost(i, j, i, k);
			db(felicidade_irmao);
			
			res = max(res, felicidade_irmao + solve(i, k, 0));
		}
	}
	else
	{
		res = 9999;
		
		for (int l = i - 1; l >= -1; l--)
		{
			int felicidade_irma = cost(i, j, l, j);
			db(felicidade_irma);
			
			res = min(res, solve(l, j, 1) - felicidade_irma);
		}
	}
	
	return res;
}

int main()
{
	scanf("%d%d", &P, &Q);
	
	dp.resize(P + 2, vector<vi>(Q + 2, vi(2, -1000000)));
	printf("%d\n", solve(P - 1, 0, 1));
	
	return 0;
}
