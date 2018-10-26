#include "bits/stdc++.h"
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back
#define fi first
#define se second

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

int N, M, D;
int aux[5];

struct state{
	int A[5];
	int B[5];
	
	void decreaseB(int pos)
	{
		B[pos]--;
		sort(B,B + 5);
	}
	
	void decreaseA(int pos)
	{
		A[pos]--;
		sort(A, A + 5);
	}
	
	void operator= (state &other)
	{
		memcpy(other.A, A, sizeof(A));
		memcpy(other.B, B, sizeof(B));
	}
};

ll encode(state &curr_state)
{
    ll res = 0;
    for (int i = 0; i < 5; i++)
    {
        res *= 10;
        res += curr_state.A[i] + '0';
    }
    for (int i = 0; i < 5; i++)
    {
        res *= 10;
        res += curr_state.B[i] + '0';
    }
    
    return res;
}



#define MOD1 369119
#define MAXLEN 100001

ll compute_hash(state &curr_state) {
    const int p = 31;
    long long hash_value = 0;
    long long p_pow = 1;
    
    for (int i = 0; i < 5; i++)
    {
        hash_value = (hash_value + (curr_state.A[i] + 1) * p_pow) % MOD1;
        p_pow = (p_pow * p) % MOD1;
    }
    
    for (int i = 0; i < 5; i++)
    {
        hash_value = (hash_value + (curr_state.B[i] + 1) * p_pow) % MOD1;
        p_pow = (p_pow * p) % MOD1;
    }
    
    return hash_value;
}

double dp[101][MOD1];
int vis[101][MOD1];

double solve(int d, state &curr_state, int total)
{
    
    if (total == 0)
    {
        return 1;
    }
    
    if (d == 0)
    {
        
        return count(curr_state.B, curr_state.B + 5, 0) == 5 ? 1:0;
    }
    
    ll encoded = compute_hash(curr_state);
    
    if (vis[d][encoded])
    {
        return dp[d][encoded];
    }
    vis[d][encoded] = 1;
    
    //~ printf("d = %d\n", d);
    //~ curr_state.print();
    
    double res = 0;
    
    for (int i = 0; i < 5; i++)
    {
        if (curr_state.A[i] > 0)
        {
            curr_state.A[i]--;
            int minus = curr_state.A[i] == 0;
            res += 1/(double)total * solve(d - 1, curr_state, total - minus);
            curr_state.A[i]++;
        }
        if (curr_state.B[i] > 0)
        {
            curr_state.B[i]--;
            int minus = curr_state.B[i] == 0;
            res += 1/(double)total * solve(d - 1, curr_state, total - minus);
            curr_state.B[i]++;
        }
    }
    
    dp[d][encoded] = res;
    return res;
}

int main() 
{
    scanf("%d%d%d", &N, &M, &D);
    
    state aux_state;
    memset(aux_state.A, 0, sizeof(aux_state.A));
    memset(aux_state.B, 0, sizeof(aux_state.B));
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &aux_state.A[i]);
    }
    sort(aux_state.A, aux_state.A + 5);
    
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &aux_state.B[i]);
    }
    sort(aux_state.B, aux_state.B + 5);
    
 
	//~ return 0;
    printf("%.14lf\n", solve(D, aux_state, N + M));
    
    return 0;
}

