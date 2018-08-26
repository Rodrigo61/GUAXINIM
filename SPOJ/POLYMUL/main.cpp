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

#include<bits/stdc++.h>
#define pi acos(-1.0)
#define MAXN 32768
 
using namespace std;
 
struct cpl
{
	double a, b;
	cpl operator* (cpl y)
	{
		cpl z;
		z.a = a*y.a - b*y.b;
		z.b = a*y.b + b*y.a;
		return z;
	}
 
	cpl operator+ (cpl y)
	{
		cpl z;
		z.a = a + y.a;
		z.b = b + y.b;
		return z;
	}
 
	cpl operator- (cpl y)
	{
		cpl z;
		z.a = a - y.a;
		z.b = b - y.b;
		return z;
	}
	cpl operator/ (double x)
	{
		cpl z;
		z.a = a/x;
		z.b = b/x;
		return z;
	}
};
 
cpl X[MAXN], Y[MAXN]; 
int N, lg;
 
void findN(int sz)
{
	for(lg = 0, N = 1; N < sz; lg++, N <<= 1);
}
 
void fft(cpl A[], int sz) // A é o polinômio, sz é o tamanho da convolução desejada
{
	int i, j, k, m, m2 = 1;
	cpl w, wm, u, t;
	findN(sz);
	for(i = 1, j = 0; i < N; i++)
	{
		int bit = N >> 1;
		for(; j >= bit; bit>>=1) 
			j -= bit;
		j += bit;
		if (i < j) 
			swap(A[i], A[j]);
	}
 
	for(i = 1; i <= lg; i++)
	{
		m = m2 << 1;
		wm.a = cos(-2*pi/m);
		wm.b = sin(-2*pi/m);
		for(k = 0; k < N; k += m)
		{
			w.a = 1;
			w.b = 0;
			for(j = 0; j < m2; j++)
			{
				t = w*A[k + j + m2];
				u = A[k + j];
				A[k+j] = u + t;
				A[k+j+m2] = u - t;
				w = w * wm;
			}
		}
		m2 = m;
	}
}
 
void ifft(cpl A[], int sz) // A é o polinômio, sz é o tamanho da convolução desejada
{
	int i, j, k, m, m2 = 1;
	cpl w, wm, u, t;
	findN(sz);
	for(i = 1, j = 0; i < N; i++)
	{
		int bit = N >> 1;
		for(; j >= bit; bit >>= 1)
			j -= bit;
		j += bit;
		if(i < j)
			swap(A[i], A[j]);
	}
	for(i = 1; i <= lg; i++)
	{
		m = m2 << 1;
		wm.a = cos(2*pi/m);
		wm.b = sin(2*pi/m);
		for(k = 0; k < N; k += m)
		{
			w.a = 1;
			w.b = 0;
			for(j = 0; j < m2; j++)
			{
				t = w*A[k+j+m2];
				u = A[k+j];
				A[k+j] = u+t;
				A[k+j+m2] = u-t;
				w = w * wm;
			}
		}
		m2 = m;
	}
	for(int i = 0; i < N; i++)
		A[i] = A[i] / N;
}

int main() 
{

	int T;
	scanf("%d", &T);
	
	
	while (T--)
	{
		
		for (int i = 0; i < N; i++)
		{
			X[i].a = Y[i].a = 0;
			X[i].b = Y[i].b = 0;
		}
		
		
		int Q;
		scanf("%d", &Q);
		
		for (int i = 0; i < Q + 1; i++)
		{
			scanf("%lf", &X[i].a);
		}
		
		fft(X, Q + Q + 1);
		
		for (int i = 0; i < Q + 1; i++)
		{
			scanf("%lf", &Y[i].a);
		}
		
		fft(Y, Q + Q + 1);
		
		for (int i = 0; i < N; i++)
		{
			X[i] = X[i] * Y[i];
		}
		
		ifft(X, Q + Q + 1);
		
		
		for (int i = 0; i < Q + Q + 1; i++)
		{
			printf("%lld ", (ll)round(X[i].a));
		}
		printf("\n");
		
		
	}
	return 0;
}
