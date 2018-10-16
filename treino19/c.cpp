#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int m = n - 1;
		int cnt = 0;
		for(int i = 0; i < 32; i++){
			if(((1<<i)&n) != ((1<<i)&m))
				cnt++;
		}
		
		cout << cnt << endl;
	}
}
