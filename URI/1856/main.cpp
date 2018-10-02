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


#define MAXN 100001
#define SQRN 325

deque<int> block[SQRN];
int N;
int block_sz;
unordered_map<int, int> which_block;

void print_blocks()
{
	
	for (int i = 0; i < block_sz && !block[i].empty(); i++)
	{
		printf("Block = %d: ", i);
		
		for (auto &v : block[i])
		{
			printf("%d ", v);
		}
		printf("\n");
	}
	printf("\n");
}

void insert_front(int b, int val)
{
	block[b].push_front(val);
	which_block[val] = b;
	
	while ((int)block[b].size() > block_sz)
	{
		int overflow = block[b].back();
		block[b].pop_back();
		
		block[b + 1].push_front(overflow);
		which_block[overflow] = b + 1;
		
		b++;
	}
	
}

void insert(int next_to, int val)
{
	
	int b = which_block[next_to];
	
	db(next_to);
	auto insert_pos = find(all(block[b]), next_to);
	insert_pos++;
	
	block[b].insert(insert_pos, val);
	which_block[val] = b;
	
	if ((int)block[b].size() > block_sz)
	{
		int overflow = block[b].back();
		block[b].pop_back();
		insert_front(b + 1, overflow);
	}
	
	//~ print_blocks();
}

void erase(int val)
{
	int b = which_block[val];
	
	block[b].erase(find(all(block[b]), val));
	
	int last_block = b;
	for (int i = b + 1; i < block_sz && !block[i].empty(); ++i)
	{
		int front = block[i].front();
		block[i].pop_front();
		block[last_block].push_back(front);
		which_block[front] = last_block;
		last_block = i;
	}
	
	//~ print_blocks();
}

int range_sum(int val_l, int val_r)
{
	int b_l = which_block[val_l];
	int b_r = which_block[val_r];
	
	if (b_l > b_r)
	{
		swap(val_l, val_r);
		swap(b_l, b_r);
	}
	
	int L = distance(block[b_l].begin(), find(all(block[b_l]), val_l));
	int R = distance(block[b_r].begin(), find(all(block[b_r]), val_r));
	
	if (b_l == b_r && L > R)
	{
		swap(L, R);
		swap(val_l, val_r);
	}
	
	db(b_l);
	db(b_r);
	db(L);
	db(R);
	
	if (b_l == b_r)
	{
		return R - L - 1;
	}
	else
	{
		int acu = 0;
		
		acu += block_sz - L - 1;
		
		for (int i = b_l + 1; i < b_r; ++i)
		{
			acu += block[i].size();
		}
		
		acu += R;
		
		return acu;
	}
}

int main() 
{

	scanf("%d", &N);
	
	block_sz = 2;
	
	vi init_vals(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &init_vals[i]);
	}
	
	int Q;
	scanf("%d\n", &Q);
	
	block_sz = (int) sqrt(N + Q + 0.1) + 1;
	//block_sz = 2;
	
	for (int i = init_vals.size() - 1; i >= 0; --i)
	{
		insert_front(0, init_vals[i]);
	}
		
	//~ print_blocks();
	
	char cmd;
	int arg1, arg2;
	for (int i = 0; i < Q; i++)
	{
		scanf("%c", &cmd);
		db(cmd);
		
		if (cmd == 'Q')
		{
			scanf("%d%d\n", &arg1, &arg2);
			printf("%d\n", range_sum(arg1, arg2));
		}
		else if (cmd == 'I')
		{
			scanf("%d%d\n", &arg1, &arg2);
			insert(arg2, arg1);
		}
		else
		{
			scanf("%d\n", &arg1);
			erase(arg1);
		}
	}
	
	
	
	
	return 0;
}
