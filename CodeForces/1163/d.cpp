#include <bits/stdc++.h>

using namespace std;
#define db(x) cerr << #x << " = " << x << endl;
#define pii pair<int, int>
#define ll long long
#define INF 0x3f3f3f3f

string text, hate, love;
vector<int> kmp_love, kmp_hate;
int vis[1005][55][55];
int dp[1005][55][55]; // LL?

void calc_lps(string &pat, vector<int> &lps) 
{ 
	lps.resize(pat.size(), 0);
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    int i = 1; 
    while (i < (int)pat.size()) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            db(lps[i]);
            i++; 
        } 
        else 
        { 
            if (len != 0) { 
                len = lps[len - 1]; 
  
            } 
            else
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

int solve(int c, int s, int t)
{
	int sc = 0;
	int tc = 0;
	
	if (s == (int)love.size())
	{
		sc = 1;
		s = kmp_love[s - 1];
	}
	
	if (t == (int)hate.size())
	{
		tc = 1;
		t = kmp_hate[t - 1];
	}
	
	if (c == (int)text.size())
	{
		return sc - tc;
	}
	
	if (vis[c][s][t])
	{
		return dp[c][s][t];
	}
	vis[c][s][t] = 1;
	
	
	int res = -INF;
	
	if (text[c] != '*')
	{
		int best_start_s = s; 
		while (best_start_s > 0 && love[best_start_s + 1] != text[c])
		{
			best_start_s = kmp_love[best_start_s] - 1;
		}
		int next_s = best_start_s + 1;
		
		int best_start_s = s; 
		while (best_start_s > 0 && love[best_start_s + 1] != text[c])
		{
			best_start_s = kmp_love[best_start_s] - 1;
		}
		int next_s = best_start_s + 1;
		
		int rec = solve(c + 1, next_s, next_t) + (sc - tc);
		res = max(res, rec);
	}
	else
	{
		// case *
		for (char l = 'a'; l <= 'z'; l++)
		{
			int next_s = s, next_t = t; 
			while (next_s != 0 && love[next_s + 1] != l)
			{
				next_s = kmp_love[next_s];
				if (next_s == 0)
				{
					next_s = -1;
					break;
				}
				
			}
			++next_s;
			
			while (next_t != 0 && hate[next_t + 1] != l)
			{
				next_t = kmp_hate[next_t];
				if (next_t == 0)
				{
					next_t = -1;
					break;
				}
			}
			++next_t;
			
			int rec = solve(c + 1, next_s, next_t) + (sc - tc);
			res = max(res, rec);
				
		}
	}
	
	dp[c][s][t] = res;
	return res;
	
}

int main()
{
	//~ love = "abcabcd";
	//~ calc_lps(love, kmp_love);
	//~ printf("kmp_love: ");
	//~ for (int i = 0; i < kmp_love.size(); i++)
	//~ {
		//~ printf("%d ", kmp_love[i]);
	//~ } printf("\n");

	//~ exit(1);
	cin >> text >> love >> hate;
	calc_lps(love, kmp_love);
	calc_lps(hate, kmp_hate);
	
	cout << solve(0, 0, 0) << endl;
}
