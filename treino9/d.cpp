#include<bits/stdc++.h>

using namespace std;
#define db(x) cerr << #x << " == " << x << endl;	
#define pb push_back

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef vector<int> vi;
typedef vector<pii> vii;


int main()
{
	int N, T;
	scanf("%d", &N);
	
	int acu = 0;
	
	scanf("%d", &T);
	int curr_init = T + 1800 - 60;
	int last_time = T + 1800 + 20;
	
	
	for (int i = 1; i < N; i++)
	{
		scanf("%d", &T);
		
		db(T);
		db(acu);
		db(curr_init);
		db(last_time);
		
		if (T <= last_time)
		{
			db("D1");
			last_time += 20;
		}
		else if (T < last_time + 120)
		{
			db("D2");
			last_time = T + 20;
		}
		else
		{
			db("D3");
			acu += last_time - curr_init + 60;
			curr_init = T + 1800 - 60;
			last_time = T + 1800 + 20;
		}
	}
	db(curr_init);
		db(last_time);
	acu += last_time - curr_init;
	
	printf("%d\n", acu + 60);
	

	
	return 0;
}

