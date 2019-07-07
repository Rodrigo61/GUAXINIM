//codigo
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db(x) cerr << #x << " = " << x << endl;

int N;
string seq;
set<string> pref, suf;
 
void add_prefs_sufs(string &s) 
{
	pref.insert("");
	suf.insert("");
	for (int i = 0; i < (int)s.size(); i++)
	{
		string p1 = s.substr(0, i + 1);
		string p2 = s.substr(i);
		
		//~ db(p1);
		//~ db(p2);
		pref.insert(p1);
		suf.insert(p2);
	}
}

int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> seq;
		//~ db(seq);
		for (int j = 0; j < (int)seq.size(); j++)
		{
			string p1 = seq.substr(0, j + 1);
			string p2 = seq.substr(j + 1);
			//~ db(p1);
		//~ db(p2);
			
			if (suf.find(p1) != suf.end() && pref.find(p2) != pref.end())
			{
				cout << seq << endl;
				return 0;
			}
		}
		
		add_prefs_sufs(seq);
	}
	
	cout << "ok" << endl;
	
}
