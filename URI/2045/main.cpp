#include "bits/stdc++.h"
using namespace std;

#define db(x) //cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define space " "
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
int X[1001], Y[1001];

int ccw(int x1, int y1, int x2, int y2)
{
	return x1*y2 - x2*y1;
}

int pointInPolygon(int x, int y) 
{
	int windingNumber = 0;
	for(int i = 0; i < N; i++) 
	{
		if (x == X[i] && y == Y[i]) 
			return 0;
		int j = (i+1)%N;
		if(Y[i] == y && Y[j] == y) 
		{
			if(min(X[i], X[j]) <= x && x <= max(X[i], X[j])) 
				return 0;
		} 
		else 
		{
			bool below = Y[i] < y;
			if (below != (Y[j] < y)) 
			{
				int orientation = ccw(X[i]-x, Y[i]-y, X[j]-x, Y[j]-y);
				if (orientation == 0) 
					return 0;
				if (below == (orientation > 0)) 
					windingNumber += below ? 1 : -1;
			}
		}
	}
	return windingNumber == 0 ? 1 : -1;
}

int main() 
{
	
	int n_case = 0;
	
	while (scanf("%d", &N), N) 
	{
		
		printf("Instancia %d\n", ++n_case);
		
		for (int i = 0; i < N; i++)
		{
			scanf("%d%d", &X[i], &Y[i]);
		}
		
		pii flag;
		scanf("%d%d", &flag.first, &flag.second);
		int flag_pos = pointInPolygon(flag.first, flag.second);
		
		int M;
		scanf("%d", &M);
		for (int i = 0; i < M; i++)
		{
			pii point;
			scanf("%d%d", &point.first, &point.second);
			int pos = pointInPolygon(point.first, point.second);

			if ((pos == flag_pos) || pos == 0)
			{
				printf("soldado %d defender\n", i + 1);
			}
			else
			{
				printf("soldado %d espanhol\n", i + 1);
			}
			
		}
		
		printf("\n");

	}

	return 0;
}
