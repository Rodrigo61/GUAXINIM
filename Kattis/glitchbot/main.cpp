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

#define N 0
#define S 1
#define L 2
#define O 3


int Xt, Yt;

int Q;
int steps[51];

bool simulation(int x, int y, int dir, int inst)
{
	if (inst == Q)
	{
		if (x == Xt && y == Yt)
		{
			return true;
		}
		
		return false;
	}
	
	if (steps[inst] == 0)
	{
		if (dir == N)
		{
			y += 1;
		}
		else if (dir == S)
		{
			y -= 1;
		}
		else if (dir == L)
		{
			x += 1;
		}
		else
		{
			x -= 1;
		}
		
		return simulation(x, y, dir, inst + 1);
	}
	else if (steps[inst] == 1)
	{
		if (dir == N)
		{
			dir = O;
		}
		else if (dir == S)
		{
			dir = L;
		}
		else if (dir == L)
		{
			dir = N;
		}
		else
		{
			dir = S;
		}
		
		return simulation(x, y, dir, inst + 1);
	}
	else
	{
		if (dir == N)
		{
			dir = L;
		}
		else if (dir == S)
		{
			dir = O;
		}
		else if (dir == L)
		{
			dir = S;
		}
		else
		{
			dir = N;
		}
		
		return simulation(x, y, dir, inst + 1);
	}
}

int main() 
{
	
	scanf("%d%d%d", &Xt, &Yt, &Q);
	
	char aux[1000];
	string str;
	for (int i = 0; i < Q; i++)
	{
		scanf("%s", aux);
		str = aux;
		
		if (str == "Forward")
		{
			steps[i] = 0;
		}
		else if (str == "Left")
		{
			steps[i] = 1;
		}
		else
		{
			steps[i] = 2;
		}
	}
	
	for (int i = 0; i < Q; i++)
	{
		int aux = steps[i];
		
		if (aux == 0)
		{
			steps[i] = 1;
			if (simulation(0, 0, N, 0))
			{
				return !printf("%d Left\n", i + 1);
			}
			
			steps[i] = 2;
			if (simulation(0, 0, N, 0))
			{
				return !printf("%d Right\n", i + 1);
			}
		}
		else if (aux == 1)
		{
			steps[i] = 0;
			if (simulation(0, 0, N, 0))
			{
				return !printf("%d Forward\n", i + 1);
			}
			
			steps[i] = 2;
			if (simulation(0, 0, N, 0))
			{
				return !printf("%d Right\n", i + 1);
			}
		}
		else
		{
			steps[i] = 0;
			if (simulation(0, 0, N, 0))
			{
				return !printf("%d Forward\n", i + 1);
			}
			
			steps[i] = 1;
			if (simulation(0, 0, N, 0))
			{
				return !printf("%d Left\n", i + 1);
			}
		}
		
		steps[i] = aux;
	}
	
	
	
	return 0;
}
