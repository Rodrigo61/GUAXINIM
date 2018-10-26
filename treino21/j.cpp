#include<bits/stdc++.h>

using namespace std;

int acum[100001];

string str;

int main()
{
	int N, f, cont;
	vector<int> divisores;
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	cin >> N;
	cin.ignore();
	while(N--)
	{
		getline(cin, str);
		stringstream ss(str);
		for(cont = 1; ss >> str; cont++)
		{
			acum[cont] = str.size()+1 + acum[cont-1];
			//printf("%d\n", acum[cont]);
		}
		cont--;
		divisores.clear();
		for(int i = 2; i*i <= acum[cont]; i++)
			if(acum[cont] % i == 0)
			{
				divisores.push_back(i);
				divisores.push_back(acum[cont]/i);
			}
		
		sort(divisores.begin(), divisores.end());
		f = 0;
		for(int i = 0; i < int(divisores.size()); i++)
		{
			int j;
			for(j = divisores[i]; j <= acum[cont]; j += divisores[i])
				if(!binary_search(acum, acum+cont+1, j))
					break;
			if(j > acum[cont])
			{
				f = 1;
				break;
			}
		}
		printf("%s\n", f ? "YES" : "NO");
	}
	return 0;
}
