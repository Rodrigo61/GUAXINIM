#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define F first
#define S second

int main()
{
	int n;
	string s;
	
	cin >> n;
	
	int x;
	
	int cnt = 0;
	
	pair<string, int> v[11];
	
	for(int i =1 ; i <= n; i++){
		cin >> s >> x;
		v[i-1] = make_pair(s, x);
	}
	
	for(int i =1 ; i <= 100; i++){
		int ini = i;
		for(int j = 0; j < n; j++){
			if(v[j].F == "SUBTRACT"){
				ini -= v[j].S;
				if(ini < 0){
					cnt++;
					break;
				}
			}
			else if(v[j].F == "ADD"){
				ini += v[j].S;
			}
			
			else if(v[j].F == "MULTIPLY"){
				ini *= v[j].S;
			}
			
			else if(v[j].F == "DIVIDE"){
				if(ini%v[j].S != 0){
					cnt++;
					break;
				}
				ini /= v[j].S;
			}
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}



