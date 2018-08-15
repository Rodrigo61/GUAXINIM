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

string str;


int pos[2001];
pii dp[2001][2001];


int main() 
{
	
	char c[2001];
	
	scanf("%s", c);
	str = c;
	int sz = str.size();

	int n_pos;
	scanf("%d", &n_pos);
	int p;
	for (int i = 0; i < n_pos; i++)
	{
		scanf("%d", &p);
		pos[p-1] = 1;
	}
	
	string rev = str;
	reverse(all(rev));
	
	for (int i = 0; i < sz + 1; i++)
	{
		dp[0][i] = {0, 0};
		dp[i][0] = {0, 0};
	}
	
	
	for (int i = 1; i < sz + 1; i++)
	{
		for (int j = 1; j < sz + 1; j++)
		{
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			
			if (str[i - 1] == rev[j - 1])
			{
				dp[i][j] = max(dp[i][j], make_pair(dp[i - 1][j - 1].first + pos[i - 1] + pos[sz - j], dp[i - 1][j - 1].second + 1));
			}
		}
	}
	
	
	db(dp[sz][sz].first);
	printf("%d\n", dp[sz][sz].second);
	

	return 0;
}
