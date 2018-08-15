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

#define X first
#define Y second

int N;
pii points[3001];

int main() 
{

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &points[i].X, &points[i].Y);
	}
	
	sort(points, points + N);
	set<int> box;
	
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		box.clear();
		
		for (int j = i + 1; j < N; j++)
		{
			int min_y = min(points[i].Y, points[j].Y);
			int max_y = max(points[i].Y, points[j].Y);
			
			auto it = box.lower_bound(min_y);
			if (it == box.end() || *it > max_y)
			{
				++ans;
			}
			
			box.insert(points[j].Y);
		}
		
	}
	
	
	printf("%d\n", ans);
	

	return 0;
}
