#include "bits/stdc++.h"
using namespace std;

#define db(x) //cerr << #x << " == " << x << endl
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

int N;
vector<pair<pair<int, int>, string>> vet;

bool isprefix(string &a, string &b)
{
	for (int i = 0; i < (int)a.size(); i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	
	return true;
}

bool issuffix(string &a, string &b)
{
	int off = b.size() - a.size();
	for (int i = 0; i < (int)a.size(); i++)
	{
		if (a[i] != b[i + off])
		{
			return false;
		}
	}
	
	return true;
}

int main() 
{
	scanf("%d", &N);
	
	vet.resize(2*N - 2);
	
	string p1, p2;
	for (int i = 0; i < 2*N - 2; i++)
	{
		cin >> vet[i].second;
		vet[i].first.first = vet[i].second.size();
		vet[i].first.second = i;
		
		if ((int)vet[i].second.size() == N - 1)
		{
			if (p1.empty())
			{
				p1 = vet[i].second;
			}
			else
			{
				p2 = vet[i].second;
			}
		}
	}
	
	string s1 = p1 + p2.back();
	string s2 = p2 + p1.back();
	
	sort(all(vet));
	db(s1);
	db(s2);
	
	vi result(2*N - 2);
	bool possible = true;
	for (int i = 0; i < 2*N - 2; i += 2)
	{
		db(vet[i].first.second);
		db(vet[i + 1].first.second);
		if (issuffix(vet[i].second, s1) && isprefix(vet[i + 1].second, s1))
		{
			result[vet[i].first.second] = 0;
			result[vet[i + 1].first.second] = 1;
		}
		else if (isprefix(vet[i].second, s1) && issuffix(vet[i + 1].second, s1))
		{
			result[vet[i].first.second] = 1;
			result[vet[i + 1].first.second] = 0;
		}
		else
		{
			possible = false;
			break;
		}
	}
	
	if (possible)
	{
		for (int i = 0; i < result.size(); i++)
		{
			if (result[i] == 0)
			{
				printf("S");
			}
			else
			{
				printf("P");
			}
		}
		return !printf("\n");
	}
	
	possible = true;
	for (int i = 0; i < 2*N - 2; i += 2)
	{
		
		if (issuffix(vet[i].second, s2) && isprefix(vet[i + 1].second, s2))
		{
			result[vet[i].first.second] = 0;
			result[vet[i + 1].first.second] = 1;
		}
		else if (isprefix(vet[i].second, s2) && issuffix(vet[i + 1].second, s2))
		{
			result[vet[i].first.second] = 1;
			result[vet[i + 1].first.second] = 0;
		}
		else
		{
			possible = false;
			break;
		}
	}
	
	if (possible)
	{
		for (int i = 0; i < (int)result.size(); i++)
		{
			if (result[i] == 0)
			{
				printf("S");
			}
			else
			{
				printf("P");
			}
		}
		return !printf("\n");
	}
	
	return 0;
}
