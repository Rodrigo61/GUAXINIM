#include "bits/stdc++.h"
using namespace std;

#define db(x) //cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back

typedef pair<int,int> pii;
typedef pair<double,double> pdd;
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

#define PI acos(-1.0)
#define EPS 0.00000001
double a, b;
double m;

int main() 
{
	
	/*
	 * Tecnica de refletir a mesa e pensar só no triangulo retangulo que formará o trajeto
	 * */
	
	double v, s;
	while (scanf("%lf%lf%lf%lf%lf", &a, &b, &v, &m, &s), a+b+v+m+s)
	{
		
		m = m * PI/180;
		
		double hip, cat_hor, cat_ver;
		hip = v * s - (v * s)/(2);
		cat_hor = cos(m) * hip;
		cat_ver = sin(m) * hip;
		
		int acu_hor = 1, acu_ver = 1;
		
		cat_hor -= a/2;
		cat_ver -= b/2;
		
		acu_hor += cat_hor/a;
		acu_ver += cat_ver/b;
		
		printf("%d %d\n", acu_hor, acu_ver);
		
	}

	return 0;
}
