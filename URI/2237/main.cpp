#include "bits/stdc++.h"
using namespace std;

#define db(x) cout << #x << " == " << x << endl
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

#define INF 1000000

vi source, target, vertex, vertex2;
string str_source;

map<string, int> content2id;
map<int, string> id2content;
vi peso;
int id;

int N = 40320;
int dist[40321];

string toString(vi &vet)
{
	string res;
	for (int i : vet)
	{
		res += i + '0';
	}
	
	return res;
}

vii get_neigh(int u)
{

	string &str_content = id2content[u];
	for (int i = 0; i < 8; i++)
	{
		vertex[i] = str_content[i] - '0';
	}
	
	vii res;
	
	for (int i = 0; i < 3; i++)
	{
		vertex2 = vertex;
		swap(vertex2[i], vertex2[i + 1]);
		str_content = toString(vertex2);
		
		if (content2id.find(str_content) == content2id.end())
		{
			content2id[str_content] = id;
			id2content[id++] = str_content;
		}
		
		swap(vertex2[i], vertex2[i + 1]);
		res.pb({content2id[str_content], peso[vertex[i]] + peso[vertex[i + 1]]});
	}
	
	for (int i = 4; i < 7; i++)
	{
		vertex2 = vertex;
		swap(vertex2[i], vertex2[i + 1]);
		str_content = toString(vertex2);

		if (content2id.find(str_content) == content2id.end())
		{
			content2id[str_content] = id;
			id2content[id++] = str_content;
		}
		
		swap(vertex2[i], vertex2[i + 1]);
		res.pb({content2id[str_content], peso[vertex[i]] + peso[vertex[i + 1]]});
	}
	
	for (int i = 0; i < 4; i++)
	{
		vertex2 = vertex;
		swap(vertex2[i], vertex2[i + 4]);
		str_content = toString(vertex2);

		if (content2id.find(str_content) == content2id.end())
		{
			content2id[str_content] = id;
			id2content[id++] = str_content;
		}
		
		swap(vertex2[i], vertex2[i + 4]);
		res.pb({content2id[str_content], peso[vertex[i]] + peso[vertex[i + 4]]});
	}
	
	
	return res;
}

int dijkstra()
{
	int u, v, w;
	
	priority_queue<pair<int, int> > fila;
	
	for(int i = 1; i <= N; i++)
		dist[i] = INF;
			
	dist[0] = 0;
	fila.push(make_pair(0, 0));
	
	while(!fila.empty())
	{
		w = -fila.top().first;
		u = fila.top().second;
		fila.pop();
		
		if (u == 1)
		{
			break;
		}
		
		if(w > dist[u])
			continue;
			
		for(pii i : get_neigh(u))
		{
			v = i.first;
			w = i.second;

			if(dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				fila.push(make_pair(-dist[v], v));
			}
		}
	}
	
	return dist[1];
}

int main() 
{

	source.resize(8);
	target.resize(8);
	vertex.resize(8);
	vertex2.resize(8);
	peso.resize(8);

	map<int, int> conversor;
	id = 0;
	
	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &source[i]);
		
		if (conversor.find(source[i]) == conversor.end())
		{
			conversor[source[i]] = id++;
		}
		
		peso[conversor[source[i]]] = source[i];
		source[i] = conversor[source[i]];
	}
	
	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &target[i]);
		target[i] = conversor[target[i]];
	}
	
	
	id = 0;
	string str_source = toString(source);
	string str_target = toString(target);
	
	content2id[str_source] = id;
	id2content[id++] = str_source;
	content2id[str_target] = id;
	id2content[id++] = str_target;
	
	if (str_source == str_target)
	{
		return !printf("0\n");
	}
	
	printf("%d\n", dijkstra());
	
	
	return 0;
}
