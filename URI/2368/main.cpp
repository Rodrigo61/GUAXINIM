#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl;
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vii vector<pii>

struct block
{
	int mi, ma;
	int i, j;
	bool inv;
	block(int _mi, int _ma, int _i, int _j, bool _inv)
	{
		mi = _mi;
		ma = _ma;
		i = _i;
		j = _j;
		inv = _inv;
	}
	bool operator<(const block &b) const
	{
		if (this->i == b.i)
			return this->j < b.j;
		return this->i < b.i;
	}
};

set<block> s_blocks;
int N, Q;

ll get_sum(ll mi, ll ma)
{
	db(mi);
	db(ma);
	return ((mi + ma)*(ma - mi + 1))/2;
}

void one_block(set<block>:: iterator &it, int L, int R)
{
	if (it->inv)
	{
		int left_elem = it->ma;
		int right_elem = it->mi;
		if (it->i != L)
			s_blocks.insert({left_elem, left_elem + (L - it->i - 1), it->i, L - 1, 1});
		s_blocks.insert({left_elem + (L - it->i), left_elem + (R - it->i), L, R, 0});
		if (it->j != R)
			s_blocks.insert({left_elem + (R - it->i) + 1, right_elem, R + 1, it->j, 1});
		
	}
	else
	{
		int left_elem = it->mi;
		int right_elem = it->ma;
		if (it->i != L)
			s_blocks.insert({left_elem + (L - it->i - 1), left_elem, it->i, L - 1, 0});
		s_blocks.insert({left_elem + (L - it->i), left_elem + (R - it->i), L, R, 1});
		db(s_blocks.size());
		if (it->j != R)
			s_blocks.insert({right_elem, left_elem - (R - it->i) + 1, R + 1, it->j, 0});
	}
	s_blocks.erase(it);
	
}

void mult_blocks(set<block>:: iterator &it, int L, int R)
{
	vector<block> affected_blocks;
	// begin
	// divide left block
	db("I BEG");
	if (it->inv)
	{
		int left_elem = it->ma;
		int right_elem = it->mi;
		if (it->i != L)
			s_blocks.insert({left_elem - (L - it->i - 1), left_elem, it->i, it->i + (L - it->i - 1), 1});
		// new block
		affected_blocks.pb({right_elem, left_elem - (L - it->i - 1), 0, 0, 0});
	}
	else
	{
		int left_elem = it->mi;
		int right_elem = it->ma;
		if (it->i != L)
			s_blocks.insert({left_elem, left_elem + (L - it->i - 1), it->i, it->i + (L - it->i - 1), 0});
		// new block
		affected_blocks.pb({left_elem + (L - it->i), right_elem, 0, 0, 1});
	}
	it = s_blocks.erase(it);
	
	// middle
	db("I MID");
	while (it != s_blocks.end() && it->j < R)
	{
		affected_blocks.pb({it->mi, it->ma, 0, 0, !it->inv});
		it = s_blocks.erase(it);
	}
	
	// end
	db("oi");
	if (it != s_blocks.end())
	{
		db("I END");
		// divide right block
		if (it->inv)
		{
			int left_elem = it->ma;
			int right_elem = it->mi;
			if (it->j != R)
				s_blocks.insert({right_elem, right_elem + (R - it->j - 1), it->j - (R - it->j - 1), it->j, 1});
			// new block
			affected_blocks.pb({left_elem - (R - it->j - 1), left_elem, 0, 0, 0});
		}
		else
		{
			int left_elem = it->mi;
			int right_elem = it->ma;
			if (it->j != R)
				s_blocks.insert({right_elem - (R - it->j - 1), right_elem, it->j - (R - it->j - 1), it->j, 0});
			// new block
			affected_blocks.pb({left_elem, left_elem + (R - it->j - 1) + 1, 0, 0, 1});
		}
		it = s_blocks.erase(it);
	}
	
	reverse(all(affected_blocks));
	int c = L;
	for (auto b : affected_blocks)
	{
		int range = b.ma - b.mi;
		b.i = c;
		c += range;
		b.j = c;
		++c;
		s_blocks.insert(b);
	}
			
}

int main()
{
	scanf("%d%d", &N, &Q);
	s_blocks.insert({1, N, 1, N, 0});
	for (auto b : s_blocks)
	{
		printf("(%d, %d) [mi = %d, ma = %d], %d\n", b.i, b.j, b.mi, b.ma, b.inv);
	}
	db(N);
	db(Q);
	for (int i = 0; i < Q; i++)
	{
		char cmd;
		int L, R;
		scanf(" %c%d%d", &cmd, &L, &R);
		db(cmd);
		db(L);
		db(R);
		if (cmd == 'I')
		{
			auto it = s_blocks.begin();
			while (it->j < L) ++it;
			
			if (it->j >= R)
			{
				one_block(it, L, R);
			}
			else
			{
				mult_blocks(it, L, R);
			}
			
			
			db(s_blocks.size());
			for (auto b : s_blocks)
			{
				printf("(%d, %d) [mi = %d, ma = %d], %d\n", b.i, b.j, b.mi, b.ma, b.inv);
			}
			db("FINISH");
		}
		else
		{
			ll sum = 0;
			auto it = s_blocks.begin();
			while (it->j < L) ++it;
			// begin
			
			// divide left block
			if (it->inv)
			{
				int left_elem = it->ma;
				int right_elem = it->mi;
				sum += get_sum(right_elem, left_elem - (L - it->i - 1));
			}
			else
			{
				int left_elem = it->mi;
				int right_elem = it->ma;
				sum += get_sum(left_elem + (L - it->i - 1) + 1, right_elem);
			}
			// middle
			while (it->j <= R)
			{
				sum += get_sum(it->mi, it->ma);
				++it;
			}
			// end
			// divide right block
			if (it->inv)
			{
				int left_elem = it->ma;
				sum += get_sum(left_elem - (R - it->j - 1), left_elem);
			}
			else
			{
				int left_elem = it->mi;
				sum += get_sum(left_elem, left_elem + (R - it->j - 1) + 1);
			}
			
			printf("%lld\n", sum);
		}
	}
	
	
}
