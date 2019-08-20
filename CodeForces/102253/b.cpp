#include<bits/stdc++.h>
     
    using namespace std;
     
    #define pb push_back
    #define vi vector<int>
    #define ll long long
    #define vll vector<ll>
    #define db(x) //cerr << #x << " = " << x << endl
     
    #define MOD 1000000007
     
    char aux[112345];
     
    ll add(ll a, ll b)
    {
    	return (a + b) % MOD;
    }
     
    ll mult(ll a, ll b)
    {
    	return (a * b) % MOD;
    }
     
    int main(){
     
    	int N;
    	int tc = 0;
    	while (scanf("%d", &N) != EOF)
    	{
    		vector<string> s;
    		vi possible_zero(26, 1);
    		int max_sz = 0;
    		for (int i = 0; i < N; i++)
    		{
    			scanf("%s", aux);
    			s.pb(string(aux));
    			max_sz = max(max_sz, (int)s.back().size());
    			if ((int)s.back().size() > 1)
    			{
    				possible_zero[s.back().front() - 'a'] = 0;
    			}
    		}
    		
    		vector<vll> freq(26, vll(max_sz, 0));
    		for (string str : s)
    		{
    			db(str);
    			int idx = (int)str.size() - 1;
    			for (char c : str)
    			{
    				freq[c - 'a'][idx]++;
    				--idx;
    			}
    		}
    		db("d1");
    		for (char c = 0; c <= 25; c++)
    		{
    			for (int i = 0; i < max_sz - 1; i++)
    			{
    				if (freq[c][i] >= 26)
    				{
    					freq[c][i + 1] += freq[c][i] / 26;
    					freq[c][i] %= 26;
    				}
    			}
    		}
    		
    		vector<char> vet_char;
    		for (int i = 'a'; i <= 'z'; i++)
    			vet_char.pb(i);
    			
    		db("d1");
    		sort(vet_char.begin(), vet_char.end(), [&](char c1, char c2) {
    			for (int i = max_sz - 1; i >= 0; i--)
    			{
    				if (freq[c1 - 'a'][i] < freq[c2 - 'a'][i])
    				{
    					return true;
    				}
    				if (freq[c2 - 'a'][i] < freq[c1 - 'a'][i])
    				{
    					return false;
    				}
    			}
    			return false;
    		});
     
    		if (!possible_zero[vet_char.front() - 'a'])
    		{
    			int i = 0;
    			while (!possible_zero[vet_char[i] - 'a']) 
    				++i;
    			char new_zero = vet_char[i];
    			vet_char.erase(vet_char.begin() + i);
    			vet_char.insert(vet_char.begin(), new_zero);
    		}
     
    		vll dict(26);
    		for (int i = 0; i < 26; i++)
    		{
    			dict[vet_char[i] - 'a'] = i;
    		}
    		
    		ll res = 0;
    		for (string str : s)
    		{
    			ll pot = 1;
    			for (int i = str.size() - 1; i >= 0; i--)
    			{
    				res = add(res, mult(pot, dict[str[i] - 'a']));
    				pot = mult(pot, 26);
    			}
    		}
    		
    		printf("Case #%d: %lld\n", ++tc, res);
    	}
    }
