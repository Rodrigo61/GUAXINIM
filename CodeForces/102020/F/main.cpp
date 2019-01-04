#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long

int N;
//~ int vis[21][2][1048586];
//~ ll dp[21][2][1048586];

//~ ll fat(int num)
//~ {
	//~ ll res = 1;
	//~ for (int i = 1; i <= num; i++)
	//~ {
		//~ res *= i;
	//~ }
	
	//~ return res;
	
//~ }

//~ ll solve(int i, int desb, int mask)
//~ {
	//~ if (i == N - 1)
	//~ {
		//~ if (desb)
		//~ {
			//~ return 1;
		//~ }
		//~ else if (!desb && !(mask & (1 << i)))
		//~ {
			//~ return 1;
		//~ }
		//~ else
		//~ {
			//~ return 0;
		//~ }
	//~ }
	
	//~ if (vis[i][desb][mask])
	//~ {
		//~ return dp[i][desb][mask];
	//~ }
	//~ vis[i][desb][mask] = 1;
	
	//~ ll res = 0;
	//~ for (int j = 0; j < N; j++)
	//~ {
		//~ if (!(mask & (1 << j)))
		//~ {
			//~ if (i == j)
			//~ {
				//~ res = (res + solve(i + 1, 1, mask | (1 << j))) % MOD;
			//~ }
			//~ else
			//~ {
				//~ res = (res + solve(i + 1, desb, mask | (1 << j))) % MOD;
			//~ }
		//~ }
	//~ }
	
	//~ dp[i][desb][mask] = res;
	//~ return res;
//~ }

int main()
{
	scanf("%d", &N);
	//~ printf("%lld\n", fat(N) - solve(0, 0, 0));
	switch(N)
	{
		case 1:
		{
			printf("0\n");
			break;
		}
		case 2:
		{
			printf("1\n");
			break;
		}
		case 3:
		{
			printf("2\n");
			break;
		}
		case 4:
		{
			printf("9\n");
			break;
		}
		case 5:
		{
			printf("44\n");
			break;
		}
		case 6:
		{
			printf("265\n");
			break;
		}
		case 7:
		{
			printf("1854\n");
			break;
		}
		case 8:
		{
			printf("14833\n");
			break;
		}
		case 9:
		{
			printf("133496\n");
			break;
		}
		case 10:
		{
			printf("1334961\n");
			break;
		}
		case 11:
		{
			printf("14684570\n");
			break;
		}
		case 12:
		{
			printf("176214841\n");
			break;
		}
		case 13:
		{
			printf("290792918\n");
			break;
		}
		case 14:
		{
			printf("71100825\n");
			break;
		}
		case 15:
		{
			printf("66512367\n");
			break;
		}
		case 16:
		{
			printf("64197866\n");
			break;
		}
			case 17:
		{
			printf("91363714\n");
			break;
		}
			case 18:
		{
			printf("644546846\n");
			break;
		}
			case 19:
		{
			printf("246389989\n");
			break;
		}
			case 20:
		{
			printf("927799753\n");
			break;
		}
	}
	
	return 0;
}
