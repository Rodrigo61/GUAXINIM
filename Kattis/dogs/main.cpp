#include "bits/stdc++.h"
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
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

int N, M;
vdd dog1_points, dog2_points;

pdd walk(pii A, pii B, double t)
{
	
	double deltaY = A.second - B.second;
	double deltaX = A.first - B.first;
	
	double angle = atan2(deltaY, deltaX);
	
	return {t*sin(angle), t*cos(angle)};
	
}


int main() 
{
	scanf("%d", &N);
	dog1_points.resize(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d", &dog1_points[i].first, &dog1_points[i].second);
	}
	
	scanf("%d", &M);
	dog2_points.resize(M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &dog2_points[i].first, &dog2_points[i].second);
	}


	int i_dog1, i_dog2;
	double t_dog1, t_dog2;
	double min_dist = 99999999;
	
	while (i_dog1 < N - 1 && i_dog2 < M - 1)
	{
		pdd P = dog1_points[i_dog1];
		pdd Q = dog1_points[i_dog1 + 1];
		pdd R = dog2_points[i_dog2];
		pdd S = dog2_points[i_dog2 + 1];
		
		P = walk(P, Q, t_dog1);
		R = walk(R, S, t_dog2);
		
		min_dist = min(min_dist, seg_dist(P, Q, R, S));
		
		double dPQ = dist(P, Q);
		double dRS = dist(R, S);
		
		if (dPQ < dRS)
		{
			t_dog2 = dPQ;
			t_dog1 = 0;
			
			i_dog1++;
		}
		else if (dPQ > dRS)
		{
			t_dog1 = dRS;
			t_dog2 = 0;
			
			i_dog2++;
		}
		else
		{
			t_dog1 = t_dog2 = 0;
			i_dog1++;
			i_dog2++;
		}
	}
	
	
	printf("%lf\n", min_dist);
	return 0;
}
