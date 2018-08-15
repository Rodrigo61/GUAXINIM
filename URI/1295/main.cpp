#include "bits/stdc++.h"
using namespace std;

#define db(x) //cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pdd> vdd;

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

#define LIMIT 10000

double dist(pdd A, pdd B)
{
	return hypot(A.first - B.first, A.second - B.second);
}

vdd points;
int N;

double closest_pair()
{
	sort(all(points));
	double min_dist = 9999999;
	set<pdd> box;
	
	box.insert({points[0].second, points[0].first});
	int left = 0;
	
	for (int i = 1; i < N; i++)
	{
		// Retira os pontos que ja nao sao mais candidatos.
		while (!box.empty() && points[i].first - points[left].first > min_dist)
		{
			box.erase({points[left].second, points[left].first});
			++left;
		}
		
		auto beg = box.lower_bound({points[i].second - min_dist, points[i].first - min_dist});
		auto end = box.lower_bound({points[i].second + min_dist, 9999999});
		
		while (beg != end)
		{
			min_dist = min(min_dist, dist({beg->second, beg->first}, points[i]));
			++beg;
		}
		
		box.insert({points[i].second, points[i].first});
		
	}
	
	return min_dist;
}

int main() 
{
	
	
	while (scanf("%d", &N), N)
	{
		points.clear();
		points.resize(N);
		
		for (int i = 0; i < N; i++)
		{
			double x, y;
			scanf("%lf %lf", &x, &y);
			points[i].first = x;
			points[i].second = y;
		}

		double min_dist = closest_pair();
		
		if (min_dist <= LIMIT)
		{
			printf("%0.4lf\n", min_dist);
		}
		else
		{
			printf("INFINITY\n");
		}
		
	}

	return 0;
}
