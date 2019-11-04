#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define db(x) //cout << #x << " = " << x << endl;
#define INF 2 * 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

#define MAXB 11
#define MAXZ 112

int B, Z;
int curr_pos[MAXB];
int next_pos[MAXB][MAXZ];
ll a[MAXZ][MAXB], m[MAXZ][MAXB];

template<class T>
T gcd(T a, T b, T &x, T &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}

	T x1, y1;
	T d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

ll crt(ll a, ll m, ll b, ll n)
{
    if (n > m)
        swap(a, b), swap(m, n);
    ll x, y, g = gcd<ll>(m, n, x, y);
    if((a - b) % g != -0)
        return -1;
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m * n / g : x;
}

ll crt_system(ll a[], ll m[], int n)
{
    // normalize
    for(int i = 0; i < n; i++) 
        a[i] = (a[i] % m[i] + m[i]) % m[i];

    ll ans = a[0];
    ll lcm = m[0];
    for(int i = 1; i < n; i++)
    {
        ans = crt(ans, lcm, a[i], m[i]);
        ll x, y;
        ll d = gcd<ll>(lcm, m[i], x, y);
        if (d == -1)
            return -1;
        lcm = lcm * m[i] / d;
    }
    return ans;
}

int main()
{
    scanf("%d%d", &B, &Z);
    for (int i = 0; i < B; i++)
    {
        scanf("%d", &curr_pos[i]);
        --curr_pos[i];
        for (int j = 0; j < Z; j++)
        {
            scanf("%d", &next_pos[i][j]);
            --next_pos[i][j];
        }
    }

    int time;
    for (time = 0; time < 300; time++)
    {
        if (count(curr_pos, curr_pos + B, curr_pos[0]) == B)
        {
            return !printf("%d %d\n", curr_pos[0] + 1, time);
        }

        for (int i = 0; i < B; i++)
        {
            curr_pos[i] = next_pos[i][curr_pos[i]];
        }
    }

    vi possible_zoo(Z, 1);

    for (int i = 0; i < B; i++)
    {
        vi vis(Z, -1);
        int cycle_sz = 0;

        while (vis[curr_pos[i]] == -1)
        {
            vis[curr_pos[i]] = cycle_sz;
            cycle_sz++;
            curr_pos[i] = next_pos[i][curr_pos[i]];
        }

        for (int j = 0; j < Z; j++)
        {
            if (vis[j] == -1)
            {
                possible_zoo[j] = 0;
            }
            else
            {
                a[j][i] = vis[j];
                m[j][i] = cycle_sz;
            }
        }
    }

    ll best = INF;
    int best_zoo;
    for (int i = 0; i < Z; i++)
    {
        if (possible_zoo[i])
        {
            ll x = crt_system(a[i], m[i], B);
            if (x != -1)
            {
                if (x < best)
                {
                    best = x;
                    best_zoo = i;
                }
            }
        }
    }

    if (best == INF)
        printf("*\n");
    else
        printf("%d %lld\n", best_zoo + 1, best + time);

}