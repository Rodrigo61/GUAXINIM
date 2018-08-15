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

	int N, L, H;
	scanf("%d%d%d", &N, &L, &H);
	
	int in[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &in[i]);
	}
	
	int target[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &target[i]);
	}
	
	int max_seq[N + 1];
	memset(max_seq, 0, sizeof(max_seq));
	
	int acu = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		
		if (!target[i] && acu + in[i] > in[i])
		{
			max_seq[i] = acu + in[i];
		}
		else if (!target[i])
		{
			max_seq[i] = in[i];
		}
		else
		{
			max_seq[i] = 0;
		}
		
		if (max_seq[i] < 0)
		{
			max_seq[i] = 0;
		}
		
		acu = max_seq[i];
	}
	
	int dp[N + 1][H + 1];
	memset(dp, 0, sizeof(dp));
	
	for (int i = 0; i < H + 1; i++)
	{
		dp[N][i] = -999999;
	}
	for (int i = 0; i < N + 1; i++)
	{
		dp[i][0] = max_seq[i];
	}
	
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 1; j < H + 1; j++)
		{
			if (target[i])
			{
				dp[i][j] = dp[i + 1][j - 1] + in[i];
			}
			else
			{
				dp[i][j] = dp[i + 1][j] + in[i];
			}
		}
	}

	
	int maxi = -9999999;
	for (int i = 0; i < N; i++)
	{
		for (int j = L; j <= H; j++)
		{
			maxi = max(maxi, dp[i][j]);
		}
	}
	
	printf("%d\n", maxi);
	
	return 0;
}
