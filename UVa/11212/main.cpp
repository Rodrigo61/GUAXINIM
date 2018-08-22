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

string target_state;
map<string, int> dist;

vector<string> get_neigh(string &curr_state)
{
	int sz = curr_state.size();
	
	vector<string> res;
	
	
	db(curr_state);
	for (int i = 0; i < sz; i++)
	{
		for (int j = i; j < sz; j++)
		{
			
			for (int m = 0; m < sz; m++)
			{
				
				if (sz - m < j - i + 1) continue;
				
				db(i);
				db(j);
				db(m);
				string aux = curr_state;
				
				for (int l = 0; l < j - i + 1; l++)
				{
					aux[m + l] = curr_state[i + l];
				}
				
				int it = 0;
				if (it == i) it = j + 1;
				
				for (int l = 0; l < m; l++)
				{
					aux[l] = curr_state[it];
					
					++it;
					if (it == i) it = j + 1;
				}
				
				for (int l = m + j - i + 1; l < sz; l++)
				{
					aux[l] = curr_state[it];
					++it;
					if (it == i) it = j + 1;
				}
				
				db(aux);
				if (aux != curr_state)
				{
					res.pb(aux);
				}
				
			}
	
		}
		
	}
	
	//~ exit(1);
	return res;
}

int BFS(string &source_state)
{
	
	dist.clear();
	dist[source_state] = 0;
	
	queue<string> q;
	q.push(source_state);
	
	while (!q.empty())
	{
		string u = q.front();
		int dist_u = dist[u];
		q.pop();
		
		if (u == target_state)
		{
			return dist_u;
		}
		
		for (auto &v : get_neigh(u))
		{
			if (dist.find(v) == dist.end())
			{
				dist[v] = dist_u + 1;
				q.push(v);
			}
		}
	}
	
	return -1;
}

int main() 
{
	
	int N;
	string curr_state;
	int n_case = 0;
	
	while (scanf("%d", &N), N)
	{
		curr_state.clear();
		for (int i = 0; i < N; i++)
		{
			int val;
			scanf("%d", &val);
			
			curr_state += val - 1 + '0';
		}
		
		target_state.clear();
		for (int i = 0; i < N; i++)
		{
			target_state += i + '0';
		}
		
		
		printf("Case %d: %d\n", ++n_case, BFS(curr_state));
	}

	return 0;
}

testando o teclado. Ele é muito ruim mesmo.juhyRequirements = ((Machine == "dl-01.recod") || (Machine == "dl-02.recod") || (Machine == "dl-03.recod") || (Machine == "sms02.recod") || (Machine == "sms03.recod") || (Machine == "sms04.recod") || (Machine == "twin01-c.recod") || (Machine == "twin02-b.recod") || (Machine == "twin02-d.recod") )jubRequirements = ((Machine == "dl-01.recod") || (Machine == "dl-02.recod") || (Machine == "dl-03.recod") || (Machine == "sms02.recod") || (Machine == "sms03.recod") || (Machine == "sms04.recod") || (Machine == "twin01-c.recod") || (Machine == "twin02-b.recod") || (Machine == "twin02-d.recod") )5rfc 1	'1	1	\
