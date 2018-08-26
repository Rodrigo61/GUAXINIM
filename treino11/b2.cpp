#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	char s[500005];
	cin >> n;
	scanf("%s", s);
	
	vector<int> v;
	set<pair<int, int> > conj;
	
	for(int i = 1; i < n; i++){
		if(s[i] < s[0]){
			cout << "No" << endl;
			return 0;
		}
		if(s[i] == s[0]){
			v.push_back(i);
		}
	}
	
	if(v.size() == 0 || v.size() == n - 1){
		cout << "Yes" << endl;
		return 0;
	}
	
	for(int i = 0; i < v.size() - 1; i++){
		conj.insert({v[i], v[i+1] - v[i]});
	}
	int size = v.size() - 1;
	conj.insert({v[size], n - v[size]});

	set<pair<int, int>  > el;

	for(int i = 1; i < v[0]; i++){
		//printf("i = %d\n", i);
		for(auto it: conj){	
			int j = (it).first;
			//printf("j = %d %d\n", j, it.second);
			if(j + i >= n){
				cout << "No" << endl;
				return 0;
			}
			else if((it).second == i){
				cout << "No" << endl;
				return 0;
			}
			else if(s[i] < s[j + i])
				el.insert(it);
			else if(s[i] > s[j + i]){
				cout << "No" << endl;
				return 0;
			}
		}
		
		for(auto it: el)
			conj.erase(it);
		el.clear();
	}
	
	cout << "Yes" << endl;
	
	return 0;
	
}
