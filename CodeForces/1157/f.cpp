#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) //cerr << #x << " = " << x << endl;
#define MAXN 212345

int N;
int vals[MAXN];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &vals[i]);
	}
	sort(vals, vals + N);
	
	deque<int> deck;
	
	int turn = 0;
	int maxi = 0;
	
	for (int i = 0; i < N; i++)
	{
		if (turn)
		{
			if (vals[i] - deck.back() <= 1)
			{
				deck.push_back(vals[i]);
			}
			else
			{
				int aux = deck.front();
				deck.clear();
				
				if (vals[i] - aux <= 1)
				{
					deck.push_front(aux);
				}
				
				deck.push_back(vals[i]);
			}
		}
		else
		{
			if (vals[i] - deck.front() <= 1)
			{
				deck.push_front(vals[i]);
			}
			else
			{
				int aux = deck.back();
				deck.clear();
				
				if (vals[i] - aux <= 1)
				{
					deck.push_back(aux);
				}
				
				deck.push_front(vals[i]);
			}
		}
		turn = !turn;
		maxi = max(maxi, (int)deck.size());
	}
	
	printf("%d\n", maxi);
	
	
	turn = 0;
	deck.clear();
	for (int i = 0; i < N; i++)
	{
		if (turn)
		{
			if (vals[i] - deck.back() <= 1)
			{
				deck.push_back(vals[i]);
			}
			else
			{
				int aux = deck.front();
				deck.clear();
				
				if (vals[i] - aux <= 1)
				{
					deck.push_front(aux);
				}
				
				deck.push_back(vals[i]);
			}
		}
		else
		{
			if (vals[i] - deck.front() <= 1)
			{
				deck.push_front(vals[i]);
			}
			else
			{
				int aux = deck.back();
				deck.clear();
				
				if (vals[i] - aux <= 1)
				{
					deck.push_back(aux);
				}
				
				deck.push_front(vals[i]);
			}
		}
		turn = !turn;
		if ((int)deck.size() == maxi)
		{
			break;
		}
		
	}
	for (auto i : deck)
		printf("%d ", i);
	printf("\n");
	
	
}
