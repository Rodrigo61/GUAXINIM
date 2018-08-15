#include "bits/stdc++.h"
using namespace std;

#define db(x) cout << #x << " == " << x << endl
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

int in[3000], out[3000];


int main() 
{

	int N, M;
	
	while (scanf("%d %d", &N, &M) != EOF)
	{
	
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &in[i]);
		}
		
		for (int i = 0; i < M; i++)
		{
			scanf("%d", &out[i]);
		}
		
		
		unordered_map<int, int> m;
		
		
		for (int i = 0; i < N; i++)
		{
			for (int j = i; j < M; j++)
			{
				if (in[i] <= out[j])
				{
					//~ db(out[j] - in[i]);
					m[out[j] - in[i]]++;
				}
			}
		}
		
		
		int maxi = 0;
		int maxi_val = 0;
		for (auto e : m)
		{
			
			if (e.second > maxi)
			{
				maxi = e.second;
				maxi_val = e.first;
			}
		}
		
		//~ db(maxi);
		printf("%d\n", maxi_val);
		
		
		
	}

	return 0;
}
