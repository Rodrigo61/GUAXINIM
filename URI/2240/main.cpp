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

struct Node
{
	int left, middle, right;
};

int NA, NB;
vector<Node> treeA, treeB;

int max_seq_central_root(const vector<Node> &tree, int u){

	if (tree[u].middle == -1)
	{
		return 1;
	}

	return max_seq_central_root(tree, tree[u].middle) + 1;
}

int max_seq_central(const vector<Node> &tree, int u, int score){

	int left_score = 0, right_score = 0, middle_score = score;
	
	db(u);
	db(score);

	if (tree[u].left != -1)
	{
		left_score = max_seq_central(tree, tree[u].left, 1);
	}
	
	if (tree[u].middle != -1)
	{
		middle_score = max_seq_central(tree, tree[u].middle, score + 1);
	}
	
	if (tree[u].right != -1)
	{
		right_score = max_seq_central(tree, tree[u].right, 1);
	}
	
	return max({left_score, middle_score, right_score});	
}


int main() 
{
	
	scanf("%d", &NA);
	treeA.resize(NA);
	for (int i = 0; i < NA; i++)
	{
		int node, l, m;
		scanf("%d%d%d", &node, &l, &m) ;
		--node, --l, --m;
		
		treeA[node].left = l;
		treeA[node].middle = m;
		treeA[node].right = -1;
	}
	
	scanf("%d", &NB);
	treeB.resize(NB);
	for (int i = 0; i < NB; i++)
	{
		int node, m, r;
		scanf("%d%d%d", &node, &m, &r) ;
		--node, --m, --r;
		
		treeB[node].right = r;
		treeB[node].middle = m;
		treeB[node].left = -1;
	}
	
	
	printf("%d\n", NA + NB - max(min(max_seq_central(treeA, 0, 1), max_seq_central_root(treeB, 0)), 
								 min(max_seq_central(treeB, 0, 1), max_seq_central_root(treeA, 0))));

	return 0;
}
