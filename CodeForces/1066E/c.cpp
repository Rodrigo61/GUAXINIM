#include <bits/stdc++.h>

using namespace std;
#define MAXN 200005
#define db(x) //cerr << #x << " = " << x << endl;

int Left[MAXN], Right[MAXN];

int main()
{
	int N;
	scanf("%d\n", &N);

	char c;
	int val;
	scanf("%c %d\n", &c, &val);
	int r = 0, l = 0;
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%c %d\n", &c, &val);
		db(c);
		db(val);
		if (c == 'L')
		{
			++l;
			Left[val] = l;
		}
		else if (c == 'R')
		{
			++r;
			Right[val] = r;
		}
		else
		{
			db(l);
			db(r);
			db(Left[val]);
			db(Right[val]);
			if (Left[val])
			{
				printf("%d\n", min(l - Left[val], Left[val] + r));
			}
			else
			{
				printf("%d\n", min(r - Right[val], Right[val] + l));
			}
			
		}
	}
	
	return 0;
}
