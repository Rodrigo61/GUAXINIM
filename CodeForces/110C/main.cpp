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

//~ vector<string> dp;

//~ string solve(int target)
//~ {
	
	//~ if (target == 7 || target == 4)
	//~ {
		//~ return to_string(target);
	//~ }
	
	//~ if (target < 0)
	//~ {
		//~ return string("");
	//~ }
	
	//~ string &res = dp[target];
	
	//~ if (res != "-1")
	//~ {
		//~ return res;
	//~ }
	
	//~ res.clear();
	
	//~ string take_7 = solve(target - 7);
	//~ db(take_7);
	//~ if (!take_7.empty())
	//~ {
		
		//~ res +=  take_7 + '7'; 
		
		//~ return res;
	//~ }
	
	//~ string take_4 = solve(target - 4);
	//~ db(take_4);
	//~ if (!take_4.empty())
	//~ {
		//~ res = take_4 + '4';
		
		//~ return res;
	//~ }
	
	
	//~ return res;
//~ }

pii dp[1000000 + 1];

int main() 
{

	int N;
	scanf("%d", &N);
	
	db("oi");
	db("oi");
	
	for (int i = 0; i < N; i++)
	{
		dp[i] = {0, 0};
	}
	db("aqui");
	
	dp[4] = {1, 0};
	dp[7] = {0, 1};
	
	for (int i = 5; i <= N; i++)
	{
		if (i == 7) continue;
		
		if (i >= 7 && dp[i - 7] != make_pair(0, 0))
		{
			dp[i] = {dp[i - 7].first, dp[i - 7].second + 1};
		}
		else if (dp[i - 4] != make_pair(0, 0))
		{
			dp[i] = {dp[i - 4].first + 1, dp[i - 4].second};
		}
	}
	
	
	if (dp[N] != make_pair(0, 0))
	{
		for (int i = 0; i < dp[N].first; i++)
		{
			printf("4");
		}
		for (int i = 0; i < dp[N].second; i++)
		{
			printf("7");
		}
		printf("\n");
	}
	else
	{
		printf("-1\n");
	}
	

	return 0;
}
