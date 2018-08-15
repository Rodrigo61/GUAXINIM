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


int get_pivo(int level)
{
	return 1 + (level * ((level - 1) * 6))/2;
}

int get_level()
{
	int upper = 200;
	int lower = 1;
	int best;
	
	while (lower <= upper)
	{
		int mid = lower + (upper - lower)/2;
		
		int sum = get_pivo(mid);
		
		db(mid);
		db(sum);
		if (sum <= N)
		{
			best = mid;
			lower = mid + 1;
		}
		else
		{
			upper = mid - 1;
		}
	}
	
	if (N == get_pivo(best))
	{
		return best;
	}
	
	return best + 1;
}

int get_edge_sz(int level)
{
	return level - 1;
}

int main() 
{

	while (scanf("%d", &N) != EOF)
	{
		
		int level = get_level();
		int pivo = get_pivo(level);
		int edge_sz = get_edge_sz(level);
		
		int x = level - 1, y = 0;
		int curr_value = pivo;
		
		db(level);
		db(pivo);
		db(edge_sz);
		db(x);
		db(y);
		db(curr_value);
		
		bool found = false;
		
		if (curr_value == N)
		{
			found = true;
		}
		
		for (int i = 0; !found && i < edge_sz; i++)
		{
			y -= 1;
			--curr_value;
			db(curr_value);
			db(x);
			db(y);
			if (curr_value == N)
			{
				found = true;
				break;
			}
		}
		
		for (int i = 0; !found && i < edge_sz; i++)
		{
			x -= 1;
			--curr_value;
			db(curr_value);
			db(x);
			db(y);
			if (curr_value == N)
			{
				found = true;
				break;
			}
		}
		
		for (int i = 0; !found && i < edge_sz; i++)
		{
			x -= 1;
			y += 1;
			--curr_value;
			db(curr_value);
			db(x);
			db(y);
			if (curr_value == N)
			{
				found = true;
				break;
			}
		}
		
		for (int i = 0; !found && i < edge_sz; i++)
		{
			y += 1;
			--curr_value;
			db(curr_value);
			db(x);
			db(y);
			if (curr_value == N)
			{
				found = true;
				break;
			}
		}
		
		for (int i = 0; !found && i < edge_sz; i++)
		{
			x += 1;
			--curr_value;
			db(curr_value);
			db(x);
			db(y);
			if (curr_value == N)
			{
				found = true;
				break;
			}
		}
		
		for (int i = 0; !found && i < edge_sz; i++)
		{
			x += 1;
			y -= 1;
			db(curr_value);
			db(x);
			db(y);
			--curr_value;
			if (curr_value == N)
			{
				found = true;
				break;
			}
		}
		
		printf("%d %d\n", x, y);
		
	}

	return 0;
}
