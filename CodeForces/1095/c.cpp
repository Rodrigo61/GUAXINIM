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

int pot[31];

void calc()
{
	int p = 1;
	
	for (int i = 0; i <= 30; i++)
	{
		pot[i] = p;
		p *= 2;
	}
}

int N, K;

int main() 
{
	calc();
	scanf("%d%d", &N, &K);
	
	priority_queue<int> pq;
	
	for (int i = 30; i >= 0 && N != 0; i--)
	{
		if (pot[i] <= N)
		{
			db(pot[i]);
			pq.push(pot[i]);
			N -= pot[i];
		}
	}
	
	//~ while ((int)pq.size() > K)
	//~ {
		//~ int a = pq.top();
		//~ pq.pop();
		//~ int b = pq.top();
		//~ pq.pop();
		//~ pq.push(a + b);
	//~ }
	
	
	while ((int)pq.size() < K && pq.top() != 1)
	{
		db((int)pq.size());
		int a = pq.top();
		pq.pop();
		pq.push(a/2);
		pq.push(a/2);
	}
	
	if ((int)pq.size() == K)
	{
		printf("YES\n");
		while (!pq.empty())
		{
			printf("%d ", pq.top());
			pq.pop();
		}
	}
	else
	{
		printf("NO\n");
	}
	
	
	return 0;
}
