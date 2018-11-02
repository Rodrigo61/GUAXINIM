#include<bits/stdc++.h>

using namespace std;

main()
{
	int i, N, k, custo = 0, ma, L;
	vector<pair<int, int> > vet[11];
	scanf("%d", &N);
	if(N <= 128)
		printf("1\n1 %d\n", N);
	else
	{
		i = 1;
		ma = 0;
		while(i <= N)
		{
			vet[0].push_back({i, min(max(N/1000, 2)+i-1, N)});
			L = vet[0].back().second-vet[0].back().first+1;
			ma = max(ma, int(L*ceil(log(L))));
			i = min(i+max(N/1000, 2), N+1);
		}
		custo += ma;
		k = 1;
		int p = 0;
		//printf("tchau\n");
		ma = 0;
		while(p < vet[k-1].size())
		{
			if(p+3 < vet[k-1].size())
			{
				vet[k].push_back({vet[k-1][p].first, vet[k-1][p+3].second});
			}
			else
			{
				vet[k].push_back({vet[k-1][p].first, vet[k-1].back().second});
			}
			L = vet[k].back().second-vet[k].back().first+1;
			ma = max(ma, int(L*2));
			p += 4;
		}
		custo += ma;
		k = 2;
		while(1)
		{
			int p = 0;
			ma = 0;
			//printf("tchau\n");
			while(p < vet[k-1].size())
			{
				if(p+1 != vet[k-1].size())
				{
					vet[k].push_back({vet[k-1][p].first, vet[k-1][p+1].second});
				}
				else
				{
					vet[k].push_back(vet[k-1][p]);
				}
				p += 2;
			}
			L = vet[k].back().second-vet[k].back().first+1;
			ma = max(ma, L);
			custo += ma;
			//printf("oi %d\n", vet[k].size());
			if(vet[k++].size() == 1)
				break;
		}
		printf("%d\n", k);
		for(int i = 0; i < k; i++)
		{
			printf("%d\n", vet[i].size());
			for(int j = 0; j < vet[i].size(); j++)
				printf("%d %d\n", vet[i][j].first, vet[i][j].second);

		}
		//printf("CUSTO: %d\n", custo);
		//printf("FOI\n");
	}
	return 0;
}
