#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define db(x) //cerr << #x << " = " << x << endl
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<pii>
#define ll long long
#define ull unsigned long long
typedef long double ld;

#define MAXN 312
#define MAXD 1123

char aux[10];
vi adj[MAXN];
vi catalog[MAXN][MAXN];
vii documents[MAXD];
bool used_document[MAXD];
vi cant_be_ancestor_of[MAXN];
bool ancestors[MAXN][MAXN];
int id = 0;


int visited[MAXN];
int in_stack[MAXN];

bool dfs(int u)
{
    if(!visited[u])
	{
        visited[u] = true;
        in_stack[u] = true;
 
		for (int &v : adj[u]) 
		{	
			if (in_stack[v])
				return true;
				
			if (dfs(v))
				return true;
		}
    }
    in_stack[u] = false;  
    return false;
}
 
bool has_cycle()
{
    memset(visited, 0, sizeof(visited));
    memset(in_stack, 0, sizeof(in_stack));

    for(int i = 0; i < id; i++)
        if (dfs(i))
            return true;
 
    return false;
}

int main()
{
    string A, B;
    scanf("%s", aux);
    A = aux;
    scanf("%s", aux);
    B = aux;

    map<string, int> compressed;
    compressed[A] = id++;
    compressed[B] = id++;

    int n;
    scanf("%d", &n);
    vector<vector<pair<string, string>>> input(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        
        for (int j = 0; j < k; j++)
        {
            string a, b;
            scanf("%s", aux);
            a = aux;
            scanf("%s", aux);
            b = aux;

            if (compressed.find(a) == compressed.end())
                compressed[a] = id++;
            if (compressed.find(b) == compressed.end())
                compressed[b] = id++;

            input[i].pb({a, b});
        }
    }

    adj[compressed[A]].pb(compressed[B]);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < (int)input[i].size(); j++)
        {
            int u = compressed[input[i][j].fi];
            int v = compressed[input[i][j].se];
            documents[i].pb({u, v});

            if (u > v) swap(u, v);

            catalog[u][v].pb(i);
        }
    }

    for (;;)
    {
        int curr_doc = -1;
        int a, b;
        for (int j = 0; j < id; j++)
        {
            vi vis(id + 1);

            queue<int> q;
            q.push(j);
            db(j);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                int pu = j;
                a = u;
                b = j;

                int cu = min(u, pu);
                int cpu = max(u, pu);

                while (!catalog[cu][cpu].empty())
                {
                    int d = catalog[cu][cpu].back();
                    catalog[cu][cpu].pop_back();
                    if (!used_document[d])
                    {
                        curr_doc = d;
                        used_document[d] = 1;
                        break;
                    }
                }

                if (curr_doc != -1)
                    break;

                for (int v : adj[u])
                {
                    if (!vis[v])
                    {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }

            if (curr_doc != -1)
                break;
        }

        db(curr_doc);

        if (curr_doc == -1)
            break;
        

        // discovering type of document
        int type = 1;
        for (int j = 0; j < (int)documents[curr_doc].size(); j++)
        {
            if (documents[curr_doc][j].fi == a && documents[curr_doc][j].se == b)
            {
                // negative
                type = 0;
            }
        }

        db(type);
        for (int j = 0; j < (int)documents[curr_doc].size(); j++)
        {
            if (type)
            {
                adj[documents[curr_doc][j].fi].pb(documents[curr_doc][j].se);
            }
            else
            {
                cant_be_ancestor_of[documents[curr_doc][j].se].pb(documents[curr_doc][j].fi);
            }
        }

        if (has_cycle())
            return !printf("No\n");
        
    }

    // check for invalid ancestors
    for (int i = 0; i < id; i++)
    {
        queue<int> q;
        q.push(i);
        vi vis(id + 5);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            ancestors[i][u] = 1;

            for (int v : adj[u])
            {
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
                    
            }
        }
    }

    for (int i = 0; i < id; i++)
    {
        for (int v : cant_be_ancestor_of[i])
            if (ancestors[v][i])
                return !printf("No\n");
    }
    
    printf("Yes\n");
    
}