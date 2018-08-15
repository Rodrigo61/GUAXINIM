#include<bits/stdc++.h>
#define pi acos(-1.0)
#define MAXN 1048576

using namespace std;

struct cpl
{
	long double a, b;
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

void fft(cpl A[], int N, int lg)
{
	int i, j, k, m, m2 = 1;
	cpl w, wm, u, t;
	for(i = 1, j = 0; i < N; i++)
	{
		int bit = N >> 1;
		for(; j >= bit; bit >>= 1)
		{
			//printf("%d\n", j);
			j -= bit;
		}
		//printf("A\n");
		j += bit;
		if(i < j)
			swap(A[i], A[j]);
	}
	//printf("a\n");
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
				u = A[k+j];
				A[k+j] = u+t;
				A[k+j+m2] = u-t;
				w = w * wm;
			}
		}
		m2 = m;
	}
	//printf("a\n");
}

void ifft(cpl A[], int N, int lg)
{
	int i, j, k, m, m2 = 1;
	cpl w, wm, u, t;
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

char str[400001], str2[200001];
int A[400001], B[400001], C[400001];

int main()
{
	long long a, b, c;
	int h, T, N, M, sz, lg, cnt = 0;
	scanf("%lld %lld %lld %d", &a, &b, &c, &h);
	scanf("%s", str);
	scanf("%s", str2);
	N = T = strlen(str);
	M = strlen(str2);
	for(int i = 0; i < M-1; i++)
		str[N+i] = str[i];
	N = N+M-1;
	for(lg = 0, sz = 1; sz < N+M+M-2; lg++, sz <<= 1);
	//printf("FOI\n");
	for(int i = 0; i < M/2; i++)
		swap(str2[i], str2[M-1-i]);
	for(int i = 0; i < N; i++)
	{
		X[i].a = str[i] == 'R';
		X[i].b = 0;
	}
	for(int i = 0; i < M; i++)
	{
		Y[i].a = str2[i] == 'A';
		Y[i].b = 0;
	}
	fft(X, sz, lg);
	fft(Y, sz, lg);
	for(int i = 0; i < sz; i++)
		X[i] = X[i]*Y[i];
	ifft(X, sz, lg);
	for(int i = M-1; i < T+M-1; i++)
	{
		//printf("%d ", (int)round(X[i].a));
		A[i-M+1] = round(X[i].a);
	}
	//printf("\n");
	for(int i = 0; i < sz; i++)
		X[i].a = X[i].b = Y[i].a = Y[i].b = 0;
	for(int i = 0; i < N; i++)
	{
		X[i].a = str[i] == 'N';
		X[i].b = 0;
	}
	for(int i = 0; i < M; i++)
	{
		Y[i].a = str2[i] == 'B';
		Y[i].b = 0;
	}
	fft(X, sz, lg);
	fft(Y, sz, lg);
	for(int i = 0; i < sz; i++)
		X[i] = X[i]*Y[i];
	ifft(X, sz, lg);
	for(int i = M-1; i < T+M-1; i++)
	{
		//printf("%d ", (int)round(X[i].a));
		B[i-M+1] = round(X[i].a);
	}
	//printf("\n");
	
	for(int i = 0; i < sz; i++)
		X[i].a = X[i].b = Y[i].a = Y[i].b = 0;
	for(int i = 0; i < N; i++)
	{
		X[i].a = str[i] == 'E';
		X[i].b = 0;
	}
	for(int i = 0; i < M; i++)
	{
		Y[i].a = str2[i] == 'C';
		Y[i].b = 0;
	}
	fft(X, sz, lg);
	fft(Y, sz, lg);
	for(int i = 0; i < sz; i++)
		X[i] = X[i]*Y[i];
	ifft(X, sz, lg);
	for(int i = M-1; i < T+M-1; i++)
	{
		//printf("%d ", (int)round(X[i].a));
		C[i-M+1] = round(X[i].a);
	}
	//printf("\n");
	for(int i = 0; i < T; i++)
		cnt += (A[i]*a+B[i]*b+C[i]*c) >= h;
	int md = __gcd(cnt, T);
	printf("%d %d\n", cnt/md, T/md);
	return 0;
}

