/* String Hashing
 * Função que precalcula o hash de toda substring de uma string.
 * Obs: Se não funcionar,tenta colocar outro primo
 * */

#include<bits/stdc++.h>
#define ll long long
#define MOD1 1000000007
#define MOD2 1000000009
#define MAXLEN 100001
using namespace std;


class Hash
{
	public:
	string str;
	ll hash1[MAXLEN], hash2[MAXLEN];
	ll pot1[MAXLEN], pot2[MAXLEN];

	Hash(string &s)
	{
		str = s;
		pot1[0] = pot2[0] = 1;
		hash1[0] = hash2[0] = 0;
		for(int i = 0; i < (int)str.size(); i++)
		{
			pot1[i+1] = (26LL*pot1[i])%MOD1;
			pot2[i+1] = (26LL*pot2[i])%MOD2;
			hash1[i+1] = (26LL*hash1[i] + (str[i]-'A'))%MOD1;
			hash2[i+1] = (26LL*hash2[i] + (str[i]-'A'))%MOD2;
		}
	}

	ll get1(int st, int en) const
	{
		return ((hash1[en] - (hash1[st]*pot1[en-st]) % MOD1) % MOD1 + MOD1)%MOD1;
	}

	ll get2(int st, int en) const
	{
		return ((hash2[en] - (hash2[st]*pot2[en-st]) % MOD2) % MOD2 + MOD2)%MOD2;
	}
	
	ll get_all1() const
	{
		return get1(0, str.size());
	}
	
	ll get_all2() const
	{
		return get2(0, str.size());
	}

	bool check_substr(int sta, int ena, int stb, int enb)
	{
		return (get1(sta, ena) == get1(stb, enb)) && (get2(sta, ena) == get2(stb, enb));
	}
	
	bool operator==(const Hash &o)
	{
		return get_all1() == o.get_all1() && get_all2() == o.get_all2();
	}
};
