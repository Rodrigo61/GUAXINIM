#include "bits/stdc++.h"
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
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
vector<vi> dp;

int solve(int i, int j)
{

	if (i > j)
	{
		return 0;
	}
	
	int &res = dp[i][j];
	
	if (res != -1)
	{
		return res;
	}
	
	if (str[i] == str[j])
	{
		res = solve(i + 1, j - 1);
	}
	else
	{
		res = min(solve(i + 1, j), solve(i, j - 1)) + 1;
	}
	
	return res;
}

int main() 
{

	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		cin >> str;
		
		dp.clear();
		dp.resize(str.size(), vi(str.size(), -1));
		cout << solve(0, str.size() - 1) << endl;
	}
	

	return 0;
}
