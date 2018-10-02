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

#define MAXN (int)500001
#define SQRN 715

int N, Q;
int vals[MAXN];
int freq[SQRN][MAXN + 100005];
int sqr;
int BIT_LIMIT;

struct Query{
	int cmd;
	int a, b, c;
};

int in[MAXN];
vector<int> ordered_in;
vector<Query> vet_query;

void update(int pos, int val, int idx)
{
	pos++;
	while (pos <= BIT_LIMIT + 1)
	{
		freq[idx][pos] += val;
		pos += (pos & (-pos));
	}
}

int value(int pos, int idx)
{
	int val = 0;
	pos++;
	while (pos > 0)
	{
		val += freq[idx][pos];
		pos -= (pos & (-pos));
	}
	
	return val;
}

int get_id(int x)
{
	return lower_bound(all(ordered_in), x) - ordered_in.begin();
}

int main() 
{
	scanf("%d", &N);
	
	sqr = sqrt(N);
	
	set<int> set_in;
	int v;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &v);
		in[i] = v;
		set_in.insert(v);
	}
	
	scanf("%d", &Q);
	int cmd;
	int a,b,c;
	vet_query.resize(Q);
	for (int i = 0; i < Q; i++)
	{
		scanf("%d", &cmd);
		vet_query[i].cmd = cmd;
		if (cmd == 0)
		{
			scanf("%d%d%d", &a, &b, &c);
			vet_query[i].a = a;
			vet_query[i].b = b;
			vet_query[i].c = c;
		}
		else
		{
			scanf("%d%d", &a, &b);
			vet_query[i].a = a;
			vet_query[i].b = b;
			set_in.insert(b);
		}
	}

	ordered_in.assign(all(set_in));
	BIT_LIMIT = set_in.size() - 1;

	for (int i = 0; i < N; i++)
	{
		vals[i] = get_id(in[i]);
		update(vals[i], 1, i/sqr);
	}
	
	
	for (int i = 0; i < Q; i++)
	{
		cmd = vet_query[i].cmd;
		
		if (cmd == 0)
		{
			a = vet_query[i].a;
			b = vet_query[i].b;
			c = vet_query[i].c;
			--a, --b;
			c = get_id(c);
			int sum = 0;
			int c_l = a / sqr,   c_r = b / sqr;

			if (c_l == c_r){
				for (int i = a; i <= b; ++i)
				{
					if (vals[i] >= c)
						sum++;
				}
			}
			else {
				for (int i = a, end = (c_l+1)*sqr-1; i <= end; ++i)
				{
					if (vals[i] >= c)
						sum++;	
				}
				for (int i = c_l+1; i <= c_r-1; ++i)
				{
					db(value(BIT_LIMIT, i));
					sum += value(BIT_LIMIT, i) - value(c - 1, i);
				}
				for (int i = c_r*sqr; i <= b; ++i)
				{
					if (vals[i] >= c)
						sum++;	
				}
			}
			
			printf("%d\n", sum);
		}
		else
		{
			a = vet_query[i].a;
			b = vet_query[i].b;
			--a;
			
			update(vals[a], -1, a/sqr);
			vals[a] = get_id(b);
			update(vals[a], 1, a/sqr);
		}
	}
	
	return 0;
}
