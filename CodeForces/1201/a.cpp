#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()

 
int main()
{
	int N, M;
	cin >> N >> M;
	vector<string> vet_s(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vet_s[i];
	}
	
	vi points(M);
	for (int i = 0; i < M; i++)
	{
		cin >> points[i];
	}
	
	int res = 0;
	for (int i = 0; i < M; i++)
	{
		vi freq(255);
		for (int j = 0; j < N; j++)
		{
			freq[vet_s[j][i]]++;
		}
		res += *max_element(all(freq)) * points[i];
	}
	
	cout << res << endl;
	
	
}
