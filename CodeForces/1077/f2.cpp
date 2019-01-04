#include "bits/stdc++.h"
using namespace std;

#define db(x) //cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define pb push_back

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
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

#define MAXN 5005
#define INF (ll) 1000000000000000
#define y second
#define x first

int N, K, X;
ll vals[MAXN];
ll dp[MAXN][MAXN];

struct myQueue {
	stack<pll> s1, s2;
	
	int size() {
		return s1.size() + s2.size();
	}
	
	bool isEmpty() {
		return size() == 0;
	}
	
	long long getMax() {
		if (isEmpty()) {
			return -INF;
		}
		if (!s1.empty() && !s2.empty()) {
			return max(s1.top().y, s2.top().y);
		}
		if (!s1.empty()) {
			return s1.top().y;
		}
		return s2.top().y;
	}
	
	void push(long long val) {
		if (s2.empty()) {
			s2.push({val, val});
		} else {
			s2.push({val, max(val, s2.top().y)});
		}
	}
	
	void pop() {
		if (s1.empty()) {
			while (!s2.empty()) {
				if (s1.empty()) {
					s1.push({s2.top().x, s2.top().x});
				} else {
					s1.push({s2.top().x, max(s2.top().x, s1.top().y)});	
				}
				s2.pop();
			}
		}
		assert(!s1.empty());
		s1.pop();
	}
};



int main() 
{
	scanf("%d%d%d", &N, &K, &X);
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &vals[i]);
	}
	
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= X + 1; j++)
		{
			dp[i][j] = -INF;
		}
	}
	
	dp[N + 1][0] = 0;
	
	for (int j = 1; j <= X; ++j)
	{
		myQueue mq;
		for (int i = N; i >= 1; i--)
		{
		
			db(j);
			mq.push(dp[i + 1][j - 1]);
			
			if (mq.size() > K)
			{
				mq.pop();
			}
			dp[i][j] = mq.getMax() + vals[i];
		}
	}
	
	ll s = -INF;
	for (int i = 1; i <= K; i++)
	{
		s = max(s, dp[i][X]);
	}
	
	if (s >= 0)
	{
		printf("%lld\n", s);
	}
	else
	{
		printf("-1\n");
	}
	
	
	return 0;
}
